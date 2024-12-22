/**
 * ***********************************************************
 * @file  : Oled.h
 * @brief : Functionality and code of the OLED display
 * @author: Eng. Mohamed Yousry
 * @date  : 22/12/2024
 * ***********************************************************
 */
#ifndef OLED_H
#define OLED_H
/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include <U8g2lib.h>
#include <Wire.h>
/*
 * ***********************************************************
 *             Objects
 * ***********************************************************
 */
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
/*
 * ***********************************************************
               Functions body
 * ***********************************************************
*/
void setupOled()
{
  u8g2.begin();
}

void loopOled()
{  
  u8g2.firstPage();                           // Start the first page
  do{
    // Draw text on the display
    u8g2.setDrawColor(1);                     // Set drawing color to black
    u8g2.drawBox(0, 0, 128, 16);              // Fill the entire display with a black background
    u8g2.setDrawColor(0);                     // Set drawing color to white
    u8g2.setFont(u8g2_font_courB10_tr);       // Set a built-in font
    u8g2.drawStr(0, 12, "ColorAidSystem!");   // Draw a string at x=0, y=10
    
    u8g2.setDrawColor(1);                     // Set drawing color to black
    u8g2.setFont(u8g2_font_courB14_tr);       // Set a built-in font
    u8g2.drawStr(25, 40, "templete 1"); // Another string at x=25, y=40
    
    u8g2.setFont(u8g2_font_courB08_tr);       // Set a built-in font
    u8g2.drawStr(0, 60, "Volume: ");          // Another string at x=0, y=60
  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
}

#endif  //OLED_H
