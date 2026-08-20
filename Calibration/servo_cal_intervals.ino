#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
}

void loop() {

  servo.write(0);
  Serial.println(0);
  delay(10000);

  servo.write(60);
  Serial.println(60);
  delay(10000);

  servo.write(90);
  Serial.println(90);
  delay(10000);

  servo.write(120);
  Serial.println(120);
  delay(10000);

  servo.write(180);
  Serial.println(180);
  delay(10000);
}