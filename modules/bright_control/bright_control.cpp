//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "bright_control.h"
#include "light_level_control.h"
#include "LDR.h"

//=====[Declaration of private defines]========================================

#define LEDS_QUANTITY 3

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut RGBLed[] = {(PB_4), (PA_0), (PD_12)};

Ticker tickerBrightControl;

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static int onTime[LEDS_QUANTITY];
static int offTime[LEDS_QUANTITY];

static int tickRateMSBrightControl = 1;
static int tickCounter[LEDS_QUANTITY];

static float periodSFloat[LEDS_QUANTITY];




//=====[Declarations (prototypes) of private functions]========================

static void setPeriod( lightSystem_t light, float period );
static void tickerCallbackBrightControl( );

//=====[Implementations of public functions]===================================

void brightControlInit()
{
    tickerBrightControl.attach( tickerCallbackBrightControl, 
                              ( (float) tickRateMSBrightControl) / 1000.0 );

    setPeriod( RGB_LED_RED, 0.01f );
    setPeriod( RGB_LED_GREEN, 0.01f );
    setPeriod( RGB_LED_BLUE, 0.01f );

    //RGBLed[0].write(1.0f);
    //RGBLed[1].write(0.5f);
    //RGBLed[2].write(0.0f);
}

void setDutyCycle( lightSystem_t light, float dutyCycle )
{
    RGBLed[light].write(dutyCycle);
}

//=====[Implementations of private functions]==================================

static void setPeriod( lightSystem_t light, float period )
{
    periodSFloat[light] = period;
}


static void tickerCallbackBrightControl( )
{
    for (int i = 0 ; i < LEDS_QUANTITY ; i++) {
    RGBLed[i].write(LDR_Filtered_Reading);     
    }
}