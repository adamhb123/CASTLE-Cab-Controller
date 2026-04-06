#include <Arduino.h>

struct Button
{
  const char *name;
  int pin;
  int lastState;
  Button(const char *name, int pin) : name(name), pin(pin), lastState(HIGH) {}
};

Button buttons[] = {
  // Left-hand side of cabinet
  Button("Start1", 5), // Start game (top)
  Button("Start2", 6), // Start game (bottom)
  Button("LIVE", 7), // Yellow button
  // Joystick
  Button("JoyUp", 8), // Yellow wires
  Button("JoyDown", 9), // Black wires
  Button("JoyRight", 10), // Red Wires
  Button("JoyLeft", 11), // Green Wires
  // Right hand side of cabinet
  Button("Fire", 12), // Red button
  Button("Aux1", 13), // White button (left)
  Button("Aux2", 14), // White button right
};

const size_t n_buttons = sizeof(buttons) / sizeof(buttons[0]);

void setup()
{
  Serial.begin(115200);
  for (size_t i = 0; i < n_buttons; i++)
  {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop()
{
  for (size_t i = 0; i < n_buttons; i++)
  {
    int state = digitalRead(buttons[i].pin);
    if (state == LOW && buttons[i].lastState == HIGH)
    {
      char buff[32];
      sprintf(buff, "//%s pressed", buttons[i].name);
      Keyboard.println(buff);
    }
    buttons[i].lastState = state;
  }
}
