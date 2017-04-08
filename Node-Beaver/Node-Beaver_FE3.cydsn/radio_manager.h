#ifndef RADIO_MANAGER_H
#define RADIO_MANAGER_H

#include <project.h>
#include <stdio.h>
#include "data.h"

#define SRC_ADDR	0x0013A20041041069 		//this xbee's addr
#define DES_ADDR	0x0013A2004152E917		//destination addr = SH:SL 64bit addr of other xbee

#define STARTER_DELIMITER	0x7E				//Frame delimiter for API Mode

void    radio_init_SPI  (void);
void    set_des_addr    (uint64_t newAddr);
uint8_t checksum_calc	(uint8_t * msg,int len);
uint8_t checksum_verify	(uint8_t * msg, int len);
void    xbee_send       (DataPacket * msg);
void    xbee_Tx_req     (DataPacket * msg);
void    xbee_Tx_req_test();

#endif
