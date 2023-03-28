/*
Cronometro mediante leds.
Control de temporizador por encuesta.
Se utilizan los siguientes leds:
-------- // COMPLETAD!!!!!!

Autorxs:
Fecha: 
*/

#include "p24HJ256GP610A.h"

#include "GPIO.h"
#include "UART2_RS232.h"
#include "oscilator.h"
#include "timers.h"
#include "commons.h"
#include "memoria.h"
#include "LCD.h"
#include "ADC1.h"


int main()
{
    ///////////////////
    // Inicializadores 
    ///////////////////
	inic_oscilator();	// Oscilador a 80MHz. Reloj a 40MHz
    inic_leds();        // Luces LED
    inic_pulsadores();  // Botones
    inic_LCD();         // Pantalla LCD
    inic_UART2();       // UART
    inic_ADC1();        // Convertidor Analogico/Digital
    
    inic_crono();       // Variables de cronometro
    inic_Timer5();      // Timer actualizador de LCD
    inic_Timer7();      // Timer cronometro
	inic_Timer9();	    // Timer contador de delays
    

    // Copiar mensajes iniciales a pantalla LCD
    copiar_FLASH_RAM(Mens_LCD_7, 0);
    copiar_FLASH_RAM(Mens_LCD_6, 1);
    
    
    // Flag para alternar entre sensores
    int flag_sens = 0;
    
    while(1){
        cronometro();
        
        // Alternancia entre recogida de potenciometro o termometro
        flag_sens ^= 1; // XOR
        
        if (flag_sens)     select_pot();
        else               select_temp();
        
        // Muestreo ADC (por encuesta)
        comienzo_muestreo();
        while(!AD1CON1bits.DONE);
        
        // Actualizar LCD
        update_ADC();
    }

	return (0);
}
	





