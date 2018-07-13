/* main.c                              
 * Description: S32K144 CAN Bootloader, use xmodem as file transfer protocol 
 *              Application flash start address is 0x5000, there need another
 *              Board as adoptar to conversion uart rs232 to CAN frame or you
 *              can use a host GUI to support Xmodem file transfer protocol. 
 *     History: 
 *              Initial Version : July 21th, 2017 4337
 */


#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "FlexCAN.h"
#include "LPSPI.h"
#include "clocks_and_modes.h"
#include "sbc_uja11691.h"

#include "config.h"
#include "xmodem.h"
#include "flash.h"

void bootup_application(uint32_t appEntry, uint32_t appStack);


int main(void)
{
    uint32_t appEntry, appStack;
    uint32_t rx_msg_count = 0;
    uint8_t data[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
  
    WDOG_disable();
    SOSC_init_8MHz();       /* Initialize system oscillator for 8 MHz xtal */
    SPLL_init_160MHz();     /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
    NormalRUNmode_80MHz();  /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
  
    FLEXCAN0_init();         /* Init FlexCAN0 */
    PORT_init();             /* Configure ports */
#ifdef SBC         /* SPI and transceiver initialization is required */
    LPSPI1_init_master();    /* Initialize LPSPI1 for communication with MC33903 */
    SBC_Init(&sbc_uja11691_InitConfig0, 1U);
#endif
    xmodem_init();
    flash_init();
    if(is_enter_triggered()) /* BTN0(sw2) pressed to download app*/
    {
        //flexcan_send_data(0x123, data, 7);
        while(1)
        {
            if(xmodem_is_active())
              {
                xmodem_download();
                  break;
              }
        }
    }
    appStack = *(uint32_t*)APP_IMAGE_START;
    appEntry = *(uint32_t*)(APP_IMAGE_START + 4);

    CAN0->MCR |= 1 << 25; // soft rest CAN module
    CAN0->MCR |= 1 << 31; // disable CAN module
    FLEXCAN0_init();
    bootup_application(appEntry,appStack);

  for (;;) 
  { 
    /* Loop: if a msg is received, transmit a msg */
    if ((CAN0->IFLAG1 >> 4) & 1) 
    {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
        flexcan0_receive_frame();
        rx_msg_count++;               /* Increment receive msg counter */
        
        if (rx_msg_count == 1000) 
        {   
            /* If 1000 messages have been received, */
            PTD->PTOR |= 1<<16;       /*   toggle output port D16 (Green LED) */
            rx_msg_count = 0;         /*   and reset message counter */
        }
        flexcan_send_data(0x123, data, 1);
    }
  }
}
void bootup_application(uint32_t appEntry, uint32_t appStack)
{
    static void (*jump_to_application)(void);
    static uint32_t stack_pointer;

    //shutdown_drivers();

    jump_to_application = (void (*)(void))appEntry;
    stack_pointer = appStack;
    S32_SCB->VTOR = 0x5000;
//  __set_MSP(stack_pointer);
    __asm volatile ("MSR msp, %0\n" : : "r" (stack_pointer) : "sp");
//  __set_PSP(stack_pointer);
    __asm volatile ("MSR psp, %0\n" : : "r" (stack_pointer) : "sp");
    jump_to_application();
}
