#include "p24HJ256GP610A.h"
#include "commons.h"

void inic_Timer7 ()
{
    TMR7 = 0 ; 	// Inicializar el registro de cuenta
    PR7 =  50000 ;	// Periodo del timer
		// Queremos que cuente 10 ms.
		// Fosc= 80 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 40 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 25 ns para ejecutar una instruccion
		// Para contar 10 ms se necesitan XXX ciclos.
   // T7CONbits.TCKPS = x;	// escala del prescaler XXX
    T7CONbits.TCS = 0;	// reloj interno
    T7CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    
    //T7CONbits.TON = 1;	// puesta en marcha del timer, lo hacemos cuando se pulse S3
}	

unsigned int mili,deci,seg,min;
void inic_crono()	
// inicializacion de las variables del cronometro
{
	IFS3bits.T7IF=0;
    IEC3bits.T7IE=1;
    mili=0;
    deci=0;
    seg=0;
}

/* 
void delay_10ms()	// detecta que el timer ha llegado a 10 milisegundos
{
	
 
}
*/



void cronometro()	
{
    /*DOS BOTONES: UNO PARA ENCENDER Y OTRO PARA APAGAR
     
    //encuesta para detectar cuando se pulsa S3 y empezar
    while(PORTDbits.RD6);
    T7CONbits.TON=1;
    //encuesta para detectar cuando se pulsa S4 y parar
    while(PORTDbits.RD13);
    T7CONbits.TON=0;
    
    while(1); 
    */
    
    //TRES BOTONES: UNO PARA EMPEZAR
    //encuesta para detectar cuando se pulsa S3 y empezar
    while(PORTDbits.RD6);
    T7CONbits.TON=1;
    while(1){
      //encuesta para detectar cuando se pulsa S4 y parar
      if(!PORTDbits.RD13){
          T7CONbits.TON=!T7CONbits.TON;
      }
      //encuesta para detectar cuando se pulsa S6 y reiniciar
      if(!PORTDbits.RD7){
          T7CONbits.TON=0;
          TMR7=0;
          LATA=0xff00;
      }
    }
    
    while(1); 
    
}


void _ISR_NO_PSV _T7Interrupt(){
    
    
    mili++;
    if(mili==100){
        deci++;
        mili=0;
        LATAbits.LATA0=!LATAbits.LATA0;
    }
    if(deci==10){
        seg++;
        deci=0;
        LATAbits.LATA1=!LATAbits.LATA1;
    }
    IFS3bits.T7IF=0;
}
