// Chopp-E: ATtiny firmware for Bypass Controller
// The code below is used to program the ATtiny85 module, equipping
// it to handle button presses, muting, and relay switching
// Author: Jubal Clapp
#include <Arduino.h>
#include <EEPROM.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
const uint8_t PIN_COIL_ON = PB0;      // initialize all needed global variables
const uint8_t PIN_COIL_OFF = PB1;
const uint8_t PIN_MUTE = PB2;
const uint8_t PIN_LED = PB3;
const uint8_t PIN_FSW = PB4;
const uint16_t DEBOUNCE_MS = 20;
const uint16_t MUTE_LEAD_MS = 5;
const uint16_t COIL_PULSE_MS = 10;
const uint16_t MUTE_TRAIL_MS = 10;
const uint8_t EE_ADDR = 0;
bool engaged = false; 

void setBypass(bool engage);           // forward declarations of necessary functions
void readButton();
void goToSleep();
ISR(PCINT0_vect) {}                    // interrupt handler

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
  GIMSK |= (1 << PCIE);                // turn on pin change inturrupts
  PCMSK |= (1 << PCINT4);              // turn on pin change for pb4 (footswitch)
  ADCSRA &= ~(1 << ADEN);              // turn off adc, which isnt used in this build
  engaged = (EEPROM.read(EE_ADDR) == 1);
  setBypass(engaged);
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
      EEPROM.update(EE_ADDR, engaged);
      while (digitalRead(PIN_FSW) == LOW){

      }
       delay(DEBOUNCE_MS);
    }
  }
}
void goToSleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   
  sleep_enable();
  sei();                                 // keep interrupts on           
  sleep_cpu();                           // program stops here until an interrupt is detected
  sleep_disable();
}

void loop () {
  readButton();
  goToSleep();
}