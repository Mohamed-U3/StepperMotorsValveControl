#ifndef GLOBAL_H
#define GLOBAL_H

/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */

/*
 * ***********************************************************
 *             Global variables
 * ***********************************************************
 */
// Declearation of variabes
extern float global_pressure_reading1;      //reading of the sensor in PSI unit.
extern float global_pressure_reading2;      //reading of the sensor in PSI unit.
extern float global_pressure_min_volt1;     //voltage when the reading is 0 PSI
extern float global_pressure_max_volt1;     //voltage when the reading is maximum PSI
extern float global_pressure_min_volt2;     //voltage when the reading is 0 PSI
extern float global_pressure_max_volt2;     //voltage when the reading is maximum PSI
extern float global_max_pressure_value1;    //the value of the maximum pressure that sensor can read
extern float global_max_pressure_value2;    //the value of the maximum pressure that sensor can read

extern float global_temperature_reading1;   //reading of the sensor in °C unit.
extern float global_temperature_reading2;   //reading of the sensor in °C unit.

#endif  //GLOBAL_H
