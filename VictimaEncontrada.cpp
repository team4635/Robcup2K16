/*
 *  Name: VictimaEncontrada.cpp
 *  Description: 
 * 
 *  
 */
#include "Arduino.h"
#include "Config.h"
#include "Sensores.h"
#include "Movernos.h"

void VictimaEncontrada(int direccion)
{
 Rotar(direccion);
 Deploy();
 CorregirRotar(direccion);
 FlashingLED();
}

void Rotar(int direccion)
{
  switch(direccion){
  case 1:;
  break;
  case 2: //rotar 90 grados;
  Rotacion(90);
  break;
  case 3://rotar 180 grados;
  Rotacion(180);
  break;
  case 4://rotar 270 grados;
  Rotacion(270);
  break;
  
  }  
}
void Deploy()
{
  for (pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

}
void CorregirRotar(int direccion)
{
  switch(direccion){
  case 1:;
  break;
  case 2: //rotar -90 grados;
  Rotacion(270);
  break;
  case 3://rotar 180 grados;
  Rotacion(180);
  break;
  case 4://rotar 90 grados;
  Rotacion(90);
  break;
}

void FlashingLED()
{
  
}  
