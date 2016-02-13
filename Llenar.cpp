/*
 *  Name: Llenar.cpp
 *  Description: 
 * 
 *  
 */

 #include "Posibilidades.h"
 #include "Config.h"
 #include "Sensores.h"


char LetraCuadroActual()
{
  int paredesArriba=getWalls(1); 
  int paredesAbajo=getWalls(3);
  int paredesDerecha=getWalls(2);
  int paredesIzquierda=getWalls(4);
  boolean esNegro=isBlack();
  
  String codigo = "";
  char codigoN = 'O';
  
  if(paredesAbajo==0)
  {
    codigo=codigo+"1";
  }
  if(paredesIzquierda==0)
  {
    codigo=codigo+"2";
  }
  if(paredesArriba==0)
  {
    codigo=codigo+"3";
  }
  if(paredesDerecha==0)
  {
    codigo=codigo+"4";
  }
  if(esNegro)
  {
    codigo="BLACK";
  }
  if(codigo=="")
  {
    codigo="0";
  }

  if(codigo.equals("134"))
  {
    codigoN='A';
  }
   
  if(codigo.equals("124")) codigoN='B';
    
  if(codigo.equals("123")) codigoN='C';
       
  if(codigo.equals("234")) codigoN='D';
      
  if(codigo.equals("14")) codigoN='E';
 
  if(codigo.equals("13")) codigoN='F';
   
  if(codigo.equals("43")) codigoN='G';
   
  if(codigo.equals("12")) codigoN='H';
 
  if(codigo.equals("24")) codigoN='I';
  
  if(codigo.equals("23")) codigoN='J';

  if(codigo.equals("1")) codigoN='K';
      
  if(codigo.equals("3")) codigoN='L';
      
  if(codigo.equals("4")) codigoN='M';
       
  if(codigo.equals("2")) codigoN='N';
       
  if(codigo.equals("0")) codigoN='O';
       
  if(codigo.equals("BLACK")) codigoN='X';
       
   return codigoN;
}

void CertezaCuadroActual(){
  pos posicion = getPosition();
  universo[posicion.x][posicion.y][posicion.z].iCerteza = 2;
}
 
void Llenar()
{
  //ModificarPosicion();
  LetraCuadroActual();
  CertezaCuadroActual();
}

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

