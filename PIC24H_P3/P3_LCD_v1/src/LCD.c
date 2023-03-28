/**********************************************************************
LCD erabiltzeko funtzioak:
	Hasieraketa
	Komando bat bidali
	Datu bat bistaratu
	Testu bat bistaratu
	Funtzio bereziak: 1. lerroan kokatu // 2. lerroan kokatu
**********************************************************************/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "timers.h"

	

/*****	LCD SUBROUTINES  *****/ 
void lcd_cmd (char cmd)        // subroutine for lcd commands
{
  RW = 0;             // RW=0, para escribir
  RS = 0;	      // RS=0, se va a escribir un comando
  DATA &= 0xFF00;     // pines RE0-RE7 (dato que se envía): poner a 0
  DATA |= cmd;        // copiar a esos pines el parametro cmd
  E = 1;              // E=1. Debe permanecer activado al menos 230 ns. 
  Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
  // 25 ns x 10 = 250 ns > 230 ns. (usar un for tarda m�s, por el desglose en assembly)
  E = 0;		// desactivar E
  RW = 1;		// desactivar escritura
}


void lcd_data (char data)      // subroutine for lcd data
{
  RW = 0;       	// RW=0, para escribir
  RS = 1;            	// RS=1, se va a escribir un caracter
  DATA &= 0xFF00;    	// pines RE0-RE7 (dato que se envía): poner a 0
  DATA |= data;      	// copiar a esos pines el parametro data
  E = 1;             	// E=1. Debe permanecer activado al menos 230 ns.
  Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
  // 25 ns x 10 = 250 ns > 230 ns
  E = 0;             	// desactivar E
  RS = 0;            	// desactivar RS
  RW = 1;		// desactivar escritura
}


void Init_LCD ()             // initialize LCD display
{
  // 15mS delay after Vdd reaches nnVdc before proceeding 
  // with LCD initialization
  // not always required and is based on system Vdd rise rate
  delay_ms (15); // 15 ms delay
			
  /* set initial states for the data and control pins */
  DATA &= 0xFF00;	
  RW = 0;                       // R/W state set low
  RS = 0;                       // RS state set low
  E = 0;                        // E state set low

  /* set data and control pins to outputs */
  TRISDATA &= 0xFF00;
  RW_TRIS = 0;                  // RW pin set as output
  RS_TRIS = 0;                  // RS pin set as output
  E_TRIS = 0;                   // E pin set as output

  /* LCD initialization sequence */ 
  lcd_cmd (0x38);				// function set (3 veces)
  delay_ms (5);         // 5 ms delay
  lcd_cmd (0x38);
  delay_us (100);       // 100 us delay
  lcd_cmd (0x38);
  delay_us (40);      // ???? delay (mirar tabla en los apuntes)
  lcd_cmd (0x38);  
  delay_us (40);      // ???? delay (mirar tabla en los apuntes)
  lcd_cmd (0x0C);       // Display on/off control, cursor blink off (0x0C)
  delay_us (40);      // ???? delay (mirar tabla en los apuntes)
  lcd_cmd (0x06);	// Entry mode set (0x06)
  delay_us (40);      // ???? delay (mirar tabla en los apuntes)
}


void puts_lcd (unsigned char *data, unsigned char count) 
{
  while (count)
	{
	 lcd_data(*data++);
         delay_us (xx);	// ???? delay (mirar tabla en los apuntes)
	 count--;
	}	
}

void line_1()
{
    lcd_cmd(0x80);  	// Set DDRAM address (@0)
    delay_us (40); 	// ???? delay (mirar tabla en los apuntes)
}

void line_2()
{
    lcd_cmd(0xC0);  	// Set DDRAM address (@40)
    delay_us (40); 	// ???? delay (mirar tabla en los apuntes)
}
