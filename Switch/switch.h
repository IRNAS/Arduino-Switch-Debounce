class Switch
{
  private:
    int m_iButtonState;     // the current reading from the input pin
    int m_iLastButtonState; // the previous reading from the input pin

    // the following variables are unsigned long's because the time, measured in miliseconds,
    // will quickly become a bigger number than can be stored in an int.
    unsigned long m_lLastDebounceTime; // the last time the output pin was toggled

    int m_iPolarity; // LOW or HIGH polarity
    int m_iButtonPin; // the number of the button pin
    unsigned long m_lDebounceDelay; // the debounce time; increase if the output flickers

  public:
    Switch(const int buttonPin, const int polarity, const bool usePullUp = true, const unsigned long debounceDelay = 50UL);
    ~Switch();

    bool get_button_state(); // returns true if button pressed, else returns false
};
