#include "p24HJ256GP610A.h"
#include "commons.h"

#include "CN.h"

void inic_Timer7 ()
{
    TMR7 = 0 ; 	// Inicializar el registro de cuenta
    PR7 =  50000 ;	// Periodo del timer ( 400k ciclos * 1:8 prescaler )
		// Queremos que cuente 10 ms.
		// Fosc= 80 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 40 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 25 ns para ejecutar una instruccion
		// Para contar 10 ms se necesitan 400k ciclos.
    T7CONbits.TCKPS = 1;	// escala del prescaler 1:8     = 0b01 
    T7CONbits.TCS = 0;	// reloj interno
    T7CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    
    T7CONbits.TON = 1;	// puesta en marcha del timer
    
    // INTERRUPCION
    IEC3bits.T7IE = 1; // Habilitar rutina de atenci�n para Timer7
}	

// Declaraci�n de variables del cronometro
unsigned int mili, deci, seg, min;

void inic_crono()	
// inicializacion de las variables del cronometro
{
    mili = deci = seg = min = 0;
}


// RUTINA DE ATENCION A LA INTERRUPCION DE Timer7
//==============================
void _ISR_NO_PSV _T7Interrupt(){
    
    // control del tiempo espera 10 ms y luego actualiza
    mili += 10;
        
    // Reset flag
    IFS3bits.T7IF = 0;
    
}

void cronometro(){
    // Actualizacion de LEDs

    if (mili == 100){
        mili = 0;
        deci++;
        LATAbits.LATA2 = !LATAbits.LATA2; // LED de decimas de segundo

        if (deci == 10){
            deci = 0;
            seg++;
            LATAbits.LATA3 = !LATAbits.LATA3; // LED de segundo

            if (seg == 60){
                seg = 0;
                min++;
            }
        }
    }
}