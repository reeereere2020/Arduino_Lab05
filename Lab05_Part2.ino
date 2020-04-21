#include <Keypad.h>
#include"SevSeg.h"
SevSeg sevseg;
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
  byte numDigits = 1;
  byte digitPins[] = {16};
  byte segmentPins[] = {3, 2, 6, 7, 8, 4, 5, 1};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);
  }
  sevseg.setNumber(key,0); 
  sevseg.refreshDisplay();
  
}


