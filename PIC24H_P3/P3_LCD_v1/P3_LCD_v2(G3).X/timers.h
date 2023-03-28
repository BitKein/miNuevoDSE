
#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */


// funciones
void inic_Timer7 ();
void inic_Timer5();
void reset_timer7(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min);
void cronometro(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min);
void inic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min);
void delay_us(unsigned int tiempo);
void delay_ms(unsigned int tiempo);