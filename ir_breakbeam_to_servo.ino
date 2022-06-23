/* 
  IR Breakbeam sensor demo!
*/

#define LEDPIN 13
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

#define SENSORPIN 4
#include <Servo.h> //import Servo Motor Libraries


// variables will change:
Servo myservo;
int sensorState = HIGH, lastState = HIGH;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  Serial.begin(9600);
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  myservo.attach(9);
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  Serial.println(sensorState);
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  /*if (sensorState == LOW) {     
    digitalWrite(LEDPIN, HIGH);
    myservo.write(0);  
    Serial.println("Broken"); 
    delay(1000);
  } 
  else {
    digitalWrite(LEDPIN, LOW);
    myservo.write(170);
    Serial.println("Unbroken");
    delay(1000);
  }*/
  
  if (sensorState && !lastState) {
    myservo.write(0);
    digitalWrite(LEDPIN, LOW);
    Serial.println("Unbroken");
    delay(1000);
  } 
  if (!sensorState && lastState) {
    myservo.write(170); 
    digitalWrite(LEDPIN, HIGH); 
    Serial.println("Broken");
    delay(1000);
  }
  lastState = sensorState;
}
