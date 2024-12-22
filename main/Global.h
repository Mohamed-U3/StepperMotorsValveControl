/**
 * ***********************************************************
 * @file  : Global.h
 * @brief : file contain Global Variables
 * @author: Eng. Mohamed Yousry
 * @date  : 20/02/2024
 * ***********************************************************
 */
#ifndef GLOBAL_H
#define GLOBAL_H
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
extern int   global_pressure_setpoint1;     //the value of the setpoint of the pressure sensor1
extern int   global_pressure_setpoint2;     //the value of the setpoint of the pressure sensor2
extern int   global_pressure_offset1;       //the value of the offset of the pressure sensor1
extern int   global_pressure_offset2;       //the value of the offset of the pressure sensor2

extern float global_temperature_reading1;   //reading of the sensor in °C unit.
extern float global_temperature_reading2;   //reading of the sensor in °C unit.
extern int   global_temperature_setpoint1;  //the value of the setpoint of the temperature sensor1
extern int   global_temperature_setpoint2;  //the value of the setpoint of the temperature sensor2
extern int   global_temperature_offset1;    //the value of the offset of the temperature sensor1
extern int   global_temperature_offset2;    //the value of the offset of the temperature sensor2

#endif  //GLOBAL_H
