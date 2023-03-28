/* Funciones relacionadas con el modulo OC para generar señal PWM
==================================================================
Autores: Garantigui Coulibaly, Alejandro Martin y Asier Septien
Fecha: 29-03-2023
*/

#include <math.h>

#include "p24HJ256GP610A.h"

#include "commons.h"
#include "memoria.h"
#include "LCD.h"
#include "ADC1.h"
#include "utilidades.h"
#include "OCPWM.h"

// OC1 -> pin RD0
int flag_OCPWM = 0;

/*
    Valor minimo y maximo de DUTY. 
    Se calculan  mediante los "define" PR20ms, MINPWM y MAXPWM
*/
unsigned int DUTY_MIN = (unsigned int) (PR20ms * MINPWM / 20); // ciclos minimos
unsigned int DUTY_MAX = (unsigned int) (PR20ms * MAXPWM / 20); // ciclos maximos
                              

void inic_OC1 () {
    OC1CON = 0;
    //OC1CONbits.OCM = 0b000;     // deshabilitar OC1 
    //OC1CONbits.OCTSEL = 0;      // seleccionar T2 para el OC
    
    OC1R  = (DUTY_MIN + DUTY_MAX) / 2; 	// Inicializar pulso con duracion intermedia
    OC1RS = OC1R;                       // inicializar registro secundario (pulso siguiente)

    OC1CONbits.OCM = 0b110;       // habilitar OC1 en modo PWM
}



/* ////////////////////////////////////
   Actualizar valores del servomotor 
   ////////////////////////////////////
 */
void update_OCPWM(){
    // Sumar o restar 10 unidades
    if      (flag_OCPWM == FLAGOC_SUMA  && (OC1R + 10) < DUTY_MAX)     OC1RS += 10; // Valor max = 1312.5, no se puede "<=""
    else if (flag_OCPWM == FLAGOC_RESTA && (OC1R - 10) >= DUTY_MIN)    OC1RS -= 10;

    // Conversion servomotor a ascii
    conversion_sensores(ascii[iDUTY], (unsigned long) OC1R);
    
    // Actualizar LCD
    updateOnLCD_PWM();

    flag_OCPWM = 0;
}

void update_duty(){
    OC1RS = ADC1_avg[iPOT] * 0.977517107 + 312;
    //OC1RS = (unsigned short) (ADC1_avg[iPOT] * (float) (1000 / 1023)) + 312;

    // Actualizar LCD
    updateOnLCD_PWM();
}

void updateOnLCD_PWM(){
    Nop();
    Nop();
    Nop();
    
    unsigned char conv[4];
    //Coversion del valor OC1RS a ascii
    conversion_sensores(conv,(unsigned int)OC1RS);
    Nop();
    Nop();
    Nop();
    
    // Actualizar LCD
    switch(pagina_LCD){
        case 3:
            // Actualizar valor de los Duty cycles del servomotor
            Ventana_LCD[0][pos_der3] = conv[0];
            Ventana_LCD[0][pos_der2] = conv[1];
            Ventana_LCD[0][pos_der1] = conv[2];
            Ventana_LCD[0][pos_der0] = conv[3];
        break;
        Nop();
        Nop();
        Nop();

        default:
        break;
    }
}