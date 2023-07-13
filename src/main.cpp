#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>
#define FPSerial softSerial
SoftwareSerial softSerial(/*rx =*/10, /*tx =*/11);
DFRobotDFPlayerMini myDFPlayer;
// put function declarations here:
#include "OneButton.h"
// Setup a new OneButton on pin A1.  
OneButton button1(2, true);
OneButton button2(3, true);
OneButton button3(0, true);
OneButton button4(5, true);
OneButton button11(9, true);
OneButton button12(8, true);
OneButton button13(7, true);
OneButton button14(12, true);
uint8_t vol1 =30;
uint8_t vol2 =2;
uint8_t timer = 0;
void ring1();
void ring2();
void ring3();
void ring4();
void play1();
void play2();
void play3();
void play4();
void stop();
uint8_t state = 0;
void setup() {

    softSerial.begin(9600);
    pinMode(A0, OUTPUT);
    digitalWrite(A0, HIGH);
    pinMode(A1, OUTPUT);
    digitalWrite(A1, HIGH);
    pinMode(A2, OUTPUT);
    digitalWrite(A2, HIGH);
    pinMode(A3, OUTPUT);
    digitalWrite(A3, HIGH);
  button1.attachLongPressStart(ring1);
  button2.attachLongPressStart(ring2);
  button3.attachLongPressStart(ring3);
  button4.attachLongPressStart(ring4);
  button11.attachLongPressStop(play1);
  button12.attachLongPressStop(play2);
  button13.attachLongPressStop(play3);
  button14.attachLongPressStop(play4);
  //button1.attachLongPressStop(stop);
  //button2.attachLongPressStop(stop);
  //button3.attachLongPressStop(stop);
  //button4.attachLongPressStop(stop);
  button11.attachLongPressStart(stop);
  button12.attachLongPressStart(stop);
  button13.attachLongPressStart(stop);
  button14.attachLongPressStart(stop);
  button1.setPressTicks(100);
  button2.setPressTicks(100);
  button3.setPressTicks(100);
  button4.setPressTicks(100);
  myDFPlayer.begin(FPSerial,true, true);
   digitalWrite(A0, LOW);
   digitalWrite(A1, LOW);
   digitalWrite(A2, LOW);
   digitalWrite(A3, LOW);
   delay(2000);
      stop();
    /*
    Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
    
  }*/
   myDFPlayer.enableDAC(); 
    //myDFPlayer.outputSetting(true, 15);
   // Serial.print(1);
    myDFPlayer.volume(30);
      
     // myDFPlayer.loop(1);
      
}

void loop() {
button1.tick();
button2.tick();
button3.tick();
button4.tick();
button11.tick();
button12.tick();
button13.tick();
button14.tick();
button1.tick();
button2.tick();
button3.tick();
button4.tick();
if (timer ==millis()) stop();
}
void stop(){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    state = 0;
    myDFPlayer.stop();

}
// put function definitions here:
void ring1(){
switch (state)
{
case 0:
    timer = millis()+15000;
    digitalWrite(A0, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.loop(5);
    state = 1;
    break;

default:
    stop();
    break;
}
}
void ring2(){
switch (state)
{
case 0:
    timer = millis()+15000;
    digitalWrite(A1, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.loop(5);
    state = 1;
    break;

default:
    stop();

    break;
}
}

void ring3(){
switch (state)
{
case 0:
    timer = millis()+15000;
    digitalWrite(A2, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.loop(5);
    state = 1;
    break;

default:
    stop();

    break;
}
}
void ring4(){
switch (state)
{
case 0:
    timer = millis()+15000;
    digitalWrite(A3, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.loop(5);
    state = 1;
    break;

default:
    stop();

    break;
}
}

void play1(){
  timer = millis()+15000;
    myDFPlayer.stop();
    myDFPlayer.volume(vol2);
  myDFPlayer.play(1);
}
void play2(){
  timer = millis()+15000;
    myDFPlayer.stop();
    myDFPlayer.volume(vol2);
  myDFPlayer.play(2);
}
void play3(){
  timer = millis()+15000;
    myDFPlayer.stop();
    myDFPlayer.volume(vol2);
  myDFPlayer.play(3);
}
void play4(){
  timer = millis()+15000;
    myDFPlayer.stop();
    myDFPlayer.volume(vol2);
  myDFPlayer.play(4);
}