/*
 Funciones relacionadas con el modulo CN: inicializacion del modulo
 y rutina de atencion.

Egileak: Alejandro Mart�n, Asier Septi�n y Garantigui Coulibaly
Data: Febrero 2023
*/

#include "p24HJ256GP610A.h"
#include "commons.h"

// Funcion para inicializar el modulo CN
//==================
void inic_CN()
{
  	CNEN2bits.CN23IE = 1;	// habilitacion de la interrupcion del pin CN23 que es al que esta conectado el pulsador S5
    CNEN2bits.CN16IE = 1;	// habilitacion de la interrupcion del pin CN16 que es al que esta conectado el pulsador S6
    CNEN2bits.CN19IE = 1;	// habilitacion de la interrupcion del pin CN19 que es al que esta conectado el pulsador S4
                            // que es al que esta conectado el pulsador S6
	IEC1bits.CNIE = 1;      // habilitacion de la interrupcion general de CN
	IFS1bits.CNIF = 0;      // Puesta a 0 del flag IF del modulo
}


// RUTINA DE ATENCION A LA INTERRUPCION DE CN
//==============================
void _ISR_NO_PSV _CNInterrupt()
{
		/*if (!PORTDbits.RD7)     
			{
				LATAbits.LATA4 = !LATAbits.LATA4; //kommutatu D7 LEDaren egoera
			}
         */
    if(!PORTDbits.RD7)  LATAbits.LATA4 = !LATAbits.LATA4;
    if(!PORTDbits.RD13) LATAbits.LATA0 = !LATAbits.LATA0;
    if(!PORTAbits.RA7)  LATAbits.LATA2 = !LATAbits.LATA2;
	IFS1bits.CNIF = 0;		
}

