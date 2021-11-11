/*
    --Arduino_Rotary_Encoder by Mehmet Yusuf Dal--
    This is a simple Arduino library for minimizing the code while using rotary encoder modules like Ky-040.

    NOTE: If you get multiply definition error while compiling, check out bottom of this file.
*/

#ifndef _ENCODER_H_
#define _ENCODER_H_

#define P_INF 32767  // Positive infinite. Max value of arduino signed int (16 bit).
#define N_INF -32768 // Negative infinite. Min value of arduino signed int (16 bit).

class Encoder{
private:
    int A, B; // A (CLK) & B (DT) pins.
    int A_state, B_state, A_last_state; // To calculate turn count of encoder.
    int counter; // Turn count of encoder.
    int c_min, c_max; // Min & max value of counter.

public:
    /*
        Constructor method:
            First 2 parameters are required: 
                - Encoder A pin number.
                - Encoder B pin number.

            The other parameters are optional:
                - Counter start value. If it is less than the minimum counter value, it will be set to the minimum counter value. Default value is 0.
                - Minimum counter value. If it is above then the maximum counter value, both will be set to infinite. Default value is N_INF (negative infinite).
                - Maximum counter value. Default value is P_INF (positive infinite).
        
        (A pin, B pin, Counter start value, Counter min, Counter max)
    */
    Encoder(int, int, int = 0, int = N_INF, int = P_INF);
    
    /*
        Calculates turn count.
    */
    void stateControl();

    /*
        Sets the minimum counter value to given number. If current counter is less then new minimum, it sets the counter to the new minimum value.
    */
    void setMin(int);

    /*
        If the given number is above then the minimum counter value, sets the maximum counter value to the given number.
    */
    void setMax(int);

    /*
        Returns the current counter value.
    */
    int getState();

};

#include "Encoder.cpp" // To compile the cpp file and this header together. If you get multiply definition error, remove this line.
#endif