/*
Impresion en LCD de datos analogicos convertidos digitalmente.
================================================================
Autores: Garantigui Coulibaly, Alejandro Martin y Asier Septien
Fecha: 20-03-2023
*/

#include "p24HJ256GP610A.h"

#include "commons.h"
#include "GPIO.h"
#include "CN.h"
#include "oscilator.h"
#include "timers.h"
#include "memoria.h"
#include "LCD.h"
#include "UART2_RS232.h"
#include "ADC1.h"


int main()
{
    ///////////////////
    // Inicializadores 
    ///////////////////
	inic_oscilator();	    // Oscilador a 80MHz. Reloj a 40MHz
    inic_leds();            // Luces LED
    inic_pulsadores();      // Botones
    TRISAbits.TRISA7 = 1;   // Pulsador S5 (I) / LED D10 (O). Config como I (pulsador)
    inic_LCD();             // Pantalla LCD
    inic_UART2();           // UART
    inic_ADC1();            // Convertidor Analogico/Digital
    
    inic_Timer5();          // Timer actualizador de LCD
	inic_Timer9();	        // Timer contador de delays
    


    /////////////
    // Programa
    /////////////
    
    // Primera pantalla
    copiar_FLASH_RAM(Mens_LCD_3, 0); /* "---- ADC_v2 ----" */
    copiar_FLASH_RAM(Mens_LCD_2, 1); /* "--- Pulsa S3  --" */
    while(PORTDbits.RD6); // wait for S3

    // Copiar mensajes iniciales a pantalla LCD
    copiar_FLASH_RAM(Mens_LCD_7, 0); /* "P: 0000  T: 0000" */
    copiar_FLASH_RAM(Mens_LCD_6, 1); /* "Crono: 00:00,0  " */

    // Inicializaciones de comienzo de programa
    inic_CN();           // Interrupciones de CN (pulsadores)
    inic_crono();        // Variables de cronometro
    inic_Timer7();       // Timer cronometro

    // Comienzo de muestreo
    comienzo_muestreo(); // Inicializacion de muestreo (por interrupcion)
    inic_Timer3();       // Timer siguiente muestreo


    while(1) {
        // Evaluar tiempo transcurrido + Actualizar crono en LCD
        cronometro();
        
        // Actualizar LCD con muestras nuevas de los sensores
        if (flag_ADC){
            update_ADC();
            reiniciar_muestreo();
        }
    }

	return (0);
}
	





