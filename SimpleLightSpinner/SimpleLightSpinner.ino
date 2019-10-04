
#include <Adafruit_CircuitPlayground.h>
#define COLOR         0x31b784
#define LOW_LIMIT     10    // The "fastest" delay time
#define HIGH_LIMIT    200   // The "slowest" delay time
 
int pixel1;   // The location of the first pixel to light
int pixel2;   // The location of the second pixel to light
int pause_time; // The amount of time to pause between steps
int delta_spin; // The rate that the pause time changes
 
///////////////////////////////////////////////////////////////////////////////
void setup() 
{
  // Initialize the CPX
  CircuitPlayground.begin();
  
  // Set a medium brightness
  CircuitPlayground.setBrightness(64);
 
  // Select two pixels as the starting locations
  pixel1 = 0;
  pixel2 = 5;
  
  // Set up the "spin" properties
  pause_time = 100;
  delta_spin = -5;
}
 
 
///////////////////////////////////////////////////////////////////////////////
void loop() {
  // Turn off all the pixels
  CircuitPlayground.clearPixels(); 
 
  // Turn on two pixels and set them to the COLOR value
  CircuitPlayground.setPixelColor(pixel1, COLOR);
  CircuitPlayground.setPixelColor(pixel2, COLOR);
 
  // Increment the pixels so that they apppear to "move" around the board
  if (CircuitPlayground.slideSwitch())
  {
    pixel1 = (pixel1 + 1) % 10;
    pixel2 = (pixel2 + 1) % 10;
  }
  else
  {
    pixel1 = (pixel1 + 9) % 10;
    pixel2 = (pixel2 + 9) % 10;
  }
 
  delay(pause_time); // pause for just a moment
  
  pause_time += delta_spin; // Update the delay time for the next iteration
  
  // Check to see if we are going outside the delay limits 
  if (pause_time < LOW_LIMIT || pause_time > HIGH_LIMIT)
  {
    delta_spin = -delta_spin; // Reverse the trend of speeding up or slowing down
  }
}
