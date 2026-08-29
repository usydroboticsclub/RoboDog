#include <Servo.h>
Servo myServo;
const int servoPin = 9;
void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(90);  // Start centred
  Serial.println("MG90S servo control");
  Serial.println("Enter an angle from 0 to 180:");
}
void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();
    // Remove any remaining newline characters
    while (Serial.available() > 0) {
      Serial.read();
    }
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);
      Serial.print("Moving servo to ");
      Serial.print(angle);
      Serial.println(" degrees");
    } else {
      Serial.println("Invalid angle. Enter a value from 0 to 180.");
    }
  }
}

