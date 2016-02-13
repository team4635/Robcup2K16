#include <Servo.h>

/*
 *  Name: VictimaEncontrada.cpp
 *  Description: 
 * 
 *  
 */
#include "Arduino.h"
#include "VictimaEncontrada.h"
#include "Config.h"
#include "Sensores.h"
#include "Movernos.h"

void VictimaEncontrada(int direccion)
{
 FlashingLED();
 //Rotar(direccion);
 Deploy();
 //CorregirRotar(direccion);
}

void Rotar(int direccion)
{
  switch(direccion)
  {
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
  Servo myservo;
  myservo.attach(5);
  for (int posi = 0; posi <= 80; posi++) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(posi);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }  for (int posi = 80; posi >= 0; posi--) 
  { // goes from 180 degrees to 0 degrees
    myservo.write(posi);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

}
void CorregirRotar(int direccion)
{
  switch(direccion){
    case 1:
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
}

void FlashingLED()
{
  int n=0;
  while(n<5)
  {
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  delay(1000);
  n++;
  }
}  
