String posibilidades(char letra){
  String codigo ="", newCodigo ="";
  int posicion[] = getPosicion();

  switch(letra){
    case 'A': codigo="134";
         break;
    case 'B': codigo="124";
         break;
    case 'C': codigo="123";
         break;
    case 'D': codigo="234";
         break;
     case 'E': codigo="14";
         break;
     case 'F': codigo="13";
         break;
     case 'G': codigo="43";
         break;
     case 'H': codigo="12";
         break;
     case 'I': codigo="24";
         break;
     case 'J': codigo="23";
         break;
     case 'K': codigo="1";
         break;
     case 'L': codigo="3";
         break;
     case 'M': codigo="4";
         break;
     case 'N': codigo="2";
         break;
     case 'O': codigo="0";
         break;
     case 'P': codigo="1234";
         break;
     default:;
         break;
    }

if(!codigo.equals("BLACK"))
    for(int h=0; h<codigo.length()-1;h++){
      switch(codigo.charAt(h)){
        case '1': 
          if(universo[posicion[0]][posicion[1]-1][posicion[2]].cert!=2){
              newCodigo=newCodigo+codigo.charAt(h)
            }
        break;
        
        case '2': 
          if(universo[posicion[0]+1][posicion[1]][posicion[2]].cert!=2){
            newCodigo=newCodigo+codigo.charAt(h)}
        break;

        case '3': 
          if(universo[posicion[0]][posicion[1]+1][posicion[2]].cert!=2){
            newCodigo=newCodigo+codigo.charAt(h)}
        break;

        case '4': 
          if(universo[posicion[0]-1][posicion[1]][posicion[2]].cert!=2){
            newCodigo=newCodigo+codigo.charAt(h)}
        break;
    }}

    if(newCodigo.equals(""))
    newCodigo = "9";
    
    return codigo;
  }


int[] getPosition(){
  int PosicionActual[3];
  boolean acabo=false;

  for(int x=0 ; x<universo.length-1 ; x++ && acabo==false)
    for(int y=0 ; y<universo[x].length-1 ; y++ && acabo==false)
      for(int p=0 ; p<universo[x][y].length-1 ; p++ && acabo==false)
        if(universo[x][y][p].pos==true){
        acabo==true;
        PosicionActual[0]=x;
        PosicionActual[1]=y;
        PosicionActual[2]=p;
  }
  return subUniverso;
}
