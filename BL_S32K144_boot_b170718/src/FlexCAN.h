/* FlexCAN.h              (c) 2015 Freescale Semiconductor, Inc.
 * Descriptions: FTM example code.
 * 16 Sep 2016 SM: Initial version
 */


#ifndef FLEXCAN_H_
#define FLEXCAN_H_

#define NODE_A        /* If using 2 boards as 2 nodes, NODE A & B use different CAN IDs */
#define SBC   /* SBC requires SPI init + max 1MHz bit rate */

typedef struct
{									    /*!< identifier union */
	uint32_t  CODE; 					/* Received message buffer code */
	uint32_t  ID;                		/* Received message ID */
	uint32_t  DLC;            		/* Recieved message number of data bytes */
	//uint32_t  LENGTH;            		/* Recieved message number of data bytes */
	//uint32  DATA[16];           	    /* Received message data string*/
	//uint8_t   DATA[64];           	    /* Received message data string*/
	uint32_t  TIMESTAMP;         		/* Received message time */
	union {
	    	uint8_t B[64];
	    	uint16_t H[32];
	    	uint32_t W[16];
	    } DATA;
}CAN_FrameType,*CAN_FramePtr;

void FLEXCAN0_init (void);
void FLEXCAN0_transmit_msg (void);
void FLEXCAN0_receive_msg (void);

void flexcan0_receive_frame();
void flexcan_send_frame(CAN_FramePtr rx_frame);
void flexcan_send_data(uint32_t msgid, uint8_t *data, uint8_t length);
void flexcan0_receive_data(void);
#endif /* FLEXCAN_H_ */
