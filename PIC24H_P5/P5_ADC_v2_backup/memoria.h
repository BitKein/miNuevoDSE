
#ifndef MEMORIA_H
#define	MEMORIA_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MEMORIA_H */


// constantes y variables
extern const unsigned char Mens_LCD_1[16];
extern const unsigned char Mens_LCD_2[16];
extern const unsigned char Mens_LCD_3[16];
extern const unsigned char Mens_LCD_4[16];
extern const unsigned char Mens_LCD_5[16];
extern const unsigned char Mens_LCD_6[16];
extern const unsigned char Mens_LCD_7[16];

extern unsigned char Ventana_LCD[2][16];

// funciones
void copiar_FLASH_RAM (const unsigned char *texto, unsigned int i);
