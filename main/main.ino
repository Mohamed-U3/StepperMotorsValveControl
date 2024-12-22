#include "Steppers.h"
#include "Oled.h"
#include "PressureSensor.h"
#include "TempSensor.h"
#include "Buttons.h"
#include "Pages.h"
#include "Global.h"



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
