#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Default PCA9685 I2C address
Adafruit_PWMServoDriver pca9685(0x40);

const int servoFrequency = 50;

// Conservative MG90S pulse range
const int minimumPulseUS = 550;
const int maximumPulseUS = 2500;

void moveServo(int channel, int angle)
{
  angle = constrain(angle, 0, 180);

  // Convert angle into pulse width
  int pulseUS = map(
    angle,
    0, 180,
    minimumPulseUS, maximumPulseUS
  );

  // Convert microseconds into PCA9685 counts (0–4095)
  int pulseCount =
      (long)pulseUS * servoFrequency * 4096L / 1000000L;

  pca9685.setPWM(channel, 0, pulseCount);
}

void standdog()
{
  // Laterial shoulder joint
  moveServo(0, 90);
  moveServo(4, 90);
  moveServo(8, 90);
  moveServo(12, 90);
  // plane shoulder joint
  moveServo(1, 60); //Left Front
  moveServo(5, 120); //Right Front
  moveServo(9, 60); //Left Back
  moveServo(13,120); //Right Back
  // elbow joint
  moveServo(2, 90);
  moveServo(6, 90);
  moveServo(10, 90);
  moveServo(14, 90);
}

void sitdog()
{
  // Laterial shoulder joint

  moveServo(0, 90); 
  moveServo(4, 90);
  moveServo(8, 90);
  moveServo(12, 90);

  // plane shoulder joint
  moveServo(1, 0); //Left Front
  moveServo(5, 180); //Right Front
  moveServo(9, 0); //Left Front
  moveServo(13, 180); //Right Front

  // elbow joint
  moveServo(2, 0);  //Left Front
  moveServo(6, 178); //Right Front
  moveServo(10, 3); //Left Back
  moveServo(14, 180); //Right Back
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  pca9685.begin();
  pca9685.setPWMFreq(servoFrequency);

  delay(10);

  Serial.println("To make the dawg stand, enter 1");
  Serial.println("To make the dawg sit, enter 0");

}

void loop()
{
  if (Serial.available() > 0)
  {
    int command = Serial.parseInt()



    if (command == 1) {
      Serial.println("Making dog stand.");
      standdog();
    }

    if (command 0) {
      Serial.println("Making dog sit.");
      sitdog();
    }

  }
}
