/* Servo motor with Arduino example code. Position and sweep. More info: https://www.makerguides.com/ */

// Include the servo library:
#include "Servo.h"
// #include <MPU9250_asukiaaa.h>
// #include <MadgwickAHRS.h>
// #include <Wire.h>

// MPU9250_asukiaaa mySensor;
// Madgwick filter;
// Create a new servo object:
Servo servoX;
Servo servoY;

// Define the servo pin:
#define xServoPin 9
#define yServoPin 10

// float xTestVals[] = { 100, 115, 125, 150, 120, 95, 65, 30, 80 };
// float yTestVals[] = { 160, 180, 130, 110, 90, 60, 20, 95, 120 };
// float xTestVals[] = { 20, 40, 60, 70, 60, 40, 30, 0 };
// float yTestVals[] = { 20, 40, 60, 70, 60, 40, 20, 0 };
//static const float xTestVals = [15, 45, 75, 45, 15, 0];
//static const float yTestVals = [20, 60, 80, 60, 20, 0];
float xTestVals[] = { 12, 20, 20, 20, 25, 25, 30, 20, 15, 10, 4, 5, 5, 8, 5, 5, 5};
float yTestVals[] = { 170, 170, 160, 165, 155, 155, 165, 168, 172, 170, 170, 172, 170, 170, 170 };
float xServoStart;
float yServoStart;
int maxLoops = 2;
int loopIndex = 0;

void setup() {
  Serial.begin(9600);
  // Wire.begin();
  // filter.begin(200);

  // mySensor.setWire(&Wire);
  // mySensor.beginAccel();
  // mySensor.beginGyro();
  // mySensor.beginMag();


  // Attach the Servo variable to a pin:
  servoX.attach(xServoPin);
  servoY.attach(yServoPin);
  xServoStart = 5;
  yServoStart = 170;
  servoY.write((float)yServoStart);
  delay(1000);
  servoX.write((float)xServoStart);
  delay(10000); // 10 second countdown to ignite rocket before test simulation values are pushed through
}

void loop() {
  // mySensor.accelUpdate();
  // mySensor.gyroUpdate();
  // mySensor.magUpdate();

  // float accelX = mySensor.accelX();
  // float accelY = mySensor.accelY();
  // float accelZ = mySensor.accelZ();

  // float gyroX = mySensor.gyroX();
  // float gyroY = mySensor.gyroY();
  // float gyroZ = mySensor.gyroZ();

  // float magX = mySensor.magX();
  // float magY = mySensor.magY();
  // float magZ = mySensor.magZ();

  // filter.update(gyroX, gyroY, gyroZ, accelX, accelY, accelZ, magX, magY, magZ);

  // Serial.print("accelX:");Serial.println(mySensor.accelX());
  // Serial.print("accelY:");Serial.println(mySensor.accelY());
  // Serial.print("accelZ:");Serial.println(mySensor.accelZ());

  // Serial.print("gyroX:");Serial.println(mySensor.gyroX());
  // Serial.print("gyroY:");Serial.println(mySensor.gyroY());
  // Serial.print("gyroZ:");Serial.println(mySensor.gyroZ());

  // float pitch = filter.getPitch();
  // float yaw = filter.getYaw();
  // float roll = filter.getRoll();

  // Serial.print("Pitch:");Serial.print(pitch);Serial.print(" Yaw:");Serial.print(yaw);Serial.print(" roll:");Serial.println(roll);

  // Tell the servo to go to a particular angle:
  while (loopIndex < maxLoops) {
    for(int i=0; i < 15; i++) {
      servoY.write(yTestVals[i]);
      Serial.print("Servo Y:");Serial.println(yTestVals[i]);
      delay(250);
      servoX.write(xTestVals[i]);
      Serial.print("Servo X:");Serial.println(xTestVals[i]);
      delay(200);
    }
    servoY.write(yServoStart);
    delay(200);
    servoX.write(xServoStart);
    Serial.print("Resetting servos to x:");Serial.print(xServoStart);Serial.print(" y:");Serial.println(yServoStart);
    delay(100);
    loopIndex++;
  }

  // Serial.println("Finished, holding mode.");
  // delay(20000);
}