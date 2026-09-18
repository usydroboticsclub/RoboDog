#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Default PCA9685 I2C address
Adafruit_PWMServoDriver pca9685(0x40);

const int servoFrequency = 50;

// Conservative MG90S pulse range
const int minimumPulseUS = 1000;
const int maximumPulseUS = 2000;

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

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  pca9685.begin();
  pca9685.setPWMFreq(servoFrequency);

  delay(10);

  Serial.println("PCA9685 serial servo controller");
  Serial.println("Enter: channel angle");
  Serial.println("Example: 3 120");
  Serial.println("Channels: 0-15");
  Serial.println("Angles: 0-180");
}

void loop()
{
  if (Serial.available() > 0)
  {
    int channel = Serial.parseInt();
    int angle = Serial.parseInt();

    // Remove newline and any remaining characters
    while (Serial.available() > 0)
    {
      Serial.read();
    }

    if (channel < 0 || channel > 15)
    {
      Serial.println("Invalid channel. Enter 0-15.");
      return;
    }

    if (angle < -360 || angle > 360)
    {
      Serial.println("Invalid angle. Enter 0-180.");
      return;
    }

    moveServo(channel, angle);

    Serial.print("Servo on channel ");
    Serial.print(channel);
    Serial.print(" moved to ");
    Serial.print(angle);
    Serial.println(" degrees.");
  }
}