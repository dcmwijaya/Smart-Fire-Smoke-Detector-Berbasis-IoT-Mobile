[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile)
![Project](https://img.shields.io/badge/Project-Mobile%20of%20Things-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)

# Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile
<strong>Tugas Akhir Indobot Academy: Kelas Awal untuk Menjadi Insinyur IoT yang Hebat Batch 1</strong><br/><br/>
Peningkatan penduduk di suatu negara merupakan salah satu modal pembangunan. Jumlah penduduk yang besar dapat memengaruhi perkembangan permukiman. Namun, di sisi lain permukiman yang tidak diimbangi dengan pengaturan yang baik dapat memicu terjadinya bencana, misalnya kebakaran. Bencana kebakaran yang terjadi dapat mengakibatkan kerugian materiil dan immateriil. Oleh karena itu, proyek ini dibuat untuk menyelesaikan masalah yang ada. Proyek ini telah dilaksanakan dan memakan waktu kurang lebih 2 minggu. Manfaat dari pembuatan proyek ini tidak lain adalah untuk menambah wawasan. Hasil penelitian menunjukkan bahwa sistem yang dibuat ini dapat mendeteksi terjadinya kebakaran. Antarmuka sistem menggunakan aplikasi MIT App Inventor.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | Wemos D1 R2 |
| Editor Kode | Arduino IDE |
| Dukungan Aplikasi | MIT App Inventor |
| Driver | USB-Serial CH340 |
| Platform IoT | Antares |
| Protokol Komunikasi | • Inter Integrated Circuit (I2C)<br>• Message Queuing Telemetry Transport (MQTT) |
| Arsitektur IoT | 4 Lapisan |
| Basis Data |  Firebase |
| Bahasa Pemrograman | C/C++ |
| Pustaka Arduino | • ESP8266WiFi (bawaan)<br>• Wire (bawaan)<br>• AntaresESP8266MQTT<br>• Firebase_Arduino_Client_Library_for_ESP8266_and_ESP32<br>• MQ2_LPG<br>• LiquidCrystal_I2C |
| Aktuator | Piezo buzzer (x1) |
| Sensor | • KY-26: Sensor Api (x1)<br>• MQ-2: Sensor Gas (x1) |
| Layar | LCD I2C (x1) |
| Komponen Lainnya | • Kabel Mikro USB - USB tipe A (x1)<br>• Kabel jumper (1 set)<br>• Breadboard (x1)<br>• Kotak casing (x1) |

<br><br>

## Unduh & Instal
1. Arduino IDE

   <table><tr><td width="810">

   ```
   https://www.arduino.cc/en/software
   ```

   </td></tr></table><br>

2. USB-Serial CH340

   <table><tr><td width="810">

   ```
   https://bit.ly/CH340_Driver
   ```

   </td></tr></table>
   
<br><br>

## Rancangan Proyek
<table>
<tr>
<th width="280">Diagram Skematik</th>
<th width="280">Diagram Ilustrasi</th>
<th width="280">Diagram Blok</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile/assets/54527592/96bb0e6b-f03d-4f39-a6d8-e993e7405f27" alt="Schematic-Diagram"></td>
<td><img src="https://user-images.githubusercontent.com/54527592/230712584-0eeead02-6707-4474-a973-2b69ad8521e0.jpg" alt="Pictorial-Diagram"></td>
<td><img src="https://user-images.githubusercontent.com/54527592/230714375-b773c927-3c82-4036-a520-8a1a20df778b.jpg" alt="Block-Diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="280">Infrastruktur</th>
<th width="280">Prototipe</th>
<th width="280">Diagram Sistem</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile/assets/54527592/77efc5b8-fc80-4b39-a979-64a548594119" alt="Infrastructure"></td>
<td><img src="https://github.com/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile/assets/54527592/998fe206-f514-4cd4-92de-0d74387e539b" alt="Prototype"></td>
<td><img src="https://github.com/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile/assets/54527592/46497a05-c8cd-425d-aa4b-40b430cb8f74" alt="Systems-Diagram"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810"> 
      
      ``` Final_Project_Indobot_KelasMulaiJadiIoTEngineerHebat.ino ```

   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">
      
      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
   
      ```
      http://arduino.esp8266.com/stable/package_esp8266com_index.json
      ```

   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` WEMOS D1 R2 ```
            
      </th></tr>
      <tr><td>
      
      • Klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp8266 ```.
      
      • Kemudian pilih Board dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` ESP8266 Board ``` -> ``` LOLIN(WEMOS) D1 R2 & mini ```.

      </td></tr>
   </table><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE

   <table><tr><td width="810">
      
      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```

   </td></tr></table><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">
      
      Unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

6. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">
      
      Klik ``` Port ``` -> Pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```

   </td></tr></table><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.<br><br>

10. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan Antares
1. Memulai Antares :

   <table><tr><td width="810">
      
   • Silakan <a href="https://beta-console.antares.id/id/signup">Registrasi</a> terlebih dahulu.

   • Selanjutnya silakan <a href="https://beta-console.antares.id/id">Masuk</a> agar dapat mengakses layanan.

   </td></tr></table><br>
   
2. Membuat applications :

   <table><tr><td width="810">
      
   • Masuk ke menu ``` Applications ```.

   • Klik ``` + Create an Application ```.

   • Dalam menu ``` Add Application ```, silakan menentukan beberapa hal berikut :
      - ``` Application Name ``` -> ``` Nama Aplikasi yang akan anda buat ```.
      - ``` Application ID ``` -> ``` ID Aplikasi yang akan anda buat ```.
      - ``` Labels ``` -> tentukan sesuai dengan kebutuhan proyek.

   </td></tr></table><br>
   
3. Membuat device :

   <table><tr><td width="810">
      
   • Pastikan anda berada di menu ``` Home / Applications / Aplikasi yang anda buat ```.

   • Klik ``` + Add Device ```.

   • Nama device ini sebaiknya anda tentukan berdasarkan variabel yang ada dalam proyek.

   </td></tr></table><br>
   
4. Konfigurasi firmware :

   <table><tr><td width="810">
      
   • Pastikan anda berada di menu ``` Account ```.

   • Salin ``` Access Key ``` tersebut.

   • Tempelkan pada kode firmware, contohnya seperti ini :

   ```
   #define ACCESSKEY "1444e88d02acb758:b996115b1c2f6f0f"
   ```

   • Kemudian, ``` Nama proyek ``` dan ``` Nama device ``` itu harus sesuai dengan yang telah dibuat tadi. Contohnya :
   
   ```
   #define projectName "Final_Project_Indobot_Academy_2023"
   #define deviceName "Smart_Fire_Smoke_Detector"
   ```

   </td></tr></table>
   
<br><br>

## Pengaturan Firebase
1. Buka situs resmi ``` Firebase ``` :

   <table><tr><td width="810">
   
   ```
   https://console.firebase.google.com/
   ```

   </td></tr></table><br>
   
2. Buat proyek dengan nama bebas.<br><br>

3. Klik ``` simbol gerigi ``` yang ada di samping ``` Project Overview ``` -> Lalu pilih ``` Project settings ``` untuk mendapatkan ``` FirebaseToken ```.<br><br>

4. Klik ``` Realtime Database ``` untuk mendapatkan ``` FirebaseURL ```.

<br><br>

## Pengaturan MIT App Inventor
1. Buka situs resmi ``` MIT App Inventor ``` :

   <table><tr><td width="810">
   
   ```
   https://appinventor.mit.edu/
   ```

   </td></tr></table><br>
   
2. Klik ``` Create Apps! ```, kemudian masuk dengan menggunakan akun google.<br><br>

3. Klik ``` Project ``` -> lalu impor berkas yang ada di direktori ``` Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile\Src\MIT App Inventor Project\ ``` :

   <table><tr><td width="810">

   ``` Smart_Fire_Smoke_Detector.aia ```

   </td></tr></table><br>

4. Klik ``` FirebaseDB1 ``` lalu atur 3 poin berikut ini :

   <table><tr><td width="810">
      
   • ``` FirebaseToken ``` -> isi dengan ``` Token ``` yang diperoleh dari bagian ``` Project settings ```.
   
   • ``` FirebaseURL ``` -> isi dengan ``` URL ``` yang diperoleh dari bagian ``` Realtime Database ```.
   
   • ``` ProjectBucket ``` -> isi dengan ``` Kontainer DB ```. Dalam hal ini adalah ``` Detect ```.

   </td></tr></table><br>

5. Kemudian klik ``` Connect ``` -> selanjutnya pilih ``` AI Companion ```.<br><br>

6. Buka ponsel cerdas anda, lalu pada ``` Google Play Store ``` cari aplikasi ``` MIT AI2 Companion ```, kemudian lakukan instalasi.<br><br>

7. Buka aplikasi ``` MIT AI2 Companion ```.<br><br>

8. Pilih metode ``` Scan QR Code ```.<br><br>

9. Arahkan ponsel cerdas anda ke area ``` QR Code ``` yang ada di situs ``` MIT App Inventor ```.

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>
   
2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
   
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>

5. Selamat menikmati [Selesai].

<br><br>

## Sorotan
<table>
<tr>
<th width="280">MIT App Inventor</th>
<th width="280">Percobaan</th>
<th width="280">Firebase</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile/assets/54527592/8fd3aaff-4cc3-4e20-bb7d-e6901f313edd" alt="Konfigurasi-MITAppInventor"></td>
<td><img src="https://github.com/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile/assets/54527592/f7e977d1-2a2d-4799-ab7f-e691ab59180d" alt="Percobaan"></td>
<td><img src="https://user-images.githubusercontent.com/54527592/230712751-33315d3e-0264-49d5-be01-26cca253053e.JPG" alt="Firebase"></td>
</tr>
</table>
<table>
<tr>
<th colspan="2">Simulasi Pemantauan dengan Aplikasi Mobile</th>
</tr>
<tr>
<td width="420"><img src="https://user-images.githubusercontent.com/54527592/230712782-dc6db3e1-b8d2-40e3-8a2d-8d55158c4a8d.png" alt="Monitoring-1"></td>
<td width="420"><img src="https://user-images.githubusercontent.com/54527592/230712794-f99306df-482b-4232-8f65-bf8caaec16e2.jpg" alt="Monitoring-2"></td>
</tr>
</table>

<br><br>

## Penafian
Aplikasi ini dibuat dengan menyertakan sumber-sumber dari pihak ketiga. Pihak ketiga di sini adalah penyedia layanan, yang layanannya berupa pustaka, kerangka kerja, dan lain-lain. Saya ucapkan terima kasih banyak atas layanannya. Telah terbukti sangat membantu dan dapat diimplementasikan.

<br><br>

## LISENSI
LISENSI MIT - Hak Cipta © 2022 - Devan C. M. Wijaya, S.Kom

Dengan ini diberikan izin tanpa biaya kepada siapa pun yang mendapatkan salinan perangkat lunak ini dan file dokumentasi terkait perangkat lunak untuk menggunakannya tanpa batasan, termasuk namun tidak terbatas pada hak untuk menggunakan, menyalin, memodifikasi, menggabungkan, mempublikasikan, mendistribusikan, mensublisensikan, dan/atau menjual salinan Perangkat Lunak ini, dan mengizinkan orang yang menerima Perangkat Lunak ini untuk dilengkapi dengan persyaratan berikut:

Pemberitahuan hak cipta di atas dan pemberitahuan izin ini harus menyertai semua salinan atau bagian penting dari Perangkat Lunak.

DALAM HAL APAPUN, PENULIS ATAU PEMEGANG HAK CIPTA DI SINI TETAP MEMILIKI HAK KEPEMILIKAN PENUH. PERANGKAT LUNAK INI DISEDIAKAN SEBAGAIMANA ADANYA, TANPA JAMINAN APAPUN, BAIK TERSURAT MAUPUN TERSIRAT, OLEH KARENA ITU JIKA TERJADI KERUSAKAN, KEHILANGAN, ATAU LAINNYA YANG TIMBUL DARI PENGGUNAAN ATAU URUSAN LAIN DALAM PERANGKAT LUNAK INI, PENULIS ATAU PEMEGANG HAK CIPTA TIDAK BERTANGGUNG JAWAB, KARENA PENGGUNAAN PERANGKAT LUNAK INI TIDAK DIPAKSAKAN SAMA SEKALI, SEHINGGA RISIKO ADALAH MILIK ANDA SENDIRI.
