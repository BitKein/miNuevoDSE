/* Funciones para los puertos de entrada/salida
================================================
Autores: Garantigui Coulibaly, Alejandro Martin y Asier Septien
Fecha: 29-03-2023
*/
#include "p24HJ256GP610A.h"
#include "commons.h"

void inic_leds(){
  TRISA = 0xFF00; // Definir como salidas los 8 pines conectados a leds: RA7-RA0		  
                  // El resto como entradas: 1 = In; 0 = Out

  //LATA=LATA & 0xff00; 	// Apagar los leds
	
}


void inic_pulsadores()
{
    AD1PCFGH = 0xFFFF;     //Definir pines AN16 - AN31 como pines digitales
    TRISDbits.TRISD6 = 1;  //Pulsador s3 .Definimos el pin como entrada
    TRISDbits.TRISD7 = 1;  //Pulsador s6. Definimos el pin como entrada
    TRISDbits.TRISD13 = 1; //Pulsador s4. Definimos el pin como entrada
}
