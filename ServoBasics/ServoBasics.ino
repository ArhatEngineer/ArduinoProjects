
#include <Servo.h>

Servo myservo;

int potPin = A0;
int servoPin = 9;
int minPWM = 500;
int maxPWM = 2500;
//Analog pin for potentimeter


void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin, minPWM, maxPWM);  //min pulse width is 500, max is 2500 where 1000 to 2000 is counterclockwise
}

void loop() {
  // put your main code here, to run repeatedly:
  int read = analogRead(potPin);
  int angle = map(read, 0, 1023, 0, 180);
  myservo.write(angle);
}
