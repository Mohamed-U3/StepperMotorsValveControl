#include "Steppers.h"
#include "Oled.h"
#include "PressureSensor.h"
#include "TempSensor.h"


void setup()
{
  Serial.begin(9600);
  Thermister_init();
  setupStepper();
  setupPressure();
  setupOled();
}

void loop()
{
  loopStepper();
}
