/**
 * ***********************************************************
 * @file  : Buttons.h
 * @brief : file contain functions related to the buttons
 * @author: Eng. Mohamed Yousry
 * @date  : 22/12/2024
 * ***********************************************************
 */
#ifndef BOTTONS_H
#define BOTTONS_H
/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include "Config.h"
#include "Global.h"

/*
 * ***********************************************************
 *           variables
 * ***********************************************************
 */

/*
* ***********************************************************
*             Defines
* ***********************************************************
*/

/*
 * ***********************************************************
 *             Functions body
 * ***********************************************************
 */
void setupbuttons()
{
  pinMode(DOWN_BUTTON_PIN ,INPUT);
  pinMode(LEFT_BUTTON_PIN ,INPUT);
  pinMode(RIGHT_BUTTON_PIN,INPUT);
  pinMode(UP_BUTTON_PIN   ,INPUT);
}

char pressedButton()
{
  if     (digitalRead(DOWN_BUTTON_PIN)  == HIGH)  return DOWN_BUTTON_PIN;
  else if(digitalRead(LEFT_BUTTON_PIN)  == HIGH)  return LEFT_BUTTON_PIN;
  else if(digitalRead(RIGHT_BUTTON_PIN) == HIGH)  return RIGHT_BUTTON_PIN;
  else if(digitalRead(UP_BUTTON_PIN)    == HIGH)  return UP_BUTTON_PIN;
  else return -1;
}

 
#endif  //BOTTONS_H
