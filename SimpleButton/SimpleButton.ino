#include <Adafruit_CircuitPlayground.h>

#define COLOR  0x31b784

int pixel = 0;
bool wasPressed = false;

void setup() 
{
  // Initialize the circuit playground
  CircuitPlayground.begin();
}
 
void loop() 
{
  // If the left button is pressed....
  if (CircuitPlayground.leftButton() && !wasPressed) 
  {
      CircuitPlayground.setPixelColor(pixel, COLOR);
      wasPressed = true;
      delay(50);
  } 
  else 
  {
      CircuitPlayground.clearPixels();
      pixel = (pixel + 1) % 10;
      wasPressed = false;
  }
}
