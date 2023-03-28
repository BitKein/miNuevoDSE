/*
 * File:   main_P1_A_v1.c
 * Author: Alejandro Martín y Asier Septién
 *
 * Created on 26/01/2023
 */

#include "p24HJ256GP610A.h"

main(void) {
    // inicializaciones de los pines como entrada o salida
    // 1= IN (entrada); 0= OUT (salida)
    // leds en el puerto A: RA7-RA0. El resto como entrada
    AD1PCFGH = 0xFFFF; // Desactivar detección analógica, redirect a digital (RA7)
    TRISA = 0xFF00;
    // Pulsadores en el puerto D
    TRISDbits.TRISD6 = 1;	// Pulsador S3 / RD6
    TRISDbits.TRISD7 = 1;	// Pulsador S6 / RD7
    TRISDbits.TRISD13 = 1;	// Pulsador S4 / RD13

    // El pin RA7 es especial ya que tiene conectados el pulsador S5 y el led D10
    // Se cambiará de valor en función de si miramos el led o el pulsador
    TRISAbits.TRISA7 = 1;
    
    // bucle principal
    while (1) {
        TRISAbits.TRISA7 = 1; // enable S5, disable D10
        Nop(); Nop(); Nop(); Nop();
        
        while (!PORTAbits.RA7) {
            TRISAbits.TRISA7 = 0; // disable S5, enable D10
            //Nop(); Nop(); Nop(); Nop();
            
            LATAbits.LATA7 = 0;
            LATAbits.LATA3 = 1;
            
            TRISAbits.TRISA7 = 1; // enable S5, disable D10
            Nop(); Nop(); Nop(); Nop();
        }
        
        TRISAbits.TRISA7 = 0; // disable S5, enable D10
        //Nop(); Nop(); Nop(); Nop();
        
        LATAbits.LATA7 = 1;
        LATAbits.LATA3 = 0;

    }
    
}


