/*
 * config.c
 *
 *  Created on: 2017Äê7ÔÂ19ÈÕ
 *      Author: 4337
 */
#include "config.h"
#include "device_registers.h"

#define SBC_UJA1169

void WDOG_disable (void)
{
  WDOG->CNT=0xD928C520; 	/* Unlock watchdog */
  WDOG->TOVAL=0x0000FFFF;	/* Maximum timeout value */
  WDOG->CS = 0x00002100;    /* Disable watchdog */
}

void PORT_init (void)
{
//=============================== CAN PORT ====================================
  PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORTE */
  PORTE->PCR[4] |= PORT_PCR_MUX(5);          /* Port E4: MUX = ALT5, CAN0_RX */
  PORTE->PCR[5] |= PORT_PCR_MUX(5);          /* Port E5: MUX = ALT5, CAN0_TX */
//=============================== LED PORT ====================================
  PCC->PCCn[PCC_PORTD_INDEX ]|=PCC_PCCn_CGC_MASK;  /* Enable clock for PORTD */
  PORTD->PCR[16] =  0x00000100;       /* Port D16: MUX = GPIO (to green LED) */
  PTD->PDDR |= 1<<16;                   /* Port D16: Data direction = output */
  PTD->PSOR |= 1<<16;
//=============================== BTN PORT ====================================
  PCC->PCCn[PCC_PORTC_INDEX ]|=PCC_PCCn_CGC_MASK;  /* Enable clock for PORTD */
  PORTC->PCR[12] =  0x00000100;         /*    Port D16: MUX = GPIO (to btn0) */
  PTC->PDDR &= ~(1<<12);                /* Port D16: Data direction = output */
//=============================== 1169 SPI ====================================
#ifdef SBC_UJA1169  /* If board has MC33904, SPI pin config. is required */
  PCC->PCCn[PCC_PORTB_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for PORTB */
  PORTB->PCR[14] |= PORT_PCR_MUX(3);     /* Port B14: MUX = ALT3, LPSPI1_SCK */
  PORTB->PCR[15] |= PORT_PCR_MUX(3);     /* Port B15: MUX = ALT3, LPSPI1_SIN */
  PORTB->PCR[16] |= PORT_PCR_MUX(3);     /* Port B16: MUX = ALT3, LPSPI1_SOUT */
  PORTB->PCR[17] |= PORT_PCR_MUX(3);     /* Port B17: MUX = ALT3, LPSPI1_PCS3 */
#endif
}

unsigned char is_enter_triggered(void)
{
	uint16_t i;

	for(i = 0; i < 0xFFF; i++);
	if(PTC->PDIR & (1<<12))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
