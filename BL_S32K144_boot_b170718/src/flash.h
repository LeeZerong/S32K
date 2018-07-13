/*
 * flash.h
 *
 *  Created on: 2017Äê7ÔÂ20ÈÕ
 *      Author: 4337
 */

#ifndef FLASH_H_
#define FLASH_H_

#include "device_registers.h"



void flash_init();
void flash_erase_sector(uint32_t addr);
void flash_program_data(uint32_t addr, uint8_t *pdata, uint32_t byte_size);
#endif /* FLASH_H_ */
