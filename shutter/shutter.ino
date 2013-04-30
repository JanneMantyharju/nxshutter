/* 
	Shutter control for rc receiver
	(c) Janne Mäntyharju 2013
	
	Pins are for Atmel TINY2313 controller, modify as needed
*/

#define RCIN 9
#define FOCUS 11
#define SHUTTER 10

#define FOCUS_ACTIVATE 1400
#define SHUTTER_ACTIVATE 1700


void setup()
{
  pinMode(RCIN, INPUT);
  pinMode(FOCUS, INPUT);
  pinMode(SHUTTER, INPUT);
  digitalWrite(FOCUS, LOW);
  digitalWrite(SHUTTER, LOW);
}

void loop()
{
  int pwm;
  
  pwm = pulseIn(RCIN, HIGH, 25000);
  if (pwm > FOCUS_ACTIVATE && pwm < SHUTTER_ACTIVATE) {
    pinMode(SHUTTER, INPUT);
    pinMode(FOCUS, OUTPUT);
  } else if (pwm > SHUTTER_ACTIVATE) {
    pinMode(FOCUS, INPUT);
    pinMode(SHUTTER, OUTPUT);    
  } else {
    pinMode(FOCUS, INPUT);
    pinMode(SHUTTER, INPUT);
  }
}
