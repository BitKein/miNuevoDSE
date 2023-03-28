/*
 Funciones relacionadas con el modulo CN: inicializacion del modulo
 y rutina de atencion.
====================================================================
Autores: Garantigui Coulibaly, Alejandro Martin y Asier Septien
Fecha: 29-03-2023
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "CN.h"
#include "memoria.h"
#include "LCD.h"

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
void _ISR_NO_PSV _CNInterrupt() {

	// Mostrar otras metricas
	if (!PORTDbits.RD13) // pulsador S4
		cambiar_pagina();

    // Desactiva el flag IF
	IFS1bits.CNIF = 0;
}

// Mostrar otras metricas en pantalla
//==================
void cambiar_pagina() {
	pagina_LCD++;
    
    if (pagina_LCD > NPAGINAS_LCD)
        pagina_LCD = 1;
    
    switch(pagina_LCD){
        case 1:
            copiar_FLASH_RAM(Mens_LCD_7, 0); /* "P: 0000  T: 0000" */
        break;
        
        case 2:
            copiar_FLASH_RAM(Mens_LCD_8, 0); /* "X: 0000  Y: 0000" */
        break;
        
        case 3:
            copiar_FLASH_RAM(Mens_LCD_9, 0); /* "      DUTY: 0000" */
        break;

        default: 
        break;
    }
	
}