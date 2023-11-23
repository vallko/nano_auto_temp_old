#ifndef DHT_FUNCTIONS_H
#define DHT_FUNCTIONS_H

#include <DHT.h>
#include <LiquidCrystal_I2C.h>
void initializeDHTSensors(DHT& dht1, DHT& dht2, int pin1, int pin2);
void readAndDisplayDHTData(String text,DHT& dht, LiquidCrystal_I2C& lcd, int colOffSet, int rowOffset);

#endif