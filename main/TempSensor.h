#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include<math.h>

#include "EEPROMLibrary.h"

#define Thermister_1_pin      TEMP1_PIN
#define Thermister_2_pin      TEMP2_PIN
#define NUM_READINGS 10      // Number of readings to average
#define READ_INTERVAL 20     // Reading interval in milliseconds 

unsigned long lastReadTime1 = 0;   // Variable to store the last reading time
double tempStack1[NUM_READINGS];   // Array to store the last 10 temperature values
int stackIndex1 = 0;               // Index to keep track of the current position in the stack
unsigned long lastReadTime2 = 0;   // Variable to store the last reading time
double tempStack2[NUM_READINGS];   // Array to store the last 10 temperature values
int stackIndex2 = 0;               // Index to keep track of the current position in the stack

unsigned long lastReadTime3 = 0;   // Variable to store the last reading time

float SetPoint      = 22.00;
float SetPointDiff  = 2.00;
signed char sensorOffset1 = 0;
signed char sensorOffset2 = 0;
extern String Temp_Alarm_reason1 = "Empty";
extern String Temp_Alarm_reason2 = "Empty";

//Decliration of Variables in other file.
extern unsigned long Com_1_OperationDelay;
extern unsigned long Com_2_OperationDelay;


void Thermister_init()
{
//  SetPoint      = 20.00;
//  EEPROM.put(0, SetPoint);
  pinMode(Thermister_1_pin,INPUT);
  pinMode(Thermister_2_pin,INPUT);
  String Readings = readStringFromEEPROM(FirstTime_ADDRESS);

  if(Readings != "The First Time")
  {
    writeStringToEEPROM(FirstTime_ADDRESS, "The First Time");

    EEPROM.put(float_SetPoint_ADDRESS, 12.00);
    EEPROM.put(float_SetPointDiff_ADDRESS, 2.00);
    EEPROM.put(signed_char_sensorOffset1_ADDRESS, 0);
    EEPROM.put(signed_char_sensorOffset2_ADDRESS, 0);
    EEPROM.put(unsigned_long_Com_1_OperationDelay_ADDRESS, 150UL);
    EEPROM.put(unsigned_long_Com_2_OperationDelay_ADDRESS, 250UL);
  }
  EEPROM.get(float_SetPoint_ADDRESS, SetPoint);
  EEPROM.get(float_SetPointDiff_ADDRESS, SetPointDiff);
  EEPROM.get(signed_char_sensorOffset1_ADDRESS, sensorOffset1);
  EEPROM.get(signed_char_sensorOffset2_ADDRESS, sensorOffset2);
//  EEPROM.get(unsigned_long_Com_1_OperationDelay_ADDRESS, Com_1_OperationDelay);
//  EEPROM.get(unsigned_long_Com_2_OperationDelay_ADDRESS, Com_2_OperationDelay);
}

//New Functions that gets the avg temperature.
//*
double Thermister1()
{
  static double averageTemp = 22.0;
  // Check if the specified interval has passed since the last reading
  if (millis() - lastReadTime1 >= READ_INTERVAL)
  {
    // Read the analog value from the thermistor
    int rawValue = analogRead(Thermister_1_pin);

    // Convert the analog value to temperature
    double temp = log(10000.0 * ((1024.0 / rawValue) - 1));
    temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
    temp = temp - 273.15;

    // Push the new temperature value onto the stack
    tempStack1[stackIndex1] = temp;
    stackIndex1 = (stackIndex1 + 1) % NUM_READINGS;

    lastReadTime1 = millis();  // Update the last reading time

    // Increment a counter to keep track of the number of readings
    static int readingsCount = 0;
    readingsCount++;

    // Check if the specified number of readings has been reached
    if (readingsCount == NUM_READINGS)
    {
      // Calculate the average temperature
      averageTemp = 0.0;
      for (int i = 0; i < NUM_READINGS; i++)
      {
        averageTemp += tempStack1[i];
      }
      averageTemp /= NUM_READINGS;

      // Reset variables for the next set of readings
      readingsCount = 0;

      return (averageTemp + sensorOffset1);
    }
  }
  return (averageTemp + sensorOffset1);
}

double Thermister2()
{
  static double averageTemp = 20.0;
  // Check if the specified interval has passed since the last reading
  if (millis() - lastReadTime2 >= READ_INTERVAL)
  {
    // Read the analog value from the thermistor
    int rawValue = analogRead(Thermister_2_pin);

    // Convert the analog value to temperature
    double temp = log(10000.0 * ((1024.0 / rawValue) - 1));
    temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
    temp = temp - 273.15;

    // Push the new temperature value onto the stack
    tempStack2[stackIndex2] = temp;
    stackIndex2 = (stackIndex2 + 1) % NUM_READINGS;

    lastReadTime2 = millis();  // Update the last reading time

    // Increment a counter to keep track of the number of readings
    static int readingsCount = 0;
    readingsCount++;

    // Check if the specified number of readings has been reached
    if (readingsCount == NUM_READINGS)
    {
      // Calculate the average temperature
      averageTemp = 0.0;
      for (int i = 0; i < NUM_READINGS; i++)
      {
        averageTemp += tempStack2[i];
      }
      averageTemp /= NUM_READINGS;

      // Reset variables for the next set of readings
      readingsCount = 0;

      return (averageTemp + sensorOffset2);
    }
  }
  return (averageTemp + sensorOffset2);
}

/*
void IncreaseTemp(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    SetPoint++;
    if(SetPoint>30) SetPoint=30;
    EEPROM.put(float_SetPoint_ADDRESS, SetPoint);
  }
  else if(*page_num == 2)
  {
    SetPointDiff++;
    if(SetPointDiff>10) SetPointDiff=10;
    EEPROM.put(float_SetPointDiff_ADDRESS, SetPointDiff);
  }
}

void IncreaseOffset(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    sensorOffset1++;
    EEPROM.put(signed_char_sensorOffset1_ADDRESS, sensorOffset1);
  }
  else if(*page_num == 2)
  {
    sensorOffset2++;
    EEPROM.put(signed_char_sensorOffset2_ADDRESS, sensorOffset2);
  }
  else if(*page_num == 3)
  {
    Com_1_OperationDelay += 10;
    if(Com_1_OperationDelay>450) Com_1_OperationDelay=450;
    EEPROM.put(unsigned_long_Com_1_OperationDelay_ADDRESS, Com_1_OperationDelay);
  }
  else if(*page_num == 4)
  {
    Com_2_OperationDelay += 10;
    if(Com_2_OperationDelay>450) Com_2_OperationDelay=450;
    EEPROM.put(unsigned_long_Com_2_OperationDelay_ADDRESS, Com_2_OperationDelay);
  }
}

void DecreaseTemp(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    SetPoint--;
    if(SetPoint<6) SetPoint=6;
    EEPROM.put(float_SetPoint_ADDRESS, SetPoint);
  }
  else if(*page_num == 2)
  {
    SetPointDiff--;
    if(SetPointDiff<1) SetPointDiff=1;
    EEPROM.put(float_SetPointDiff_ADDRESS, SetPointDiff);
  }
}

void DecreaseOffset(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    sensorOffset1--;
    EEPROM.put(signed_char_sensorOffset1_ADDRESS, sensorOffset1);
  }
  else if(*page_num == 2)
  {
    sensorOffset2--;
    EEPROM.put(signed_char_sensorOffset2_ADDRESS, sensorOffset2);
  }
  else if(*page_num == 3)
  {
    Com_1_OperationDelay -= 10;
    if(Com_1_OperationDelay<150) Com_1_OperationDelay=150;
    EEPROM.put(unsigned_long_Com_1_OperationDelay_ADDRESS, Com_1_OperationDelay);
  }
  else if(*page_num == 4)
  {
    Com_2_OperationDelay -= 10;
    if(Com_2_OperationDelay<150) Com_2_OperationDelay=150;
    EEPROM.put(unsigned_long_Com_2_OperationDelay_ADDRESS, Com_2_OperationDelay);
  }
}

void check_Input_Output_temp_def(char Alarm)
{
  //First Alarm Starts Here.
  static bool arr[6] = {false,false,false,false,false,false};
  if(Thermister1() <= Thermister2() && Alarm == 1) //if the Temprature that enter the system is colder then the temprature that gets out that means something is wrong.
  {
    static char counter = 0;
    if(counter == 0){arr[counter] = true; lastReadTime3 = millis(); counter++;}
    if(millis() - lastReadTime3 >= (2UL*60*1000)) //every 2 minutes
    {
      switch (counter)
      {
        case 1: arr[counter] = true; counter++; break;
        case 2: arr[counter] = true; counter++; break;
        case 3: arr[counter] = true; counter++; break;
        case 4: arr[counter] = true; counter++; break;
        case 5: arr[counter] = true; counter=0; break;
        default: counter = 0;
      }

      lastReadTime3 = millis();
    }
  }
  if(arr[0] == true && arr[1] == true && arr[2] == true && arr[3] == true && arr[4] == true && arr[5] == true)
  {
    temperature_difference_Alarm = HIGH;
    Temp_Alarm_reason1 = "reverse flow or     ";
    Temp_Alarm_reason2 = " sensor failure     ";
    for(char i = 0; i<6; i++) arr[i] = false;
  }
  //First Alarm Ends Here.

  //Second Alarm starts Here.
  if((Thermister1() < 4 || Thermister2() < 4) && Alarm == 2)
  {
    temperature_difference_Alarm = HIGH;
    Temp_Alarm_reason1 = "Low temp or sensor  ";
    Temp_Alarm_reason2 = " failure            ";
  }
  //Second Alarm Ends Here.
  if (temperature_difference_Alarm == LOW)
  {
    Temp_Alarm_reason1 = "                    ";
    Temp_Alarm_reason2 = "                    ";
    //temperature_difference_Alarm = LOW;
  }
}

*/

#endif  //TEMPSENSOR_H
