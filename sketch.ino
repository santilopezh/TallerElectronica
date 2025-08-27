#include "AnalogSensor.h"

const uint8_t SENSOR_PIN = 34;  // ADC1 (ideal para potenciómetro en Wokwi)
const uint8_t LED_PIN    = 2;   // LED integrado en muchos ESP32

AnalogSensor sensor(SENSOR_PIN, 16);

// --- funciones “libres” para demostrar con/sin retorno y con/sin argumentos ---
void printHello() {                           // sin argumentos, sin retorno
  Serial.println("Iniciando lectura del sensor...");
}
int sum(int a, int b) { return a + b; }       // con argumentos, con retorno

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  sensor.begin();
  printHello();
}

void loop() {
  sensor.printStatus("Potenciometro");        // sin retorno, con argumento

  int raw = sensor.readRaw();                 // con retorno
  digitalWrite(LED_PIN, (raw > 2000) ? HIGH : LOW);

  int s = sum(3, 4);                          // ejemplo de función con retorno
  Serial.print("Suma de ejemplo: ");
  Serial.println(s);

  delay(1000);
}
