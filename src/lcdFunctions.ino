#include <Arduino.h>
#include "lcdFunctions.h"

void clearLcdEvery(LiquidCrystal_I2C &lcd, int seconds)
{
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();

    // Check if one second has passed
    if (currentMillis - previousMillis >= seconds)
    {
        // Reset the timer
        previousMillis = currentMillis;
        // Your code here (this will be executed once every second)
        static int counter = 0;
        counter++;

        // Clear the LCD
        lcd.clear();

        // for (int row = 0; row < 3; row++)
        // {
        //         lcd.setCursor(0, row);
        //         lcd.print("                   ");
        //     /* code */
        // }

        // Print the counter value to the LCD
        // lcd.setCursor(1, 1);
        // lcd.print("Counter: ");
        // lcd.print(counter);
    }
}
