# Sensor-de-luz-conectado-a-servomotor-
Nuestro sistema busca poder utilizar sensores de luz para permitir que el servomotor gire en direccion donde hay mas luz, esto luego puediendo ser aplicado a por ejemplo, sistemas que requieran luz directa.
## Equipo
| Integrante | Rol | GitHub |
| - - - - - - - - - - - - -| - - - - - - - - - - - - - - - - - - -| - - - - - - - - - - - -|
| Agustin Bratti | Diseño 3D | @Agusinev |
| Joaquin Nilo | Hardware |  |
| Franco Lombardi | Software / Firmware | |
## Descripcion del Problema
El principal problema es la ineficiencia hasta cierto punto de que la recoleccion de luz solar no fuera suficiente estando inmovil, por ende, mejorando el sistema para permitir una rotacion que ademas complemente la funcion de estar apuntando al sol.
## Arquitectura del Sistema
Sensor PM2 .5 -> ESP32 -> Firebase -> Dashboard Node - RED (EJEMPLO, CAMBIAR)
## Instrucciones de Uso (EJEMPLO CAMBIAR)
### Cargar el firmware
1. Abre ‘ firmware / main . ino ‘ en Arduino IDE
2. Instala las librerias listadas en ‘ FUENTES . md ‘
3. Configura las credenciales WiFi en ‘ config .h ‘
4. Conecta el ESP32 y sube el codigo
### Ver el dashboard
- URL : https :// mi - dashboard . com
## Estructura del Repositorio
- ‘ firmware / ‘ -- Codigo fuente Arduino
- ‘ hardware / ‘ -- Esquematicos y BOM
- ‘ diseno -3 d / ‘ -- Archivos Fusion 360 y planos
- ‘ testing / ‘ -- Protocolos y evidencias
- ‘ docs / ‘ -- Reporte final
