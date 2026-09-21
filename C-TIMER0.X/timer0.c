#include <xc.h>
#include "timer0.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{ 
	/* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
          
    /* HFINTOSC; counter not synchronized; prescaler 1:1024 */
	T0CON1 = 0x7A;
    
    /* Load TMR0 with initial value (hex) */
    /* tCLK x counts  x prescaler = TMR0 counting time */
    /* 1/64MHz * (65535-3035) * 1024 =  1 */
	TMR0 = (unsigned char)0x0BDB;
}

/* Enable TIMER0 */
void TIMER0_Start(void)
{ 
	/* Timer0 enabled */
	T0CON0 |= 0x80;          
}

/* Disable TIMER0 */
void TIMER0_Stop(void)
{ 
	/* Timer0 disabled */
	T0CON0 &= 0xF7;
}

void TIMER0_Reset(void)
{ 
	TMR0 = (unsigned char)0x0000;
}