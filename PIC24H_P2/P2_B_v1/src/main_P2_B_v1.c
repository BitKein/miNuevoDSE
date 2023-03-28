/*
Cronometro mediante leds.
Control de temporizador por encuesta.
Se utilizan los siguientes leds:
-------- // COMPLETAD!!!!!!

Autores: Alejandro Martin, Asier Septien y Garantigui Coulibaly
Fecha: Febrero 2023
*/

#include "p24HJ256GP610A.h"

#include "oscilator.h"
#include "GPIO.h"
#include "timers.h"
#include "commons.h"
#include "CN.h"




int main()
{
    
	inic_oscilator();	// Seleccion e inicializacion del reloj: 80 MHz
	
	inic_leds();	// Inicializacion leds: sentido y valor inicial.
    
    inic_pulsadores(); // Inicializacion pulsadores: sentido (entrada)
	    
    inic_CN(); // Inicializacion rutinas de atencion de los pulsadores

    while(!start);
    
    inic_crono();	//Inicializacion variables cronometro.

    inic_Timer7();	// Inicializacion T7 con un periodo de 10 milisegundos.

	while(1) cronometro();
    
	return (0);
}
	





