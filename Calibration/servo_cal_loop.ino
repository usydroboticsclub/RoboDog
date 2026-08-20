 #include <Servo.h>

Servo servo;

int ranValue = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
}

void loop() {

  for (ranValue = 0; ranValue <= 360; ranValue += 10) {

    servo.write(ranValue);
    Serial.println(ranValue);
    delay(1000);
  }
}