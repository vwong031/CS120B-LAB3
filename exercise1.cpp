/*
* Name & Email: Valerie Wong (vwong031@ucr.edu)
* Discussion Section: 021
* Assignment: Lab 3 Exercise 1
* Exercise Description: The potentiometer will light up 0-4 LEDs based on the strength of the reading. 
*                       When the reading of the photoresistor is bright, the functionality is ON,
*                       else if the reading of the photoresistor is dark, the functionality is OFF.

* I acknowledge all content contained herein, excluding template 
  or example code, is my own original work.

* Demo Link: https://youtu.be/m0taMxzxV4E
*/
int B[4] = {2, 3, 4, 5};
int rlp = 9;
int blp = 10;
int glp = 11;

void setup() {
  pinMode(rlp, OUTPUT);
  pinMode(glp, OUTPUT);
  pinMode(blp, OUTPUT);
  
  for (int i = 0; i < 4; ++i) {
    pinMode(B[i], OUTPUT);
  }
  Serial.begin(9600);
}

enum States {INIT, OFF, ON} state = INIT;

void turnOFF(int val) {
  for (int i = 4; i >= val; --i) {
    digitalWrite(B[i], LOW);
  }
}

void lightLEDs(int val) {
  for (int i = 0; i < val; ++i) {
    digitalWrite(B[i], HIGH);
  }
}

void ledOFF() {
  for (int i = 0; i < 4; ++i) {
    digitalWrite(B[i], LOW);
  }
}

void readPotentiometer() {
  int val = analogRead(A0);
  
  val = map(val, 0, 1023, 0, 4);
  
  lightLEDs(val);
  turnOFF(val);
}

bool readPhotoresistor() {
  int val = analogRead(A1);
  Serial.println(val);
  bool isBright = true;
  
  if (val < 130) {
     isBright = false;
  }
  
  return isBright;
}

// This function takes in the state as an argument & returns the current state
void Tick() {

  switch (state) { // State transitions

    case INIT:
      //State Transition
      state = OFF;
      break;

    case OFF:
      // If photoresistor bright, stay OFF
      // If photoresistor dark, transition to ON    
      if (readPhotoresistor()) {
        state = ON;
      }
      break;

    case ON:
      // If photoresistor dark, stay ON
      // If photoresistor bright, transition to OFF
    if (!readPhotoresistor()) {
        state = OFF;
      }
      //State Transition
      break;
    default:
      break;
  }

  switch (state) { // State Action

    case INIT:
      //State Action
      break;

    case OFF:
      //State Action
      // Turn all LEDs off
      // Disregard potentiometer
      ledOFF();
      break;

    case ON:
      //State Action
      // Read in value of potentiometer & turn on that many LEDs
      readPotentiometer();
      break;
  }
}

void loop() {

  ///Default arduino function

 
  Tick();
}
