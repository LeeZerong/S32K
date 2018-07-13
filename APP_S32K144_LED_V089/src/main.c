/*
 * mian.c
 * app_for_s32k_boot
 */
#include "clocks_and_modes.h"
#include "S32K144.h"

#define PCC_LED0_INDEX     PCC_PORTD_INDEX
#define LED0_PORT           PORTD
#define LED0_GPIO           PTD
#define LED0_INDEX          15

int main (void)
{
	uint8_t i = 0;
	uint16_t j;

	SOSC_init_8MHz();      /* Initialize system oscillator for 8 MHz xtal_pin */
	SPLL_init_160MHz();    /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
	NormalRUNmode_80MHz(); /* Initialize clocks: 80 MHz sysclk & core, 40 MHz bus,
								  20 MHz flash */

	PCC->PCCn[PCC_LED0_INDEX] |= PCC_PCCn_CGC_MASK;
	LED0_PORT->PCR[LED0_INDEX] |= PORT_PCR_MUX(1);
	LED0_GPIO->PDDR |= 1 << LED0_INDEX;
	LED0_GPIO->PCOR |= 1 << LED0_INDEX;

	for(;;)
	{
		LED0_GPIO->PTOR |= 1 << LED0_INDEX;
		for(i = 0; i < 8; i++)
		{
			for(j = 0; j < 65535; j++);
		}
	}
}
