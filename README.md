# Sensor-de-luz-conectado-a-servomotor-
Nuestro sistema busca poder utilizar sensores de luz para permitir que el servomotor gire en direccion donde hay mas luz, esto luego puediendo ser aplicado a por ejemplo, sistemas que requieran luz directa.
## Equipo
| Integrante | Rol | GitHub |

| - - - - - - - - - - - - -| - - - - - - - - - - - - - - - - - - -| - - - - - - - - - - - -|

| --Agustin Bratti --- | ---------Diseño 3D----------| --- @Agusinev --- |


| -Franco Lombardi- | ------Software / Firmware------|@francolombardi-123 | 

## Descripcion del Problema
El principal problema es la ineficiencia hasta cierto punto, dado que la recoleccion de luz solar no es suficiente estando inmovil, por ende, buscando una solucion que permita al sistema rotar entorno a mirar a una fuente de luz, en este caso el sol
## Arquitectura del Sistema (EJEMPLO CAMBIAR)
Sensor pwr led 4 pin fotosensible -> ESP32 -> Firebase -> Dashboard Node - RED -> Servomotor gs360
## Instrucciones de Uso 
Mediante sensores de luz, subir codigo a arduino, al detectar mayores niveles de luz el servomotor girara.
### Cargar el firmware
1. Desconectar todos los cables entre Arduino y NodeMCU
2. Conectar el **Arduino Uno** al PC y cargar `arduino_seguidor.ino`
3. Conectar el **NodeMCU** al PC y cargar `nodemcu_seguidor.ino`
4. Reconectar todos los cables
## Estructura del Repositorio
- ‘ firmware / ‘ -- Codigo fuente Arduino
- ‘ hardware / ‘ -- Esquematicos y BOM
- ‘ diseno -3 d / ‘ -- Archivos Fusion 360 y planos
- ‘ testing / ‘ -- Protocolos y evidencias
- ‘ docs / ‘ -- Reporte final
