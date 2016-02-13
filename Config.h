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


#endif
