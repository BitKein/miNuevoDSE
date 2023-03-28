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

// Definiciones
#define iPOT    0
#define iTEMP   1
#define iJSTK_X 2
#define iJSTK_Y 3


// Variables globales
unsigned char ascii[METRICAS][4];
long ADC1_muestras[METRICAS][NMUESTREOS];
long ADC1_avg[METRICAS];
int  cont_muestras[METRICAS];

int flag_ADC = 0;
int pagina_LCD = 1;
long num_conversiones;



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
    AD1CON1bits.SSRC = 2;    
    AD1CON1bits.ASAM = 1;

    // Muestreo simultaneo o secuencial
    //AD1CON1bits.SIMSAM = 0; 
                
    // Comienzo muestreo automatico o por programa (SAMP=1) 		
    //AD1CON1bits.ASAM = 0;

    /* ////////////////////////////////////////////////////// */

    // Inicializacion registro control AD1CON2
    AD1CON2 = 0;  // todos los campos a 0

    /* ////////////////////////////////////////////////////// */

    // Inicializacion registro control AD1CON3
    AD1CON3 = 0;    // todos los campos a 0

    // Reloj con el que funciona el ADC:  0= reloj CPU; 1= RC erlojua 
    //AD1CON3bits.ADRC = 0;  // 
    AD1CON3bits.SAMC = 31;   // Tiempo muestreo = numero de Tad 
    AD1CON3bits.ADCS = 3;   // Relacion entre TAD y Tcy. TAD = Tcy(ADCS+1)

    /* ////////////////////////////////////////////////////// */

    // Inicializacion registro control AD1CON4
    AD1CON4 = 0;

    /* ////////////////////////////////////////////////////// */

    // Inicializacion registro AD1CHS123
    AD1CHS123 = 0;	// seleccion del canal 1,2 eta 3

    /* ////////////////////////////////////////////////////// */

    // Inicializacion registro AD1CHS0
    AD1CHS0 = 0;

    // Entrada analogica conectada al convertidor
    AD1CHS0bits.CH0SA = AN_POT; // potenciometro como primera muestra a medir
    //AD1CHS0bits.CH0SB = 0;

    /* ////////////////////////////////////////////////////// */

    // Inicializacion registros AD1CSS 
    // Si escaneo secuencial 1, si no 0
    AD1CSSH = 0;   // AN16 - AN31 
    AD1CSSL = 0;   // AN0  - AN15 

    /* ////////////////////////////////////////////////////// */

    // Inicializacion registros AD1PCFG. Inicialmente todas AN como digitales
    AD1PCFGH = 0xFFFF;      // 1= digital / 0= Analog    (AN16 - AN31)
    AD1PCFGL = 0xFFFF;      // Puerto B, todos digitales (AN0  - AN15)

    // Inicializar como analogicas solo las que vayamos a usar
    AD1PCFGLbits.PCFG5 = 0;   // potenciometro       (AN5)
    AD1PCFGLbits.PCFG4 = 0;   // sensor temperatura  (AN4)
    AD1PCFGLbits.PCFG8 = 0;   // Joystick X-axis     (AN8)
    AD1PCFGLbits.PCFG9 = 0;   // Joystick Y-axis     (AN9)

    /* ////////////////////////////////////////////////////// */

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

    /* ////////////////////////////////////////////////////// */

    AD1CON1bits.ADON = 1;  // Habilitar el modulo ADC
}


/* ///////////////////////////////////////
   Comienzo del primer muestreo analogico
   ///////////////////////////////////////
 */
void comienzo_muestreo() {
    int i, j;
    
    for (i = 0; i < METRICAS; i++) {
        for (j = 0; j < NMUESTREOS; j++)
            ADC1_muestras[i][j] = 0;

        ADC1_avg[i] = 0;
        cont_muestras[i] = 0;
    }
    num_conversiones = 0;
    //AD1CON1bits.SAMP = 1; 
}

/* ///////////////////////////////////////
   Reiniciar muestreo analogico
   ///////////////////////////////////////
 */
void reiniciar_muestreo() {
    int i;

    // Reiniciar contadores de muestras y medias
    for (i = 0; i < METRICAS; i++){
        ADC1_avg[i] = 0;
        cont_muestras[i] = 0;
    }

    flag_ADC = 0;        // Desactivar actualizacion LCD
    AD1CON1bits.ADON = 1;       // Habilitar el modulo ADC
    //AD1CON1bits.SAMP = 1;       // Comenzar nuevo muestreo
}


/* ////////////////////////////////////////////////
   Actualizar valores en la LCD (por interrupcion)
   ////////////////////////////////////////////////
 */
void update_ADC(){
    int i, j;
    
    // Obtener medias
    for (i = 0; i < METRICAS; i++){
        for (j = 0; j < NMUESTREOS; j++)
            ADC1_avg[i] += ADC1_muestras[i][j];

        ADC1_avg[i] /= NMUESTREOS;
    }
    
    // Conversion metrica a ascii
    for (i = 0; i < METRICAS; i++)
        conversion_sensores(ascii[i], ADC1_avg[i]);

    
    switch(pagina_LCD){
        case 1:
            // Actualizar valor de potencia
            Ventana_LCD[0][pos_izq3] = ascii[iPOT][0];
            Ventana_LCD[0][pos_izq2] = ascii[iPOT][1];
            Ventana_LCD[0][pos_izq1] = ascii[iPOT][2];
            Ventana_LCD[0][pos_izq0] = ascii[iPOT][3];

            // Actualizar valor de temperatura
            Ventana_LCD[0][pos_der3] = ascii[iTEMP][0];
            Ventana_LCD[0][pos_der2] = ascii[iTEMP][1];
            Ventana_LCD[0][pos_der1] = ascii[iTEMP][2];
            Ventana_LCD[0][pos_der0] = ascii[iTEMP][3];
        break;

        case 2:
            // Actualizar valor de Joystick eje X
            Ventana_LCD[0][pos_izq3] = ascii[iJSTK_X][0];
            Ventana_LCD[0][pos_izq2] = ascii[iJSTK_X][1];
            Ventana_LCD[0][pos_izq1] = ascii[iJSTK_X][2];
            Ventana_LCD[0][pos_izq0] = ascii[iJSTK_X][3];

            // Actualizar valor de Joystick eje Y
            Ventana_LCD[0][pos_der3] = ascii[iJSTK_Y][0];
            Ventana_LCD[0][pos_der2] = ascii[iJSTK_Y][1];
            Ventana_LCD[0][pos_der1] = ascii[iJSTK_Y][2];
            Ventana_LCD[0][pos_der0] = ascii[iJSTK_Y][3];
        break;

        default:
        break;
    }


}



/* ////////////////////////////////////////////
   Actualizar valores de LCD (por interrupcion)
   ////////////////////////////////////////////
 */
void _ISR_NO_PSV _ADC1Interrupt(){
    int i, j;
    
    num_conversiones++;

    switch(AD1CHS0bits.CH0SA){
        case AN_POT: 
            j = cont_muestras[iPOT];

            ADC1_muestras[iPOT][j] = ADC1BUF0;  // Obtener valor del buffer
            AD1CHS0bits.CH0SA = AN_TEMP;        // Cambio de lectura de sensor

            cont_muestras[iPOT]++;
        break;

        case AN_TEMP: 
            j = cont_muestras[iTEMP];

            ADC1_muestras[iTEMP][j] = ADC1BUF0;  // Obtener valor del buffer
            AD1CHS0bits.CH0SA = AN_JSTK_X;        // Cambio de lectura de sensor

            cont_muestras[iTEMP]++;
        break;

        case AN_JSTK_X: 
            j = cont_muestras[iJSTK_X];

            ADC1_muestras[iJSTK_X][j] = ADC1BUF0;  // Obtener valor del buffer
            AD1CHS0bits.CH0SA = AN_JSTK_Y;        // Cambio de lectura de sensor

            cont_muestras[iJSTK_X]++;
        break;

        case AN_JSTK_Y: 
            j = cont_muestras[iJSTK_Y];

            ADC1_muestras[iJSTK_Y][j] = ADC1BUF0;  // Obtener valor del buffer
            AD1CHS0bits.CH0SA = AN_POT;        // Cambio de lectura de sensor

            cont_muestras[iJSTK_Y]++;
        break;
    }

    
    // Si hemos recogido suficientes muestras...

    int terminado = 1;

    for (i = 0; i < METRICAS; i++){
        if (cont_muestras[i] != NMUESTREOS){
            terminado = 0;
            break;
        }
    }

    if (terminado){
        AD1CON1bits.ADON = 0;  // Deshabilitar el modulo ADC
        flag_ADC = 1;   // Comenzar actualizacion LCD
       
      
    // Si no, realizar nuevo muestreo
    } /* else {
        AD1CON1bits.SAMP = 1; 
    }
    */
    // Desactiva el flag IF
    IFS0bits.AD1IF = 0;
}


