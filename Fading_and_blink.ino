/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 04 MArch 2018
 By g6b0r
 
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */


int ledPin = 9;    // LED connected to digital pin 9


int powerLed = 13; // 
boolean powerLedStatus = false;

long lastTimeBlink = 0;
long lastTimeFade = 0;
long blinkDelay = 500; // delay in millis for blinkin led on/off
long fadeDelay = 20; // delay in millis for changing fading led
int fadeStep = 5; //led fading step
boolean fadeUp = true;
int fadeValue = 0;

void setup()  { 

  pinMode( powerLed, OUTPUT);
  LedChange( powerLed, &powerLedStatus );
  lastTimeBlink = millis();
  changeFade();
  lastTimeFade = millis();
} 

void LedChange( int pin, boolean *state ){
  *state = !(*state);
  int newState ;
  if ( *state == true ){ newState = HIGH; } 
  else{ newState = LOW; }
  digitalWrite( pin, newState );
}

void LedOn( int pin ){
  digitalWrite( pin, HIGH );
}

void loop()  { 
   if (( millis() - lastTimeBlink ) > blinkDelay ){
     LedChange( powerLed, &powerLedStatus );
     lastTimeBlink = millis();
   }
   
   if (( millis() - lastTimeFade ) > fadeDelay ){
     changeFade();
     lastTimeFade = millis();
   }
}

void changeFade(){
  //up/down
  if ( fadeUp == true ){
    fadeValue += fadeStep;
    if (fadeValue >= 255 ){
      fadeValue = 255;
      fadeUp = false;
    }
  }else{
    fadeValue -= fadeStep;
    if (fadeValue <= 0  ){
      fadeValue = 0;
      fadeUp = true;    
    }
  }
    analogWrite(ledPin, fadeValue);           
}
