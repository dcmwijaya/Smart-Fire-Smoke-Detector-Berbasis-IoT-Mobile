// WiFi
#include <ESP8266WiFi.h>
#include <AntaresESP8266MQTT.h>
#define WIFISSID "YOUR_WIFI_NAME"
#define PASSWORD "YOUR_WIFI_PASSWORD"

// MQTT ANTARES
#define ACCESSKEY "YOUR_ANTARES_ACCESS_KEY"
#define projectName "YOUR_ANTARES_APPLICATION_NAME"
#define deviceName "YOUR_ANTARES_DEVICE_NAME"
AntaresESP8266MQTT antares(ACCESSKEY);

// Firebase
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#define API_KEY "YOUR_FIREBASE_API_KEY"
#define DATABASE_URL "YOUR_FIREBASE_DATABASE_URL" 
FirebaseData fbdo; 
FirebaseAuth auth;
FirebaseConfig config;

// Sensor & Actuator
#include <MQ2_LPG.h>
#define Gas_Pin A0
MQ2Sensor mq2(Gas_Pin);
#define Flame_Pin D5
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define Buzzer_Pin D3

// Variabel Global
int gas_read; int flame_read;
String gas_status, flame_status;
int gasAntares; int flameAntares;
unsigned long sendDataPrevMillis = 0;
bool signupOK = false;

// Koneksi WiFi-Antares dengan protokol MQTT
void koneksiWiFiAntares(){
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID, PASSWORD);
  antares.setMqttServer();
  antares.setCallback(callback);
}

// Koneksi Firebase
void koneksiFirebase(){
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  if (Firebase.signUp(&config, &auth, "", "")){ Serial.println("Successfully connected...\n"); signupOK = true; }
  else{ Serial.printf("%s\n", config.signer.signupError.message.c_str()); }
  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

// Kalibrasi Data Gas
#define RL_Value 100
#define x1_Value 199.150007852152
#define x2_Value 797.3322752256328
#define y1_Value 1.664988323698715
#define y2_Value 0.8990240080541785
#define x_Value 497.4177875376839
#define y_Value 1.0876679972710004
#define Ro_Value 6.02
#define Voltage_Value 5.0
#define bitADC_Value 1023.0 // Resolusi ADC berdasarkan papan pengembangan yang sedang dipakai

void mq2Calibration(){
  mq2.RL(RL_Value); // Nilai RL yang ditetapkan
  mq2.Ro(Ro_Value); // Nilai Ro yang ditetapkan
  mq2.Volt(Voltage_Value); // Nilai Volt yang ditetapkan
  mq2.BitADC(bitADC_Value); // Nilai BitADC yang ditetapkan
  mq2.mCurve(x1_Value, x2_Value, y1_Value, y2_Value); // Nilai m_Curve yang ditetapkan
  mq2.bCurve(x_Value, y_Value); // Nilai b_Curve yang ditetapkan
  mq2.getCalibrationData(); // Memanggil data kalibrasi data MQ2 untuk Gas LPG
//  mq2.viewCalibrationData(); // Tampilkan data MQ2 yang telah di kalibrasi
}

// Baca Sensor
void bacaSensor(){
  mq2Calibration(); // Memanggil method mq2Calibration
  gas_read = mq2.readGas(); // Baca data sensor Gas LPG
  flame_read = digitalRead(Flame_Pin); // Baca data sensor Flame
}

// Publish Data Sensor ke Platform IoT Antares
void sendAntares(){
  bacaSensor(); // Memanggil method bacaSensor
  antares.add("gas", gas_read); // Menambahkan topic dengan nama "gas"
  antares.add("flame", flame_read); // Menambahkan topic dengan nama "flame"
  antares.publish(projectName, deviceName); // Publish data sensor ke Platform Antares
  delay(5000); // Tunda 5 detik
}

// Subscribe Data IoT Antares
void callback(char topic[], byte payload[], unsigned int length) {
  antares.get(topic, payload, length); // Memanggil topic dengan payloadnya
  gasAntares = antares.getInt("gas"); // Memanggil topic "gas" dan disimpan ke dalam variabel gasAntares
  flameAntares = antares.getInt("flame"); // Memanggil topic "flame" dan disimpan ke dalam variabel flameAntares
  // Print subscribe data ke serial monitor
  Serial.println("[ANTARES] SUBSCRIBE DATA:\n"); 
  Serial.println("topic: " + antares.getTopic());
  Serial.println("payload: " + antares.getPayload()); 
  Serial.println("gas: " + String(gasAntares)); 
  Serial.println("flame: " + String(flameAntares)+"\n");
}

// Pengolahan Data Sensor
void Olah_Data(){
  // Cek Sensor Gas: LPG
  if(gasAntares > 200){ // Jika gas LPG lebih dari 200 maka :
    gas_status = String(gasAntares)+"ppm-Danger"; Serial.println("Gas Monitoring: "+String(gas_status)+" => (Evacuate) - Alarm is ringing"); Display_LCD(" ON ", " "); // Cetak Data
    digitalWrite(Buzzer_Pin, HIGH); // Buzzer: ON
  } else{ // Jika gas LPG tidak lebih dari 200 maka :
    gas_status = String(gasAntares)+"ppm-Normal"; Serial.println("Gas Monitoring: "+String(gas_status)+" => (Safe) - Alarm is silent"); Display_LCD(" OFF ", " "); // Cetak Data
    digitalWrite(Buzzer_Pin, LOW); // Buzzer: OFF
  }
  // Cek Sensor Api
  if(flameAntares == 1){ // Jika ada api maka :
    flame_status = "Detected"; Serial.println("Flame Monitoring: "+String(flameAntares)+" ("+String(flame_status)+") => (Evacuate) - Alarm is ringing\n"); Display_LCD(" ", " ON "); // Cetak Data
    digitalWrite(Buzzer_Pin, HIGH); // Buzzer: ON
  } else{ // Jika tidak ada api maka :
    flame_status = "Not-Detected"; Serial.println("Flame Monitoring: "+String(flameAntares)+" ("+String(flame_status)+") => (Safe) - Alarm is silent\n"); Display_LCD(" ", " OFF "); // Cetak Data
    digitalWrite(Buzzer_Pin, LOW); // Buzzer: OFF
  }
}

// Cetak Data Sensor di LCD
void Display_LCD(String BuzzerGas, String BuzzerFlame){
    lcd.setCursor(0,0); lcd.print("G: "); lcd.print(gasAntares,1); // Cetak data gas di baris 0, kolom 0
    lcd.setCursor(10,0); lcd.print("B:"); lcd.print(BuzzerGas); // Cetak data buzzer di baris 10, kolom 0
    lcd.setCursor(0,1); lcd.print("F: "); lcd.print(flameAntares); // Cetak data flame di baris 0, kolom 1
    lcd.setCursor(10,1); lcd.print("B:"); lcd.print(BuzzerFlame); // Cetak data buzzer di baris 10, kolom 1
}

// Kirim Data IoT ke Platform Firebase
void sendFirebase(){
  Olah_Data(); // Memanggil method Olah_Data
  Firebase.RTDB.setString(&fbdo, "/Detect/Gas", gas_status); // Mengirimkan data gas ke firebase
  Firebase.RTDB.setString(&fbdo, "/Detect/Flame", flame_status); // Mengirimkan data flame ke firebase
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 5000 || sendDataPrevMillis == 0)){ // Jika Firebase terhubung dan interval waktu ditetapkan setiap 5 detik sekali dalam mengirimkan data maka :
    sendDataPrevMillis = millis(); // Menghitung interval pengiriman data
    if(Firebase.RTDB.setString(&fbdo, "/Detect/Gas", gas_status)){ // Jika berhasil mengirimkan data gas ke firebase maka cetak :
      Serial.println("PATH: " + fbdo.dataPath()); Serial.println("TYPE: " + fbdo.dataType()); Serial.println("Send data (Gas) to Firebase: successfully...");
    }
    else { // Jika gagal mengirimkan data gas ke firebase maka cetak :
      Serial.println("REASON: " + fbdo.errorReason()); Serial.println("Send data (Gas) to Firebase: failed...");
    }
    if(Firebase.RTDB.setString(&fbdo, "/Detect/Flame", flame_status)){ // Jika berhasil mengirimkan data flame ke firebase maka cetak :
      Serial.println("\nPATH: " + fbdo.dataPath()); Serial.println("TYPE: " + fbdo.dataType()); Serial.println("Send data (Flame) to Firebase: successfully...\n");
    }
    else { // Jika gagal mengirimkan data flame ke firebase maka cetak :
      Serial.println("\nREASON: " + fbdo.errorReason()); Serial.println("Send data (Flame) to Firebase: failed...\n");
    }
  }
}

// Method Setup
void setup(){
  Serial.begin(115200); // Baudrate
  koneksiWiFiAntares(); // Koneksi WiFi-Antares dengan protokol MQTT
  koneksiFirebase(); // Koneksi Firebase 
  mq2.begin(); // Memulai MQ2
  pinMode(Flame_Pin,INPUT_PULLUP); // Inisialisasi status pin flame sebagai INPUT_PULLUP
  pinMode(Buzzer_Pin,OUTPUT); // Inisialisasi status pin buzzer sebagai OUTPUT
  digitalWrite(Buzzer_Pin, LOW); // Default Buzzer: OFF
  lcd.init(); // Memulai LCD
  lcd.backlight(); delay(250); lcd.noBacklight(); delay(250); lcd.backlight(); // Splash Screen
  lcd.setCursor(0,0); lcd.print("Smart Fire-Smoke"); lcd.setCursor(4,1); lcd.print("Detector"); delay(3000); // Menampilkan data pada LCD
  lcd.clear(); // Menghapus penampilan data pada LCD
}

// Method Loop
void loop(){
  antares.checkMqttConnection(); // Mengecek koneksi MQTT berhasil atau tidak
  sendAntares(); // Memanggil method sendAntares
  sendFirebase(); // Memanggil method sendFirebase
} 
