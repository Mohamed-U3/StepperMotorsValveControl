/**
 * ***********************************************************
 * @file  : EEPROMLibrary.h
 * @brief : file contain functions and definitions related to eeprom
 * @author: Eng. Mohamed Yousry
 * @date  : 20/02/2024
 * ***********************************************************
 */
#ifndef EEPROMLIBRARY_H
#define EEPROMLIBRARY_H
/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include <EEPROM.h>
/*
* ***********************************************************
              Defines
* ***********************************************************
*/
//addresses for EEPROM
#define float_SetPoint_ADDRESS                            0
#define float_SetPointDiff_ADDRESS                        (float_SetPoint_ADDRESS                     + sizeof(float))
#define signed_char_sensorOffset1_ADDRESS                 (float_SetPointDiff_ADDRESS                 + sizeof(float))
#define signed_char_sensorOffset2_ADDRESS                 (signed_char_sensorOffset1_ADDRESS          + sizeof(signed char))

#define unsigned_long_Com_1_OperationDelay_ADDRESS        (signed_char_sensorOffset2_ADDRESS          + sizeof(signed char))
#define unsigned_long_Com_2_OperationDelay_ADDRESS        (unsigned_long_Com_1_OperationDelay_ADDRESS + sizeof(unsigned long))

#define FirstTime_ADDRESS                                 (unsigned_long_Com_2_OperationDelay_ADDRESS + sizeof(unsigned long))

/*
 * ***********************************************************
               Functions body
 * ***********************************************************
*/
// Function to write a string to EEPROM
void writeStringToEEPROM(int address, const String& data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        EEPROM.write(address + i, data[i]);
    }
    // Null-terminate the string
    EEPROM.write(address + data.length(), '\0');
}

// Function to read a string from EEPROM
String readStringFromEEPROM(int address)
{
    String result;
    char character = EEPROM.read(address);
    while (character != '\0')
    {
        result += character;
        address++;
        character = EEPROM.read(address);
    }
    return result;
}

#endif  //EEPROMLIBRARY_H
