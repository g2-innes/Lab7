//=====[#include guards - begin]===============================================

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum {
     DISPLAY_TYPE_LCD_HD44780, 
     DISPLAY_TYPE_GLCD_ST7920,
} displayType_t;

typedef enum {
     DISPLAY_CONNECTION_GPIO_4BITS,
     DISPLAY_CONNECTION_GPIO_8BITS,
     DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER,
     DISPLAY_CONNECTION_SPI
} displayConnection_t;

typedef enum {
     DISPLAY_MODE_CHAR, 
     DISPLAY_MODE_GRAPHIC
} displayMode_t;

typedef struct {
   displayConnection_t connection;
   displayType_t type;                                                                   
   displayMode_t mode;                                                  
} display_t;

//=====[Declarations (prototypes) of public functions]=========================

void displayInit( displayType_t type, displayConnection_t connection );
 
void displayCharPositionWrite( uint8_t charPositionX, uint8_t charPositionY );

void displayStringWrite( const char * str );

void displayClear( void );

// GLCD display only

void displayModeWrite( displayMode_t mode );

void displayBitmapWrite( uint8_t* bitmap );

//=====[#include guards - end]=================================================

#endif // _DISPLAY_H_