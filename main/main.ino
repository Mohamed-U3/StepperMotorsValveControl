#include "Steppers.h"
#include "Oled.h"
#include "PressureSensor.h"
#include "TempSensor.h"
#include "Global.h"


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
//  loopStepper();
  loopPressure();
  display.clearDisplay();
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Temp1: "));      display.println(Thermister1());
  
  display.print(F("Temp2: "));      display.println(Thermister2());
  
  display.print(F("Pressure1: "));  display.println(global_pressure_reading1);
  
  display.print(F("Pressure2: "));  display.println(global_pressure_reading2);
  
  display.println(F("Temp5: "));
  display.println(F("Temp6: "));
  display.println(F("Temp7: "));
  display.println(F("Temp8: "));
  display.display();      // Show initial text
}
