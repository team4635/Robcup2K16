int posicion[]=getPosicion();

int sensorUno;
int sensorDos;
int sensorTres;
int sensorCuatro;

void modificarPosicion(int movimiento){
  switch(movimiento){
    case 1: universo[posicion[0]][[posicion[1]][posicion[2]].pos=false;
            universo[posicion[0]][[posicion[1]-1][posicion[2]].pos=true;
      break;
    case 2: universo[posicion[0]][[posicion[1]][posicion[2]].pos=false;
            universo[posicion[0]+1][[posicion[1]][posicion[2]].pos=true;
      break;
    case 3: universo[posicion[0]][[posicion[1]][posicion[2]].pos=false;
            universo[posicion[0]][[posicion[1]+1][posicion[2]].pos=true;
      break;
    case 4: universo[posicion[0]][[posicion[1]][posicion[2]].pos=false;
            universo[posicion[0]-1][[posicion[1]][posicion[2]].pos=true;
      break;
    default: universo[posicion[0]][[posicion[1]][posicion[2]].pos=true;
      break;
}

void actualizarSensores(){
  sensorUno=
}



