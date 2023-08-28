#include <Arduino.h>
#if !defined(UBRR1H)
#include <FireTimer.h>
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>
//#include <DFRobotDFPlayerMini.h>
SoftwareSerial mySerial(4, 0); // RX, TX
#endif
DFPlayerMini_Fast myDFPlayer;
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
unsigned long timer = 0;
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
  button1.setPressTicks(50);
  button2.setPressTicks(50);
  button3.setPressTicks(50);
  button4.setPressTicks(50);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);

#if !defined(UBRR1H)
  mySerial.begin(9600);
  delay(1000);
  
  myDFPlayer.begin(mySerial, true);
#else
  Serial1.begin(9600);
  myMP3.begin(Serial1, true);
#endif
   delay(1000);
      stop();
    
  //myDFPlayer.outputSetting(true, 15);
   // Serial.print(1);
    myDFPlayer.volume(30);
    //myDFPlayer.normalMode();
  
      
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

if ((timer+15000)<millis()) {
  stop();
}
}
void stop(){
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    state = 0;
    //if (timer != 0) myDFPlayer.stop();
    timer = 0;
    
}
// put function definitions here:
void ring1(){
switch (state)
{
case 0:
    stop();
    timer = millis();
    digitalWrite(A0, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.playFolder(01, 05);
    state = 1;
    break;

default:
    stop();
    state = 0;
    break;
}
}
void ring2(){
switch (state)
{
case 0:
  
    stop();
    timer = millis();
    digitalWrite(A1, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.playFolder(01, 05);
    state = 1;
    break;

default:
state = 0;
    stop();

    break;
}
}

void ring3(){
switch (state)
{
case 0:
    stop();
    timer = millis();
    digitalWrite(A2, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.playFolder(01, 05);
    state = 1;
    break;

default:
    state = 0;   stop();

    break;
}
}
void ring4(){
switch (state)
{
case 0:
    stop();
    timer = millis();
    digitalWrite(A3, LOW);
    myDFPlayer.volume(vol1);
    myDFPlayer.playFolder(01, 05);
    state = 1;
    break;

default:
state = 0;
    stop();

    break;
}
}

void play1(){
 //if (timer != 0) myDFPlayer.stop();
  timer = millis()+30000;
    myDFPlayer.volume(vol2);
  myDFPlayer.playFolder(1, 1);
}
void play2(){
  //if (timer!=0) myDFPlayer.stop();
  timer = millis()+30000;
    myDFPlayer.volume(vol2);
  myDFPlayer.playFolder(01, 02);
}
void play3(){
  //if (timer != 0) myDFPlayer.stop();
  timer = millis()+30000;
    myDFPlayer.volume(vol2);
  myDFPlayer.playFolder(01, 03);
}
void play4(){
  
  //if (timer != 0) myDFPlayer.stop();
  timer = millis()+30000;
    myDFPlayer.volume(vol2);
  myDFPlayer.playFolder(01, 04);
} 