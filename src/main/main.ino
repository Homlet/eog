#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(9);
}

void loop() {
  delay(25);
  servo.write(40);
  delay(25);
  servo.write(0);
}
