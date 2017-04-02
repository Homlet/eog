#include <Servo.h>

#define PIN_EOG A1

#define ALPHA 0.9921875

float mean = 0;
float dev = 0;
int cycle = 0;

void setup() {
  // Stub.
}

void loop() {
  // Exponential running average of value (low-pass filter).
  int value = analogRead(PIN_EOG);
  int off = value - mean;
  mean = ALPHA * mean + (1 - ALPHA) * value;
  dev = ALPHA * dev + (1 - ALPHA) * off;

  // Output the values every 50 cycles.
  cycle++;
  if (cycle == 50) {
    Serial.print(mean);
    Serial.print(":");
    Serial.println(dev);
    cycle = 0;
  }
}

