# CS120B-LAB3

## Wiring Diagram
![image](https://user-images.githubusercontent.com/74090811/206831708-08377d4b-c0a2-495f-ae79-38685e279a5d.png)

## Exercise 1:
The potentiometer reading will be mapped to the integer range 0-4 (rather than 0-15), and will light up 0-4 of the red LEDs based on the strength of the reading. 

On/Off Functionality:
* When the reading from the photoresistor is 'bright' the system will be 'On'
* When the system is 'On' you can control the LEDs with the potentiometer
* When the reading from the photoresistor is 'dark' the system will be 'Off'
* When the system is 'Off,' the LEDs will remain off regardless of the potentiometer reading

You will determine the photoresistor thresholds for 'dark' and 'bright' based on the environment where you implement this exercise.

Demo Link: https://youtu.be/m0taMxzxV4E

## Exercise 2:
You will make the RGB LED cycle through its colors.

Demo Link: https://youtu.be/2-nZnYo-kt0

## Exercise 3:
You will create a lighting system for a child's bedroom. The light system contains a four-LED light controlled by the potentiometer and an RGB nightlight.

When the reading from the photoresistor is 'bright' the nightlight should turn off and the four LEDs should be be controlled by the potentiometer as in Exercise 1

When the reading from the photoresistor is 'dark' the four LEDs turn off, the potentiometer is ignored, and the RGB nightlight turns on and cycles through its colors as in Exercise 2.

Note: Not sure why the first 3 LEDs aren’t as bright 😓

Demo Link: https://youtu.be/grt_V0q7kLc

