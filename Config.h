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
#define leftMotor 2
#define rightMotor 3
#define frontMotor 4
#define backMotor 5

#define trigPinRight 50
#define echoPinRight 51
#define trigPinLeft 48
#define echoPinLeft 49
#define trigPinFront 46
#define echoPinFront 47
#define trigPinBack 52
#define echoPinBack 53

#define heatPinBack 45
#define heatPinRight 44
#define heatPinLeft 43
#define heatPinFront 42

#define colorPinSensor 19

#define ledPin 37

#define btnPin 39

extern celda universo[13][13][3];

#endif
