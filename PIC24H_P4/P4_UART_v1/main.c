#include "p24HJ256GP610A.h"

#include "oscilator.h"
#include "GPIO.h"
#include "commons.h"
#include "timers.h"
#include "LCD.h"
#include "memoria.h"
#include "utilidades.h"
#include "UART2_RS232.h"


int main()
{

	
	inic_oscilator();		// Seleccion e inicializacion del reloj: 40 MHz
	inic_leds();			// Inicializacio?n leds: sentido y valor inicial
    Init_LCD();
	
    set_initial_text(); // pone el texto inicial en la LCD
        
    inic_crono();	//Inicializacion variables cronometro.
    inic_Timer5();
    inic_Timer7();
    inic_UART2();

    while(1) cronometro();
     
	return (0);
}
