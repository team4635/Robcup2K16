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
#include <Wire.h>
#include <SPI.h>
#include <SparkFunLSM9DS1.h>

LSM9DS1 imu;

#define LSM9DS1_M  0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG  0x6B // Would be 0x6A if SDO_AG is LOW

#define DECLINATION -8.58 // Declination (degrees) in Boulder, CO.
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

  setupGyro();
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
  readData();
  if(blu > 200 && red > 200 && grn > 200)
  {
    return true;
  }
  return false;
}

bool getButton()
{
  
}

void setupGyro()
{
  // [enabled] turns the gyro on or off.
  imu.settings.gyro.enabled = true;  // Enable the gyro
  // [scale] sets the full-scale range of the gyroscope.
  // scale can be set to either 245, 500, or 2000
  imu.settings.gyro.scale = 245; // Set scale to +/-245dps
  // [sampleRate] sets the output data rate (ODR) of the gyro
  // sampleRate can be set between 1-6
  // 1 = 14.9    4 = 238
  // 2 = 59.5    5 = 476
  // 3 = 119     6 = 952
  imu.settings.gyro.sampleRate = 3; // 59.5Hz ODR
  // [bandwidth] can set the cutoff frequency of the gyro.
  // Allowed values: 0-3. Actual value of cutoff frequency
  // depends on the sample rate. (Datasheet section 7.12)
  imu.settings.gyro.bandwidth = 0;
  // [lowPowerEnable] turns low-power mode on or off.
  imu.settings.gyro.lowPowerEnable = false; // LP mode off
  // [HPFEnable] enables or disables the high-pass filter
  imu.settings.gyro.HPFEnable = true; // HPF disabled
  // [HPFCutoff] sets the HPF cutoff frequency (if enabled)
  // Allowable values are 0-9. Value depends on ODR.
  // (Datasheet section 7.14)
  imu.settings.gyro.HPFCutoff = 1; // HPF cutoff = 4Hz
  // [flipX], [flipY], and [flipZ] are booleans that can
  // automatically switch the positive/negative orientation
  // of the three gyro axes.
  imu.settings.gyro.flipX = false; // Don't flip X
  imu.settings.gyro.flipY = false; // Don't flip Y
  imu.settings.gyro.flipZ = false; // Don't flip Z
}

float orientationSensorHeading()
{
  imu.readMag();
  imu.readGyro();
  float heading = 0;
  if (imu.my == 0)
    heading = (imu.mx < 0) ? 180.0 : 0;
  else
    heading = atan2(imu.mx, imu.my);
    
  heading -= DECLINATION * PI / 180;
  
  if (heading > PI) heading -= (2 * PI);
  else if (heading < -PI) heading += (2 * PI);
  else if (heading < 0) heading += 2 * PI;
  
  // Convert everything from radians to degrees:
  heading *= 180.0 / PI;

  

  //return heading;
  return imu.calcGyro(imu.gz);
}
float getAngle()
{
  return orientationSensorHeading()/119;
}

