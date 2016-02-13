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
#define colorPinSensorBaud 4800
#define waitDelay 200

// Received RGB values from ColorPAL
int red;
int grn;
int blu;

// Set up two software serials on the same pin.
SoftwareSerial serin(colorPinSensor, unused);
SoftwareSerial serout(unused, colorPinSensor);


// Reset ColorPAL; see ColorPAL documentation for sequence
void reset() {
  delay(200);
  pinMode(colorPinSensor, OUTPUT);
  digitalWrite(colorPinSensor, LOW);
  pinMode(colorPinSensor, INPUT);
  while (digitalRead(colorPinSensor) != HIGH);
  pinMode(colorPinSensor, OUTPUT);
  digitalWrite(colorPinSensor, LOW);
  delay(80);
  pinMode(colorPinSensor, INPUT);
  delay(waitDelay);
}

void sensorSetup() {
  reset();                  // Send reset to ColorPal
  serout.begin(colorPinSensorBaud);
  pinMode(colorPinSensor, OUTPUT);
  serout.print("= (00 $ m) !"); // Loop print values, see ColorPAL documentation
  serout.end();              // Discontinue serial port for transmitting

  serin.begin(colorPinSensorBaud);            // Set up serial port for receiving
  pinMode(colorPinSensor, INPUT);
}

// Parse the hex data into integers
void parseAndPrint(char * data) {
  sscanf (data, "%3x%3x%3x", &red, &grn, &blu);
  char buffer[32];
  sprintf(buffer, "R%4.4d G%4.4d B%4.4d", red, grn, blu);
  Serial.println(buffer);
}

void readData() {
  char buffer[32];
 
  if (serin.available() > 0) {
    // Wait for a $ character, then read three 3 digit hex numbers
    buffer[0] = serin.read();
    if (buffer[0] == '$') {
      for(int i = 0; i < 9; i++) {
        while (serin.available() == 0);     // Wait for next input character
        buffer[i] = serin.read();
        if (buffer[i] == '$')               // Return early if $ character encountered
          return;
      }
      parseAndPrint(buffer);
      delay(10);
    }
  }
}

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
bool getButton()
{
  
}


