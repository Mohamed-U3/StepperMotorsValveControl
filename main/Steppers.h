/**
 * ***********************************************************
 * @file  : Steppers.h
 * @brief : Functionality and code of the stepper motors.
 * @author: Eng. Mohamed Yousry
 * @date  : 22/12/2024
 * ***********************************************************
 */
#ifndef STEPPERS_H
#define STEPPERS_H

/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include <Arduino.h>
#include "Config.h"
#include "A4988.h"
/*
 * ***********************************************************
 *             Defines
 * ***********************************************************
 */
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 32650
#define RPM 25
#define MS1 10
#define MS2 11
#define MS3 12
/*
 * ***********************************************************
 *             Objects
 * ***********************************************************
 */
A4988 stepper1(MOTOR_STEPS, STEPPER1_DIR_PIN, STEPPER1_STEP_PIN, MS1, MS2, MS3);
A4988 stepper2(MOTOR_STEPS, STEPPER2_DIR_PIN, STEPPER2_STEP_PIN, MS1, MS2, MS3);

/*
 * ***********************************************************
 *             Functions body
 * ***********************************************************
 */
void setupStepper()
{
  /*
     Set target motor RPM.
  */
  stepper1.begin(RPM);
  stepper2.begin(RPM);
  // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
  // stepper.setEnableActiveState(LOW);
  stepper1.enable();
  stepper2.enable();
  /*
    Microstepping mode: 1, 2, 4, 8, 16 or 32 (where supported by driver)
    Mode 1 is full speed.
    Mode 32 is 32 microsteps per step.
    The motor should rotate just as fast (at the set RPM),
    but movement precision is increased, which may become visually apparent at lower RPMs.
  */
  stepper1.setMicrostep(32);   // Set microstep mode to 1:8
  stepper2.setMicrostep(32);   // Set microstep mode to 1:8
  // set current level (for DRV8880 only).
  // Valid percent values are 25, 50, 75 or 100.
  // stepper.setCurrent(100);
}

void loopStepper()
{
  // In 1:8 microstepping mode, one revolution takes 8 times as many microsteps
  //    stepper.move(32 * MOTOR_STEPS);    // forward revolution
  //    stepper.move(-32 * MOTOR_STEPS);   // reverse revolution

  // One complete revolution is still 360° regardless of microstepping mode
  // rotate() is easier to use than move() when no need to land on precise microstep position
  stepper1.rotate(1080);
  stepper2.rotate(-1080);
  delay(500);
  stepper1.rotate(-1080);
  stepper2.rotate(1080);

  delay(1000);
}

#endif  //STEPPERS_H
