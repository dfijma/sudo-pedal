#include "DigiKeyboard.h"

#define KEY_DELETE 76

int wasPressed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.update();
  if (digitalRead(0) == HIGH && !wasPressed) {
    DigiKeyboard.sendKeyStroke(KEY_A,MOD_CONTROL_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_S);
    DigiKeyboard.sendKeyStroke(KEY_U);
    DigiKeyboard.sendKeyStroke(KEY_D);
    DigiKeyboard.sendKeyStroke(KEY_O);
    DigiKeyboard.sendKeyStroke(KEY_SPACE);
    DigiKeyboard.sendKeyStroke(KEY_E,MOD_CONTROL_LEFT);
    wasPressed = 1;
  }
  else if (digitalRead(0) == LOW && wasPressed) {
    DigiKeyboard.sendKeyStroke(KEY_A,MOD_CONTROL_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_DELETE);
    DigiKeyboard.sendKeyStroke(KEY_DELETE);
    DigiKeyboard.sendKeyStroke(KEY_DELETE);
    DigiKeyboard.sendKeyStroke(KEY_DELETE);
    DigiKeyboard.sendKeyStroke(KEY_DELETE);
    DigiKeyboard.sendKeyStroke(KEY_E,MOD_CONTROL_LEFT);
    wasPressed = 0;
  }
}
