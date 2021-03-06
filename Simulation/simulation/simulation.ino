/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

const int rPin = 11;
const int gPin = 10;
const int bPin = 9;

byte colorValue[3];
byte timeTriggers[4];
typedef enum {GREEN, YELLOW, ORANGE, RED} COLOR;
const byte GREENValue[3] = {0,255,0};
const byte YELLOWValue[3] = {0,255,0};
const byte ORANGEValue[3] = {0,255,0};
const byte REDValue[3] = {0,255,0}; 

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  /* Setup digital outputs */
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  //turnOff();

  //lightHouse();
  //blink(3, GREEN);

  
}

// the loop function runs over and over again forever
void loop() {
  
  
  for (int i = 0; i<4; i++) { //56
    lightHouse(); //350 ms   
  }
  
  //delay(10000);
  blink(8,GREEN);
  //delay(5000);
  for (int i = 0; i<1; i++) {
    lightHouse(); //350 ms   
  }
  blink(8,YELLOW);
  //delay(3000);
  for (int i = 0; i<2; i++) {
    lightHouse(); //350 ms   
  }
  blink(8,ORANGE);
  //delay(2000);
  for (int i = 0; i<1; i++) {
    lightHouse(); //350 ms   
  }
  blink(100,RED);
  while (true) {
    lightHouse();
  }
  
}

void blink(int times, COLOR color) {
  switch(color) {
    case GREEN:
      //colorValue = GREENValue;
      setColor(0,255,0);
      break;
    case YELLOW:
      setColor(255,255,0);
      break;
    case ORANGE:
      setColor(218,121,18);
      break;
    case RED:
      setColor(255,0,0);
      break;
  }

  
  for (int i = 0; i<times; i++) {
    turnOn();
    delay(200);              // wait for a second
    turnOff();
    delay(200);              // wait for a second
  }
}

void turnOn() {
  analogWrite(rPin, colorValue[0]);
  analogWrite(gPin, colorValue[1]);
  analogWrite(bPin, colorValue[2]);
}

void turnOff() {
  analogWrite(rPin, 255);
  analogWrite(gPin, 255);
  analogWrite(bPin, 255);
}

void setColor(int red, int green, int blue) {
  colorValue[0] = red;
  colorValue[1] = green;
  colorValue[2] = blue;
}

void lightHouse() {
  for (int i = 50; i<255; i++) {
    analogWrite(rPin, i);
    analogWrite(gPin, i);
    analogWrite(bPin, i);
    delay(10);
  }

  delay(250);
  for (int i = 255; i>50; i--) {
    analogWrite(rPin, i);
    analogWrite(gPin, i);
    analogWrite(bPin, i);
    delay(10);
  }
  
}


