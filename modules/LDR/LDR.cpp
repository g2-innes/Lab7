//=====[Libraries]=============================================================

#include "mbed.h"
#include "LDR.h"
#include "fire_alarm.h"

AnalogIn LDR_Raw(A2);
AnalogIn LDR_Filtered(A4);

float LDR_Raw_Reading = 0.0;
float LDR_Filtered_Reading = 0.0;



float LDR_Raw_Output(){
    LDR_Raw_Reading = LDR_Raw.read();
    return LDR_Raw_Reading;
}

float LDR_Filtered_Output(){
    LDR_Filtered_Reading = LDR_Filtered.read();
    
    if (LDR_Filtered_Reading > 1){
        LDR_Filtered_Reading = 1;
    }
    if (LDR_Filtered_Reading < 0.1){
        LDR_Filtered_Reading = 0;
    }
    return LDR_Filtered_Reading;
}

