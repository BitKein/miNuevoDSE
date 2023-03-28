/* Texto predefinido y copia de datos para la LCD
===================================================
Autores: Garantigui Coulibaly, Alejandro Martin y Asier Septien
Fecha: 29-03-2023
*/

#include "p24HJ256GP610A.h"

//const unsigned char Mens_LCD_1[] = {"- DSE 2022-23 --"};
const unsigned char Mens_LCD_2[] = {"--- Pulsa S3  --"};
const unsigned char Mens_LCD_3[] = {"--- OCPWM_v1 ---"};
//const unsigned char Mens_LCD_4[] = {"  S4 comienza --"};
//const unsigned char Mens_LCD_5[] = {"S3 st/stop, S6=0"};
const unsigned char Mens_LCD_6[] = {"Crono: 00:00,0  "};
const unsigned char Mens_LCD_7[] = {"P: 0000  T: 0000"};
const unsigned char Mens_LCD_8[] = {"X: 0000  Y: 0000"};
const unsigned char Mens_LCD_9[] = {"      DUTY: 0000"};


unsigned char Ventana_LCD[2][16];

void copiar_FLASH_RAM (const unsigned char *texto, unsigned int i) {
  unsigned int j;
  for (j = 0; j < 16; j++) Ventana_LCD[i][j] = texto[j];
}

