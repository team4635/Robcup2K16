#ifndef CONFIG_H
#define CONFIG_H

// Defines our map and the information each cell has.
struct celda{
  int iCerteza;
  int iDecision;
  bool bPosicion;
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

//Definitions of motors in the drivetrain
#define leftMotor 3
#define rightMotor 6
#define frontMotor 5
#define backMotor 9

#define trigPinRight 50
#define echoPinRight 51
#define trigPinLeft 48
#define echoPinLeft 49
#define trigPinFront 46
#define echoPinFront 47
#define trigPinBack 52
#define echoPinBack 53

extern celda universo[21][21][9];

#endif
