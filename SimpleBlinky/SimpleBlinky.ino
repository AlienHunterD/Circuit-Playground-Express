/*
This program provides a simple check onthe setup and connection to the IDE
It will blink the red light adjacent to the micro-USB, at one HZ
on for one-half second and off for one-half second
*/

int LED = 13;

// the setup function runs once when you press reset or power the board
void setup() 
{
  pinMode(LED, OUTPUT); // initialize digital pin 13 as an output.
}

// the loop function runs over and over again forever
void loop() 
{
  digitalWrite(LED, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(LED, LOW);  // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
}
