#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(uint8_t pin, uint8_t samples)
: _pin(pin), _samples(samples) {}

void AnalogSensor::begin() {
  // En ESP32 los pines ADC no requieren pinMode para analogRead()
}

int AnalogSensor::readRaw() const {
  return analogRead(_pin);
}

int AnalogSensor::readAverage() const {
  long sum = 0;
  for (uint8_t i = 0; i < _samples; i++) {
    sum += analogRead(_pin);
    delay(2); // pequeña pausa para estabilizar
  }
  return (int)(sum / _samples);
}

float AnalogSensor::toVoltage(int raw) const {
  return (raw * _vref) / 4095.0;
}

void AnalogSensor::printStatus(const String& label) {
  int raw = readAverage();
  float volt = toVoltage(raw);
  Serial.print(label);
  Serial.print(": raw=");
  Serial.print(raw);
  Serial.print(" -> ");
  Serial.print(volt, 3);
  Serial.println(" V");
}
