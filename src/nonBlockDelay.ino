#include <Arduino.h>

unsigned long previousMillis = 0;
const long interval = 2000; // Set the interval in milliseconds


void nonBlockingDelay() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Code to execute after the specified interval

    // Reset the timer
    previousMillis = currentMillis;
  }
}