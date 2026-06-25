#include <Arduino.h>

const int PIN_LDR1  = A0;
const int PIN_LDR2  = A1;

const int UMBRAL  = 30;
const int PASO    = 2;
const int MIN_ANG = 0;
const int MAX_ANG = 180;

int angulo = 90;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ldr1 = analogRead(PIN_LDR1);
  int ldr2 = analogRead(PIN_LDR2);

  // logica automatica
  int diferencia = ldr1 - ldr2;
  if (diferencia > UMBRAL && angulo > MIN_ANG) {
    angulo -= PASO;
  } else if (diferencia < -UMBRAL && angulo < MAX_ANG) {
    angulo += PASO;
  }

  // enviar datos al NodeMCU cada 500ms
  static unsigned long ultimoEnvio = 0;
  if (millis() - ultimoEnvio > 500) {
    String mensaje = "LDR1:" + String(ldr1) + ",LDR2:" + String(ldr2) + ",ANG:" + String(angulo);
    Serial.println(mensaje);
    ultimoEnvio = millis();
  }

  delay(50);
}
