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
 *            Variables
 * ***********************************************************
 */
int pressure1Zero              = 102.4;  //analog reading of pressure transducer at 0 psi
int pressure1Max               = 921.6;  //analog reading of pressure transducer at maximum psi
int pressure1transducermaxPSI  = 100;    //psi value of transducer being used
int pressure2Zero              = 102.4;  //analog reading of pressure transducer at 0 psi
int pressure2Max               = 921.6;  //analog reading of pressure transducer at maximum psi
int pressure2transducermaxPSI  = 100;    //psi value of transducer being used
float pressureValue            = 0;      //variable to store the value coming from the pressure transducer

/*
 * ***********************************************************
 *             Functions body
 * ***********************************************************
 */
void setupPressure()
{
  pinMode(PRESSURE1_PIN,INPUT);
  pinMode(PRESSURE2_PIN,INPUT);

  //Pressure sensor parameters configrations
  PRESSURE_MIN_VOLT1   = (512.00/1023.00);    //voltage when the reading is 0 PSI
  PRESSURE_MAX_VOLT1   = (1536.00/341.00);    //voltage when the reading is maximum PSI
  PRESSURE_MIN_VOLT2   = (512.00/1023.00);    //voltage when the reading is 0 PSI
  PRESSURE_MAX_VOLT2   = (1536.00/341.00);    //voltage when the reading is maximum PSI
  MAX_PRESSURE_VALUE1  = 100;                 //the value of the maximum pressure that sensor can read
  MAX_PRESSURE_VALUE2  = 100;                 //the value of the maximum pressure that sensor can read

  pressure1Zero = (PRESSURE_MIN_VOLT1*(1023.00/5.00));
  pressure1Max  = (PRESSURE_MAX_VOLT1*(1023.00/5.00));
  pressure2Zero = (PRESSURE_MIN_VOLT2*(1023.00/5.00));
  pressure2Max  = (PRESSURE_MAX_VOLT2*(1023.00/5.00));
  pressure1transducermaxPSI = MAX_PRESSURE_VALUE1;
  pressure2transducermaxPSI = MAX_PRESSURE_VALUE2;
}

void loopPressure()
{
  pressureValue = analogRead(PRESSURE1_PIN);
  pressureValue = ((pressureValue-pressure1Zero)*pressure1transducermaxPSI)/(pressure1Max-pressure1Zero); //conversion equation to convert analog reading to psi
  PRESSURE_SENSOR_READING1 = pressureValue; //Values in PSI

  pressureValue = analogRead(PRESSURE2_PIN);
  pressureValue = ((pressureValue-pressure2Zero)*pressure2transducermaxPSI)/(pressure2Max-pressure2Zero); //conversion equation to convert analog reading to psi
  PRESSURE_SENSOR_READING2 = pressureValue; //Values in PSI
}

#endif  //PRESSURESENSOR_H
