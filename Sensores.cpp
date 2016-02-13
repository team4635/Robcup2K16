/*
 *  Name: Sensores.cpp
 *  Description: 
 * 
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
      trigPin = trigPinRight;
      echoPint = echoPinRight;
    case 2:
      trigPin = trigPinLeft;
      echoPint = echoPinLeft;
    case 3:
      trigPin = trigPinFront;
      echoPint = echoPinFront;
    case 4:
      trigPin = trigPinBack;
      echoPint = echoPinBack;
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

