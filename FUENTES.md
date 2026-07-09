# Fuentes del Proyecto

## Librerías utilizadas

| Librería | Versión | Fuente |
|---|---|---|
| `Arduino.h` | Incluida en Arduino IDE | Arduino Core |
| `ESP8266WiFi.h` | Incluida en ESP8266 Core | esp8266 by ESP8266 Community |
| `ESP8266WebServer.h` | Incluida en ESP8266 Core | esp8266 by ESP8266 Community |
| `SoftwareSerial.h` | Incluida en ESP8266 Core | esp8266 by ESP8266 Community |
| `Servo.h` | Incluida en ESP8266 Core | esp8266 by ESP8266 Community |

## Datasheets y referencias de componentes

| Componente | Referencia |
|---|---|
| NodeMCU ESP8266 | https://www.espressif.com/sites/default/files/documentation/esp8266-technical_reference_en.pdf |
| Arduino Uno | https://docs.arduino.cc/hardware/uno-rev3 |
| Servo GS-3630BB | Datasheet del fabricante Guang Sheng Servo |
| Módulo LDR 4 pines | Referencia genérica de módulo fotoresistivo con comparador LM393 |

## Código externo adaptado

No se utilizó código externo copiado directamente. El firmware fue desarrollado específicamente para este proyecto.

## Uso de Inteligencia Artificial

Durante el desarrollo del proyecto se utilizó **Claude (Anthropic)** como herramienta de apoyo para el diseño del sistema, la resolución de problemas de hardware y la implementación del firmware.

### Desarrollo del firmware

- **Herramienta:** Claude by Anthropic (claude.ai)
- **Uso:** apoyo en el diseño de la arquitectura de comunicación Serial entre Arduino y NodeMCU, implementación de la API REST en el ESP8266, resolución de conflictos entre librerías (Servo y SoftwareSerial), y depuración de problemas de niveles de voltaje en la comunicación Serial.
- **Adaptación:** todas las propuestas generadas fueron revisadas, probadas físicamente y modificadas por el equipo para adaptarlas a los componentes disponibles. Se realizaron múltiples iteraciones hasta lograr el funcionamiento correcto del sistema completo.
- **Validación:** el funcionamiento del firmware fue comprobado mediante pruebas experimentales con los sensores LDR, el servo motor y la API REST, verificando que el sistema respondiera correctamente a cambios de luz antes de darlo por finalizado.
- **Comprensión:** ambos integrantes revisaron el código final, comprenden la función de sus principales módulos y son capaces de explicar su funcionamiento durante la presentación del proyecto.

### Diseño del divisor de voltaje

Se utilizó Claude para calcular los valores de resistencias necesarios para reducir los 5V lógicos del Arduino a los 3.3V tolerados por el NodeMCU, usando la fórmula del divisor de voltaje resistivo.
