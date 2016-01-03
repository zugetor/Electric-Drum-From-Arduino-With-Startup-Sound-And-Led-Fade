//-------------------------------------------------------------------------------
#include <Keyboard.h>
#include "pitches.h"
#include "SoftPWM.h"
int analogpin0={A0};
int analogpin1={A1};
int analogpin2={A2};
int analogpin3={A3};
int analogpin4={A4};
int analogpin5={A5};
int threshold=150;
int melody[] = {
      NOTE_B0, NOTE_B0, NOTE_C4, NOTE_B0, NOTE_C4, NOTE_B0, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_B0, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_F4, NOTE_G4
      };

int noteDurations[] = {
      2, 2, 5, 5, 5, 4, 6, 7, 7, 5, 5, 5, 5, 5, 6, 9, 9
};
long ts;
//-------------------------------------------------------------------------------





//-------------------------------------------------------------------------------
void setup()
{
Serial.begin(9600);
Keyboard.begin();
for (int thisNote = 0; thisNote < 17; thisNote++) {

        int noteDuration = 1000/noteDurations[thisNote];
        tone(13, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(13); 
}   
SoftPWMBegin();

 // Create on pins 9 and 10
 SoftPWMSet(3, 0);
  SoftPWMSet(5, 0);
   SoftPWMSet(6, 0);
    SoftPWMSet(9, 0);
     SoftPWMSet(10, 0);
      SoftPWMSet(11, 0);

 // Set full scale fade time of pin 9 (up in 500 ms, down in 1000 ms)
 SoftPWMSetFadeTime(3, 500, 500);
  SoftPWMSetFadeTime(5, 500, 500);
   SoftPWMSetFadeTime(6, 500, 500);
    SoftPWMSetFadeTime(9, 500, 500);
     SoftPWMSetFadeTime(10, 500, 500);
      SoftPWMSetFadeTime(11, 500, 500);

}
//-------------------------------------------------------------------------------





//-------------------------------------------------------------------------------
void loop()
{
//-------------------------------------------------------------------------------

//------------------------------------------------------------------------------- 
if(analogRead(analogpin0)>threshold)
{
Serial.println("A0");
Keyboard.press('w');
delay(10);
Keyboard.releaseAll();

  SoftPWMSetPercent(3, 100);
}

  else {
    if(millis()- ts >= 200) {
      ts = millis();
    SoftPWMSetPercent(3, 0);
    }
  }
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
if (analogRead(analogpin1)>threshold)
{
Serial.println("A1");
  Keyboard.press('a');
    delay(10);
  Keyboard.releaseAll();
  
  SoftPWMSetPercent(5, 100);
}

  else {
    if(millis()- ts >= 200) {
      ts = millis();
    SoftPWMSetPercent(5, 0);
    }
  }
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
if (analogRead(analogpin2)>threshold)
{
Serial.println("A2"); 
  Keyboard.press('s');
  delay(10);
  Keyboard.releaseAll();
  
  SoftPWMSetPercent(6, 100);
}

  else {
    if(millis()- ts >= 200) {
      ts = millis();
    SoftPWMSetPercent(6, 0);
    }
  }
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
if (analogRead(analogpin3)>threshold)
{
Serial.println("A3"); 
  Keyboard.press('d');
  delay(10);
  Keyboard.releaseAll();
  
  SoftPWMSetPercent(9, 100);
}

  else {
    if(millis()- ts >= 200) {
      ts = millis();
    SoftPWMSetPercent(9, 0);
    }
  }
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
if (analogRead(analogpin4)>threshold)
{
Serial.println("A4"); 
  Keyboard.press('q');
  delay(10);
  Keyboard.releaseAll();
  
  SoftPWMSetPercent(10, 100);
}

  else {
    if(millis()- ts >= 200) {
      ts = millis();
    SoftPWMSetPercent(10, 0);
    }
  }
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
if (analogRead(analogpin5)>threshold)
{
Serial.println("A5"); 
  Keyboard.press('e');
  delay(10);
  Keyboard.releaseAll();
  
  SoftPWMSetPercent(11, 100);
}

  else {
    if(millis()- ts >= 200) {
      ts = millis();
    SoftPWMSetPercent(11, 0);
    }
  }
//-------------------------------------------------------------------------------
}
//-------------------------------------------------------------------------------

