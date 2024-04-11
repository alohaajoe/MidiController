#include <Arduino.h>

const int buttonPins[] = {2, 3, 4, 5, 6}; // Pins für die Buttons
const int numButtons = sizeof(buttonPins) / sizeof(int);
int lastButtonStates[numButtons]; // Zustände der Buttons

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < numButtons; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
    lastButtonStates[i] = LOW; // Anfangszustand ist HIGH
  }
}

void loop()
{
  for (int i = 0; i < numButtons; i++)
  {
    int currentButtonState = digitalRead(buttonPins[i]);
    if (currentButtonState != lastButtonStates[i])
    {
      if (currentButtonState == HIGH)
      {
        Serial.print("Button ");
        Serial.print(i);
        Serial.println(" released");
      }
      else if (currentButtonState == LOW)
      {
        Serial.print("Button ");
        Serial.print(i);
        Serial.println(" pressed");
      }
      lastButtonStates[i] = currentButtonState;
    }
    //delay(100); // debounce delay
  }
}