/**
 * ***********************************************************
 * @file  : Pages.h
 * @brief : Functionality of the Pages Displayed on the OLED
 * @author: Eng. Mohamed Yousry
 * @date  : 22/12/2024
 * ***********************************************************
 */
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
#include "Oled.h"
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
#define PRESSURE_SENSOR_READING1        global_pressure_reading1          //The readings of the sensor is written in this global variable.
#define PRESSURE_SENSOR_READING2        global_pressure_reading2          //The readings of the sensor is written in this global variable.
#define PRESSURE_MIN_VOLT1              global_pressure_min_volt1         //voltage when the reading is 0 PSI
#define PRESSURE_MAX_VOLT1              global_pressure_max_volt1         //voltage when the reading is maximum PSI
#define PRESSURE_MIN_VOLT2              global_pressure_min_volt2         //voltage when the reading is 0 PSI
#define PRESSURE_MAX_VOLT2              global_pressure_max_volt2         //voltage when the reading is maximum PSI
#define MAX_PRESSURE_VALUE1             global_max_pressure_value1        //the value of the maximum pressure that sensor can read
#define MAX_PRESSURE_VALUE2             global_max_pressure_value2        //the value of the maximum pressure that sensor can read

#define TEMPERATURE_SENSOR_READING1     global_temperature_reading1       //The readings of the sensor is written in this global variable.
#define TEMPERATURE_SENSOR_READING2     global_temperature_reading2       //The readings of the sensor is written in this global variable.

//Configurations
#define MAX_PAGES     4
#define MAX_LINES     7

/*
 * ***********************************************************
               Functions body
 * ***********************************************************
*/
void page1() /////////////////////////////////////////////////////////////////////////////***************** Page 1 Start ****************************///////////////
{
  u8g2.firstPage();
  do {
    // Clear the page
    u8g2.setDrawColor(1); // Background color white
    u8g2.drawBox(0, 0, 128, 10); // Clear the display area
    
    u8g2.setDrawColor(0); // Text color black
    u8g2.setFont(u8g2_font_courR08_tf); // Set a suitable font
//    u8g2.setFont(u8g2_font_6x10_tr); // Set a suitable font
    
    // Display the menu options
    u8g2.setCursor(0,  8); u8g2.print((current_line == 1) ? F("<   > ") : F("<     ")); u8g2.print(F("Settings      >"));
    u8g2.setDrawColor( 1); // Text color white
    u8g2.setCursor(0, 18); u8g2.print((current_line == 2) ? F(">") : F(" ")); u8g2.print(F("PrsrMinVolt1: ")); u8g2.print(PRESSURE_MIN_VOLT1);
    u8g2.setCursor(0, 26); u8g2.print((current_line == 3) ? F(">") : F(" ")); u8g2.print(F("PrsrMaxVolt1: ")); u8g2.print(PRESSURE_MAX_VOLT1);
    u8g2.setCursor(0, 34); u8g2.print((current_line == 4) ? F(">") : F(" ")); u8g2.print(F("PrsrMinVolt2: ")); u8g2.print(PRESSURE_MIN_VOLT2);
    u8g2.setCursor(0, 42); u8g2.print((current_line == 5) ? F(">") : F(" ")); u8g2.print(F("PrsrMaxVolt2: ")); u8g2.print(PRESSURE_MAX_VOLT2);
    u8g2.setCursor(0, 50); u8g2.print((current_line == 6) ? F(">") : F(" ")); u8g2.print(F("MaxPressVal1: ")); u8g2.print(MAX_PRESSURE_VALUE1);
    u8g2.setCursor(0, 58); u8g2.print((current_line == 7) ? F(">") : F(" ")); u8g2.print(F("MaxPressVal2: ")); u8g2.print(MAX_PRESSURE_VALUE2);
  } while (u8g2.nextPage());

  // Handle interactions
  switch (current_line)
  {
    case 1:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 2:
      if (increaseVal == 1) { PRESSURE_MIN_VOLT1 += 0.1; increaseVal = 0; }
      if (decreaseVal == 1) { PRESSURE_MIN_VOLT1 -= 0.1; decreaseVal = 0; }
      break;
    case 3:
      if (increaseVal == 1) { PRESSURE_MAX_VOLT1 += 0.1; increaseVal = 0; }
      if (decreaseVal == 1) { PRESSURE_MAX_VOLT1 -= 0.1; decreaseVal = 0; }
      break;
    case 4:
      if (increaseVal == 1) { PRESSURE_MIN_VOLT2 += 0.1; increaseVal = 0; }
      if (decreaseVal == 1) { PRESSURE_MIN_VOLT2 -= 0.1; decreaseVal = 0; }
      break;
    case 5:
      if (increaseVal == 1) { PRESSURE_MAX_VOLT2 += 0.1; increaseVal = 0; }
      if (decreaseVal == 1) { PRESSURE_MAX_VOLT2 -= 0.1; decreaseVal = 0; }
      break;
    case 6:
      if (increaseVal == 1) { MAX_PRESSURE_VALUE1 += 1; increaseVal = 0; }
      if (decreaseVal == 1) { MAX_PRESSURE_VALUE1 -= 1; decreaseVal = 0; }
      break;
    case 7:
      if (increaseVal == 1) { MAX_PRESSURE_VALUE2 += 1; increaseVal = 0; }
      if (decreaseVal == 1) { MAX_PRESSURE_VALUE2 -= 1; decreaseVal = 0; }
      break;
    default:
      break;
  }
}  /////////////////////////////////////////////////////////////////////////////***************** Page 1 END ****************************///////////////

void page2()/////////////////////////////////////////////////////////////////////////////***************** Page 2 Start ****************************///////////////
{
  u8g2.firstPage();
  do {
    // Clear the page
    u8g2.setDrawColor(1);               // Background color white
    u8g2.drawBox(0, 0, 128, 10);        // Drawing white Box
    
    u8g2.setDrawColor(0);               // Text color black
    u8g2.setFont(u8g2_font_courR08_tf); // Set a suitable font
    
    // Display the menu options
    u8g2.setCursor(0,  8); u8g2.print((current_line == 1) ? F("<   > ") : F("<     ")); u8g2.print(F("Page2         >"));

    u8g2.setDrawColor( 1); // Text color white
    u8g2.setCursor(0, 18); u8g2.print((current_line == 2) ? F(">") : F(" ")); u8g2.print(F("Line2: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 26); u8g2.print((current_line == 3) ? F(">") : F(" ")); u8g2.print(F("Line3: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 34); u8g2.print((current_line == 4) ? F(">") : F(" ")); u8g2.print(F("Line4: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 42); u8g2.print((current_line == 5) ? F(">") : F(" ")); u8g2.print(F("Line5: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 50); u8g2.print((current_line == 6) ? F(">") : F(" ")); u8g2.print(F("Line6: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 58); u8g2.print((current_line == 7) ? F(">") : F(" ")); u8g2.print(F("Line7: ")); u8g2.print(current_line);
  } while (u8g2.nextPage());

  // Handle interactions
  switch (current_line)
  {
    case 1:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 2:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 3:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 4:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 5:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 6:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 7:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    default:
      break;
  }
}/////////////////////////////////////////////////////////////////////////////***************** Page 2 END ****************************///////////////

void page3()/////////////////////////////////////////////////////////////////////////////***************** Page 3 Start ****************************///////////////
{
  u8g2.firstPage();
  do {
    // Clear the page
    u8g2.setDrawColor(1);               // Background color white
    u8g2.drawBox(0, 0, 128, 10);        // Drawing white Box
    
    u8g2.setDrawColor(0);               // Text color black
    u8g2.setFont(u8g2_font_courR08_tf); // Set a suitable font
    
    // Display the menu options
    u8g2.setCursor(0,  8); u8g2.print((current_line == 1) ? F("<   > ") : F("<     ")); u8g2.print(F("Page3         >"));

    u8g2.setDrawColor( 1); // Text color white
    u8g2.setCursor(0, 18); u8g2.print((current_line == 2) ? F(">") : F(" ")); u8g2.print(F("Line2: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 26); u8g2.print((current_line == 3) ? F(">") : F(" ")); u8g2.print(F("Line3: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 34); u8g2.print((current_line == 4) ? F(">") : F(" ")); u8g2.print(F("Line4: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 42); u8g2.print((current_line == 5) ? F(">") : F(" ")); u8g2.print(F("Line5: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 50); u8g2.print((current_line == 6) ? F(">") : F(" ")); u8g2.print(F("Line6: ")); u8g2.print(current_line);
    u8g2.setCursor(0, 58); u8g2.print((current_line == 7) ? F(">") : F(" ")); u8g2.print(F("Line7: ")); u8g2.print(current_line);
  } while (u8g2.nextPage());

  // Handle interactions
  switch (current_line)
  {
    case 1:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 2:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 3:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 4:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 5:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 6:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 7:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    default:
      break;
  }
}/////////////////////////////////////////////////////////////////////////////***************** Page 3 END ****************************///////////////

void mainpage()/////////////////////////////////////////////////////////////////////////////***************** main Page Start ****************************///////////////
{
  u8g2.firstPage();
  do {
    // Clear the page
    u8g2.setDrawColor(1);               // Background color white
    u8g2.drawBox(0, 0, 128, 10);        // Drawing white Box
    
    u8g2.setDrawColor(0);               // Text color black
    u8g2.setFont(u8g2_font_courR08_tf); // Set a suitable font
    
    // Display the menu options
    u8g2.setCursor(0,  8); u8g2.print((current_line == 1) ? F("<   > ") : F("<     ")); u8g2.print(F("main Page     >"));

    u8g2.setDrawColor( 1); // Text color white
    u8g2.setCursor(0, 18); u8g2.print((current_line == 2) ? F(">") : F(" ")); u8g2.print(F("Pressure 1: "));    u8g2.print(PRESSURE_SENSOR_READING1);
    u8g2.setCursor(0, 26); u8g2.print((current_line == 3) ? F(">") : F(" ")); u8g2.print(F("Pressure 2: "));    u8g2.print(PRESSURE_SENSOR_READING2);
    u8g2.setCursor(0, 34); u8g2.print((current_line == 4) ? F(">") : F(" ")); u8g2.print(F("Temperature 1: ")); u8g2.print(TEMPERATURE_SENSOR_READING1);
    u8g2.setCursor(0, 42); u8g2.print((current_line == 5) ? F(">") : F(" ")); u8g2.print(F("Temperature 2: ")); u8g2.print(TEMPERATURE_SENSOR_READING2);
    u8g2.setCursor(0, 50); u8g2.print((current_line == 6) ? F(">") : F(" ")); u8g2.print(F("Line6: "));         u8g2.print(current_line);
    u8g2.setCursor(0, 58); u8g2.print((current_line == 7) ? F(">") : F(" ")); u8g2.print(F("Line7: "));         u8g2.print(current_line);
  } while (u8g2.nextPage());

  // Handle interactions
  switch (current_line)
  {
    case 1:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 2:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 3:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 4:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 5:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 6:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    case 7:
      if (increaseVal == 1) { current_page++; increaseVal = 0; }
      if (decreaseVal == 1) { current_page--; decreaseVal = 0; }
      break;
    default:
      break;
  }
}/////////////////////////////////////////////////////////////////////////////***************** main page END ****************************///////////////

//Task of Loading Pages on OLED.
void loopPages()
{
  switch (pressedButton())
  {
    case DOWN_BUTTON_PIN:   if (button_last_state == 0){  current_line = (current_line + 1 > MAX_LINES) ? 1 : current_line + 1; button_last_state = 1;  } break;
    case UP_BUTTON_PIN:     if (button_last_state == 0){  current_line = (current_line - 1 < 1) ? MAX_LINES : current_line - 1; button_last_state = 1;  } break;
    case RIGHT_BUTTON_PIN:  if (button_last_state == 0){  increaseVal  = 1;                                                     button_last_state = 1;  } break;
    case LEFT_BUTTON_PIN:   if (button_last_state == 0){  decreaseVal  = 1;                                                     button_last_state = 1;  } break;
    default:  button_last_state = 0;
  }

  switch (current_page)
  {
    case 1: page1();    break;
    case 2: page2();    break;
    case 3: page3();    break;
    case 4: mainpage(); break;
    default: mainpage();
  }

  if(current_page < 1)
  {
    current_page = MAX_PAGES;
  }
  else if (current_page > MAX_PAGES)
  {
    current_page = 1;
  }
}

#endif  //PAGES_H
