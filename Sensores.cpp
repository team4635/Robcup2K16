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

#define trigPinRight 10
#define echoPinRight 10
#define trigPinLeft 10
#define echoPinLeft 10
#define trigPinFront 10
#define echoPinFront 10
#define trigPinBack 10
#define echoPinBack 10


long getDistance(int iPos)
{
  int trigPin = 0;
  int echoPin = 0;
  switch(iPos)
  {
     case 1:
      trigPin = trigPinFront;
      echoPint = echoPinFront;
    case 2:
      trigPin = trigPinRight;
      echoPint = echoPinRight;
    case 3:
      trigPin = trigPinBack;
      echoPint = echoPinBack;
    case 4:
      trigPin = trigPinLeft;
      echoPint = echoPinLeft;
    default:
      trigPin = trigPinRight;
      echoPint = echoPinRight;
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

int getWalls(){
  int m = getDistance()/30;
  return m;
}

