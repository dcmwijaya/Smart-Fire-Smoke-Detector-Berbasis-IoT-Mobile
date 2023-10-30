[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile)
![Project](https://img.shields.io/badge/Project-Mobile%20of%20Things-light.svg?style=flat&logo=github&logoColor=white&color=bcbcbc)
![MobileApps](https://img.shields.io/badge/Mobile%20Apps-MIT-%2DApp-%2DInventor-light.svg?style=flat&logo=android&logoColor=white&color=bcbcbc)
![Firebase](https://img.shields.io/badge/Database-Firebase-light.svg?style=flat&logo=firebase&logoColor=white&color=bcbcbc)
![Arduino](https://img.shields.io/badge/Tools-Arduino%20IDE-light.svg?style=flat&logo=arduino&logoColor=white&color=bcbcbc)

# Smart-Fire-Smoke-Detector-Berbasis-IoT-Mobile
<strong>Indobot Academy Final Project: The Starting Class to Become a Great IoT Engineer Batch 1</strong><br/>
This project is closely related to smart home technology, where this tool is used in real time to make it easier for users to measure the extent of fire potential in the surrounding room. Existing sensors can operate when affected by light and gas intensity. This tool has been simulated on a mobile basis using the MIT App Inventor platform.

<br/><br/>

## Features / Framework / Tools
| Media | Description |
| --- | --- |
| Platform | Antares & MIT App Inventor |
| IoT Protocol | MQTT |
| Architecture | 4 Layer |
| Board Development | Wemos D1 R2 |
| Code Editor | Arduino IDE |
| Arduino Library | ESP8266WiFi, AntaresESP8266MQTT, Firebase_ESP_Client, addons/TokenHelper, addons/RTDBHelper, MQ2_LPG, Wire, & LiquidCrystal_I2C  |
| Database |  Firebase |
| Actuators | Piezo buzzer |
| Sensor | Fire Sensor (KY-26) & Gas Sensor (MQ-2) |
| Display | LCD I2C |
| Other Components | Jumper cable & Breadboard  |

<br><br>


## Download & Install
Download Arduino IDE :
```bash
https://www.arduino.cc/en/software
```

<br><br>

## Settings
1. Open the Arduino IDE first, then enter the Boards Manager Url by copying the following link:
```bash
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
2. Board Setup in Arduino IDE
   <ul>
      <li>Method: click Boards Manager -> ESP8266 Boards -> LOLIN(WEMOS) D1 R2 & Mini.</li>
   </ul>
3. Port Setup in Arduino IDE
   <ul>
      <li>Method: click Port -> Choose according to your device port (you can see in device manager).</li>
   </ul>
4. Install Library in Arduino IDE
   <ul>
      <li>Method: click Tools -> Manage Libraries -> Install Library according to project needs.</li>
   </ul>

<br><br>

## Schematic Diagram
<img src="https://user-images.githubusercontent.com/54527592/230712347-46f2d325-6f03-488e-8b79-b0f987550dee.jpg">
<br/><br/>

## Pictorial Diagram
<img src="https://user-images.githubusercontent.com/54527592/230712584-0eeead02-6707-4474-a973-2b69ad8521e0.jpg">
<br/><br/>

## Block Diagram
<img src="https://user-images.githubusercontent.com/54527592/230714375-b773c927-3c82-4036-a520-8a1a20df778b.jpg">
<br/><br/>

## Infrastructure In Project
<img src="https://user-images.githubusercontent.com/54527592/231572412-e9f16257-0fdd-4237-8f61-4a72559a68fb.jpg">
<br/><br/>

## Designing Prototype
<img src="https://user-images.githubusercontent.com/54527592/230714098-e75e4eb4-e150-4660-a591-94e8451a21f4.jpg">
<br/><br/>

## Systems Diagram
<img src="https://user-images.githubusercontent.com/54527592/231572541-280549e4-fcae-4a69-bfc6-c6ed95f71c7d.jpg">
<br/><br/>

## Running
1. Download this Repository.
2. Make sure you have the necessary electronic components.
3. Make sure your components have been designed according to the diagram.
4. Make sure the components are well connected (Adjust Board and Port settings).
5. It is recommended to create a Broker account along with this service.
6. Make sure to change the arduino program code in the "Router" section according to the device you are using.
7. If you do not apply points 2 and 3 for the purposes of project development, it is fine, but please note that some things need to be changed in order to function properly.
8. Done, good luck.
<br/><br/><br/>

## Implementation
<table border="0">
  <img src="https://user-images.githubusercontent.com/54527592/230714068-daaa11fd-2d23-4870-95c4-b946df4f036b.JPG" style="width:1920px;">
  <img src="https://user-images.githubusercontent.com/54527592/230768145-f70b5be3-38aa-4728-9524-2c75360eaf72.jpg" style="width:1920px;">
  <img src="https://user-images.githubusercontent.com/54527592/230712751-33315d3e-0264-49d5-be01-26cca253053e.JPG">
  <tr>
    <td><img src="https://user-images.githubusercontent.com/54527592/230712782-dc6db3e1-b8d2-40e3-8a2d-8d55158c4a8d.png"></td>
    <td><img src="https://user-images.githubusercontent.com/54527592/230712794-f99306df-482b-4232-8f65-bf8caaec16e2.jpg"></td>
  </tr>
</table>
<br/><br/>

## LICENSE
MIT License - Copyright (c) 2022 - Devan C. M. Wijaya, S.Kom

Permission is hereby granted without charge to any person obtaining a copy of this software and the software-related documentation files to deal in them without restriction, including without limitation the right to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons receiving the Software to be furnished therewith on the following terms:

The above copyright notice and this permission notice must accompany all copies or substantial portions of the Software.

IN ANY EVENT, THE AUTHOR OR COPYRIGHT HOLDER HEREIN RETAINS FULL OWNERSHIP RIGHTS. THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, THEREFORE IF ANY DAMAGE, LOSS, OR OTHERWISE ARISES FROM THE USE OR OTHER DEALINGS IN THE SOFTWARE, THE AUTHOR OR COPYRIGHT HOLDER SHALL NOT BE LIABLE, AS THE USE OF THE SOFTWARE IS NOT COMPELLED AT ALL, SO THE RISK IS YOUR OWN.
