#include "xmodem.h"
#include "flash.h"
#include "crc16.h"
#include "FlexCAN.h"

#include <string.h>


#define ENABLE_XMODEM       1



#define SOH     0x01 
#define EOT     0x04 
#define ACK     0x06 
#define NAK     0x15 
#define CAN     0x18 
#define ESC     0x1b 

#define CRC16POLY   0x1021  
#define PKTLEN_128  128   
#define XMODEM_BUFLEN	256
//#pragma location = ".textrw" 

#ifndef ALIGN
/* Compiler Related Definitions */
#ifdef __CC_ARM                         /* ARM Compiler */
    #define ALIGN(n)                    __attribute__((aligned(n)))
#elif defined (__IAR_SYSTEMS_ICC__)     /* for IAR Compiler */
    #define PRAGMA(x)                   _Pragma(#x)
    #define ALIGN(n)                    PRAGMA(data_alignment=n)
#elif defined (__GNUC__)                /* GNU GCC Compiler */
    #define ALIGN(n)                    __attribute__((aligned(n)))
#endif /* Compiler Related Definitions */
#endif

#if ENABLE_XMODEM

uint32_t flash_app_addr;
static uint8_t callback_buffer[XMODEM_BUFLEN];
volatile static uint32_t readOffset, writeOffset;


static void read_bytes(uint8_t * buffer, uint32_t byteCount)
{
    uint32_t currentBytesRead = 0;

    while(currentBytesRead != byteCount)
    {
        if (readOffset != writeOffset)
        {
            buffer[currentBytesRead++] = callback_buffer[readOffset++];
            readOffset &= XMODEM_BUFLEN - 1;
        }
    }
}

static int read_packet(uint8_t *buffer, uint8_t idx)
{
    uint8_t  seq[2],crc1,crc2;
    uint16_t  crc16, verify16;
	crc16_data_t crcInfo;
	
	read_bytes(seq,2);

	read_bytes(buffer,PKTLEN_128);
	crc16_init(&crcInfo);
	crc16_update(&crcInfo,buffer,PKTLEN_128);
	crc16_finalize(&crcInfo,&verify16);
	
	read_bytes(&crc1,1);
	read_bytes(&crc2,1);
    crc16  = ((uint16_t)crc1 << 8)|crc2;

    if ((crc16 != verify16) || (seq[0] != idx) || (seq[1] != (uint8_t) ((~(uint32_t)idx)&0xff)))
        return(-1);

    return(0);
}
/*-------------------------------------------
 * use flash function write file to flash
 * there must be change to s32k144
 * erase sector and program to needed address
 * ------------------------------------------
 */
static int xmodem_write_image(uint8_t * data, uint16_t data_size)
{

    ALIGN(4) static uint8_t abuf[FEATURE_FLS_PF_BLOCK_SECTOR_SIZE];
//    __disable_irq(); /* during the flash erase and write should not be interrupt */
    if((flash_app_addr & (FEATURE_FLS_PF_BLOCK_SECTOR_SIZE-1))==0)
    {
    	flash_erase_sector(flash_app_addr);
    }

    memcpy(abuf, data, data_size);
    flash_program_data(flash_app_addr, abuf, data_size);
//    __enable_irq();
	flash_app_addr += data_size;
	return 0;
}

void xmodem_init(void)
{
	flash_app_addr = APP_IMAGE_START;
	readOffset = 0;
	writeOffset = 0;
}

bool xmodem_is_active(void)
{
	xmodem_putchar('C');
	flexcan0_receive_data();
	if(xmodem_getchar_present())
		return true;
	else
		return false;
}
/*----------------------------
 * uart interrupt routine
 * need change ---------------
 * LPUART0RXTX
 */
void xmodem_uart_handler(void)
{
//    uint8_t byte;
//    if(UART_IsRxBuffFull(pUART))
//    {
//        byte = UART_ReadDataReg(pUART);
//        xmodem_queue_byte(byte);
//    }
//
//    if(UART_CheckFlag(pUART, UART_FlagOR))
//    {
//        byte = UART_ReadDataReg(pUART);
//    }
    
}

void xmodem_queue_byte(uint8_t byte)
{
    callback_buffer[writeOffset++] = byte;
    writeOffset &= XMODEM_BUFLEN - 1;
}
/*
 * xmodem transfer data
 * uart  tx data x
 */
void xmodem_putchar(char x)
{
	uint32_t i;
	//TODO:put char
	flexcan_send_data(0x123, &x, 1);
	for(i = 0; i < 0xff; i++);

}

bool xmodem_getchar_present(void)
{
	return readOffset != writeOffset;
}

uint32_t xmodem_download(void)
{
    uint8_t ch;
    int done;
	uint8_t buffer[PKTLEN_128];
    uint8_t idx = 0x01;
    
    uint32_t size = 0;

    done = 0;
    while(done == 0) 
    {
		read_bytes(&ch,1);

        switch(ch) 
        {   
            case SOH:
                done = read_packet(buffer, idx);

                if (done == 0) 
                {
                    idx++;
                    size += PKTLEN_128;
					xmodem_write_image((uint8_t*)buffer, PKTLEN_128);
					xmodem_putchar(ACK);
					flexcan0_receive_data();
                }        
				else
				{
					done = 0;
					xmodem_putchar(NAK);
					flexcan0_receive_data();
				}
                break;
            case EOT:
                xmodem_putchar(ACK);
            
                //while (!(UART1->S1 & UART_S1_TC_MASK)) ;
                //uart_wait_xmit_complete(XMODEM_UART_PORT);
                done = size;
                break;

            case CAN:
            case ESC:
				done = -1;
				break;	
				
			default:
				xmodem_putchar(NAK);
				break;
        }
    }

    return 1;
}
#endif

