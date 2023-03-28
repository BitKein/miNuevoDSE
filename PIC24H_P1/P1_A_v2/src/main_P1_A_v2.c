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
    AD1PCFGH=0xFFFF;
    TRISA = 0xFF00;
    // Pulsadores en el puerto D
    TRISDbits.TRISD6 = 1;	// Pulsador S3 / RD6
    TRISDbits.TRISD7 = 1;	// Pulsador S6 / RD7
    TRISDbits.TRISD13 = 1;	// Pulsador S4 / RD13

    // El pin RA7 es especial ya que tiene conectados el pulsador S5 y el led D10

    TRISAbits.TRISA7 = 1;
    
    /************************/
    
    
    
    // bucle principal
    while (1) {
        // Pulsar S3
       
        if (!PORTDbits.RD6) {
            TRISAbits.TRISA7 = 0; // disable S5, enable D10
            Nop(); Nop();

            Nop(); // Nops para el debugger (breaks actúan tarde -- 2-3 instr.)
            Nop();
            LATAbits.LATA7 = 0; // apagar D10
            LATAbits.LATA6 = 1; // encender D9
            Nop();
            Nop();
        }
        else{
            TRISAbits.TRISA7 = 0; // disable S5, enable D10
            Nop(); Nop();

            Nop(); 
            Nop();
            LATAbits.LATA7 = 1; // encender D10
            LATAbits.LATA6 = 0; // apagar D9
            Nop();
            Nop();
        }
        
        // Pulsar S4
        if (!PORTDbits.RD13) {
            Nop();
            Nop();
            LATAbits.LATA1 = 0; // apagar D4
            LATAbits.LATA0 = 1; // encender D3 
            Nop();
            Nop();
        }
        else {
            Nop();
            Nop();
            LATAbits.LATA1 = 1; // encender D4
            LATAbits.LATA0 = 0; // apagar D3 
            Nop();
            Nop();
        }
        
        // Pulsar S5
        TRISAbits.TRISA7 = 1; // enable S5, disable D10
        Nop(); Nop(); Nop(); Nop();
        
        if (!PORTAbits.RA7 && TRISAbits.TRISA7 == 1) {
        TRISAbits.TRISA7 = 0;
            Nop();
            Nop();
            LATAbits.LATA3 = 0; // apagar D6
            LATAbits.LATA2 = 1; // encender D5 
            Nop();
            Nop();
        }
        else {
            TRISAbits.TRISA7 = 0;
            Nop();
            Nop();
            LATAbits.LATA3 = 1; // encender D6
            LATAbits.LATA2 = 0; // apagar D5
            Nop();
            Nop();
        }
        
        // Pulsar S6
        if (!PORTDbits.RD7) { 
            Nop();
            Nop();
            LATAbits.LATA5 = 0; // apagar D8
            LATAbits.LATA4 = 1; // encender D7 
            Nop();
            Nop();
        }
        else {
            Nop();
            Nop();
            LATAbits.LATA5 = 1; // encender D8
            LATAbits.LATA4 = 0; // apagar D7
            Nop();
            Nop();
        }
        
        /*
        // Encender LEDs por default
        LATAbits.LATA1 = 1; // D4
        LATAbits.LATA3 = 1; // D6
        LATAbits.LATA5 = 1; // D8
        LATAbits.LATA7 = 1; // D10 <- observar si va bien, por el pin RA7
        
        // Apagar LEDs por default
        LATAbits.LATA0 = 0; // D3
        LATAbits.LATA2 = 0; // D5
        LATAbits.LATA4 = 0; // D7
        LATAbits.LATA6 = 0; // D9
         */
        
    }
    
}
