/*
Funciones de inicializacion y tratamiento de pulsadores y leds

Egileak: Alejandro Martin, Asier Septien y Garantigui Coulibaly
Data: Febrero 2023
*/


#include "p24HJ256GP610A.h"
#include "commons.h"

void inic_leds()
{
  TRISA = 0xff00; // Definir como salidas los 8 pines conectados a leds: RA7-RA0
  // El resto como entradas: 1 = In; 0 = Out
  Nop();	
  Nop();
  LATA=LATA & 0xff00; 	// Apagar los leds
	
}

void inic_pulsadores() {
    // Definir los pines de los pulsadores S3, S4 y S6 como entrada
	// S3(RD6), S6(RD7) y S4(RD13) 
    TRISDbits.TRISD6 = 1;
	TRISDbits.TRISD7 = 1;
	TRISDbits.TRISD13 = 1;
}
      
