/* 
	Shutter control for rc receiver
	(c) Janne Mäntyharju 2013
	
	Pins are for Atmel TINY2313 controller, modify as needed
*/

#define RCIN 0
#define FOCUS 11
#define SHUTTER 10
#define LED_FOCUS 5
#define LED_SHUTTER 1 

#define FOCUS_ACTIVATE 1400
#define SHUTTER_ACTIVATE 1700


void setup()
{
  pinMode(RCIN, INPUT);
  pinMode(FOCUS, INPUT);
  pinMode(SHUTTER, INPUT);
  pinMode(LED_FOCUS, OUTPUT);
  pinMode(LED_SHUTTER, OUTPUT);
  digitalWrite(FOCUS, LOW);
  digitalWrite(SHUTTER, LOW);
  
  digitalWrite(LED_FOCUS, HIGH);
  digitalWrite(LED_SHUTTER, HIGH);
  delay(1000);
  digitalWrite(LED_FOCUS, LOW);
  digitalWrite(LED_SHUTTER, LOW);  
}

void loop()
{
  UCSRB=0;
  int pwm;

  pwm = pulseIn(RCIN, HIGH, 25000);
  if (pwm > FOCUS_ACTIVATE && pwm < SHUTTER_ACTIVATE) {
    pinMode(SHUTTER, INPUT);
    digitalWrite(LED_SHUTTER, LOW); 
    
    pinMode(FOCUS, OUTPUT);
    digitalWrite(LED_FOCUS, HIGH);    
  } else if (pwm > SHUTTER_ACTIVATE) {
    pinMode(FOCUS, INPUT);
    digitalWrite(LED_FOCUS, LOW);
    
    pinMode(SHUTTER, OUTPUT);
    digitalWrite(LED_SHUTTER, HIGH);
  } else {
    pinMode(FOCUS, INPUT);
    digitalWrite(LED_FOCUS, LOW);
    
    pinMode(SHUTTER, INPUT);
    digitalWrite(LED_SHUTTER, LOW); 
  }
}
