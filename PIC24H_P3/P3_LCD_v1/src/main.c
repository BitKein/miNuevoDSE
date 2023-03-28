/*
Autores: Alejandro Martin, Asier Septien y Garantigui Coulibaly
Fecha: Febrero 2023
*/

#include "p24HJ256GP610A.h"

#include "oscilator.h"
#include "GPIO.h"
#include "timers.h"
#include "commons.h"


int main()
{
    
    inic_pulsadores();
    Init_LCD();

    copiar_FLASH_RAM(Mens_LCD_1, 0);
    copiar_FLASH_RAM(Mens_LCD_2, 1);
    while(PORTDbits.RD6);
    
    copiar_FLASH_RAM(Mens_LCD_3, 0);
    copiar_FLASH_RAM(Mens_LCD_4, 1);
    while(PORTDbits.RD13);

    
    copiar_FLASH_RAM(Mens_LCD_5, 0);
    copiar_FLASH_RAM(Mens_LCD_6, 1);
    inic_Timer9();
    
	while(1) cronometro();
    
	return (0);
}
	





