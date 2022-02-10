#include <Arduino.h>
#include <Servo.h>

//see the explaination for this in ArduinoBots 9.1
int right = 1590;
int left = 1300;

//variables for the pins
int pinright = 12;
int pinleft = 13;

//def servos
Servo servoright;
Servo servoleft;

void setup() {
  //start the serial monitor.
  Serial.begin(9600);
  
  //set pins
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(2, OUTPUT);

}

void backUp(){
  //go in reverse for 0.5 seconds
  servoright.writeMicroseconds(left);
  servoleft.writeMicroseconds(right);
  delay(2000);

  //turn for 0.25 seconds
  servoright.writeMicroseconds(left);
  servoleft.writeMicroseconds(left);
  delay(1000);
}

void loop() {
  //read pins
  byte leftWhisker = digitalRead(3);
  byte rightWhisker = digitalRead(4);

  //setup the motor pins
  servoright.attach(pinright);
  servoleft.attach(pinleft);

  //print them out :>
  Serial.println(leftWhisker);
  Serial.println(rightWhisker);
  Serial.println("\n");

  //check if you bumped!
  if (leftWhisker == 0 || rightWhisker == 0){
    //enable the LED
    digitalWrite(2,HIGH);
    //back up and move
    backUp();
    //turn off LED
    digitalWrite(2, LOW);
  }

  //go straight for a bit, until it is checking time again
  servoright.writeMicroseconds(right);
  servoleft.writeMicroseconds(left);

  //make sure you don't overwhelm the CPU
  delay(100);
  
}