// main_menu.h
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <Arduino.h>

class MainMenu {
public:
  MainMenu(int analogPin);
  void displayMenu();
  int getMenuOption();

private:
  int _analogPin;
  int _buttonValue;

  int getOption(int value);
};

#endif
