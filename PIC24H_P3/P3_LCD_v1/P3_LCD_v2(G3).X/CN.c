#include "p24HJ256GP610A.h"
#include "commons.h"

void inic_CN(){
    IEC1bits.CNIE = 1;      // habilitacion de la interrupcion general de CN
    CNEN2bits.CN19IE = 1; //Habilitar interrupcion del pulsador s4
    CNEN2bits.CN16IE = 1; //Habilitar interrupcion del pulsador s6
	IFS1bits.CNIF = 0;      // Puesta a 0 del flag IF del modulo
}

void _ISR_NO_PSV _CNInterrupt()
{
  
    if(!PORTDbits.RD13) //pulsador s4
    {
        T7CONbits.TON = !T7CONbits.TON;	// parada del temporizador
    }else{
        if(!PORTDbits.RD7) //pulsador s6
        {
            flag_reset = 1;
        }
    }
    IFS1bits.CNIF = 0;
}
