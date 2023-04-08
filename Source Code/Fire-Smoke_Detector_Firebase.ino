// WiFi
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif
#define WIFI_SSID " "
#define WIFI_PASSWORD " "
// Firebase
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#define API_KEY " "
#define DATABASE_URL " " 
FirebaseData fbdo; 
FirebaseAuth auth;
FirebaseConfig config;
unsigned long sendDataPrevMillis = 0;
bool signupOK = false;
// LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
// Sensor
#include <MQ2_LPG.h>
MQ2Sensor mq2;
#define Gas_Pin A0
#define Flame_Pin D5
#define Buzzer_Pin D3
int gas_read = 0;
int flame_read = 0;
String gas_status, flame_status;

// Koneksi WiFi
void koneksiWiFi(){
  WiFi.mode(WIFI_STA);
  Serial.print("Menyambungkan ke: ");
  Serial.print(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println();
  Serial.print("Terhubung ke Local IP: ");
  Serial.println(WiFi.localIP());
}

// Koneksi Firebase
void koneksiFirebase(){
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("Successfully connected...\n");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

// Gas Calibration Data.
#define RL_Value 10
#define x1_Value 199.150007852152
#define x2_Value 797.3322752256328
#define y1_Value 1.664988323698715
#define y2_Value 0.8990240080541785
#define x_Value 497.4177875376839
#define y_Value 1.0876679972710004
#define Ro_Value 2.7
#define Voltage_Value 3.3
#define bitADC_Value 1023.0

void mq2Calibration(){
  mq2.RL(RL_Value);
  mq2.Ro(Ro_Value);
  mq2.Volt(Voltage_Value);
  mq2.BitADC(bitADC_Value);
  mq2.mCurve(x1_Value, x2_Value, y1_Value, y2_Value);
  mq2.bCurve(x_Value, y_Value);
  mq2.getDataCalibration();
//  mq2.viewDataCalibration();
}

// Baca Sensor
void Fire_Smoke(){
  mq2Calibration();
  gas_read = mq2.readGas();
  flame_read = digitalRead(Flame_Pin);
}

// Pengolahan Data Sensor
void Olah_Data(){
  Fire_Smoke();
  // Cek Sensor Gas: LPG
  if(gas_read > 200){
    // Cetak Data
    gas_status = String(gas_read)+"ppm-Danger";
    Serial.println("Gas Monitoring: "+String(gas_status)+" => (Evacuate) - Alarm is ringing");
    Display_LCD(" ON ", " ");
    // Buzzer: ON
    digitalWrite(Buzzer_Pin, HIGH);
  } else{
    // Cetak Data
    gas_status = String(gas_read)+"ppm-Normal";
    Serial.println("Gas Monitoring: "+String(gas_status)+" => (Safe) - Alarm is silent");
    Display_LCD(" OFF ", " ");
    // Buzzer: OFF
    digitalWrite(Buzzer_Pin, LOW);
  }
  // Cek Sensor Api
  if(flame_read==HIGH){
    // Cetak Data
    flame_status = "Detected";
    Serial.println("Flame Monitoring: "+String(flame_status)+" => (Evacuate) - Alarm is ringing\n");
    Display_LCD(" ", " ON ");
    // Buzzer: ON
    digitalWrite(Buzzer_Pin, HIGH);
  } else{
    // Cetak Data
    flame_status = "Not-Detected";
    Serial.println("Flame Monitoring: "+String(flame_status)+" => (Safe) - Alarm is silent\n");
    Display_LCD(" ", " OFF ");
    // Buzzer: OFF
    digitalWrite(Buzzer_Pin, LOW);
  }
}

// Cetak Data Sensor di LCD
void Display_LCD(String BuzzerGas, String BuzzerFlame){
    lcd.setCursor(0,0);
    lcd.print("G: ");
    lcd.print(gas_read,1);
    lcd.setCursor(10,0);
    lcd.print("B:"); 
    lcd.print(BuzzerGas);
    lcd.setCursor(0,1);
    lcd.print("F: ");
    lcd.print(flame_read);
    lcd.setCursor(10,1);
    lcd.print("B:");
    lcd.print(BuzzerFlame);
}

// Kirim Data IoT
void Send_Data_IoT(){
  Olah_Data();
  Firebase.RTDB.setString(&fbdo, "/Detect/Gas", gas_status);
  Firebase.RTDB.setString(&fbdo, "/Detect/Flame", flame_status);
}

// Method Setup
void setup(){
  // Baudrate
  Serial.begin(115200);
  // Koneksi WiFi & Firebase
  koneksiWiFi(); koneksiFirebase();
  // Inisialisasi status pin device
  pinMode(Gas_Pin,INPUT);
  mq2.begin(Gas_Pin);
  pinMode(Flame_Pin,INPUT_PULLUP);
  pinMode(Buzzer_Pin,OUTPUT);
  // Default Buzzer: OFF
  digitalWrite(Buzzer_Pin, LOW);
  // Memulai LCD
  lcd.init();
  // Splash Screen
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  // Menampilkan data pada LCD
  lcd.setCursor(0,0);
  lcd.print("Smart Fire-Smoke");
  lcd.setCursor(4,1);
  lcd.print("Detector");
  delay(3000);
  // Menghapus penampilan data pada LCD
  lcd.clear(); 
}

// Method Loop
void loop(){
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 5000 || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();
    Send_Data_IoT(); // Memanggil method Send_Data_IoT
    if(Firebase.RTDB.setString(&fbdo, "/Detect/Gas", gas_status)){
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      Serial.println("Send data (Gas) to Firebase: successfully...");
    }
    else {
      Serial.println("REASON: " + fbdo.errorReason());
      Serial.println("Send data (Gas) to Firebase: failed...");
    }
    if(Firebase.RTDB.setString(&fbdo, "/Detect/Flame", flame_status)){
      Serial.println("\nPATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      Serial.println("Send data (Flame) to Firebase: successfully...\n");
    }
    else {
      Serial.println("\nREASON: " + fbdo.errorReason());
      Serial.println("Send data (Flame) to Firebase: failed...\n");
    }
  }
} 
