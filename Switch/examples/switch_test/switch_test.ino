#include "switch.h"

Switch swt(2, LOW);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // LED
}

void loop()
{
  if(swt.get_button_state()) digitalWrite(LED_BUILTIN, HIGH);
  else digitalWrite(LED_BUILTIN, LOW);
}
