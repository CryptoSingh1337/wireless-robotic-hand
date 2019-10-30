#include <Servo.h>  //the library which helps us to control servo
#include <SPI.h>    //the communication interface with the modem  
#include "RF24.h"   //the library which helps us to control the radio modem  

Servo myServo1; //define Servo
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

RF24 radio(9,10);                     //this represent the CE and CSN connected to digital pins 9 and 10 of the Arduino   

const uint64_t pipe = 0xF0F0F0F0D2LL; //this represents the address of the receiver module

int msg[1];

int data; //data variable
int pos;  //position variable

void setup(){

  myServo1.attach(3); //myServo1 connect to digitsl pin 3
  myServo2.attach(5); //myServo2 connect to digitsl pin 5
  myServo3.attach(6); //myServo3 connect to digitsl pin 6
  myServo4.attach(7); //myServo4 connect to digitsl pin 7
  myServo5.attach(8); //myServo5 connect to digitsl pin 8
  
  radio.begin();                   //it activates the module                
  radio.openReadingPipe(1, pipe);  //the module starts recieving the data send by the transmitter
  radio.setChannel(115);           //it set the channel
  radio.setDataRate( RF24_2MBPS ); //the data rate is 2 MBPS
  radio.startListening();          //the module starts listening the data which is send by tranmitter         
  }

void loop(){
  if(radio.available()){
    radio.read(msg, 1);

    if(msg[0] <11 && msg[0] >-1){
      data = msg[0], pos=map(data, 0, 10, 160, 0);
      myServo1.write(pos); 
    }
    if(msg[0] <21 && msg[0]>10){
      data = msg[0], pos=map(data, 11, 20, 160, 0);
      myServo2.write(pos);
    }
    if(msg[0] <31 && msg[0]>20){
      data = msg[0], pos=map(data, 21, 30, 160, 0);
      myServo3.write(pos);
    }
    if(msg[0] <41 && msg[0]>30){
      data = msg[0], pos=map(data, 31, 40, 160, 0);
      myServo4.write(pos);
    }
    if(msg[0] <51 && msg[0]>40){
      data = msg[0], pos=map(data, 41, 50, 160, 0);
      myServo5.write(pos);
    }
  }
}
