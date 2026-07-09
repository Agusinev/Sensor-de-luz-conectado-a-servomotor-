# Firmware

Esta carpeta contiene el código fuente para los dos microcontroladores del sistema.

## Archivos

| Archivo | Microcontrolador | Descripción |
|---|---|---|
| `arduino_seguidor.ino` | Arduino Uno | Lee sensores LDR, calcula el ángulo y envía datos por Serial |
| `nodemcu_seguidor.ino` | NodeMCU ESP8266 | Recibe datos por Serial, mueve el servo y expone la API REST |

## Requisitos

### Arduino IDE
- Versión 1.8.x o superior

### Librerías necesarias

| Librería | Placa | Cómo instalar |
|---|---|---|
| `Arduino.h` | Arduino Uno | Incluida por defecto |
| `ESP8266WiFi.h` | NodeMCU | Incluida con el paquete esp8266 |
| `ESP8266WebServer.h` | NodeMCU | Incluida con el paquete esp8266 |
| `SoftwareSerial.h` | NodeMCU | Incluida con el paquete esp8266 |
| `Servo.h` | NodeMCU | Incluida con el paquete esp8266 |

### Soporte para NodeMCU
Agregar esta URL en Archivo → Preferencias → Gestor de URLs adicionales:
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
Luego instalar **esp8266 by ESP8266 Community** desde el Gestor de tarjetas.

## Configuración antes de cargar

En `nodemcu_seguidor.ino`, modificar las siguientes líneas con las credenciales de la red WiFi:

```cpp
const char* SSID     = "TU_RED_WIFI";
const char* PASSWORD = "TU_CONTRASENA";
```

## Orden de carga

1. Desconectar todos los cables entre Arduino y NodeMCU
2. Conectar el **Arduino Uno** al PC y cargar `arduino_seguidor.ino`
3. Conectar el **NodeMCU** al PC y cargar `nodemcu_seguidor.ino`
4. Reconectar todos los cables

> ⚠️ El cable del divisor de voltaje (TX Arduino → D7 NodeMCU) puede interferir con la carga del código. Desconectarlo antes de cargar y reconectarlo después.

## Lógica del firmware

### arduino_seguidor.ino

- Lee los valores analógicos de LDR1 (A0) y LDR2 (A1)
- Calcula la diferencia entre ambos sensores
- Si la diferencia supera el umbral de 30, incrementa o decrementa el ángulo en 2 grados
- Envía los valores de LDR1, LDR2 y ángulo al NodeMCU cada 500ms por Serial

### nodemcu_seguidor.ino

- Recibe los datos del Arduino por SoftwareSerial (pin D7)
- Mueve el servo GS-3630BB al ángulo recibido (pin D1)
- Expone el endpoint `GET /estado` con los datos en formato JSON
- Imprime la IP asignada por el router en el monitor serie al iniciar
