/*
 *  Name: Movernos.cpp
 *  Description: 
 * 
 *  
 */
#include  <vexMotor.h>
#include "Config.h"
#include "Sensores.h"
#include "Posibilidades.h"

#define num 255
#define factor 10
vexMotor vMotorLeftDown;
vexMotor vMotorLeftUp;
vexMotor vMotorRightUp;
vexMotor vMotorRightDown;
int x = 0;
int y = 0;
float angle = 0;

int arrayM[100];
int countM=0;
int arrayD[100];
int countD=0;


void motorsSetup()
{
  vMotorLeftDown.attach(leftMotor);
  vMotorLeftUp.attach(rightMotor);
  vMotorRightUp.attach(frontMotor);
  vMotorRightDown.attach(backMotor);
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
      //break;
    default: x = 0;
             y = 0; 
             countM++;
      break;
  }
  
  long lCurrentDistance = getDistance(posibilidad);
  float fRampAngle = 0;
  while(getDistance(posibilidad) < (lCurrentDistance-30))
  {
    //Angulo //Actualizar el angulo para corregir la trayectoria
    vMotorLeftDown.write(-x+y-angle*factor);
    vMotorLeftUp.write(x-y-angle*factor);
    vMotorRightUp.write(-x-y-angle*factor);
    vMotorRightDown.write(x+y-angle*factor);
    fRampAngle += getAngleX();
    if (fRampAngle > 20 )
    {
      pos ActualPos = getPosition();
      universo[ActualPos.x][ActualPos.y][ActualPos.z-1];
    }
    if (fRampAngle < -20 )
    {
      pos ActualPos = getPosition();
      universo[ActualPos.x][ActualPos.y][ActualPos.z+1];
    }
    while(fRampAngle < -20){
        vMotorLeftDown.write(0);
        vMotorLeftUp.write(0);
        vMotorRightUp.write(0);
        vMotorRightDown.write(0);
    }
  
  }
  vMotorLeftDown.write(0);
  vMotorLeftUp.write(0);
  vMotorRightUp.write(0);
  vMotorRightDown.write(0);     
}
void aUltimaD()
{

  for(int h=countM ; h>0 ; h--)
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
    vMotorLeftDown.write(-x+y-angle*factor);
    vMotorLeftUp.write(x-y-angle*factor);
    vMotorRightUp.write(-x-y-angle*factor);
    vMotorRightDown.write(x+y-angle*factor);     
    }
    vMotorLeftDown.write(0);
    vMotorLeftUp.write(0);
    vMotorRightUp.write(0);
    vMotorRightDown.write(0);
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
   vMotorLeftDown.write(100);
   vMotorLeftUp.write(100);
   vMotorRightUp.write(100);
   vMotorRightDown.write(100);
   fAnguloActual += getAngle();
  }
  
}
void test()
{
  //Angulo //Actualizar el angulo para corregir la trayectoria
  vMotorLeftDown.write(0);
  vMotorLeftUp.write(0);
  vMotorRightUp.write(0);
  vMotorRightDown.write(0);     
}
