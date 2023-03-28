/*
 Funciones relacionadas con el modulo CN: inicializacion del modulo
 y rutina de atencion.

Egileak: Alejandro Martin, Asier Septien y Garantigui Coulibaly
Data: Febrero 2023
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "CN.h"
#include "timers.h"

// Variable global de ejecucion/parada
int start = 0;

// Funcion para inicializar el modulo CN
//==================
void inic_CN()
{
  	CNEN2bits.CN16IE = 1;	// habilitacion de la interrupcion del pin CN16
                            // que es al que esta conectado el pulsador S6
    
    CNEN1bits.CN15IE = 1;	// habilitacion de la interrupcion del pin CN15
                            // que es al que esta conectado el pulsador S3
    
    CNEN2bits.CN19IE = 1;	// habilitacion de la interrupcion del pin CN19
                            // que es al que esta conectado el pulsador S4
    
	IEC1bits.CNIE = 1;      // habilitacion de la interrupcion general de CN
	IFS1bits.CNIF = 0;      // Puesta a 0 del flag IF del modulo
}


// RUTINA DE ATENCION A LA INTERRUPCION DE CN
//==============================
void _ISR_NO_PSV _CNInterrupt()
{
		if (!PORTDbits.RD6 && !start) // pulsador S3 para iniciar
            start = 1;
		
        if (!PORTDbits.RD7 && start) // pulsador S6 para parar/continuar
            T7CONbits.TON = !T7CONbits.TON;	// apagar/encender Timer7

        if (!PORTDbits.RD13){
            mili = deci = seg = min = TMR7 = 0;
            LATA=LATA & 0xff00; 	// Apagar los leds
        }

        
	IFS1bits.CNIF = 0;		
}

