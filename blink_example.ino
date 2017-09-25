#include <protothreading.h>//include the protothreading library

// created 2017:
// by Joseph Raub

//circut-
// two leds connected to pins 3 and 4 with a 220 Ohm resistor between the cathode and GND pin on your Arduino board.

//define variables for neatness
int led1 = 4;
int led2 = 3;


//create two (or more) instances of the Thread Class
Thread thread1;
Thread thread2;

//define the function to toggle the 1st led
void blinkLed1(){
  if(digitalRead(led1) == HIGH){
    digitalWrite(led1,LOW);
  }
  else{
    digitalWrite(led1,HIGH);
  }
}

//define the function to toggle the 2nd led
void blinkLed2(){
  if(digitalRead(led2) == HIGH){
    digitalWrite(led2,LOW);
  }
  else{
    digitalWrite(led2,HIGH);
  }
}

void setup() {
  //set pinModes
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
  //set how many milliseconds will pass before the light blinks
  thread1.setCycleSpeed(1250);
  //pass the function you want the thread to call when the time is up !!Be sure to put an asterisk before the function name!!
  thread1.setFunc(*blinkLed1);

  
  thread2.setCycleSpeed(1200);
  thread2.setFunc(*blinkLed2);
  
}

void loop() {
  //tell the thread to cycle
  thread1.cycle();
  thread2.cycle();
}



