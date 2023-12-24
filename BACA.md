[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile)
![Project](https://img.shields.io/badge/Project-Mobile%20of%20Things-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)

# Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile
<strong>Tugas Akhir Indobot Academy: Kelas Awal untuk Menjadi Insinyur IoT yang Hebat Batch 1</strong><br/>
Proyek ini sangat erat kaitannya dengan teknologi smart home, dimana alat ini digunakan secara real time untuk memudahkan pengguna dalam mengukur sejauh mana potensi kebakaran di ruangan sekitarnya. Sensor yang ada dapat beroperasi ketika terpengaruh oleh intensitas cahaya dan gas. Alat ini telah disimulasikan secara mobile dengan menggunakan platform MIT App Inventor.

<br><br>

## Fitur / Kerangka Kerja / Peralatan
| Media | Deskripsi |
| --- | --- |
| Papan Pengembangan | Wemos D1 R2 |
| Editor Kode | Arduino IDE |
| Driver | USB-Serial CH340 |
| Platform IoT | Antares |
| Protokol IoT | MQTT |
| Arsitektur | 4 Lapisan |
| Platform Aplikasi Seluler | MIT App Inventor |
| Basis Data |  Firebase |
| Pustaka Arduino | ESP8266WiFi, AntaresESP8266MQTT, Firebase_ESP_Client, addons/TokenHelper, addons/RTDBHelper, MQ2_LPG, Wire, & LiquidCrystal_I2C  |
| Aktuator | Piezo buzzer |
| Sensor | Sensor Api (KY-26) & Sensor Gas (MQ-2) |
| Layar | LCD I2C |
| Komponen Lainnya | Kabel Jumper & Breadboard  |

<br><br>

## Unduh & Instal
1. Arduino IDE

   ```
   https://www.arduino.cc/en/software
   ```
<br>

2. USB-Serial CH340

   ```
   https://bit.ly/CH340_Driver
   ```
   
<br><br>

## Persyaratan Proyek
<table>
<tr>
<th width="280">Diagram Skematik</th>
<th width="280">Diagram Piktorial</th>
<th width="280">Diagram Blok</th>
</tr>
<tr>
<td><img src="https://user-images.githubusercontent.com/54527592/230712347-46f2d325-6f03-488e-8b79-b0f987550dee.jpg" alt="Schematic-Diagram"></td>
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
<td><img src="https://user-images.githubusercontent.com/54527592/231572412-e9f16257-0fdd-4237-8f61-4a72559a68fb.jpg" alt="Infrastructure"></td>
<td><img src="https://user-images.githubusercontent.com/54527592/230714098-e75e4eb4-e150-4660-a591-94e8451a21f4.jpg" alt="Prototype"></td>
<td><img src="https://user-images.githubusercontent.com/54527592/231572541-280549e4-fcae-4a69-bfc6-c6ed95f71c7d.jpg" alt="Systems-Diagram"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik: ``` File ``` -> ``` Open ``` -> ``` Final_Project_Indobot_KelasMulaiJadiIoTEngineerHebat.ino ```.<br><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE<br><br>
   • Cara: klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut:
   
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
   
3. ``` Pengaturan Board ``` di Arduino IDE<br><br>
   • Cara: klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp8266 ```. Kemudian pilih Board dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` ESP8266 Board ``` -> ``` LOLIN(WEMOS) D1 R2 & mini ```.<br><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE<br><br>
   • Cara: klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```.<br><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE<br><br>
   • Cara: unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```.<br><br>

6. ``` Pengaturan Port ``` di Arduino IDE<br><br>
   • Cara: klik ``` Port ``` -> Pilih sesuai dengan port perangkat Anda ``` (Anda dapat melihatnya di Device Manager) ```.<br><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang Anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.

<br><br>

## Pengaturan Firebase
1. Dalam proses....

<br><br>

## Pengaturan MIT App Inventor
1. Buka situs resmi ``` MIT App Inventor ``` :
   
   ```
   https://appinventor.mit.edu/
   ```
   
2. klik ``` Create Apps! ```, kemudian masuk dengan menggunakan akun google.<br><br>

3. Klik ``` Project ``` -> lalu impor ``` Smart_Fire_Smoke_Detector.aia ``` dari direktori ``` Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile\Src\MIT App Inventor Project\ ```.<br><br>

4. Kemudian klik ``` Connect ``` -> selanjutnya pilih ``` AI Companion ```.<br><br>

5. Buka smartphone anda, lalu pada ``` Google Play Store ``` cari aplikasi ``` MIT AI2 Companion ```, kemudian lakukan instalasi.<br><br>

6. Buka aplikasi ``` MIT AI2 Companion ```.<br><br>

7. Pilih metode ``` Scan QR Code ```.<br><br>

8. Arahkan smartphone anda ke area ``` QR Code ``` yang ada di situs ``` MIT App Inventor ```.

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>
   
2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
   
4. Membuat akun untuk Platform IoT beserta layanannya.<br><br>
    
5. Jika Anda tidak menerapkan poin 2 dan 3 untuk tujuan pengembangan proyek, tidak masalah, tetapi perlu diketahui bahwa beberapa hal perlu diubah sesuai dengan kebutuhan Anda agar sistem dapat bekerja dengan baik.<br><br>

6. Pastikan semua Things telah dibuat.<br><br>

7. Selamat menikmati [Selesai].

<br><br>

## Sorotan
<table>
<tr>
<th width="280">MIT App Inventor</th>
<th width="280">Percobaan</th>
<th width="280">Firebase</th>
</tr>
<tr>
<td><img src="https://user-images.githubusercontent.com/54527592/230714068-daaa11fd-2d23-4870-95c4-b946df4f036b.JPG" alt="Konfigurasi-MITAppInventor"></td>
<td><img src="https://user-images.githubusercontent.com/54527592/230768145-f70b5be3-38aa-4728-9524-2c75360eaf72.jpg" alt="Percobaan"></td>
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
LISENSI MIT - Hak Cipta (c) 2022 - Devan C. M. Wijaya, S.Kom

Dengan ini diberikan izin tanpa biaya kepada siapa pun yang mendapatkan salinan perangkat lunak ini dan file dokumentasi terkait perangkat lunak untuk menggunakannya tanpa batasan, termasuk namun tidak terbatas pada hak untuk menggunakan, menyalin, memodifikasi, menggabungkan, mempublikasikan, mendistribusikan, mensublisensikan, dan/atau menjual salinan Perangkat Lunak ini, dan mengizinkan orang yang menerima Perangkat Lunak ini untuk dilengkapi dengan persyaratan berikut:

Pemberitahuan hak cipta di atas dan pemberitahuan izin ini harus menyertai semua salinan atau bagian penting dari Perangkat Lunak.

DALAM HAL APAPUN, PENULIS ATAU PEMEGANG HAK CIPTA DI SINI TETAP MEMILIKI HAK KEPEMILIKAN PENUH. PERANGKAT LUNAK INI DISEDIAKAN SEBAGAIMANA ADANYA, TANPA JAMINAN APAPUN, BAIK TERSURAT MAUPUN TERSIRAT, OLEH KARENA ITU JIKA TERJADI KERUSAKAN, KEHILANGAN, ATAU LAINNYA YANG TIMBUL DARI PENGGUNAAN ATAU URUSAN LAIN DALAM PERANGKAT LUNAK INI, PENULIS ATAU PEMEGANG HAK CIPTA TIDAK BERTANGGUNG JAWAB, KARENA PENGGUNAAN PERANGKAT LUNAK INI TIDAK DIPAKSAKAN SAMA SEKALI, SEHINGGA RISIKO ADALAH MILIK ANDA SENDIRI.
