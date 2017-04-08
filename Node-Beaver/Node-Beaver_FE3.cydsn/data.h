#ifndef DATA_H
#define DATA_H

#include <project.h>

#define SD_QUEUE_LENGTH		1024
#define USB_QUEUE_LENGTH	256
#define MILLI_PERIOD 		43200000	//decrementing timer starting from this val, check top design
    
typedef struct {
	uint32_t millicounter;      //timestamp
	uint16_t id;                //id is for tracking CAN ID
	uint8_t length;         	//data length
	uint8_t data[8];            //8bytes for each message
} DataPacket;


void msg_recieve(DataPacket * msg);

#endif
