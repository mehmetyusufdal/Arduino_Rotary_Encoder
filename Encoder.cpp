/*
    --Arduino_Rotary_Encoder by Mehmet Yusuf Dal--
    This is a simple Arduino library for minimizing the code while using rotary encoder modules like Ky-040.
*/

#ifndef _ENCODER_
#define _ENCODER_
#include "Encoder.h"

Encoder::Encoder(int A, int B, int c_start, int c_min, int c_max){
    if(c_min > c_max){
        c_min = N_INF;
        c_max = P_INF;
    }

    Encoder::c_min = c_min;
    Encoder::c_max = c_max;

    if(c_min <= c_start){
        if(c_max >= c_start){
            Encoder::counter = c_start;
            Encoder::c_start = c_start;
        }
        else{
            Encoder::counter = c_max;
            Encoder::c_start = c_max;
        }
    }
    else{
        Encoder::counter = c_min;
        Encoder::c_start = c_min;
    }

    Encoder::A = A;
    Encoder::B = B;
    
    pinMode(A, INPUT);
    pinMode(B, INPUT);

    Encoder::A_last_state = digitalRead(A);

}

void Encoder::stateControl(){
    Encoder::A_state = digitalRead(Encoder::A);

    if(Encoder::A_state != Encoder::A_last_state){
        if(digitalRead(Encoder::B) != Encoder::A_state){
            if(Encoder::counter < Encoder::c_max) Encoder::counter++;
        }
        else{
            if(Encoder::counter > Encoder::c_min) Encoder::counter--;
        }

        Encoder::A_last_state = Encoder::A_state;
    }

}

void Encoder::setMin(int c_min){
    if(c_min < Encoder::c_max ){
        Encoder::c_min = c_min;
        if(Encoder::counter < c_min) Encoder::counter = c_min;
    }

}

void Encoder::setMax(int c_max){
    if(c_max > Encoder::c_min){
        Encoder::c_max = c_max;
        if(Encoder::counter > c_max) Encoder::counter = c_max;
    }

}

void Encoder::setStart(int c_start){
    if(Encoder::c_min <= c_start){
        if(Encoder::c_max >= c_start){
            Encoder::c_start = c_start;
        }
        else{
            Encoder::c_start = Encoder::c_max;
        }
    }
    else{
        Encoder::c_start = Encoder::c_min;
    }

}

void Encoder::resetCounter(){
    Encoder::counter = Encoder::c_start;

}

int Encoder::getState(){ return Encoder::counter; }

#endif