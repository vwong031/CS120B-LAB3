/*
* Name & Email: Valerie Wong
* Discussion Section: 021
* Assignment: Lab 3 Exercise 2
* Exercise Description: Make RGB light cycle through its colors

* I acknowledge all content contained herein, excluding template 
  or example code, is my own original work.

* Demo Link: https://youtu.be/2-nZnYo-kt0
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

enum States {INIT, RED, GREEN, BLUE} state = INIT;

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


// This function takes in the state as an argument & returns the current state
void Tick() {

  switch (state) { // State transitions

    case INIT:
      //State Transition
      state = RED;
      break;

    case RED:
      state = (millis() % 500 == 0) ? GREEN : RED;
      break;

    case GREEN:
      //State Transition
      state = (millis() % 500 == 0) ? BLUE : GREEN;
      break;
    
    case BLUE:
      state = (millis() % 500 == 0) ? RED : BLUE;
      break;
    
    default:
      break;
  }

  switch (state) { // State Action

    case INIT:
      //State Action
      break;

    case RED:
      //State Action
      generateCycle();
      analogWrite(rlp, val_red);
      analogWrite(glp, val_green);
      analogWrite(blp, val_blue);
      break;

    case GREEN:
      //State Action
      generateCycle();
      analogWrite(rlp, val_red);
      analogWrite(glp, val_green);
      analogWrite(blp, val_blue);
      break;
    
    case BLUE:
      generateCycle();
      analogWrite(rlp, val_red);
      analogWrite(glp, val_green);
      analogWrite(blp, val_blue);
      break;
  }
}

void loop() {

  ///Default arduino function

 
  Tick();
}
