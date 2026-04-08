#include <Arduino.h>

struct Button {
  const char *name;
  int pin;
  int lastState;
  uint16_t map_key; // Key to map button press to
  Button(const char *name, int pin, uint16_t map_key) :
  name(name), pin(pin), lastState(HIGH), map_key(map_key) {}
};

Button buttons[] = {
  // Left-hand side of cabinet
  Button("Start1", 5, KEY_1), // Start game (top)
  Button("Start2", 6, KEY_2), // Start game (bottom)
  Button("LIVE", 7, KEY_ENTER), // Yellow button
  // Joystick
  Button("JoyUp", 8, KEY_W), // Yellow wires
  Button("JoyDown", 9, KEY_S), // Black wires
  Button("JoyRight", 10, KEY_D), // Red Wires
  Button("JoyLeft", 11, KEY_A), // Green Wires
  // Right hand side of cabinet
  Button("Fire", 12, KEY_SPACE), // Red button
  Button("Aux1", 13, KEY_Z), // White button (left)
  Button("Aux2", 14, KEY_X), // White button (right)
  Button("Off", 15, KEY_ESC), // Off for "On/off" toggle
  Button("On", 16, KEY_SYSTEM_WAKE_UP), // On for "On/off" toggle
  Button("VolDown", 17, KEY_MEDIA_VOLUME_DEC), // Vol down (-) for "-Vol+" toggle
  Button("VolUp", 18, KEY_MEDIA_VOLUME_INC) // Vol up (+) for "-Vol+" toggle
};

const size_t n_buttons = sizeof(buttons) / sizeof(buttons[0]);

/*void processKeyQueue(RBQueue<uint16_t>& k_queue)
{
  while (!rbQueueIsEmpty(k_queue)){
    uint16_t pressedKey;
    dequeue(k_queue, pressedKey);
    //Serial.println("Pressed key:");
    Keyboard.press(pressedKey);
    delay(10);
    Keyboard.release(pressedKey);
  }
}*/

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
    while (state == LOW && buttons[i].lastState == HIGH)
    {
      //char buff[32];
      //sprintf(buff, "//%s pressed", buttons[i].name);
      //Serial.println(buff);
      //enqueue(key_queue, buttons[i].map_key);
      Keyboard.press(buttons[i].map_key);
      delay(10);
      state = digitalRead(buttons[i].pin);
    }
    if(buttons[i].lastState == HIGH) {
      Keyboard.release(buttons[i].map_key);
    }
    buttons[i].lastState = state;
  }
  //processKeyQueue(key_queue);
}