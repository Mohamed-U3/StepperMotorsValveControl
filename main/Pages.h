#ifndef PAGES_H
#define PAGES_H

/*
 * ***********************************************************
               Includes
 * ***********************************************************
*/
#include "Config.h"
#include "Global.h"
#include "Buttons.h"

/*
 * ***********************************************************
             variables
 * ***********************************************************
*/
unsigned char current_page      = 1;
unsigned char current_line      = 1;
bool          button_last_state = 0;
bool          increaseVal       = 0;
bool          decreaseVal       = 0;

/*
* ***********************************************************
              Defines
* ***********************************************************
*/
#define PRESSURE_SENSOR_READING1    global_pressure_reading1      //The readings of the sensor is written in this global variable.
#define PRESSURE_SENSOR_READING2    global_pressure_reading2      //The readings of the sensor is written in this global variable.
#define PRESSURE_MIN_VOLT1          global_pressure_min_volt1     //voltage when the reading is 0 PSI
#define PRESSURE_MAX_VOLT1          global_pressure_max_volt1     //voltage when the reading is maximum PSI
#define PRESSURE_MIN_VOLT2          global_pressure_min_volt2     //voltage when the reading is 0 PSI
#define PRESSURE_MAX_VOLT2          global_pressure_max_volt2     //voltage when the reading is maximum PSI
#define MAX_PRESSURE_VALUE1         global_max_pressure_value1    //the value of the maximum pressure that sensor can read
#define MAX_PRESSURE_VALUE2         global_max_pressure_value2    //the value of the maximum pressure that sensor can read
/*
 * ***********************************************************
               Functions body
 * ***********************************************************
*/

void page1()
{
  display.clearDisplay();
  display.setTextSize(1);               // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print((current_line == 1) ? F("<   > ") : F("<     "));  display.print(F("Settings      >")); display.println();
  display.print((current_line == 2) ? F(">") : F(" ")); display.print(F("PrsrMinVolt: "));  display.println(PRESSURE_MIN_VOLT1);
  display.print((current_line == 3) ? F(">") : F(" ")); display.print(F("Line3: "));  display.println(current_line);
  display.print((current_line == 4) ? F(">") : F(" ")); display.print(F("Line4: "));  display.println(current_line);
  display.print((current_line == 5) ? F(">") : F(" ")); display.print(F("Line5: "));  display.println(current_line);
  display.print((current_line == 6) ? F(">") : F(" ")); display.print(F("Line6: "));  display.println(current_line);
  display.print((current_line == 7) ? F(">") : F(" ")); display.print(F("Line7: "));  display.println(current_line);
  display.print((current_line == 8) ? F(">") : F(" ")); display.print(F("Line8: "));  display.println(current_line);

  display.display();                    // Show initial text

  switch (current_line)
  {
    case 1: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 2: if (increaseVal == 1){ PRESSURE_MIN_VOLT1 = PRESSURE_MIN_VOLT1 + 0.1; increaseVal = 0;}
            if (decreaseVal == 1){ PRESSURE_MIN_VOLT1 = PRESSURE_MIN_VOLT1 - 0.1; decreaseVal = 0;}   break;
    case 3: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 4: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 5: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 6: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 7: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 8: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    default: ;
  }
}

void page2()
{
  display.clearDisplay();
  display.setTextSize(1);               // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print((current_line == 1) ? F("<   > ") : F("<     "));  display.print(F("Page2         >")); display.println();
  display.print((current_line == 2) ? F(">") : F(" ")); display.print(F("Line2: "));  display.println(current_line);
  display.print((current_line == 3) ? F(">") : F(" ")); display.print(F("Line3: "));  display.println(current_line);
  display.print((current_line == 4) ? F(">") : F(" ")); display.print(F("Line4: "));  display.println(current_line);
  display.print((current_line == 5) ? F(">") : F(" ")); display.print(F("Line5: "));  display.println(current_line);
  display.print((current_line == 6) ? F(">") : F(" ")); display.print(F("Line6: "));  display.println(current_line);
  display.print((current_line == 7) ? F(">") : F(" ")); display.print(F("Line7: "));  display.println(current_line);
  display.print((current_line == 8) ? F(">") : F(" ")); display.print(F("Line8: "));  display.println(current_line);

  display.display();                    // Show initial text

  switch (current_line)
  {
    case 1: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 2: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 3: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 4: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 5: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 6: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 7: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 8: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    default: ;
  }
}

void page3()
{
  display.clearDisplay();
  display.setTextSize(1);               // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print((current_line == 1) ? F("<   > ") : F("<     "));  display.print(F("Page3         >")); display.println();
  display.print((current_line == 2) ? F(">") : F(" ")); display.print(F("Line2: "));  display.println(current_line);
  display.print((current_line == 3) ? F(">") : F(" ")); display.print(F("Line3: "));  display.println(current_line);
  display.print((current_line == 4) ? F(">") : F(" ")); display.print(F("Line4: "));  display.println(current_line);
  display.print((current_line == 5) ? F(">") : F(" ")); display.print(F("Line5: "));  display.println(current_line);
  display.print((current_line == 6) ? F(">") : F(" ")); display.print(F("Line6: "));  display.println(current_line);
  display.print((current_line == 7) ? F(">") : F(" ")); display.print(F("Line7: "));  display.println(current_line);
  display.print((current_line == 8) ? F(">") : F(" ")); display.print(F("Line8: "));  display.println(current_line);

  display.display();                    // Show initial text

  switch (current_line)
  {
    case 1: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 2: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 3: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 4: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 5: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 6: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 7: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 8: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    default: ;
  }
}

void mainpage()
{
  display.clearDisplay();
  display.setTextSize(1);               // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print((current_line == 1) ? F("|   > ") : F("|     "));  display.print(F("main page     >")); display.println();
  display.print((current_line == 2) ? F(">") : F(" ")); display.print(F("Line2: "));  display.println(current_line);
  display.print((current_line == 3) ? F(">") : F(" ")); display.print(F("Line3: "));  display.println(current_line);
  display.print((current_line == 4) ? F(">") : F(" ")); display.print(F("Line4: "));  display.println(current_line);
  display.print((current_line == 5) ? F(">") : F(" ")); display.print(F("Line5: "));  display.println(current_line);
  display.print((current_line == 6) ? F(">") : F(" ")); display.print(F("Line6: "));  display.println(current_line);
  display.print((current_line == 7) ? F(">") : F(" ")); display.print(F("Line7: "));  display.println(current_line);
  display.print((current_line == 8) ? F(">") : F(" ")); display.print(F("Line8: "));  display.println(current_line);

  display.display();                    // Show initial text

  switch (current_line)
  {
    case 1: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 2: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 3: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 4: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 5: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 6: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 7: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 8: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    default: ;
  }
}

void loopPages()
{
  switch (pressedButton())
  {
    case DOWN_BUTTON_PIN:   if (button_last_state == 0){  current_line = (current_line + 1 > 8) ? 1 : current_line + 1; button_last_state = 1;  } break;
    case UP_BUTTON_PIN:     if (button_last_state == 0){  current_line = (current_line - 1 < 1) ? 8 : current_line - 1; button_last_state = 1;  } break;
    case RIGHT_BUTTON_PIN:  if (button_last_state == 0){  increaseVal  = 1;                                             button_last_state = 1;  } break;
    case LEFT_BUTTON_PIN:   if (button_last_state == 0){  decreaseVal  = 1;                                             button_last_state = 1;  } break;
    default:  button_last_state = 0;
  }

  switch (current_page)
  {
    case 1: page1();  break;
    case 2: page2();  break;
    case 3: page3();  break;
    default: mainpage();
  }

  if(current_page < 0 || current_page > 4)
  {
    current_page = 1;
  }
}

#endif  //PAGES_H
