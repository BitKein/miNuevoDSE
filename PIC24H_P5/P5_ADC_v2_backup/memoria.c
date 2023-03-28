/* Texto predefinido y copia de datos para la LCD
===================================================
Autores: Garantigui Coulibaly, Alejandro Martin y Asier Septien
Fecha: 20-03-2023
*/

#include "p24HJ256GP610A.h"

//const unsigned char Mens_LCD_1[] = {"- DSE 2022-23 --"};  //linea 1.1, 16 caracteres
const unsigned char Mens_LCD_2[] = {"--- Pulsa S3  --"};  //linea 2.1, 16 caracteres
const unsigned char Mens_LCD_3[] = {"---- ADC_v2 ----"};  //linea 1.2, 16 caracteres
//const unsigned char Mens_LCD_4[] = {"  S4 comienza --"};  //linea 2.2, 16 caracteres
//const unsigned char Mens_LCD_5[] = {"S3 st/stop, S6=0"};  //linea 1.3, 16 caracteres
const unsigned char Mens_LCD_6[] = {"Crono: 00:00,0  "};  //linea 2.3, 16 caracteres
const unsigned char Mens_LCD_7[] = {"P: 0000  T: 0000"};  //linea 2.3, 16 caracteres
const unsigned char Mens_LCD_8[] = {"X: 0000  Y: 0000"};  //linea 2.3, 16 caracteres


unsigned char Ventana_LCD[2][16];

void copiar_FLASH_RAM (const unsigned char *texto, unsigned int i) {
  unsigned int j;
  for (j = 0; j < 16; j++) Ventana_LCD[i][j] = texto[j];
}

