#include "switch.h"

// switch connected to Arduino pin 2
// if switch pressed pin voltage is LOW
// using Arduino's built-in pull-up resistor
Switch swt(2, LOW);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // user LED
}

void loop()
{
  // if button pressed turn the user LED on, else turn it off
  if(swt.get_button_state()) digitalWrite(LED_BUILTIN, HIGH);
  else digitalWrite(LED_BUILTIN, LOW);
}
