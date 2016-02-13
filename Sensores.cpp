/*
 *  Name: Sensores.cpp
 *  Description: Defines the sensor functions.
 *  
 *  Sensor configurations
 *   
 *   
 *  Sensor positions relative to its default orientation:
 *  
 *                        Front
 *                          1
 *                          -
 *                  Left 4 | | 2 Right
 *                          -
 *                          3
 *                         Back
 *  
 */

#include "Arduino.h"
#include "Config.h"
#include <SoftwareSerial.h>

#define unused 255         // Non-existant pin # for SoftwareSerial
#define sioBaud 4800
#define waitDelay 200

// Set up two software serials on the same pin.
SoftwareSerial serin(colorPinSensor, unused);
SoftwareSerial serout(unused, colorPinSensor);

long getDistance(int iPos)
{
  int trigPin = 0;
  int echoPin = 0;
  switch(iPos)
  {
     case 1:
      trigPin = trigPinFront;
      echoPin = echoPinFront;
      break;
    case 2:
      trigPin = trigPinRight;
      echoPin = echoPinRight;
      break;
    case 3:
      trigPin = trigPinBack;
      echoPin = echoPinBack;
      break;
    case 4:
      trigPin = trigPinLeft;
      echoPin = echoPinLeft;
      break;
    default:
      trigPin = trigPinRight;
      echoPin = echoPinRight;
      break;
  }

  
  long lDuration = 0;
   /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  lDuration = pulseIn(echoPin, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.

  long lDistance = lDuration / 58.2;
  if (lDistance>200)
  {
    lDistance = 200;
  }
  return lDistance;
 }

int getWalls(int iPos)
{
  int m = getDistance(iPos)/30;
  return m;
}
bool isVictim(int iPos)
{
  int pin = 0;
  switch(iPos)
  {
     case 1:
      pin = heatPinFront;
      break;
    case 2:
      pin = heatPinRight;
      break;
    case 3:
      pin = heatPinBack;
      break;
    case 4:
      pin = heatPinLeft;
      break;
    default:
      pin = heatPinBack;
      break;
  }
  return digitalRead(pin);
}
bool isBlack()
{
  
}


