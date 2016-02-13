/*
 * Name: Robocup2K16
 * Description: This is the main program for the robocup competition.
 * Our code is separated into different files which are defined by funcionality.
 * 
 * This the current configuration:
 *    1. Llenar (Updates the tridimensional map)
 *      a. HayVictima (Search in the current position if there's a victim and pulls the rescue kit)
 *    2. Posibilidades (Changes Decisions to where to go)
 *    3. Movernos (Moves until there's new cell)
 *      a. EstarEnRampa (Detect if the robot is on a ramp)
 *      b. Obstaculo (Detect if there's an obstacle)
 */


// Include all the functions from files
// !!!Note!!!: Comment out the ones you aren't using
//#include "Llenar.h"
#include "Movernos.h"
//#include "Posibilidades.h"
#include "Config.h"

void setup() 
{
  // Heat Sensor Setup
  pinMode(heatPinBack, INPUT);
  pinMode(heatPinFront, INPUT);
  pinMode(heatPinRight, INPUT);
  pinMode(heatPinLeft, INPUT);

  // Ultrasonic Sensor Setup
  pinMode(trigPinBack, OUTPUT);
  pinMode(echoPinBack, INPUT);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);

  //Vex Motors Setup
  motorsSetup();

}

void loop() 
{
  // put your main code here, to run repeatedly:

}
