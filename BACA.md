[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile)
![Project](https://img.shields.io/badge/Project-Mobile%20of%20Things-light.svg?style=flat&logo=github&logoColor=white&color=bcbcbc)
![MobileApps](https://img.shields.io/badge/Mobile%20Apps-MIT-%2DApp-%2DInventor-light.svg?style=flat&logo=android&logoColor=white&color=bcbcbc)
![Firebase](https://img.shields.io/badge/Database-Firebase-light.svg?style=flat&logo=firebase&logoColor=white&color=bcbcbc)
![Arduino](https://img.shields.io/badge/Tools-Arduino%20IDE-light.svg?style=flat&logo=arduino&logoColor=white&color=bcbcbc)

# Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile
<strong>Tugas Akhir Indobot Academy: Kelas Awal untuk Menjadi Insinyur IoT yang Hebat Batch 1</strong><br/>
Proyek ini sangat erat kaitannya dengan teknologi smart home, dimana alat ini digunakan secara real time untuk memudahkan pengguna dalam mengukur sejauh mana potensi kebakaran di ruangan sekitarnya. Sensor yang ada dapat beroperasi ketika terpengaruh oleh intensitas cahaya dan gas. Alat ini telah disimulasikan secara mobile dengan menggunakan platform MIT App Inventor.

<br/><br/>

## Fitur / Kerangka Kerja / Peralatan
| Media | Deskripsi |
| --- | --- |
| Platform | Antares & MIT App Inventor |
| Protokol IoT | MQTT |
| Arsitektur | 4 Layer |
| Papan Pengembangan | Wemos D1 R2 |
| Editor Kode | Arduino IDE |
| Pustaka Arduino | ESP8266WiFi, AntaresESP8266MQTT, Firebase_ESP_Client, addons/TokenHelper, addons/RTDBHelper, MQ2_LPG, Wire, & LiquidCrystal_I2C  |
| Basis Data |  Firebase |
| Aktuator | Piezo buzzer |
| Sensor | Sensor Api (KY-26) & Sensor Gas (MQ-2) |
| Layar | LCD I2C |
| Komponen Lainnya | Kabel Jumper & Breadboard  |

<br><br>


## Unduh & Instal
Unduh Arduino IDE :
```bash
https://www.arduino.cc/en/software
```

<br><br>

## Pengaturan
1. Buka Arduino IDE terlebih dahulu, kemudian masukkan Url Boards Manager dengan cara menyalin tautan berikut:
```bash
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
2. Pengaturan Board di Arduino IDE
   <ul>
      <li>Cara: klik Boards Manager -> ESP8266 Boards -> LOLIN(WEMOS) D1 R2 & Mini.</li>
   </ul>
3. Pengaturan Port di Arduino IDE
   <ul>
      <li>Cara: klik Port -> Pilih sesuai dengan port perangkat Anda (Anda dapat melihatnya di Device Manager).</li>
   </ul>
4. Instal pustaka di Arduino IDE
   <ul>
      <li>Cara: klik Tools -> Manage Libraries -> Instal Pustaka sesuai dengan kebutuhan proyek.</li>
   </ul>

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
<br/><br/>

## Menjalankan
1. Unduh Repositori ini.
2. Pastikan Anda memiliki komponen elektronik yang diperlukan.
3. Pastikan komponen Anda telah dirancang sesuai dengan diagram.
4. Pastikan komponen terhubung dengan baik (Sesuaikan pengaturan Board dan Port).
5. Disarankan untuk membuat akun Broker sekaligus dengan layanannya.
6. Pastikan untuk mengubah kode program arduino di bagian "Router" sesuai dengan perangkat yang Anda gunakan.
7. Jika Anda tidak menerapkan poin 2 dan 3 untuk keperluan pengembangan proyek itu tidak masalah, tetapi harap dicatat bahwa beberapa hal perlu diubah agar dapat berfungsi dengan baik.
8. Selesai, semoga berhasil.
<br/><br/><br/>

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

<br/><br/>

## LISENSI
LISENSI MIT - Hak Cipta (c) 2022 - Devan C. M. Wijaya, S.Kom

Dengan ini diberikan izin tanpa biaya kepada siapa pun yang mendapatkan salinan perangkat lunak ini dan file dokumentasi terkait perangkat lunak untuk menggunakannya tanpa batasan, termasuk namun tidak terbatas pada hak untuk menggunakan, menyalin, memodifikasi, menggabungkan, mempublikasikan, mendistribusikan, mensublisensikan, dan/atau menjual salinan Perangkat Lunak ini, dan mengizinkan orang yang menerima Perangkat Lunak ini untuk dilengkapi dengan persyaratan berikut:

Pemberitahuan hak cipta di atas dan pemberitahuan izin ini harus menyertai semua salinan atau bagian penting dari Perangkat Lunak.

DALAM HAL APAPUN, PENULIS ATAU PEMEGANG HAK CIPTA DI SINI TETAP MEMILIKI HAK KEPEMILIKAN PENUH. PERANGKAT LUNAK INI DISEDIAKAN SEBAGAIMANA ADANYA, TANPA JAMINAN APAPUN, BAIK TERSURAT MAUPUN TERSIRAT, OLEH KARENA ITU JIKA TERJADI KERUSAKAN, KEHILANGAN, ATAU LAINNYA YANG TIMBUL DARI PENGGUNAAN ATAU URUSAN LAIN DALAM PERANGKAT LUNAK INI, PENULIS ATAU PEMEGANG HAK CIPTA TIDAK BERTANGGUNG JAWAB, KARENA PENGGUNAAN PERANGKAT LUNAK INI TIDAK DIPAKSAKAN SAMA SEKALI, SEHINGGA RISIKO ADALAH MILIK ANDA SENDIRI.
