/*
 *  Name: Movernos.cpp
 *  Description: 
 * 
 *  
 */
#include  <vexMotor.h>
#include "Config.h"
#include "Sensores.h"

#define num 255
#define factor 10
vexMotor vMotorLeft;
vexMotor vMotorRight;
vexMotor vMotorFront;
vexMotor vMotorBack;
int x = 0;
int y = 0;
float angle = 0;

int arrayM[100];
int countM=0;
int arrayD[100];
int countD=0;


void motorsSetup()
{
  vMotorLeft.attach(leftMotor);
  vMotorRight.attach(rightMotor);
  vMotorFront.attach(frontMotor);
  vMotorBack.attach(backMotor);
}

char decisionR(String codigo){
  char posib;
  if(codigo.length()<= 1)
  posib=codigo.charAt(0);
  else{
    arrayD[countD]= countM;
    countD++;
    long m =random(codigo.length());
    posib = codigo.charAt(m);
     }
     return posib;
}

void MovernosHacia(String P)
{
  char posibilidad = decisionR(P);
  switch(posibilidad)
  {
    case '1': x = 0;
            y = num;
            arrayM[countM]=3;
            countM++;
      break;
    case '2': x = num;
            y = 0;
            arrayM[countM]=4;
            countM++;
      break;
    case '3': x = 0;
            y = -num;
            arrayM[countM]=1;
            countM++;
      break;
    case '4': x = -num;
            y = 0;
            arrayM[countM]=2;
            countM++;
      break;
     //case '9': aUltimaD();
      break;
    default: x = 0;
             y = 0; 
             countM++;
      break;
  }
  
  long lCurrentDistance = getDistance(posibilidad);
  while(getDistance(posibilidad) < (lCurrentDistance-30))
  {
  //Angulo //Actualizar el angulo para corregir la trayectoria
  vMotorLeft.write(-x+y-angle*factor);
  vMotorRight.write(x-y-angle*factor);
  vMotorFront.write(-x-y-angle*factor);
  vMotorBack.write(x+y-angle*factor);     
  }
  vMotorLeft.write(0);
  vMotorRight.write(0);
  vMotorFront.write(0);
  vMotorBack.write(0);     
}
void aUltimaD(){

  for(int h=countM ; h>0 ; h--){
    {
      char posibilidad = decisionR(String(arrayM[h]));
      switch(posibilidad)
      {
        case '1': x = 0;
                y = num;
                arrayM[countM]=3;
          break;
        case '2': x = num;
                y = 0;
                arrayM[countM]=4;
          break;
        case '3': x = 0;
                y = -num;
                arrayM[countM]=1;
          break;
        case '4': x = -num;
                y = 0;
                arrayM[countM]=2;
          break;
         //case '9': aUltimaD();
          break;
        default: x = 0;
                 y = 0; 
          break;
      }
  
  long lCurrentDistance = getDistance(posibilidad);
  while(getDistance(posibilidad) < (lCurrentDistance-30))
  {
  //Angulo //Actualizar el angulo para corregir la trayectoria
  vMotorLeft.write(-x+y-angle*factor);
  vMotorRight.write(x-y-angle*factor);
  vMotorFront.write(-x-y-angle*factor);
  vMotorBack.write(x+y-angle*factor);     
  }
  vMotorLeft.write(0);
  vMotorRight.write(0);
  vMotorFront.write(0);
  vMotorBack.write(0);
  countM--;  
  }
  countD--;
}

void EstarEnRampa()
{
  
}
void Rotacion(float AnguloDeseado)
{
  float fAnguloActual = 0;
  while(fAnguloActual<AnguloDeseado)
  {
   vMotorLeft.write(100);
   vMotorRight.write(100);
   vMotorFront.write(100);
   vMotorBack.write(100);
   fAnguloActual += getAngle();
  }
  
}
