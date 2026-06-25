#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
#include <Servo.h>

// ── configuracion WiFi ──────────────────────────────
const char* SSID     = "iPhone de Franco";
const char* PASSWORD = "lomrob99";

// ── SoftwareSerial: D7 = RX ─────────────────────────
SoftwareSerial serialArduino(D7, D6); // D6 TX no conectado

Servo servo;
const int PIN_SERVO = D1;

ESP8266WebServer server(80);

// ── estado global ───────────────────────────────────
int ldr1   = 0;
int ldr2   = 0;
int angulo = 90;

// ── lectura de datos del Arduino ────────────────────
void leerArduino() {
  static String buffer = "";
  while (serialArduino.available()) {
    char c = serialArduino.read();
    if (c == '\n') {
      int i1 = buffer.indexOf("LDR1:");
      int i2 = buffer.indexOf(",LDR2:");
      int i3 = buffer.indexOf(",ANG:");
      if (i1 >= 0 && i2 > 0 && i3 > 0) {
        ldr1   = buffer.substring(i1 + 5, i2).toInt();
        ldr2   = buffer.substring(i2 + 6, i3).toInt();
        angulo = buffer.substring(i3 + 5).toInt();
        servo.write(angulo);
      }
      buffer = "";
    } else {
      buffer += c;
    }
  }
}

// ── endpoint /estado ────────────────────────────────
void handleEstado() {
  String json = "{";
  json += "\"ldr1\":"   + String(ldr1)   + ",";
  json += "\"ldr2\":"   + String(ldr2)   + ",";
  json += "\"angulo\":" + String(angulo);
  json += "}";
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}

// ── setup ───────────────────────────────────────────
void setup() {
  Serial.begin(9600);
  serialArduino.begin(9600);
  servo.attach(PIN_SERVO);
  servo.write(90);

  WiFi.begin(SSID, PASSWORD);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/estado", HTTP_GET, handleEstado);
  server.begin();
}

// ── loop ────────────────────────────────────────────
void loop() {
  server.handleClient();
  leerArduino();
}
