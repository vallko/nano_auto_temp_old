#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include "DHTFunctions.h"
#include <nonBlockDelay.h>

int lcdAddress = 0x27;
int lcdColumns = 20;
int lcdRows = 4;
String text = "";

LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

#define DHTPIN_1 2    // Digital pin for the first DHT11 sensor
#define DHTPIN_2 3    // Digital pin for the second DHT11 sensor
#define DHTTYPE DHT11 // DHT11 sensor typ
DHT dht1(DHTPIN_1, DHTTYPE);
DHT dht2(DHTPIN_2, DHTTYPE);

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
  lcd.clear();
  initializeDHTSensors(dht1, dht2, DHTPIN_1, DHTPIN_2);
}

void loop()
{
  // Read temperature and humidity from the first DHT sensor
  float temperature1 = dht1.readTemperature();
  float humidity1 = dht1.readHumidity();

  // Read temperature and humidity from the second DHT sensor
  float temperature2 = dht2.readTemperature();
  float humidity2 = dht2.readHumidity();

  // Check if readings are valid
  if (!isnan(temperature1) && !isnan(humidity1) && !isnan(temperature2) && !isnan(humidity2))
  {
    readAndDisplayDHTData(text="In",dht1, lcd, 0, 0);
    readAndDisplayDHTData(text="Out",dht2, lcd, 13, 0);
    nonBlockingDelay();
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error reading");
    lcd.setCursor(0, 1);
    lcd.print("DHT sensor");
    nonBlockingDelay();
  }
}
