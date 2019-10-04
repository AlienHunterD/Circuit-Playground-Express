////////////////////////////////////////////////////////////////////////////
// Circuit Playground Capacitive Touch Tones
//
// Play a tone for each touch pad.
// Using 4th octave note frequencies, to nearest 1Hz.
// https://www.seventhstring.com/resources/notefrequencies.html
//
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

#define CAP_THRESHOLD   300
#define DEBOUNCE        125

uint8_t pads[] = {3, 2, 0, 1, 6, 9, 10};
bool was_pressed[] = {false, false, false, false, false, false, false};  

uint8_t numberOfPads = sizeof(pads)/sizeof(uint8_t);

////////////////////////////////////////////////////////////////////////////
void takeAction(uint8_t pad) {
  char note = '?';
  int freq = 0;
  uint8_t light = 0;
  int color = 0x000000;
  
  //Serial.print("PAD "); Serial.print(pad); Serial.print(" playing note: ");
  switch (pad) {
    case 3:
      note = 'C';
      freq = 262;
      light = 0;
      color = 0xFF0000;
      break;
    case 2:
      note = 'D';
      freq = 294;
      light = 1;
      color = 0x888800;
      break;
    case 0:
      note = 'E';
      freq = 330;
      light = 2;
      color = 0x00FF00;
      break;
    case 1:
      note = 'F';
      freq = 349;
      light = 3;
      color = 0x008888;
      break;
    case 6:
      note = 'G';
      freq = 392;
      light = 6;
      color = 0x0000FF;
      break;
    case 9:
      note = 'A';
      freq = 440;
      light = 7;
      color = 0x880088;
      break;
    case 10:
      note = 'B';
      freq = 494;
      light = 8;
      color = 0x555555;
      break;
    default:
      note = '?';
  }
  if (CircuitPlayground.slideSwitch())
  {
    CircuitPlayground.playTone(freq, 100, false);
  }
  CircuitPlayground.setPixelColor(light, color);
  CircuitPlayground.setPixelColor(light+1, color);

  delay(DEBOUNCE); // Wait just a bit
  
  CircuitPlayground.clearPixels();
  
  //Serial.println(note);
}

////////////////////////////////////////////////////////////////////////////
boolean capButton(uint8_t pad) {
  // Check if capacitive touch exceeds threshold.
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) 
  {
    return true;  
  }
  else 
  {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////
void setup() {
  // Initialize serial.
  Serial.begin(9600); 
  
  // Initialize Circuit Playground library.
  CircuitPlayground.begin();

}

////////////////////////////////////////////////////////////////////////////
void loop() {
  // Loop over every pad.

  for (int i=0; i<numberOfPads; i++) {

    // Check if pad is touched.
    if (capButton(pads[i])) 
    {
      if(was_pressed[i])
      {
        was_pressed[i] = false;
      }
      else
      {     
        // Do something.
        takeAction(pads[i]);
      }
      
    }
    else
    {
      was_pressed[i] = true;
    }
  }

}
