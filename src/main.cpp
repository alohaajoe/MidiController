#include <Arduino.h>
#include <Servo.h>

const int buttonPins[] = {A0, A1, A2, A3, A4}; // Pins für die Buttons
const int servoPin [] = {3, 5, 9, 10, 11}; // Pin für den Servo
const int numButtons = sizeof(buttonPins) / sizeof(int);
int lastButtonStates[numButtons]; // Zustände der Buttons
Servo servos [numButtons]; // Servo-Objekte
int anglePressed = 0;
int angleReleased = 90;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < numButtons; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
    lastButtonStates[i] = LOW; // Anfangszustand ist LOW
    servos[i].attach(servoPin[i]);
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
        servos[i].write(angleReleased);
      }
      else if (currentButtonState == LOW)
      {
        Serial.print("Button ");
        Serial.print(i);
        Serial.println(" pressed");
        servos[i].write(anglePressed);
      }
      lastButtonStates[i] = currentButtonState;
    }
  }
}