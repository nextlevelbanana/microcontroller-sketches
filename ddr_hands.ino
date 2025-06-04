#include <Keyboard.h>

bool isBeamBroken[] = {false, false, false, false}; //left, right, up, down
uint8_t pins[] = {A3, A0, A2}; //left, right, up, down
String arrowNames[] = {"LEFT", "RIGHT", "UP", "DOWN"};
char keys[] = {KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW, KEY_DOWN_ARROW};

void setup() {
  Keyboard.begin();
  Serial.begin(9600); // Initialize Serial Monitor
}

void loop() {
  for (int i = 0; i < 3; i++) {
    float rawValue = analogRead(pins[i]);

    bool prevState = isBeamBroken[i];

    if ( rawValue > 370 && rawValue < 700) {
      isBeamBroken[i] = true;
      Serial.println(rawValue);
      if (!prevState) {
        Serial.println(arrowNames[i] + " on");
        Keyboard.press(keys[i]);
      }
    } else {
      isBeamBroken[i] = false;
      if (prevState) {
      Serial.println(arrowNames[i] + " off");
      Keyboard.release(keys[i]);
      };
    }
  }

  delay(10);
}
