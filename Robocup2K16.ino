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
#include "Llenar.h"
#include "Movernos.h"
#include "Posibilidades.h"
#include "Config.h"
#include "Sensores.h"
#include "VictimaEncontrada.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(22, 24, 26, 28, 30, 32);
int toggle = 0;
float anglet = 0;
void setup() 
{
  Serial.begin(9600);
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
  pinMode(ledPin,OUTPUT);
  //Vex Motors Setup
  motorsSetup();

  //Sensor Setup

  //LCD Setup
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Saving the Whales!");
  lcd.clear();

  universo[6][6][1].bPosicion = true;

}

void loop() 
{
  while(toggle==LOW)
  {
    /*
    lcd.setCursor(0, 0);
    lcd.print(getDistance(2));
    lcd.setCursor(4,0);
    lcd.print(isVictim(2));
  
    lcd.setCursor(6, 0);
    lcd.print(getDistance(4));
    lcd.setCursor(11,0);
    lcd.print(isVictim(4));
  
    lcd.setCursor(0, 1);
    lcd.print(getDistance(1));
    lcd.setCursor(4,1);
    lcd.print(isVictim(1));
  
    lcd.setCursor(6, 1);
    lcd.print(getDistance(3));
    lcd.setCursor(11,1);
    lcd.print(isVictim(3));
    */
    anglet += getAngle();
    lcd.setCursor(0, 0);
    lcd.print(anglet);
    Serial.println(anglet);
    delay(500);
    lcd.clear();

    toggle = getButton();
    //test();  
  }
  
  while(toggle== HIGH)
  {
    lcd.clear();
    lcd.print("Llenar Function");
    Llenar();
    delay(1000);
  MovernosHacia(posibilidades(LetraCuadroActual()));
  if(isBlack())aUltimaD();
  if(isVictim(1))VictimaEncontrada(1);
  if(isVictim(2))VictimaEncontrada(2);
  if(isVictim(3))VictimaEncontrada(3);
  if(isVictim(4))VictimaEncontrada(4);
  
  if(getButton()==1) toggle = 0;
  }
}

