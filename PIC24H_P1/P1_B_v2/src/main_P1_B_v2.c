/*
 PRACTICA P1 B, v2
Egileak: Alejandro Martín, Asier Septién y Garantigui Coulibaly
Data: Febrero 2023
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "GPIO.h"
#include "CN.h"



int main()
{
 inic_leds();        
 inic_pulsadores(); 
 
 LATAbits.LATA6 = 1;  

 // STARTUP: encuesta sobre el pulsador S4 (RD13) 
 while (PORTDbits.RD6);
		
 LATAbits.LATA6 = 0;		//apagar D3 (RA0)
 LATAbits.LATA5 = 1;		//encender D4 (RA1)
 
 // INIT PROGRAM
 inic_CN();
 while(1);
}
