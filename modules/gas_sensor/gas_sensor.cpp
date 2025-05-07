//=====[Libraries]=============================================================

#include "mbed.h"

#include "gas_sensor.h"

AnalogIn mq2(A3);

#define gasLimit 1800

float gasReading = 0.0;
float mq2Read = 0.0;


float mq2Sensor(float analogRead){
    return analogRead * 4800;
}

void gasTrigger(){  
    gasReading = mq2Sensor(mq2.read());
    //printf("gas reading: %.2f\n",gasReading);
}

bool gasDetectedRead(){
    if (gasReading > gasLimit ){
        return 1;}
    
    else{
        return 0;
    }
}

float mq2Sensor(){
    return mq2.read() *4800;
}