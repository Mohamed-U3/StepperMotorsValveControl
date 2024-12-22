/**
 * ***********************************************************
 * @file  : Global.cpp
 * @brief : file contain functionalities of Global module
 * @author: Eng. Mohamed Yousry
 * @date  : 20/02/2024
 * ***********************************************************
 */
/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include "Global.h"

/*
 * ***********************************************************
 *            Global variables
 * ***********************************************************
 */
// Declearation of variabes
float global_pressure_reading1;     //reading of the sensor in PSI unit.
float global_pressure_reading2;     //reading of the sensor in PSI unit.
float global_pressure_min_volt1;    //voltage when the reading is 0 PSI
float global_pressure_max_volt1;    //voltage when the reading is maximum PSI
float global_pressure_min_volt2;    //voltage when the reading is 0 PSI
float global_pressure_max_volt2;    //voltage when the reading is maximum PSI
float global_max_pressure_value1;   //the value of the maximum pressure that sensor can read
float global_max_pressure_value2;   //the value of the maximum pressure that sensor can read
int   global_pressure_setpoint1;    //the value of the setpoint of the pressure sensor1
int   global_pressure_setpoint2;    //the value of the setpoint of the pressure sensor2
int   global_pressure_offset1;       //the value of the offset of the pressure sensor1
int   global_pressure_offset2;       //the value of the offset of the pressure sensor2

float global_temperature_reading1;  //reading of the sensor in °C unit.
float global_temperature_reading2;  //reading of the sensor in °C unit.
int   global_temperature_setpoint1; //the value of the setpoint of the temperature sensor1
int   global_temperature_setpoint2; //the value of the setpoint of the temperature sensor2
