#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include "Config.h"
#include "Global.h"

/*
 * ***********************************************************
 *             Defines
 * ***********************************************************
 */
#define PRESSURE_SENSOR_READING1    global_pressure_reading1
#define PRESSURE_SENSOR_READING2    global_pressure_reading2

/*
 * ***********************************************************
 *            Variables
 * ***********************************************************
 */
const int pressureZero              = 102.4;  //analog reading of pressure transducer at 0psi
const int pressureMax               = 921.6;  //analog reading of pressure transducer at maximum psi
const int pressuretransducermaxPSI  = 100;    //psi value of transducer being used
float     pressureValue             = 0;      //variable to store the value coming from the pressure transducer

/*
 * ***********************************************************
 *             Functions body
 * ***********************************************************
 */
void setupPressure()
{
  pinMode(PRESSURE1_PIN,INPUT);
  pinMode(PRESSURE2_PIN,INPUT);
}

void loopPressure()
{
  pressureValue = analogRead(PRESSURE1_PIN);
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi
  PRESSURE_SENSOR_READING1 = pressureValue; //Values in PSI

  pressureValue = analogRead(PRESSURE2_PIN);
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi
  PRESSURE_SENSOR_READING2 = pressureValue; //Values in PSI
}

#endif  //PRESSURESENSOR_H
