/*
 *  Name: Sensores.h
 *  Description: 
 * 
 *  
 */

#ifndef SENSORES_H
#define SENSORES_H

#include "Arduino.h"

void sensorSetup();
long getDistance(int iPos);
int getWalls(int iPos);
bool isBlack();
bool isVictim(int iPos);

#endif
