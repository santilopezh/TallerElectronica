#ifndef ANALOGSENSOR_H
#define ANALOGSENSOR_H

#include <Arduino.h>

//Comentario para mostrar el commit

//Santiago Lopez Hernandez

class AnalogSensor {
public:
  explicit AnalogSensor(uint8_t pin, uint8_t samples = 10);
  void begin();                   // inicialización (si la necesitas)
  int  readRaw() const;           // lectura cruda 0..4095
  
  float toVoltage(int raw) const; // convierte a voltaje (0..3.3V aprox)
  void printStatus(const String& label); // sin retorno, con argumento

private:
  uint8_t _pin;
  uint8_t _samples;
  const float _vref = 3.3;        // referencia típica del ESP32
};

#endif
