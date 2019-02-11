#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

const int lrPin = 4;
const int udPin = 2;

int xPos = 0;
int yPos = 00;

#define D3 0;

const int laser = D3;

Servo servoX;
Servo servoY;

void ledOn() {
  digitalWrite(laser, HIGH);
}

void ledOff() {
  digitalWrite(laser, LOW);
}

void moveRight() {
  xPos++;
  Serial.print("X: ");
  Serial.println(xPos);
  servoX.write(xPos);
}

void moveLeft() {
  xPos--;
  Serial.print("X: ");
  Serial.println(xPos);
  servoX.write(xPos);
}

void moveDown() {
  yPos--;
  Serial.print("y: ");
  Serial.println(yPos);
  servoY.write(yPos);
}

void moveUp() {
  yPos++;
  Serial.print("y: ");
  Serial.println(yPos);
  servoY.write(yPos);
}

void setup() {
  Serial.begin(115200);
  servoX.attach(lrPin);
  servoY.attach(udPin);

  pinMode(laser, OUTPUT);
  
  ledOn();

  Serial.print("X: ");
  Serial.print(xPos);
  Serial.print(" Y: ");
  Serial.print(yPos);
}

void loop() {
  if(xPos<120){
    moveRight();
  }


  if(yPos<120){
    moveUp();
  }
  delay(100);
}
