/**
 * ***********************************************************
 * @file  : main.ino
 * @brief : file contain the main function of arduino project
 * @author: Eng. Mohamed Yousry
 * @date  : 22/12/2024
 * ***********************************************************
 */
 /*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include "Steppers.h"
#include "Oled.h"
#include "PressureSensor.h"
#include "TempSensor.h"
#include "Buttons.h"
#include "Pages.h"
#include "Global.h"
/*
 * ***********************************************************
 *             Functions body
 * ***********************************************************
 */
void setup()
{
  Serial.begin(9600);
  setupStepper();
  setupPressure();
  setupOled();
  setupbuttons();
}

void loop()
{
//  loopStepper();
  loopPressure();
  loopPages();
  NTC_loop();
}
