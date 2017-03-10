#include "can_manager.h"

volatile DataPacket can_queue[CAN_QUEUE_LENGTH];
volatile uint16_t can_head = 0, can_tail = 0;

void can_init() {
	CAN_1_GlobalIntEnable(); // CAN Initialization
	CAN_1_Init();
	CAN_1_Start();
} // can_init()


/* can_get()
	Takes data_queue, data_head, and data_tail.
	Returns nothing.

	Clears data_queue first. Goes through can_queue, extracts information
	according to their type, and enqueues data to data_queue. Wraps data_queue if
	it is full. Finally, clears can_queue. 

	Note that global variables can_queue, can_head, and can_tail are used. */
void can_get(DataPacket* data_queue, uint16_t* data_head, uint16_t* data_tail) {
    
	uint8_t atomic_state = CyEnterCriticalSection(); //BEGIN ATOMIC
	while(can_head != can_tail) {   // move and convert can message queue to data queue
		data_queue[*data_tail].id = can_queue[can_head].id;
		data_queue[*data_tail].length = can_queue[can_head].length;
		data_queue[*data_tail].millicounter = can_queue[can_head].millicounter;
		data_queue[*data_tail].data[0] = can_queue[can_head].data[0];
		data_queue[*data_tail].data[1] = can_queue[can_head].data[1];
		data_queue[*data_tail].data[2] = can_queue[can_head].data[2];
		data_queue[*data_tail].data[3] = can_queue[can_head].data[3];
		data_queue[*data_tail].data[4] = can_queue[can_head].data[4];
		data_queue[*data_tail].data[5] = can_queue[can_head].data[5];
		data_queue[*data_tail].data[6] = can_queue[can_head].data[6];
		data_queue[*data_tail].data[7] = can_queue[can_head].data[7];

		can_head = (can_head + 1) % CAN_QUEUE_LENGTH;           // move to next can message
		*data_tail = (*data_tail + 1) % DATA_QUEUE_LENGTH;      // increment data tail
		if(*data_tail == *data_head) {                          // if data queue full
			*data_head = (*data_head + 1) % DATA_QUEUE_LENGTH;  //wrap around
        }
	} // for all can messages in queue

	can_head = can_tail = 0;
    CyExitCriticalSection(atomic_state);               // END ATOMIC
} // can_receive()



void can_test_send() {
	uint8_t i;
	CAN_1_TX_MSG message;
	CAN_1_DATA_BYTES_MSG test_data;

	message.id = 0x100;
	message.rtr = 0;
	message.ide = 0;
	message.dlc = 0x08;
	message.irq = 1;
	message.msg = &test_data;

	for(i=0;i<8;i++)
		test_data.byte[i] = i;

	CAN_1_SendMsg(&message);
} // can_test_send()


void can_test_receive(DataPacket* data_queue, uint16_t* data_tail, uint16_t* data_head) {
    uint8 i;
    //test packets
    uint8_t atomic_state = CyEnterCriticalSection(); // BEGIN ATOMIC
    for(i=101; i<104; i++) {  //start CAN ID at 100 
		data_queue[*data_tail].millicounter = millis_timer_ReadCounter();    
		data_queue[*data_tail].id = 0x0999;
		data_queue[*data_tail].length = 8;
		data_queue[*data_tail].data[0]= 1;
		data_queue[*data_tail].data[1]= 2;
		data_queue[*data_tail].data[2]= 3;
		data_queue[*data_tail].data[3]= 4;
		data_queue[*data_tail].data[4]= 5;
		data_queue[*data_tail].data[5]= 6;
		data_queue[*data_tail].data[6]= 7;
        data_queue[*data_tail].data[7]= 8;
        
        *data_tail = (*data_tail + 1) % DATA_QUEUE_LENGTH;      // increment data tail
        if(*data_tail == *data_head) {                          // if data queue full
			*data_head = (*data_head + 1) % DATA_QUEUE_LENGTH;  //wrap around
        }
    } //for
    CyExitCriticalSection(atomic_state); // END ATOMIC
}
