# Fuentes del Proyecto
## Librerias utilizadas

Arduino (arduino_seguidor.ino)
Librería
Arduino.h Base del Arduino, incluida automáticamente
NodeMCU (nodemcu_seguidor.ino)
Librería 
ESP8266WiFi.h Conectar el NodeMCU a la red WiFi
ESP8266WebServer.h Crear el servidor HTTP para la API 
RESTSoftwareSerial.h Leer los datos del Arduino por el pin D7
Servo.h Controlar el servo GS-3630BB desde el pin D1


### reconexion WiFi ( main . ino , lineas 45 -62)
- Fuente : randomnerdtutorials . com
- Adaptacion : espera 500 ms -> 2000 ms ;
reintentos maximos (5) .
## Uso de Inteligencia Artificial
- Herramienta : Grok (Mayo 2026), Claude (Junio 2026)
- Prompt : Ayudame a crear un seguidor del sol movil con un servomotor y 2 sensores LDR
- Adaptacion : Ayudas de conexion de cables, fallas en la API.
- Comprension : Recoger nivel de luz solar y devolver rotacion en grados para el servomotor
