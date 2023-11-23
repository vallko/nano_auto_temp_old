#include "DHTFunctions.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <nonBlockDelay.h>

void initializeDHTSensors(DHT &dht1, DHT &dht2, int pin1, int pin2)
{
    dht1.begin(); // Start the first DHT sensor
    dht2.begin(); // Start the second DHT sensor
}

void readAndDisplayDHTData(String text, DHT &dht, LiquidCrystal_I2C &lcd, int colOffSet, int rowOffset)
{
    // Read temperature and humidity from the DHT sensor
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Check if readings are valid
    if (!isnan(temperature) && !isnan(humidity))
    {
        lcd.setCursor(colOffSet, rowOffset);
        lcd.print(text);
        lcd.setCursor(colOffSet, rowOffset + 1);
        lcd.print("T:");
        lcd.print(temperature, 1);
        lcd.print("C");
        lcd.setCursor(colOffSet, rowOffset + 2);
        lcd.print("H:");
        lcd.print(humidity, 1);
        lcd.print("%");
        lcd.setCursor(colOffSet = 2, rowOffset + 3);
        lcd.print("                ");

        if ((temperature > 40))
        {
            lcd.setCursor(colOffSet = 2, rowOffset + 3);
            lcd.print("High Temperature");
            nonBlockingDelay();
        }
        if (temperature <= 0)
        {
            lcd.setCursor(colOffSet = 2, rowOffset + 1);
            lcd.print("Low Temperature!");
            nonBlockingDelay();
        }
    }
    else
    {
        // If readings are invalid, print an error message on the LCD
        lcd.setCursor(0, rowOffset);
        lcd.print("Error reading DHT");
    }
}
