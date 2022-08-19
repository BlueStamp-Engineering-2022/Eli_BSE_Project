# Obstacle avoiding robot
This robot avoids obstacles by detection from a ultrasonic sensor, which can detect objects through sound waves. The ultrasonic sensor is attached to a servo by a 3D printed attachment. This information gets transferred to an Arduino UNO that will make a decision whether or not an object has been detected. Then with the motor driver being connected to the Arduino, the motor driver will receive the information and turn accordingly. To break down the code: the robot starts by moving forward. The distance from the closest object will be returned. If the distance of this object is less than 40 cm, the servo will turn the ultrasonic sensor left and right while getting distances from both sides. If the distance on left side is greater than 40 cm, the robot will turn in that direction. Otherwise the servo will move ultrasonic sensor to the right side and if that distance is less than 40 cm, the robot will turn. If there's an object in both directions, the robot will back up and check the distances again.

| Eli | Monta Vista High | Mechanical engineering | Incoming Senior |
|:--:|:--:|:--:|:--:|
  
# Final Milestone
My final milestone was making some changes to how the robot responded to the obstacles in the code. Although the robot avoided obstacles, it did not go back to its original direction, and I wanted to make sure the robot did that. I had some issues initially making that code concise because the computer did not understand. Once I strategized and did some more pseudocode, I was able to go about this more methodically, and I was able to achieve the desired result of the robot.


[![Final Milestone](https://i3.ytimg.com/vi/JuZjTQxcPFg/maxresdefault.jpg)](https://www.youtube.com/watch?v=JuZjTQxcPFg){:target="_blank" rel="noopener"}

# Second Milestone
My second milestone was syncing up the ultrasonic sensor with the wheels. The robot parts consisted of wheels along with the wheel motors, servo, motor driver, and ultrasonic sensor. I had issues with the motor driver due to improper wiring of it. Since I had no issues with the syncing of the ultrasonic sensor, the wheels were able to react accordingly to the signal from the ultrasonic sensor.

[![Second Milestone](https://i3.ytimg.com/vi/SMfc3sqW4As/maxresdefault.jpg)](https://www.youtube.com/watch?v=SMfc3sqW4As){:target="_blank" rel="noopener"}
# First Milestone
  

My first milestone was assembling the parts of the robot and make sure that they worked individually. The robot parts consisted of wheels along with the wheel motors, servo, motor driver, and ultrasonic sensor. I had issues with the ultrasonic sensor due to incorrect code as well as issues with downloading the library. The ultrasonic sensor was not printing the values it was supposted to do. After a bit of trial and error, I saw that the way I had wired the ultrasonic sensor and the way I had coded it was incorrect. Once I had that corrected the ultrasonic sensor worked.

[![First Milestone](http://i3.ytimg.com/vi/wvDvka75ShQ/hqdefault.jpg)](https://www.youtube.com/watch?v=wvDvka75ShQ "First milestone"){:target="_blank" rel="noopener"}
# Starter Project

My starter project was a customizable Arduino project that consisted of an IR breakbeam and a servo motor. When the IR breakbeam detects an object like a hand, this info will be sent to the servo where it will move 170 degrees
[![Starter Project](https://user-images.githubusercontent.com/69122710/174345371-3a62341b-28e7-43f3-bd80-5abbd103eb37.png)](https://www.youtube.com/watch?v=yVBOp2GziYg "Starter Project"){:target="_blank" rel="noopener"}
