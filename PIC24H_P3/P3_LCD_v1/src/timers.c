#include "p24HJ256GP610A.h"
#include "commons.h"

void inic_Timer9 ()
{
    T9CONbits.TCS = 0;	// reloj interno
    T9CONbits.TGATE = 0;	// Deshabilitar el modo Gate
}	


void delay_ms(unsigned int ms){	// detecta que el timer ha llegado a los ms parametrados
    /* PRE: ms < 100 */
    
    TMR9 = 0;
    unsigned long pr = (unsigned long) ms * 40000;
    
    if (ms <= 13){ // solo si ms == 1, se usara prescaler 1:1
        T9CONbits.TCKPS = 1; // prescaler 1:8
        PR9 = (unsigned int) (pr / 8);
    }
    else { // abarca resto para ms < 100
        T9CONbits.TCKPS = 2;        
        PR9 = (unsigned int) (pr / 64); // prescaler 1:64
    }

    T9CONbits.TON = 1;	// puesta en marcha del timer

    // Encuesta continua
    while (!IFS3bits.T9IF);	// T7IF = 0. Wait until interruption flag == 1
    IFS3bits.T9IF = 0;

    T9CONbits.TON = 0;	// puesta en marcha del timer
}



void delay_us(unsigned long us){	// detecta que el timer ha llegado a los us parametrados
    TMR9 = 0;
    unsigned long pr = (unsigned long) us * 40;
    
    if (us <= 13000){ // solo si us == 1, se usara prescaler 1:1
        T9CONbits.TCKPS = 1; // prescaler 1:8
        PR9 = (unsigned int) (pr / 8);
    }
    else { // abarca resto para ms < 100
        T9CONbits.TCKPS = 2; // prescaler 1:64     
        PR9 = (unsigned int) (pr / 64);
    }

    T9CONbits.TON = 1;	// puesta en marcha del timer

    // Encuesta continua
    while (!IFS3bits.T9IF);	// T7IF = 0. Wait until interruption flag == 1
    IFS3bits.T9IF = 0;

    T9CONbits.TON = 0;	// puesta en marcha del timer
}

