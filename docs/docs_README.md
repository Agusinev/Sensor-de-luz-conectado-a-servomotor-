# Documentación del Proyecto

Esta carpeta contiene los informes y documentación generada durante el desarrollo del destilador solar automático.

## Contenido

| Archivo | Descripción |
|---|---|
| `informe-final.pdf` | Informe completo del proyecto con introducción, desarrollo y conclusiones |
| `presentacion.pptx` | Presentación del proyecto para exposición |

## Descripción del sistema

El sistema consiste en un destilador solar con seguimiento automático de la luz. Utiliza dos sensores LDR para detectar la posición del sol y un servo motor para rotar la plataforma del destilador hacia la fuente de mayor intensidad lumínica.

### Arquitectura

```
LDR 1 (A0) ──┐
              ├── Arduino Uno ── Serial TX ── Divisor de voltaje ── NodeMCU ESP8266 ── API REST (WiFi)
LDR 2 (A1) ──┘        │
                    Servo GS-3630BB (D1 NodeMCU)
```

### Flujo de datos

1. Los sensores LDR leen la intensidad de luz en ambos lados de la plataforma
2. El Arduino Uno calcula la diferencia y determina el ángulo del servo
3. El dato es enviado por Serial al NodeMCU ESP8266
4. El NodeMCU mueve el servo y expone los datos en tiempo real mediante una API REST accesible por IP WiFi local

## Instrucciones para cargar el firmware

1. Abrir Arduino IDE
2. Instalar el paquete **esp8266 by ESP8266 Community** desde el Gestor de tarjetas
3. Seleccionar la placa correspondiente:
   - Para el Arduino: `Arduino Uno`
   - Para el NodeMCU: `NodeMCU 1.0 (ESP-12E Module)`
4. Configurar las credenciales WiFi en `nodemcu_seguidor.ino`
5. Cargar `arduino_seguidor.ino` en el Arduino Uno
6. Cargar `nodemcu_seguidor.ino` en el NodeMCU

## Uso de la API

Una vez encendido el sistema, el NodeMCU imprime su IP en el monitor serie (9600 baudios). Con esa IP se puede acceder al endpoint:

```
GET http://[IP]/estado
```

Respuesta de ejemplo:
```json
{
  "ldr1": 512,
  "ldr2": 480,
  "angulo": 94
}
```
