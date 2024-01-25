#include <Wire.h>
#include <Servo.h>
#include <MPU6050.h>

MPU6050 mpu;

Servo myservo;  

int servoPin = 9;  // Servo signal pin
int angle = 90;    // Initial servo position

void setup() {
  Serial.begin(9600);

  Wire.begin();
  mpu.initialize();

  myservo.attach(servoPin);
  myservo.write(angle);  // Set initial servo position
}

void loop() {
  // Read gyro data
  int16_t gyroX = mpu.getRotationX();
  
  // Adjust the servo angle based on gyro data
  angle += gyroX / 100;  
  
  // Limit the servo angle to a reasonable range
  angle = constrain(angle, 0, 180);

  // Move the servo
  myservo.write(angle);

  // Print gyro data and servo angle to Serial Monitor
  Serial.print("GyroX: ");
  Serial.print(gyroX);
  Serial.print(" | Servo Angle: ");
  Serial.println(angle);

  delay(20);  
}
