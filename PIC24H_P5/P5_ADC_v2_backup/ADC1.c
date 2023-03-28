/* Funciones para el modulo ADC1
==================================
Autores: Garantigui Coulibaly, Alejandro Martin y Asier Septien
Fecha: 20-03-2023
*/

#include <p24HJ256GP610A.h>
#include "ADC1.h"
#include "LCD.h"
#include "commons.h"
#include "memoria.h"
#include "utilidades.h"

// Variables globales
unsigned char pot_ascii[4], temp_ascii[4];
long ADC1pot[NMUESTREOS], ADC1temp[NMUESTREOS];
long ADC1pot_avg, ADC1temp_avg;
int flag_ADC;
int samp_pot, samp_temp;


/* /////////////////////////////
   Inicializador del modulo ADC 
   /////////////////////////////
 */
void inic_ADC1 (void) {
// Inicializacion registro control AD1CON1
AD1CON1 = 0;       // todos los campos a 0

// Salida de 12 bits o 10 bits
//AD1CON1bits.AD12B = 0;  

// Comienzo digitalizacion automatico
// 111=Auto-convert / 010=TMR3 ADC1 y TMR5 ADC2 / 001=INT0 / 000= SAMP 
AD1CON1bits.SSRC = 7;    		

// Muestreo simultaneo o secuencial
//AD1CON1bits.SIMSAM = 0; 
             
// Comienzo muestreo automatico o por programa (SAMP=1) 		
//AD1CON1bits.ASAM = 0;

                    
// Inicializacion registro control AD1CON2
AD1CON2 = 0 ;  // todos los campos a 0


// Inicializacion registro control AD1CON3
AD1CON3 = 0;    // todos los campos a 0
// Reloj con el que funciona el ADC:  0= reloj CPU; 1= RC erlojua 
//AD1CON3bits.ADRC = 0;  // 
AD1CON3bits.SAMC = 31;   // Tiempo muestreo = numero de Tad 
AD1CON3bits.ADCS = 3;   // Relacion entre TAD y Tcy TAD = Tcy(ADCS+1)


// Inicializacion registro control AD1CON4
AD1CON4 = 0;


// Inicializacion registro AD1CHS123
AD1CHS123 = 0;	//seleccion del canal 1,2 eta 3


// Inicializacion registro AD1CHS0
AD1CHS0 = 0;

// Asignamos primer muestreo para potenciometro
AD1CHS0bits.CH0SA = AN_POT; // elige la entrada analogica conectada

//AD1CHS0bits.CH0SB = 0;


// Inicializacion registros AD1CSS 
// Si escaneo secuencial 1, si no 0

AD1CSSH = 0;   // 16-31 
AD1CSSL = 0;   // 0-15 

// Inicializacion registros AD1PCFG. Inicialmente todas AN como digitales
AD1PCFGH = 0xFFFF;      // 1= digital / 0= Analog
AD1PCFGL = 0xFFFF;      // Puerto B, todos digitales
// Inicializar como analogicas solo las que vayamos a usar
AD1PCFGLbits.PCFG5 = 0;   // potenciometro
AD1PCFGLbits.PCFG4 = 0;   // sensor temperatura

// Bits y campos relacionados con las interrupciones
IFS0bits.AD1IF = 0;    
IEC0bits.AD1IE = 1; // Interrupcion activada    
//IPC3bits.AD1IP=xx;    

// Config DMA/Interrupcion
AD1CON2bits.SMPI = 0; // 0 = NO usar DMA. Activar por interrupcion
//AD1CON2bits.SMPI3 = 0;
//AD1CON2bits.SMPI2 = 0;
//AD1CON2bits.SMPI1 = 0;
//AD1CON2bits.SMPI0 = 0;


//AD1CON
AD1CON1bits.ADON = 1;  // Habilitar el modulo ADC
}


/* ///////////////////////////////////////
   Comienzo del primer muestreo analogico
   ///////////////////////////////////////
 */
void comienzo_muestreo() {
    int i;
    for (i = 0; i < NMUESTREOS; i++){
        ADC1pot[i] = 0;
        ADC1temp[i] = 0;
    }
    ADC1pot_avg = ADC1temp_avg = 0;
    
    samp_pot = samp_temp = 0;
    flag_ADC = 0;
    
    AD1CON1bits.SAMP = 1; 
}

/* ///////////////////////////////////////
   Reiniciar muestreo analogico
   ///////////////////////////////////////
 */
void reiniciar_muestreo() {
    samp_pot = samp_temp = 0;   // Reiniciar contador de muestras
    ADC1pot_avg = ADC1temp_avg = 0;
    flag_ADC = 0;        // Desactivar actualizacion LCD
    AD1CON1bits.ADON = 1;       // Habilitar el modulo ADC
    AD1CON1bits.SAMP = 1;       // Comenzar nuevo muestreo
}


/* ////////////////////////////////////////////////
   Actualizar valores en la LCD (por interrupcion)
   ////////////////////////////////////////////////
 */
void update_ADC(){
    int i;
    
    // Obtener medias
    for(i = 0; i < NMUESTREOS; i++){
        ADC1pot_avg += ADC1pot[i];
        ADC1temp_avg += ADC1temp[i];
    }
    ADC1pot_avg  /= NMUESTREOS;
    ADC1temp_avg /= NMUESTREOS;
    
    // Conversion metrica a ascii
    conversion_sensores(pot_ascii, ADC1pot_avg);
    conversion_sensores(temp_ascii, ADC1temp_avg);
    
    // Actualizar valor de potencia
    Ventana_LCD[0][pos_p3] = pot_ascii[0];
    Ventana_LCD[0][pos_p2] = pot_ascii[1];
    Ventana_LCD[0][pos_p1] = pot_ascii[2];
    Ventana_LCD[0][pos_p0] = pot_ascii[3];

    // Actualizar valor de temperatura
    Ventana_LCD[0][pos_t3] = temp_ascii[0];
    Ventana_LCD[0][pos_t2] = temp_ascii[1];
    Ventana_LCD[0][pos_t1] = temp_ascii[2];
    Ventana_LCD[0][pos_t0] = temp_ascii[3];

}



/* ////////////////////////////////////////////
   Actualizar valores de LCD (por interrupcion)
   ////////////////////////////////////////////
 */
void _ISR_NO_PSV _ADC1Interrupt(){

    if (AD1CHS0bits.CH0SA == AN_POT){
        ADC1pot[samp_pot++] = ADC1BUF0;             // Obtener valor del buffer
        AD1CHS0bits.CH0SA = AN_TEMP;    // Cambio de lectura de sensor
        
    } else if(AD1CHS0bits.CH0SA == AN_TEMP){
        ADC1temp[samp_temp++] = ADC1BUF0;            // Obtener valor del buffer
        AD1CHS0bits.CH0SA = AN_POT;     // Cambio de lectura de sensor
    }
    
    // Si hemos recogido suficientes muestras...
    if (samp_pot == 8 && samp_temp == 8){
        AD1CON1bits.ADON = 0;  // Deshabilitar el modulo ADC
        flag_ADC = 1;   // Comenzar actualizacion LCD
       
        
    // Si no, realizar nuevo muestreo
    } else {
        AD1CON1bits.SAMP = 1; 
    }
    
    // Desactiva el flag IF
    IFS0bits.AD1IF = 0;
}


