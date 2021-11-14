/*
    --Arduino_Rotary_Encoder by Mehmet Yusuf Dal--
    This is a simple Arduino library for minimizing the code while using rotary encoder modules like Ky-040.

    Basic example for this library. This code detects state change of the encoder and prints counter value on serial monitor.
*/

#include <Encoder.h>

#define ENC_CLK 4 // A  |-----------------|
#define ENC_DT 3  // B  | Encoder Pinouts |
#define ENC_SW 2  // sw |-----------------|

Encoder encoder(ENC_CLK, ENC_DT); // Create an encoder object with default settings.

int encoder_last_state = encoder.getState(); // State control variable for printing the counter on change.

void setup()
{
  pinMode(ENC_SW, INPUT_PULLUP); // Encoder switch.
  Serial.begin(9600);
  Serial.println(encoder.getState()); // Print first state of the encoder.

}

void loop()
{
  encoder.stateControl(); // Check the state change of the encoder.

  // If the encoders state has changed, print the new counter value.
  if(encoder_last_state != encoder.getState()){
    Serial.println(encoder.getState());
    encoder_last_state = encoder.getState();
  }

  // If the encoder switch pressed, reset the counter.
  if(!digitalRead(ENC_SW)) encoder.resetCounter();

}