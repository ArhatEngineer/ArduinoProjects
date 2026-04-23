#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLD_RESET -1


Servo servo1;

int servoPin = 9;
int potPin = A0;
int minPWM = 500;
int maxPWM = 2500;
int lastValue = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(200);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(60, 16);
  display.println("Begin!!");
  display.display();
  
  
  //servo setup
  servo1.attach(servoPin, minPWM, maxPWM);
}

void loop() { 
  int currentval = analogRead(potPin);
  int angle = map(currentval,0,1023,0,180);
  servo1.write(angle);

  if(currentval > (lastValue + 2)) {
  Serial.println("Hot!!");
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(60, 16);
  display.println("Hot!!");
  display.display();
  }


  if(currentval < (lastValue - 2)) {
  Serial.println("Cold!!");
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(60, 16);
  display.println("Cold!!");
  display.display();
  }

  lastValue = currentval;

  delay(10);

}
