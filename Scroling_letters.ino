#include <FrequencyTimer2.h>

int serialdata = 2;
int shiftclock = 3;       //Define 74HC595 Pins
int latchclock = 4;

boolean cell[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 0, 0, 1, 1, 0 },
  { 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1 },         //Displaying Matrix
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};
boolean newcell[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },         // temporary store for the scrolling
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};
boolean pin[16];        //shift register arrays
boolean newpin[16];
boolean oldpin[16];


void
setup() {
  // put your setup code here, to run once:
    pinMode(serialdata,OUTPUT);
    pinMode(shiftclock,OUTPUT);
    pinMode(latchclock,OUTPUT);
FrequencyTimer2::disable();
FrequencyTimer2::setPeriod(2000);
FrequencyTimer2::setOnOverflow(display);    //interupts for the display function

}

 
 int count=0;
 char print[] = {'W','E','L','C','O','M','E'};  //showing letters
 int indexcount = 6;      //last index value in letter array

void loop() {
  // put your main code here, to run repeatedly:

count=0;

for(int d=0; d<8; d++){
  count++;
  delay(200);

}
cellchange(indexcount);



}

void clean(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      cell[i][j] = 0;
      newcell[i][j] = 0;
    }
  }
}
