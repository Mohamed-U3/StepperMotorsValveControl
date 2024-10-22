/**
 * ***********************************************************
 * @file  : Global.cpp
 * @brief : file contain functionalities of Global module
 * @author: Engineer\ Mohamed Yousry
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
