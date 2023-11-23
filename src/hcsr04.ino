#include "HCSR04Functions.h"
#include <nonBlockDelay.h>

HCSR04Functions::HCSR04Functions(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float HCSR04Functions::getDistance() {
  // Trigger the HC-SR04 to send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time taken for the pulse to return
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  int distance = duration  / 58;
  
  return distance;
}

