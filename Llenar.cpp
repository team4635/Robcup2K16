/*
 *  Name: Llenar.cpp
 *  Description: 
 * 
 *  
 */

 #include "Posibilidades.h"
 #include "Config.h"
 #include "Sensores.h"

void ModificarPosicion(int movimiento)
{
  pos posicion = getPosition();
  switch(movimiento){
    case 1: universo[posicion.x][posicion.y][posicion.z].bPosicion = false;
            universo[posicion.x][posicion.y-1][posicion.z].bPosicion = true;
      break;
    case 2: universo[posicion.x][posicion.y][posicion.z].bPosicion = false;
            universo[posicion.x+1][posicion.y][posicion.z].bPosicion = true;
      break;
    case 3: universo[posicion.x][posicion.y][posicion.z].bPosicion = false;
            universo[posicion.x][posicion.y+1][posicion.z].bPosicion = true;
      break;
    case 4: universo[posicion.x][posicion.y][posicion.z].bPosicion = false;
            universo[posicion.x-1][posicion.y][posicion.z].bPosicion = true;
      break;
    default: universo[posicion.x][posicion.y][posicion.z].bPosicion = true;
      break;
  }
}

void LetraCuadroActual()
{
  int paredesArriba=getWalls(1); 
  int paredesAbajo=getWalls(3);
  int paredesDerecha=getWalls(2);
  int paredesIzquierda=getWalls(4);
  bool esNegro=isBlack();
  
  String codigo = "";
  
  if(paredesAbajo==0){
    codigo=codigo+"1";
  }
  if(paredesIzquierda==0){
    codigo=codigo+"2";
  }
  if(paredesArriba==0){
    codigo=codigo+"3";
  }
  if(paredesDerecha==0){
    codigo=codigo+"4";
  }
  if(esNegro){
    codigo="BLACK";
  }
  if(codigo==""){
    codigo="0";
  }
  
  switch(codigo){
    case "134": codigo='A';
         break;
    case '124': codigo='B';
         break;
    case "123": codigo='C';
         break;
    case "234": codigo='D';
         break;
     case "14": codigo='E';
         break;
     case "13": codigo='F';
         break;
     case "43": codigo='G';
         break;
     case "12": codigo='H';
         break;
     case "24": codigo='I';
         break;
     case "23": codigo='J';
         break;
     case "1": codigo='K';
         break;
     case "3": codigo='L';
         break;
     case "4": codigo='M';
         break;
     case "2": codigo='N';
         break;
     case "0": codigo='O';
         break;
     case "BLACK": codigo='X';
         break;
     default:;
         break;
  }
  
}

void CertezaCuadroActual(){
  pos posicion = getPosition();
  universo[posicion.x][posicion.y][posicion.z].iCerteza = 2;
}

