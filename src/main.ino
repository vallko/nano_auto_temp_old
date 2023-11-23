#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include "DHTFunctions.h"
#include <nonBlockDelay.h>
#include "HCSR04Functions.h"

int lcdAddress = 0x27;
int lcdColumns = 20;
int lcdRows = 4;
String text = "";

LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

const int trigPin1 = 4; // Trig pin of the first HC-SR04
const int echoPin1 = 5; // Echo pin of the first HC-SR04

const int trigPin2 = 6; // Trig pin of the second HC-SR04
const int echoPin2 = 7; // Echo pin of the second HC-SR04

HCSR04Functions hcsr04_1(trigPin1, echoPin1);
HCSR04Functions hcsr04_2(trigPin2, echoPin2);

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
  float temperature1 = dht1.readTemperature();
  float humidity1 = dht1.readHumidity();
  float temperature2 = dht2.readTemperature();
  float humidity2 = dht2.readHumidity();
  int distance1 = hcsr04_1.getDistance();
  int distance2 = hcsr04_2.getDistance();
  nonBlockingDelay();
  lcd.setCursor(6, 0);
  lcd.print("F:");
  if (distance1 < 5)
  {
    lcd.print("XXX");
  }
  else
  {
    lcd.print(distance1);
  }
  delay(100);
  lcd.print("   ");
  lcd.setCursor(6, 3);
  lcd.print("B:");
  if (distance2 < 5)
  {
    lcd.print("XXX");
  }
  else
  {
    lcd.print(distance2);
  }
  delay(100);
  lcd.print("   ");
  readAndDisplayDHTData(text = "In", dht1, lcd, 0, 0);
  readAndDisplayDHTData(text = "Out", dht2, lcd, 13, 0);
}
