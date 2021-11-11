/*
    --Arduino_Rotary_Encoder by Mehmet Yusuf Dal--
    This is a simple Arduino library for minimizing the code while using rotary encoder modules like Ky-040.

    Basic example.
*/

#include <Encoder.h>

#define ENC_CLK 4 // A  |----------------|
#define ENC_DT 3  // B  | encoder pinout |
#define ENC_SW 2  // sw |----------------|

Encoder encoder(ENC_CLK, ENC_DT);

int encoder_last_state = encoder.getState();

void setup()
{
  pinMode(ENC_SW, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop()
{
  encoder.stateControl();

  if(encoder_last_state != encoder.getState()){
    Serial.println(encoder.getState());
    encoder_last_state = encoder.getState();
  }

  if(!digitalRead(ENC_SW)) Serial.println("Button Pressed");

}