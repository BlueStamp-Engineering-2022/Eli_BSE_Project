# Obstacle avoiding robot
This robot avoids obstacles by detection to an ultrasonic sensor, which can detect objects through sound waves. Once an object is detected 20 cm away, this information will be send to a motor driver which will make the wheels turn thus avoiding the obstacle. If an object is not detected, the robot will continue to move forward.

| Eli Mitra | Monta Vista High | Mechanical engineering | Incoming Senior |
|:--:|:--:|:--:|:--:|

<details>
  <summary>
    #include "SR04.h"
#include <Servo.h>
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long dist_left, dist_right;
bool right_close, left_close;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position
const int LeftMotorForward = 8;
const int LeftMotorBackward = 7;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;
const int enA = 6;
const int enB = 3;
#define maximum_distance 200
boolean goesForward = false;

//int distance = 100;

void setup() {
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  myservo.attach(9);
}

void loop() {
  goForward();
  delay(100);
  lookLeft();
  delay(50);
  getLeftDist();
  delay(50);
  lookRight();
  delay(50);
  getRightDist();
}

void lookLeft() {
  myservo.write(180);
  delay(100);
  dist_left = sr04.Distance();
  delay(100);
  getLeftDist();
}

void lookRight() {
  Serial.println(dist_right);
  myservo.write(-180);
  delay(100);
  dist_right = sr04.Distance();
  delay(100);
  getRightDist();
}

void getLeftDist() {
    long old_val_left = dist_left;
    long new_val_left = sr04.Distance();
    if(dist_left <= 20) {
      stopRobot();
      delay(50);
      wheel90DegRight();
      delay(200);
      lookLeft();
      lookRight();
    }
    else {
      goForward();
      delay(100);
    }
    if(new_val_left > old_val_left) {
      wheel90DegLeft();
      delay(200);
      stopRobot();
      delay(100);
      goForward();
    }
}

void getRightDist() {
    long old_val_right = dist_right;
    long new_val_right = sr04.Distance();
    if(dist_right <= 20) {
      stopRobot();
      delay(50);
      wheel90DegLeft();
      delay(200);
      lookLeft();
      lookRight();
    }
    else {
      goForward();
      delay(100);
    }
    if(new_val_right > old_val_right) {
      wheel90DegRight();
      delay(200);
      stopRobot();
      delay(100);
      goForward();
    }
}

void stopRobot() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  delay(100);
}

void wheel90DegRight() {
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(100);
}

void wheel90DegLeft() {
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  delay(100);
}

void goForward() {
  analogWrite(enA, 123);
  analogWrite(enB, 123);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH); 
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW); 
  delay(100);
}
  </summary>
  details
</details>

![Headstone Image](![Screen Shot 2022-07-13 at 9 40 58 AM](https://user-images.githubusercontent.com/69122710/178787027-1a4b4926-12e6-4ac9-abe9-018458be392d.png)
)
  
# Final Milestone
My final milestone was making some changes to how the robot responded to the obstacles in the code. Although the robot avoided obstacles, it did not go back to its original direction, and I wanted to make sure the robot did that. I had some issues initially making that code concise because the computer did not understand. Once I strategized and did some more pseudocode, I was able to go about this more methodically, and I was able to achieve the desired result of the robot.


[![Final Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1612573869/video_to_markdown/images/youtube--F7M7imOVGug-c05b58ac6eb4c4700831b2b3070cd403.jpg )](https://www.youtube.com/watch?v=F7M7imOVGug&feature=emb_logo "Final Milestone"){:target="_blank" rel="noopener"}

# Second Milestone
My second milestone was syncing up the ultrasonic sensor with the wheels. The robot parts consisted of wheels along with the wheel motors, servo, motor driver, and ultrasonic sensor. I had issues with the motor driver due to improper wiring of it. Since I had no issues with the syncing of the ultrasonic sensor, the wheels were able to react accordingly to the signal from the ultrasonic sensor.

[![Second Milestone](https://i3.ytimg.com/vi/SMfc3sqW4As/maxresdefault.jpg)](https://www.youtube.com/watch?v=SMfc3sqW4As){:target="_blank" rel="noopener"}
# First Milestone
  

My first milestone was assembling the parts of the robot and make sure that they worked individually. The robot parts consisted of wheels along with the wheel motors, servo, motor driver, and ultrasonic sensor. I had issues with the ultrasonic sensor due to incorrect code as well as issues with downloading the library. The ultrasonic sensor was not printing the values it was supposted to do. After a bit of trial and error, I saw that the way I had wired the ultrasonic sensor and the way I had coded it was incorrect. Once I had that corrected the ultrasonic sensor worked.

[![First Milestone](http://i3.ytimg.com/vi/wvDvka75ShQ/hqdefault.jpg)](https://www.youtube.com/watch?v=wvDvka75ShQ "First milestone"){:target="_blank" rel="noopener"}
# Starter Project

My starter project was a customizable Arduino project that consisted of an IR breakbeam and a servo motor. When the IR breakbeam detects an object like a hand, this info will be sent to the servo where it will move 170 degrees
[![Starter Project](https://user-images.githubusercontent.com/69122710/174345371-3a62341b-28e7-43f3-bd80-5abbd103eb37.png)](https://www.youtube.com/watch?v=yVBOp2GziYg "Starter Project"){:target="_blank" rel="noopener"}
