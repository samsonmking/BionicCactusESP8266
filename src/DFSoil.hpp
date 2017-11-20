#ifndef DFSOIL_H
#define DFSOIL_H

#include <SoilSensor.hpp>
#include <Arduino.h>
#include <RunningMedian.h>

class DFSoil : public SoilSensor {
public:
  DFSoil(int pin, int high = 419, int low = 715);
  void loop();
  int getPercent();
  void setHigh(int high) {
    _high = high;
    calculateConstants();
  };
  void setLow(int low) {
    _low = low;
    calculateConstants();
  };
  int readRaw();
  virtual int readPercent();
  int calculatePercent(int raw);
private:
  RunningMedian _samples;
  void calculateConstants();
  int _pin;
  int _high;
  int _low;
  float _m;
  float _b;
};

#endif
