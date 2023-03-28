/*
Cronometro mediante leds.
Control de temporizador por encuesta.
Se utilizan los siguientes leds:
-------- // COMPLETAD!!!!!!

Autorxs:
Fecha: 
*/

#include "p24HJ256GP610A.h"

#include "oscilator.h"
#include "timers.h"
#include "commons.h"


int main()
{
    
	inic_oscilator();	// Seleccion e inicializacion del reloj: 80 MHz	
	inic_Timer9();	// Inicializacion T9

	
    // Testeo de delays
    delay_ms(5);
    Nop(); Nop(); Nop();
    
    delay_ms(15);
    Nop(); Nop(); Nop();

    delay_ms(45);
    Nop(); Nop(); Nop();


    
    delay_us(75);
    Nop(); Nop(); Nop();
    
    delay_us(300);
    Nop(); Nop(); Nop();

    delay_us(1400);
    Nop(); Nop(); Nop();


	return (0);
}
	





