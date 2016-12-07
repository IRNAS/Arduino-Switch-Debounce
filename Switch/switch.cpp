#include "switch.h"
#include "Arduino.h"

Switch::Switch(const int buttonPin, const int polarity) :
  m_iButtonPin(buttonPin),
  m_iPolarity(polarity), // LOW or HIGH  polarity
  m_iButtonState((polarity == HIGH) ? LOW : HIGH), // the current reading from the input pin
  m_iLastButtonState((polarity == HIGH) ? LOW : HIGH), // the previous reading from the input pin
  m_lLastDebounceTime(0), // the last time the output pin was toggled
  m_lDebounceDelay(50) // the debounce time; increase if the output flickers
{
  pinMode(m_iButtonPin, INPUT_PULLUP); // set as input
}


Switch::~Switch()
{
}


// returns true if button pressed, else returns false
bool Switch::get_button_state()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(m_iButtonPin);

  // If the switch changed, due to noise or pressing:
  if (reading != m_iLastButtonState)
  {
    m_iLastButtonState = reading;
    // reset the debouncing timer
    m_lLastDebounceTime = millis();
  }

  if ((millis() - m_lLastDebounceTime) > m_lDebounceDelay)
  {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    m_iButtonState = m_iLastButtonState;

    // if button was pressed
    if(m_iButtonState == m_iPolarity) return true;
  }

  return false;
}

