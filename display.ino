int py =0 ;
void display(){
 
  py++;
  if(py==8){
    py=0;
  }
  pin [8+py] =LOW;
  newpin [8+py] =LOW;

  for(int i=0; i<8; i++){
    if(cell[py][i]==1){
      pin[i] =HIGH;

    }
  }
    for(int i=0; i<8; i++){
    if(newcell[py][i]==1){
      newpin[i] =HIGH;

    }
  }
  pinchange(count);
  writepins();
  clearpins();

}
void pinchange(int x){

  pincopy();
     for(int i=0; i<8; i++){
      if((i+x)<8){
        pin[i] = pin[i+x];
      }else
      {
        break;
      }
     }
      for(int i=0; i<8; i++){

      pin[7-x+i+1] =oldpin[i];
       if(7-x+i+1==7){
        break;
      }    

    }

}
void pincopy(){
  for(int p=0; p<16; p++){
    oldpin[p] = newpin[p];
  }
}
int cc=0;
void cellchange(int p){
  cellcopy();

    letter(print[cc]);
cc++;
if(cc==p+1){
  cc=0;
}
}
void cellcopy(){
  for(int a=0; a<8; a++){
    for(int b=0; b<8; b++){
      cell[a][b]= newcell[a][b];
    }
  }
}
void writepins(){

  digitalWrite(latchclock,LOW);

  for(int i=0; i<16; i++){
  digitalWrite(shiftclock,LOW);
  digitalWrite(serialdata,pin[15-i]);
  digitalWrite(shiftclock,HIGH);

  }
  digitalWrite(latchclock,HIGH);

}

void clearpins(){
  for(int i=0; i<8; i++){
    pin[8+i]=HIGH;
    pin[i]=LOW;
    newpin[8+i]=HIGH;
    newpin[i]=LOW;
  }
}

