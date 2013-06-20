#include <stepMotor.h>

/*
  A program to control 3 motors on an arduino given input from a processing program.
  
  Start date: 5/25/2013
*/

const int xSteps = 200;
const int ySteps = 200;

stepMotor x(xSteps,6,7,8,9);
stepMotor y(ySteps,10,11,12,13);

int val;
long xSpeed = 0;
long ySpeed = 0;

void setup() 
{
  Serial.begin(115200);
  x.setPhase(0);
  y.setPhase(0);
  x.setSpeed(0);
  y.setSpeed(0);
  while(!Serial);
}

void loop() 
{
  checkAxis();
  x.step();
  y.step();
}

void checkAxis()
{
  if(Serial.available() > 0)
  {
    val = Serial.read();
    switch (val)
    {
      case 120:
        xSpeed = (Serial.read() - '0') + (Serial.read() - '0') + (Serial.read() - '0');
        x.setSpeed(xSpeed);
        Serial.println(xSpeed);
        break;
      case 121:
        ySpeed = (Serial.read() - '0') + (Serial.read() - '0') + (Serial.read() - '0');
        y.setSpeed(ySpeed);
        Serial.println(ySpeed);
        break;
      case 122:
        Serial.println("Silly, that hasn't been shown yet");
        break;
      case 46:
        break;
      default:
        Serial.println("wrong motor selector");
        Serial.flush();
        break;
    }
  }
}


