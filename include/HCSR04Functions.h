#ifndef HCSR04_FUNCTIONS_H
#define HCSR04_FUNCTIONS_H

#include <Arduino.h>
class HCSR04Functions {
public:
  HCSR04Functions(int trigPin, int echoPin);
  float getDistance();

private:
  int trigPin;
  int echoPin;
};

#endif
