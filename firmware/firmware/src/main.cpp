#include <Arduino.h>
const uint8_t PIN_COIL_ON = PB0;
const uint8_t PIN_COIL_OFF = PB1;
const uint8_t PIN_MUTE = PB2;
const uint8_t PIN_LED = PB3;
const uint8_t PIN_FSW = PB4;
const uint16_t DEBOUNCE_MS = 20;
bool engaged = false; 

void setup() {
  // put your setup code here, to run once:
  digitalWrite(PIN_COIL_ON, LOW);
  pinMode(PIN_COIL_ON, OUTPUT);
  digitalWrite(PIN_COIL_OFF, LOW);
  pinMode(PIN_COIL_OFF, OUTPUT);
  digitalWrite(PIN_MUTE, LOW);
  pinMode(PIN_MUTE, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_FSW, INPUT);

}
void readButton () {
  bool reading = digitalRead(PIN_FSW);
  if (reading == LOW){
    delay(DEBOUNCE_MS);
    reading = digitalRead(PIN_FSW);
    if (reading == LOW){
      engaged = !engaged;
      digitalWrite(PIN_LED, engaged ? HIGH : LOW);
      while (digitalRead(PIN_FSW) == LOW){

      }
       delay(DEBOUNCE_MS);
    }
  }
}

void loop () {
  readButton();
}
