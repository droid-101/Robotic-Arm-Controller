#include <Servo.h>

#define BASE_PIN       3
#define REACH_PIN      9
#define VERTICAL_PIN   10
#define CLAW_PIN       11

#define DEFAULT_BASE_POSITION      80.25
#define DEFAULT_REACH_POSITION     85
#define DEFAULT_VERTICAL_POSITION  120
#define DEFAULT_CLAW_POSITION      47

#define BASE_MIN      30
#define REACH_MIN     60
#define VERTICAL_MIN  80
#define CLAW_MIN      47

#define BASE_MAX      90
#define REACH_MAX     175
#define VERTICAL_MAX  175
#define CLAW_MAX      105

char key;

double baseAngle;
double reachAngle;
double verticalAngle;
double clawAngle;

Servo base;
Servo reach;
Servo vertical;
Servo claw;

void defaultPositions()
{
  base.write(DEFAULT_BASE_POSITION);
  delay(1000);
  reach.write(DEFAULT_REACH_POSITION);
  delay(1000);
  vertical.write(DEFAULT_VERTICAL_POSITION);
  delay(1000);
  claw.write(DEFAULT_CLAW_POSITION);
  delay(1000);
}



void setup()
{
  base.attach(BASE_PIN);
  reach.attach(REACH_PIN);
  vertical.attach(VERTICAL_PIN);
  claw.attach(CLAW_PIN);
  defaultPositions();

  baseAngle = DEFAULT_BASE_POSITION;
  reachAngle = DEFAULT_REACH_POSITION;
  verticalAngle = DEFAULT_VERTICAL_POSITION;
  clawAngle = DEFAULT_CLAW_POSITION;

  Serial.begin(115200);
}



void loop()
{
  
  if (Serial.available() > 0)
  {
    key = Serial.read();
    
    switch (key)
    {
      case 'd':
        if (baseAngle < BASE_MAX)
      {
        baseAngle += 1;
        base.write(baseAngle);
      }
        break;

      case 'a':
        if (baseAngle > BASE_MIN)
        {
        baseAngle -= 1;
        base.write(baseAngle);
        }
        break;
      
      case 'w':
        if (reachAngle < REACH_MAX)
        {
        reachAngle += 2;
        reach.write(reachAngle);
        }
        break;

      case 's':
        if (reachAngle > REACH_MIN)
        reachAngle -= 2;
        reach.write(reachAngle);
        break;

      case 'i':
        if (verticalAngle < VERTICAL_MAX)
        {
        verticalAngle += 2;
        vertical.write(verticalAngle);
        }
        break;

      case 'k':
        if (verticalAngle > VERTICAL_MIN)
        {
        verticalAngle -= 2;
        vertical.write(verticalAngle);
        }
        break;

      case 'l':
        if (clawAngle < CLAW_MAX)
        {
          clawAngle += 2;
          claw.write(clawAngle);
        }
        break;
      case 'j':
        if (clawAngle > CLAW_MIN)
        {
          clawAngle -= 2;
          claw.write(clawAngle);  
        }
        break;
      default:
        // nothing
        break;
    }
  }
}
