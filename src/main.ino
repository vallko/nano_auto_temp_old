#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

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
  dht1.begin(); // Start the first DHT sensor
  dht2.begin(); // Start the second DHT sensor
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
    // Print temperature and humidity on the LCD
    lcd.clear();
    // In The Car
    lcd.setCursor(0, 0);
    lcd.print("In");
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(temperature1, 1);
    lcd.print("C");
    lcd.setCursor(0, 2);
    lcd.print("H:");
    lcd.print(humidity1, 1);
    lcd.print("%");
    // out the car
    lcd.setCursor(12, 0);
    lcd.print("Out");
    lcd.setCursor(12, 1);
    lcd.print("T:");
    lcd.print(temperature2, 1);
    lcd.print("C");
    lcd.setCursor(12, 2);
    lcd.print("H:");
    lcd.print(humidity2, 1);
    lcd.print("%");
    // Delay before the next iteration
    delay(2000);
    if ((temperature1 > 25) || (temperature2 > 25))
    {
      lcd.setCursor(2, 3);
      lcd.print("High Temperature");
       delay(3000);
    }
        if ((temperature1) <= 2 || (temperature2 <= 2))
    {
      lcd.setCursor(2, 3);
      lcd.print("Low Temperature!");
       delay(3000);
    }
  }
  else
  {
    // If readings are invalid, print an error message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error reading");
    lcd.setCursor(0, 1);
    lcd.print("DHT sensor");

    // Delay before the next iteration
    delay(2000);
  }
}
