#include <Servo.h>

Servo myServo1;
Servo myServo2;
Servo myServo3;

int const potPin1 = A0;
int angle1;
int potVal1;

int const potPin2 = A1;
int angle2;
int potVal2;

int const potPin3 = A2;
int angle3;
int potVal3;

void setup()
{
 myServo1.attach(9); 
 myServo2.attach(10); 
 myServo3.attach(11); 
}

void loop()
{
 potVal1 = analogRead(potPin1);
 potVal2 = analogRead(potPin2);
 potVal3 = analogRead(potPin3);
 
 angle1 = potVal1/(1023/180);
 angle2 = potVal2/(1023/180);
 angle3 = potVal3/(1023/180);
 
 myServo1.write(angle1);
 delay(15);
 
 myServo2.write(angle2);
 delay(15);
 
 myServo3.write(angle3 + 90);
 delay(15);
}
