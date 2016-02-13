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

long getDistance(int iPos)
{
  int trigPin = 0;
  int echoPin = 0;
  switch(iPos)
  {
     case 1:
      trigPin = trigPinFront;
      echoPin = echoPinFront;
    case 2:
      trigPin = trigPinRight;
      echoPin = echoPinRight;
    case 3:
      trigPin = trigPinBack;
      echoPin = echoPinBack;
    case 4:
      trigPin = trigPinLeft;
      echoPin = echoPinLeft;
    default:
      trigPin = trigPinRight;
      echoPin = echoPinRight;
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
  return lDuration / 58.2;
 }

int getWalls(int iPos)
{
  int m = getDistance(iPos)/30;
  return m;
}
bool isBlack()
{
  
}


