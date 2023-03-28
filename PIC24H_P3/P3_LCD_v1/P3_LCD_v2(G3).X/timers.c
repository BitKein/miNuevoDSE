#include "p24HJ256GP610A.h"
#include "commons.h"
#include "LCD.h"
#include "memoria.h"
#include "utilidades.h"

int flag;
int flag_reset;
unsigned char estado_lcd = 0;


void inic_Timer7 ()
{

    TMR7 = 0 ; 	// Inicializar el registro de cuenta
    PR7 =  25000 - 1;	// Periodo del temporizador, 200000 ciclos / prescales, menos 1 porque empieza en 0
		// Queremos que cuente 10 ms.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 10 ms se necesitan 200000 ciclos.
    T7CONbits.TCKPS = 1;	// escala del prescaler 8
    T7CONbits.TCS = 0;	// reloj interno
    T7CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    T7CONbits.TON = 1;	// puesta en marcha del temporizador
    IEC3bits.T7IE = 1;      // habilitacion de la interrupcion de T7
	IFS3bits.T7IF = 0;      // Puesta a 0 del flag IF de T7
	
}	

void inic_Timer9 (unsigned char delay, unsigned int tiempo)//1 para ms, 0 para us
{
    TMR9 = 0;
    unsigned int cuenta = 0;
    int prescaler;
    if(delay){
        //cuenta = tiempo * 2500;
        if(tiempo>3){
            if(tiempo>26){
                if(tiempo>209){
                    prescaler = 256;
                    T9CONbits.TCKPS = 3;
                }else{
                    prescaler = 64;
                    T9CONbits.TCKPS = 2;
                }
            }else{
                prescaler = 8;
                T9CONbits.TCKPS = 1;
            }
        }else{
            prescaler = 1;
            T9CONbits.TCKPS = 0;
        }
        if(tiempo>838){ //Esto no podemos contar
            while(1);
        }else{
            cuenta = 20000/prescaler + 1;
            cuenta = cuenta * tiempo;
        }
        PR9 = cuenta / prescaler - 1;
    }else{
        if (tiempo<1500){
        cuenta = 200 * tiempo;
        PR9 = cuenta - 1;
        T9CONbits.TCKPS = 0;        // escala del prescaler 1
        }
        else{
            while(1);
        }
        
    }
    T9CONbits.TCS = 0;	// reloj interno
    T9CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    T9CONbits.TON = 1;	// puesta en marcha del temporizador
}

void inic_Timer5(){
    TMR5 = 0;
    PR5 =  40000 - 1;	// Periodo del temporizador, 40000 ciclos / prescales, menos 1 porque empieza en 0
		// Queremos que cuente 2 ms.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 2 ms  se necesitan 40000 ciclos.
    T5CONbits.TCKPS = 0;	// escala del prescaler 1
    T5CONbits.TCS = 0;	// reloj interno
    T5CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    T5CONbits.TON = 1;	// puesta en marcha del temporizador
    IEC1bits.T5IE = 1;      // habilitacion de la interrupcion de T5
	IFS1bits.T5IF = 0;      // Puesta a 0 del flag IF de T5
}


void inic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min)	
// inicializacion de las variables del cronometro
{
    //Iniciar contadores a 0
    *mili = 0;
    *deci = 0;
    *seg = 0;
    *min = 0;
    flag = 0;
}

void delay_ms(unsigned int tiempo)	// detecta que el timer ha llegado a "tiempo" milisegundos
{
    inic_Timer9(1, tiempo);
    //IFS3 es el registro del temporizador 9
    while (IFS3bits.T9IF==0);	// encuesta continua
    IFS3bits.T9IF=0;
    T9CONbits.TON = 0;

}

void delay_us(unsigned int tiempo)	// detecta que el timer ha llegado a "tiempo" microsegundos
{
    
    inic_Timer9(0, tiempo);
    //IFS3 es el registro del temporizador 9
    while (IFS3bits.T9IF==0);	// encuesta continua
    IFS3bits.T9IF=0;
    T9CONbits.TON = 0;

}


void reset_timer7(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min)
{
    TMR7 = 0 ; 	// Inicializar el registro de cuenta
    inic_crono(mili, deci, seg, min);   // Reinicar valores
    LATAbits.LATA0 = 0;                 // Apagar D3
    LATAbits.LATA2 = 0;                 // Apagar D5
    LATAbits.LATA4 = 0;                 // Apagar D7
    flag_reset = 0;                     // Reiniciar flag de reinicio
    copiar_FLASH_RAM(Mens_LCD_6,1);
    line_2();
    puts_lcd(&Ventana_LCD[1][0],16);
    
}

void _ISR_NO_PSV _T7Interrupt(){
    flag = 1;
    IFS3bits.T7IF = 0; 
    
}

void _ISR_NO_PSV _T5Interrupt(){
    static unsigned int indice = 0;
    switch (estado_lcd){
    case 0:
        lcd_cmd(0x80);  	// Set DDRAM address (@0)
        indice = 0;
        estado_lcd = 1;
        break;
    case 1:
        
        lcd_data(Ventana_LCD[0][indice]);
        indice ++;
        if (indice == 16){
            estado_lcd = 2;
        }
        
        break;
    case 2:
        lcd_cmd(0xC0);  	// Set DDRAM address (@40)
        indice = 0;
        estado_lcd = 3;
        break;
    case 3:
        
        lcd_data(Ventana_LCD[1][indice]);
        indice ++;
        if (indice == 16){
            estado_lcd = 0;
        }
        break;      
    }
    IFS1bits.T5IF = 0;
}
void cronometro(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min)	// control del tiempo mediante el temporizador 7
{
    unsigned char mins[2];
    unsigned char segs[2];
    unsigned char decs[2];
    			// actualiza las variables del cronometro adecuadamente
    (*mili) +=10;   //incrementar el contador de milisegundos en 10
    if(*mili==100){ // cuando el contador de milisegundos llega a 1 decima
        (*deci)++;  // incrementar el contador de decimas en 1
        *mili = 0;  // reiniciar contador de milisegundos a 0
        LATAbits.LATA0 = !LATAbits.LATA0; // conmutar led D3
        conversion_tiempo(decs,*deci);
        Ventana_LCD[1][13] = decs[1];
        if(*deci==10){// cuando el contador de decimales llega a 10 (1 segundo)
            (*seg)++;// aumentamos la variable segundo
            *deci = 0;//reiniciar contador de decimales a 0
            LATAbits.LATA2 = !LATAbits.LATA2; //conmutamos el led D5
            if(*seg==60){//cuando el contador de segundos llega a 60 (1 minuto)
                (*min)++;//aumentamos la variable minuto
                *seg=0;//reiniciar contador de segundos a 0
                LATAbits.LATA4 = !LATAbits.LATA4; //Conmutamos el led D7
                conversion_tiempo(mins,*min);
                Ventana_LCD[1][7] = mins[0];
                Ventana_LCD[1][8] = mins[1];
            }
            conversion_tiempo(segs,*seg);
            Ventana_LCD[1][10] = segs[0];
            Ventana_LCD[1][11] = segs[1]; 
            
        }
            
    }
}
