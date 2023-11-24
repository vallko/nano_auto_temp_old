// main_menu.cpp
#include "MainMenu.h"

MainMenu::MainMenu(int analogPin) {
  _analogPin = analogPin;
    pinMode(_analogPin, INPUT_PULLUP); // Enable internal pull-up resistor

}

void MainMenu::displayMenu() {
  // Read the analog value from the keypad
  _buttonValue = analogRead(_analogPin);

  // Determine which button is pressed based on the analog value
  int option = getOption(_buttonValue);

  // Print the menu option to Serial Monitor
  Serial.print("Selected Option: ");
  Serial.println(option);
}

int MainMenu::getOption(int value) {
  // Map the analog values to corresponding options
  if (value < 100) {
    return 1;
  } else if (value < 300) {
    return 2;
  } else if (value < 500) {
    return 3;
  } else if (value < 700) {
    return 4;
  } else if (value < 1000){
    return 5;
  }else{
    return 6;
  }
}

int MainMenu::getMenuOption() {
  // Return the menu option
  return getOption(_buttonValue);
}
