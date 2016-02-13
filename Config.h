#ifndef CONFIG_H
#define CONFIG_H

// Defines our map and the information each cell has.
struct celda{
  int iCerteza;
  int iDecision;
  boolean bPosicion;
  char cLetra;
};
typedef struct pos{
  int x;
  int y;
  int z;
};


// This defines our map dimiensions.
#define maxSize 21
#define mapHeight 2

// This is our array of the map.
celda universo[21][21][9];

//Definitions of motors in the drivetrain
#define leftMotor 3
#define rightMotor 6
#define frontMotor 5
#define backMotor 9

#define trigPinRight 10
#define echoPinRight 10
#define trigPinLeft 10
#define echoPinLeft 10
#define trigPinFront 10
#define echoPinFront 10
#define trigPinBack 10
#define echoPinBack 10

#endif
