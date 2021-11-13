/*
    --Arduino_Rotary_Encoder by Mehmet Yusuf Dal--
    This is a simple Arduino library for minimizing the code while using rotary encoder modules like Ky-040.
*/

#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "Arduino.h"

#define P_INF 32767  // Positive infinite. Max value of arduino signed int (16 bit).
#define N_INF -32768 // Negative infinite. Min value of arduino signed int (16 bit).

class Encoder{
private:
    int A, B; // A (CLK) & B (DT) pins.
    int A_state, B_state, A_last_state; // To calculate turn count of encoder.
    int counter; // Turn count of encoder.
    int c_min, c_max; // Min & max value of counter.
    int c_start; // Start value of counter.
    int c_step; // Incrementation amount of counter.

public:
    /*
        Constructor method:
            First 2 parameters are required: 
                - Encoder A pin number.
                - Encoder B pin number.

            The other parameters are optional:
                - Counter start value. If it is less than the minimum counter value, it will be set to the minimum counter value.
                    If it is above than the maximum counter value, it will be set to the maximum counter value. Default value is 0.
                - Incrementation amount of the counter. Nagative values reverses the encoder direction.
                - Minimum counter value. If it is above then the maximum counter value, both will be set to infinite. Default value is N_INF (negative infinite).
                - Maximum counter value. Default value is P_INF (positive infinite).
        
        (A pin, B pin, Counter start value, Counter incrementation amount, Counter min, Counter max)
    */
    Encoder(int, int, int=0, int=1, int=N_INF, int=P_INF);
    
    /*
        Calculates turn count.
    */
    void stateControl();

    /*
        If the given number is less then the maximum counter value, sets the minimum counter value to given number. 
        If current counter is less then new minimum, it sets the counter to the new minimum value.
    */
    void setMin(int);

    /*
        If the given number is above then the minimum counter value, sets the maximum counter value to the given number.
        If current counter is above then new maximum, it sets the counter to the new maximum value.
    */
    void setMax(int);

    /*
        Sets counter start value to given number. If it is less than the minimum counter value, it will be set to the minimum counter value.
        If it is above than the maximum counter value, it will be set to the maximum counter value.
    */
    void setStart(int);

    /*
        Sets incrementation amount of counter to given number. Nagative values reverses the encoder direction.
    */
    void setStep(int);

    /*
        Sets counter to start value.
    */
    void resetCounter();

    /*
        Returns the current counter value.
    */
    int getState();

};

#endif