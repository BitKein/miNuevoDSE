#include "p24HJ256GP610A.h"

#include "oscilator.h"
#include "GPIO.h"
#include "commons.h"
#include "timers.h"
#include "LCD.h"
#include "memoria.h"
#include "utilidades.h"
#include "CN.h"


int main()
{
	unsigned int ms,ds,s,min;
	
	inic_oscilator();		// Seleccion e inicializacion del reloj: 40 MHz
	
	inic_leds();			// Inicializacio?n leds: sentido y valor inicial.
    
    inic_pulsadores();

    Init_LCD ();
    
	
    set_initial_text(); //pone el texto inicial en la LCD
    
    while(PORTDbits.RD13);       // encuesta sobre S
    
    inic_Timer7();			// Inicializacion T7
    inic_crono(&ms,&ds,&s,&min);	//Inicializacion variables cronometro.
    inic_CN();
    
    inic_Timer5();
    /* while(1){
        
        if(flag){
            cronometro(&ms,&ds,&s,&min);
            flag = 0;
        }        
        if(flag_reset) {
            reset_timer7(&ms,&ds,&s,&min);
            flag_reset = 0;
        }
        
	}
    */
    while(1) cronometro(&ms,&ds,&s,&min);
     
	return (0);
}
