/*
 * IRTest.cpp
 *
 * Test code for IR interface with WAVGAT UNO R3. Wiring: +5V to IR receiver Vcc, signal to 7.
 *
 */
#include <IRremote.hpp>
#include <Arduino.h>

// define sensor pin
int IR_RECEIVE_PIN = 7;

void setup() {
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
    Serial.begin(9600);
}

void loop() {
    if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.printIRResultShort(&Serial); // optional use new print version
      // ...
      IrReceiver.resume(); // Enable receiving of the next value
    }
}
