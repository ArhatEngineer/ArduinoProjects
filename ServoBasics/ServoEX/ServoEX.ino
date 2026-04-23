#include <Servo.h>
Servo servo1;

int servoPin = 9;
int minPWM = 500;
int maxPWM = 2500;
void setup() {
  servo1.attach(servoPin,minPWM,maxPWM);
  // put your setup code here, to run once:

}

void loop() {
  servo1.write(0);
  delay(1000);
   servo1.write(90);
  delay(1000);
   servo1.write(180);
  delay(1000);
  // put your main code here, to run repeatedly:

}
