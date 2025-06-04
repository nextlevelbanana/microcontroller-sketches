#include "Keyboard.h"

// constants won't change. They're used here to set pin numbers:
const int redButtonPin = 5;  // aka TX
const int redLEDPin = 1;

const int yelButtonPin = 4;
const int yelLEDPin = 6;

const int bluButtonPin = 8;
const int bluLEDPin = 10;

// variables will change:
int redButtonState = HIGH; 
int redLEDState = HIGH; 
int yelButtonState = HIGH; 
int yelLEDState = HIGH; 
int bluButtonState = HIGH; 
int bluLEDState = HIGH; 

long lastRedPress = 0;
long lastYelPress = 0;
long lastBluPress = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(redLEDPin, OUTPUT);
  pinMode(yelLEDPin, OUTPUT);
  pinMode(bluLEDPin, OUTPUT);

  digitalWrite(redLEDPin, redLEDState);
  digitalWrite(yelLEDPin, yelLEDState);
  digitalWrite(bluLEDPin, bluLEDState);


  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(yelButtonPin, INPUT_PULLUP);
  pinMode(bluButtonPin, INPUT_PULLUP);
  Serial.println("hello world");
}

void loop() {
  // read the state of the pushbutton value:
  redButtonState = digitalRead(redButtonPin);
  yelButtonState = digitalRead(yelButtonPin);
  bluButtonState = digitalRead(bluButtonPin);

  long now = millis();


  // check if the pushbutton is pressed. If it is, the buttonState is LOW, we're doing this inverted for some reason:
  if (redButtonState == LOW) {
    if (lastRedPress == 0 || now - lastRedPress > 200) {
      Serial.println("boop left!"); 
      Keyboard.press(KEY_LEFT_ARROW);
      lastRedPress = now;
    }
  }

  if (yelButtonState == LOW) {
    if (lastYelPress == 0 || now - lastYelPress > 200) {
      Serial.println("boop mid!");
      Keyboard.press(KEY_DOWN_ARROW);
      lastYelPress = now;
    }
  }

  if (bluButtonState == LOW) {
    if (lastBluPress == 0 || now - lastBluPress > 200) {
      Serial.println("boop rt!");
      Keyboard.press(KEY_RIGHT_ARROW);
      lastBluPress = now;
    }
  }
  Keyboard.releaseAll();
}
