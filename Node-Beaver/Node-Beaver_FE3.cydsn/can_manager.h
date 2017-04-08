#ifndef CAN_MANAGER_H
#define CAN_MANAGER_H

    
#include <project.h>
#include "data.h"

    
void can_init();
void can_msg_init(DataPacket* can_msg, uint16_t id);
int  can_process(DataPacket* can_msg);
int  can_compare(DataPacket* prev_msg, DataPacket* new_msg);
void can_test_send();
void can_test_receive();

#endif
