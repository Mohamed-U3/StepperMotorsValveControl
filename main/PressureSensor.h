#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include "Config.h"

void setupPressure()
{
  pinMode(PRESSURE1_PIN,INPUT);
  pinMode(PRESSURE2_PIN,INPUT);
}

void loopPressure()
{
  analogRead(PRESSURE1_PIN);
  analogRead(PRESSURE2_PIN);
}

#endif  //PRESSURESENSOR_H
