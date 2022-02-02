#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#define echoPin 7 
#define trigPin 8

long duration, distance;
int sensorCounter = 0;

void setup(){
  Serial.begin(9600);
  lcd.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  lcd.home();
  lcd.print("Counter: ");
  lcd.print(sensorCounter);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  if (distance <= 20) {
    sensorCounter++;
  }
}
