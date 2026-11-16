#include <Arduino.h>
const uint8_t PIN_COIL_ON = PB0;      // initialize all needed global variables
const uint8_t PIN_COIL_OFF = PB1;
const uint8_t PIN_MUTE = PB2;
const uint8_t PIN_LED = PB3;
const uint8_t PIN_FSW = PB4;
const uint16_t DEBOUNCE_MS = 20;
const uint16_t MUTE_LEAD_MS = 5;
const uint16_t COIL_PULSE_MS = 10;
const uint16_t MUTE_TRAIL_MS = 10;
bool engaged = false; 

void setup() {
  digitalWrite(PIN_COIL_ON, LOW);      // initialize all needed pins
  pinMode(PIN_COIL_ON, OUTPUT);
  digitalWrite(PIN_COIL_OFF, LOW);
  pinMode(PIN_COIL_OFF, OUTPUT);
  digitalWrite(PIN_MUTE, LOW);
  pinMode(PIN_MUTE, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_FSW, INPUT);

}
void setBypass(bool engage) {          // switch relay to requested state
  digitalWrite(PIN_MUTE, HIGH);
  delay(MUTE_LEAD_MS);
  if (engage) {
    digitalWrite(PIN_COIL_ON, HIGH);
    delay(COIL_PULSE_MS);
    digitalWrite(PIN_COIL_ON, LOW);
  } else {
    digitalWrite(PIN_COIL_OFF, HIGH);
    delay(COIL_PULSE_MS);
    digitalWrite(PIN_COIL_OFF, LOW);
  }
  delay(MUTE_TRAIL_MS);
  digitalWrite(PIN_MUTE, LOW);
  digitalWrite(PIN_LED, engage ? HIGH : LOW);
}

void readButton () {
  bool reading = digitalRead(PIN_FSW);
  if (reading == LOW){
    delay(DEBOUNCE_MS);
    reading = digitalRead(PIN_FSW);
    if (reading == LOW){
      engaged = !engaged;
      setBypass(engaged);
      while (digitalRead(PIN_FSW) == LOW){

      }
       delay(DEBOUNCE_MS);
    }
  }
}

void loop () {
  readButton();
}
