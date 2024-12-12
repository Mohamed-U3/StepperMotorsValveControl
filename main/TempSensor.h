#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include "EEPROMLibrary.h"
#include "Config.h"
#include "Global.h"

#define Thermister_1_pin                TEMP1_PIN                       //Pin of NTC 1 (TEMP1_PIN what is in "Config.h" configuration file)
#define Thermister_2_pin                TEMP2_PIN                       //Pin of NTC 2 (TEMP1_PIN what is in "Config.h" configuration file)
#define TEMPERATURE_SENSOR_READING1     global_temperature_reading1     //The readings of the sensor is written in this global variable.
#define TEMPERATURE_SENSOR_READING2     global_temperature_reading2     //The readings of the sensor is written in this global variable.

class NTCThermistor
{
  private:
    // Pin where the thermistor is connected
    int _pin;

    // Thermistor characteristics
    const float NOMINAL_RESISTANCE = 10000.0;  // 10k ohm at 25°C
    const float NOMINAL_TEMPERATURE = 25.0;    // Reference temperature

    // Steinhart-Hart coefficients (typical for 10k NTC)
    const float BETA_COEFFICIENT = 3950.0;

    // Voltage divider fixed resistor value
    const float SERIES_RESISTOR = 10000.0;  // 10k ohm series resistor

  public:
    // Constructor
    NTCThermistor(int pin) : _pin(pin)
    {
      // Set the analog pin to input mode
      pinMode(_pin, INPUT);
    }

    // Read raw analog value
    int readRawValue()
    {
      return analogRead(_pin);
    }

    // Convert analog reading to voltage
    float readVoltage()
    {
      return readRawValue() * (5.0 / 1023.0);
    }

    // Calculate resistance of the thermistor
    float calculateResistance()
    {
      float voltage = readVoltage();
      float resistance = SERIES_RESISTOR / ((5.0 / voltage) - 1.0);
      return resistance;
    }

    // Convert temperature using Steinhart-Hart equation
    float getTemperatureCelsius()
    {
      float resistance = calculateResistance();

      // Steinhart-Hart equation
      float steinhart;
      steinhart = log(resistance / NOMINAL_RESISTANCE) / BETA_COEFFICIENT;     // 1/B * ln(R/Ro)
      steinhart += 1.0 / (NOMINAL_TEMPERATURE + 273.15);                       // + (1/To)
      steinhart = 1.0 / steinhart;                                             // Invert
      steinhart -= 273.15;                                                     // Convert to Celsius

      return steinhart;
    }

    // Convert to Fahrenheit
    float getTemperatureFahrenheit()
    {
      return (getTemperatureCelsius() * 9.0 / 5.0) + 32.0;
    }
};
NTCThermistor NTC1(Thermister_1_pin);
NTCThermistor NTC2(Thermister_2_pin);

void NTC_loop()
{
  TEMPERATURE_SENSOR_READING1 = NTC1.getTemperatureCelsius();
  TEMPERATURE_SENSOR_READING2 = NTC2.getTemperatureCelsius();
}

#endif  //TEMPSENSOR_H
