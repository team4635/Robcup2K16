/*
 * Name: Robocup2K16
 * Description: This is the main program for the robcup competition.
 * Our code is separated into differente files in which are define by funcionality.
 * 
 * This the current configuration:
 *    1. Llenar (Updates the tridimensional map)
 *      a. HayVictima (Search in the current position if there's a victim and pulls the rescue kit)
 *    2. Posibilidades (Changes Decesions to where to go)
 *    3. Movernos (Moves until there's new cell)
 *      a. EstarEnRampa (Detect if there's a ramp)
 *      b. Obstaculo (Detect if there's an obstacale)
 */


// Include all the functions from files
// !!!Note!!!: Comment out the ones you aren't using
//#include "Llenar.h"
//#include "Movernos.h"
//#include "Posibilidades.h"

// This defines our map dimiensions.
#define maxSize 19
#define mapHeight 2

// Defines our map and the information each cell has.
struct celda{
  int iCerteza;
  int iDecision;
  boolean bPosicion;
  char cLetra;
}

// This is our array of the map.
celda universo[mapSize][mapSize][mapHeight];



void setup() 
{
  // put your setup code here, to run once:

}

void loop() 
{
  // put your main code here, to run repeatedly:

}
