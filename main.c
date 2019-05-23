#include "Alteri.h"
#include "xlcd.h"

 
void Set_LCD (void)                       //Configuración del modulo LCD 
{
    OpenXLCD (EIGHT_BIT & LINES_5X7);
    WriteCmdXLCD (SHIFT_DISP_LEFT);
    WriteCmdXLCD (DON);
    WriteCmdXLCD (BLINK_OFF);
 
}

void Write_firstMessage (void)           //Escribe el mensaje en la pantalla.
{
    putrsXLCD ("MICROCHIP PIC18F");
    WriteCmdXLCD (NEXT_LINE);
    putrsXLCD ("  Hola Mundo  ");
    
}
    
void Write_secondMessage(void)         //Escribe un segundo mensaje, borrando primero el anterior.
{
    putrsXLCD("== ALTERI ==");
    WriteCmdXLCD (NEXT_LINE);
    putrsXLCD ("  YEAR 2019  ");
}
void main (void)
{
   
    Set_LCD();
    Write_firstMessage();
    
    delay_ms (2000);
    WriteCmdXLCD (BORRAR_PANTALLA);
    Write_secondMessage();
    while (1);
}

void DelayFor18TCY (void)
{
    _delay(240);
}

void DelayPORXLCD (void)
{
    delay_ms(15);
}


void DelayXLCD (void)
{  
    delay_ms(5);
}