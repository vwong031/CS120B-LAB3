/*
* Name & Email: Valerie Wong
* Discussion Section: 021
* Assignment: Lab 3 Exercise 3
* Exercise Description: 

* I acknowledge all content contained herein, excluding template 
  or example code, is my own original work.

* Demo Link: https://youtu.be/grt_V0q7kLc
*/
int B[4] = {5, 4, 3, 2};
int rlp = 9;
int blp = 10;
int glp = 11;

unsigned char val_red;
unsigned char val_green;
unsigned char val_blue;

void setup() {
  pinMode(rlp, OUTPUT);
  pinMode(glp, OUTPUT);
  pinMode(blp, OUTPUT);
  
  for (int i = 0; i < 4; ++i) {
    pinMode(B[i], OUTPUT);
  }
  Serial.begin(9600);
}

enum States {INIT, LED_ON, CYCLE } state = INIT;

float mapping(float x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void generateCycle() {
  float red = sin((float)millis()/400);
  float green = sin((float)millis()/400 + (float)2*PI/3);
  float blue = sin((float)millis()/400 + (float)4*PI/3);
  
  val_red = mapping(red, -1, 1, 0, 255);
  val_green = mapping(green, -1, 1, 0, 255);
  val_blue = mapping(blue, -1, 1, 0, 255);
}

// Turn off LEDs based on potentiometer reading
void turnOFF(int val) {
  for (int i = 4; i >= val; --i) {
    digitalWrite(B[i], LOW);
  }
}

// Turn off RGB Light
void rgbOFF() {
  analogWrite(rlp, 0);
  analogWrite(glp, 0);
  analogWrite(blp, 0);
}

// Light LEDs based off potentiometer reading
void lightLEDs(int val) {
  for (int i = 0; i < val; ++i) {
    digitalWrite(B[i], HIGH);
  }
}

// Turn off ALL LEDs
void ledOFF() {
  for (int i = 0; i < 4; ++i) {
    digitalWrite(B[i], LOW);
  }
}

// Control LEDs based on potentiometer reading
void readPotentiometer() {
  int val = analogRead(A0);
  
  val = map(val, 0, 1023, 0, 4);
  
  lightLEDs(val);
  turnOFF(val);
}

// If true, LEDs ON, else RGB light ON
bool readPhotoresistor() {
  int val = analogRead(A1);
  Serial.println(val);
  bool isBright = true;
  
  if (val < 155) {
  	 isBright = false;
  }
  
  return isBright;
}

// This function takes in the state as an argument & returns the current state
void Tick() {

  switch (state) { // State transitions

    case INIT:
      //State Transition
      state = LED_ON;
      break;

    case LED_ON:
      // If photoresistor bright, stay ON
      // If photoresistor dark, transition to RED    
      if (!readPhotoresistor()) {
        state = RED;
        ledOFF();
      }
      break;

    case CYCLE:
      // If photoresistor dark, continue cycling through colors
      // If photoresistor bright, transition to LED
	  if (readPhotoresistor()) {
        state = LED_ON;
        rgbOFF();
      }
      break;

    default:
      break;
  }

  switch (state) { // State Action

    case INIT:
      //State Action
      break;

    case LED_ON:
      //State Action
      // Read in value of potentiometer & turn on that many LEDs
      readPotentiometer();
      break;

    case CYCLE:
      //State Action
      generateCycle();
      analogWrite(rlp, val_red);
      analogWrite(glp, val_green);
      analogWrite(blp, val_blue);
      break;

    default:
      break;
  }
}

void loop() {

  ///Default arduino function

 
  Tick();
}
