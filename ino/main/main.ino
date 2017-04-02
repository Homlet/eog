#include <Servo.h>

#define PIN_EOG A1
#define PIN_SERVO 9

#define SPEED 2
#define ALPHA 0.9921875

enum Direction {
  LEFT,
  NONE,
  RIGHT
};

int offset(Direction dir) {
  switch(dir){
    case LEFT: return -SPEED;
    case RIGHT: return SPEED;
    default:
    case NONE: return 0;
  }
}

Servo servo;
float mean = 0;
float dev = 0;
int cycle = 0;
Direction movement = NONE;

void setup() {
  //servo.attach(PIN_SERVO);
}

void loop() {
  // Exponential running average of value (low-pass filter).
  int value = analogRead(PIN_EOG);
  int off = value - mean;
  mean = ALPHA * mean + (1 - ALPHA) * value;
  dev = ALPHA * dev + (1 - ALPHA) * off;

//  // Detect if movement happened.
//  if (inst_dev > 2 * dev) {
//    if (value - mean > 1) {
//      movement = LEFT;
//    } else {
//      movement = RIGHT;
//    }
//  }

  // Output the values every 50 cycles.
  cycle++;
  if (cycle == 50) {
    Serial.print(mean);
    Serial.print(":");
    Serial.println(dev);
    cycle = 0;
//    movement = NONE;
  }
}

