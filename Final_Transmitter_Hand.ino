#include <SPI.h>   //the communication interface with the modem                 
#include "RF24.h"  //the library which helps us to control the radio modem
int msg[1];


int poten_5 = A5; //defines that poten5 connect to analog pin A5
int poten_4 = A4; //defines that poten4 connect to analog pin A4
int poten_3 = A3; //defines that poten3 connect to analog pin A3
int poten_2 = A2; //defines that poten2 connect to analog pin A2
int poten_1 = A1; //defines that poten1 connect to analog pin A1


int poten_5_val;
int poten_4_val;
int poten_3_val;
int poten_2_val;
int poten_1_val;

RF24 radio(9,10);                     //this represent the CE and CSN connected to digital pins 9 and 10 of the Arduino                      
                                      
const uint64_t pipe = 0xF0F0F0F0D2LL; //this represents the address of the receiver module


void setup(void){
  Serial.begin(9600);
  radio.begin();                  //it activates the module
  radio.setChannel(115);          //it set the channel
  radio.setDataRate( RF24_2MBPS); //the data rate is 2 MBPS
  radio.openWritingPipe(pipe);    //the module starts writing the data and send to the receiver module      
}

void loop(){

  poten_1_val = analogRead(poten_1); 
                             
  poten_1_val = map(poten_1_val, 0, 200, 0, 10);
  msg[0] = poten_1_val;
  radio.write(msg, 1);

  poten_2_val = analogRead(poten_2);
                             
  poten_2_val = map(poten_2_val, 0, 200, 11, 20);
  msg[0] = poten_2_val;
  radio.write(msg, 1);

  poten_3_val = analogRead(poten_3);
                             
  poten_3_val = map(poten_3_val, 0, 200, 21, 30);
  msg[0] = poten_3_val;
  radio.write(msg, 1);

  poten_4_val = analogRead(poten_4);
                             
  poten_4_val = map(poten_4_val, 0, 200, 31, 40);
  msg[0] = poten_4_val;
  radio.write(msg, 1);

  poten_5_val = analogRead(poten_5);
                             
  poten_5_val = map(poten_5_val, 0, 200, 41, 50);
  msg[0] = poten_5_val;
  radio.write(msg, 1);
}
