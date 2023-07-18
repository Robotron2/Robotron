#include <AFMotor.h>
//Define the sensor pins
#define sensorOneTrig A0
#define sensorTwoTrig A1
#define sensorThreeTrig A2
#define sensorOneEcho A3
#define sensorTwoEcho A4
#define sensorThreeEcho A5
//Set the speed of the motors in rpm
#define Speed 200

//Create objects for the motors from the AFmotor library
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
  //Set the Trig pins as output pins
  pinMode(sensorOneTrig, OUTPUT);
  pinMode(sensorTwoTrig, OUTPUT);
  pinMode(sensorThreeTrig, OUTPUT);
  
  //Set the Echo pins as input pins
  pinMode(sensorOneEcho, INPUT);
  pinMode(sensorTwoEcho, INPUT);
  pinMode(sensorThreeEcho, INPUT);
  //Set the speed of the motors
  
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
}

void loop() {
  int centerSensor = sensorTwo();
  int leftSensor = sensorOne();
  int rightSensor = sensorThree();
// Check the distance using the IF condition
  if (50 >= centerSensor) {
    Stop();
    Serial.println("Stop");
    delay(300);
    if (leftSensor > rightSensor) {
      //turn left
      left();
      Serial.println("Left");
      delay(500);
    } else {
      //turn right
      right();
      Serial.println("Right");
      delay(500);
    }
  }
  Serial.println("Forward");
  //move forward by default.
  forward();
}

//////////////////////////////////////////////////////////////////Function to get the sensor values////////////////////////////////////////////////////////////////////////////////////////////////////

//Get sensorOne output
int sensorOne() {
  //pulse output
  digitalWrite(sensorOneTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorOneTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorOneTrig, LOW);

  long t = pulseIn(sensorOneEcho, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}

 //Get sensorTwo output
int sensorTwo() {
  //pulse output
  digitalWrite(sensorTwoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTwoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTwoTrig, LOW);

  long t = pulseIn(sensorTwoEcho, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}

//Get sensorThree output
int sensorThree() {
  //pulse output
  digitalWrite(sensorThreeTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorThreeTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorThreeTrig, LOW);

  long t = pulseIn(sensorThreeEcho, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}

///////////////////////////////////////////////////////////////////////////Motor Functions//////////////////////////////////////////////////////////////////
void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void left() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void right() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
