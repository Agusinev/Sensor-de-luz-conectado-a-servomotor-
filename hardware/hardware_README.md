# Hardware

Esta carpeta contiene el esquemático de conexiones y la lista de componentes del sistema.

## Lista de componentes (BOM)

| Componente | Modelo | Cantidad | Función |
|---|---|---|---|
| Microcontrolador principal | Arduino Uno | 1 | Lee los sensores LDR y calcula el ángulo |
| Módulo WiFi | NodeMCU ESP8266 | 1 | Mueve el servo y expone la API REST por WiFi |
| Servo motor | GS-3630BB | 1 | Rota la plataforma del destilador |
| Sensor de luz | Módulo LDR (4 pines) | 2 | Detectan la intensidad lumínica en ambos lados |
| Resistencia | 1 kΩ | 1 | Divisor de voltaje (R1) |
| Resistencia | 2 kΩ | 1 | Divisor de voltaje (R2) |
| Protoboard | — | 1 | Conexiones sin soldar |
| Cables dupont | Macho-Macho / Macho-Hembra | varios | Conexiones entre componentes |

## Esquema de conexiones

### Sensores LDR

| Pin módulo LDR | Conectar a |
|---|---|
| VCC | 3.3V NodeMCU |
| GND | GND común (protoboard) |
| A0 (LDR 1) | Pin A0 Arduino |
| A0 (LDR 2) | Pin A1 Arduino |
| D0 | No conectar |

### Servo GS-3630BB

| Cable | Conectar a |
|---|---|
| Rojo (VCC) | 5V Arduino |
| Café (GND) | GND común (protoboard) |
| Amarillo (señal) | Pin D1 NodeMCU |

### Divisor de voltaje (TX Arduino → NodeMCU)

El Arduino Uno opera a 5V lógicos y el NodeMCU a 3.3V. Se requiere un divisor de voltaje para proteger el NodeMCU.

```
TX Arduino (pin 1) → R1 (1kΩ) → punto medio → R2 (2kΩ) → GND
                                      │
                                  D7 NodeMCU
```

| Conexión | Desde | Hacia |
|---|---|---|
| R1 pata 1 | Pin TX (pin 1) Arduino | — |
| R1 pata 2 | — | Punto medio |
| R2 pata 1 | Punto medio | — |
| R2 pata 2 | — | GND común |
| Punto medio | — | Pin D7 NodeMCU |

### GND común

Todos los siguientes GND deben ir a la misma fila negativa de la protoboard, con un cable hacia el GND del Arduino:

- GND Arduino
- GND NodeMCU
- GND LDR 1
- GND LDR 2
- GND Servo (cable café)
- Pata 2 de R2

## Notas importantes

- El cable del divisor de voltaje (D7 NodeMCU) debe desconectarse antes de cargar código al NodeMCU para evitar interferencias
- El servo se alimenta desde el 5V del Arduino pero recibe la señal PWM desde el NodeMCU (3.3V), lo cual es compatible con el GS-3630BB
- Ambos microcontroladores se alimentan por USB independientes
