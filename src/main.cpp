#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

const int BTN_START_2 = 5; // D0 (see PINOUT.md)

template <typename TState>
class Button {
  private:
    int pin;
  public:
    TState lastState;
    Button(int pin, TState defaultState){
      this->pin = pin;
      this->lastState = defaultState;
    }
    void setPinMode(const int btnPinMode){
      pinMode(this->pin, btnPinMode);
    }
    TState read(){
      return digitalRead(this->pin);
    }
};

// Define buttons
Button<int> btnStart2 = Button<int>(5, HIGH);


void setup() {
  Serial.begin(115200);
  btnStart2.setPinMode(INPUT_PULLUP);
}

void loop() {
  if(btnStart2.read() == LOW && btnStart2.lastState == HIGH){
    Serial.println("BTN_START_2 pressed");
    delay(100);
  }
}
  // put your main code here, to run repeatedly:

// put function definitions here:
//int myFunction(int x, int y) {
//  return x + y;
//}