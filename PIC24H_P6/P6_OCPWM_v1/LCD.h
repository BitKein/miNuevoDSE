#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

void lcd_cmd(char cmd);	
void lcd_data(char data);
void inic_LCD();
void puts_lcd (unsigned char *data, unsigned char count);
void line_1();
void line_2();

extern int pagina_LCD;
extern unsigned char ascii[5][4];
