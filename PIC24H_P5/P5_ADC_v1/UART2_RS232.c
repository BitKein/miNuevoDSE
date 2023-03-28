/* Funciones para trabajar con el modulo UART2
================================================
Autores: Alejandro Martin, Asier Septien y Garantigui Coulibaly
Fecha:
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "timers.h"
#include "memoria.h"
#include "LCD.h"
#include "UART2_RS232.h"

unsigned int estado_tx, cidx, line;

void inic_UART2 () {
	
     // Velocidad de transmision
     // Hay que hacer solo una de las dos asignaciones siguientes
	U2BRG = BAUD_RATEREG_2_BRGH1;
    //U2BRG = BAUD_RATEREG_2_BRGH0;

     // U2MODE: habilitar el modulo (UARTEN), 8 bits, paridad par (PDSEL),
     // 1 bit de stop (STSEL), BRGH ...
	U2MODE = 0;
	U2MODEbits.BRGH = 1;

     // U2STA: modo de interrupcion en el envio (UTXISEL), habilitacion del
     // envio (UTXEN), modo de interrupcion en la recepcion (URXISEL)
	U2STA = 0;

     // inicializacion de los bits IE e IF relacionados (IP si se quiere modificar)
	IFS1bits.U2RXIF = 0;
    IFS1bits.U2TXIF = 0;
	IEC1bits.U2RXIE = 1;
    IEC1bits.U2TXIE = 1;

     	//IPC7bits.U2RXIP=xx;
        //IPC7bits.U2TXIP=xx;

     // interrupciones debidas a errores + bug
	IEC4bits.U2EIE = 0;
	U2STAbits.OERR = 0;

     // Habilitar el modulo y la linea TX.
     // Siempre al final y en ese orden!!!

	U2MODEbits.UARTEN = 1;    // habilitar UART2
	U2STAbits.UTXEN = 1;      // habilitar transmision tras habilitar modulo

	delay_us(T_1BIT_US); 	// Esperar tiempo de 1 bit 
    
    // Inicializacion/reset de los valores usados en la transmision UART
    reset_U2TX();
}

/* Inicializacion/reset de los valores usados en la transmision UART */
void reset_U2TX(){
    IFS1bits.U2TXIF = 0;    // interrumpir rutina de atencion si se pulsa 'i'
    cidx = line = 0;        // resetear posicion (linea y caracter)
    estado_tx = STAT_CLEAR; // primer estado = borrar pantalla
    U2TXREG = 0;            // reiniciar cadena
}

/* Receptor UART */
void _ISR_NO_PSV _U2RXInterrupt() {
    
    // Recoger comando
    char cmd = U2RXREG;
    switch(cmd){
        case 'i':   // i = reiniciar
        case 'I':
            inic_crono();       // reiniciar variables + Timer7
            copiar_FLASH_RAM(Mens_LCD_6, 1); // limpiar pantalla (poner 00:00,0)
            reset_U2TX();       // reiniciar maquina de estados de U2TX
            break;
        case 'c':   // c = continuar
        case 'C':
            T7CONbits.TON = 1;
            break;
        case 'p':   // p = parar
        case 'P':
            T7CONbits.TON = 0;
            break;
        default: 
            break;
    }
    Ventana_LCD[1][15] = cmd;   // mostrar ultimo comando enviado en la LCD
    
    IFS1bits.U2RXIF = 0;
}

/* Transmisor UART */
void _ISR_NO_PSV _U2TXInterrupt() {
    char c;

    switch(estado_tx){
        
        // Primer estado: borrar pantalla
        case STAT_CLEAR:
            U2TXREG = clrscr[cidx++];
            if (cidx == 4){
                cidx = 0;
                estado_tx = STAT_HOME;
            }
            break;
        
        // Posicionar cursor al inicio
        case STAT_HOME:
            U2TXREG = home[cidx++];
            if (cidx == 3){
                cidx = 0;
                estado_tx = STAT_LINE;
            }
            break;
            
        // Escribir linea (tanto linea 1 como 2)
        case STAT_LINE:
            U2TXREG = Ventana_LCD[line][cidx++];
            if (cidx == 16){
                cidx = 0;
                line++;
                if (line == 2){
                    estado_tx = STAT_HOME;
                    line = 0;
                } else {
                    estado_tx = STAT_NL;
                }
            }
            break;
            
        // Salto de linea
        case STAT_NL:
            c = cidx++;
            if (c == 0) {
                U2TXREG = CR;
            }
            else if (c == 1) {
                U2TXREG = LF;
                estado_tx = STAT_LINE;
                cidx = 0;
            }
            break;
            
        default: 
            break;
                
    }
    IFS1bits.U2TXIF = 0;
}