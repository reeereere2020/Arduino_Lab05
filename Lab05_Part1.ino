#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'C', 'D', 'E', 'F'}, {'9','6','3', 'B'},
  {'8', '5', '2', 'A'}, {'7', '1', '4', '0'}
};
byte rowPins[ROWS] = {14, 13, 17, 15};
byte colPins[COLS] = {12, 11, 9, 10};
Keypad keypad = Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);
  }
}


