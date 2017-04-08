#ifndef SD_MANAGER_H
#define SD_MANAGER_H


#include <project.h>

#include <stdio.h>
#include <stdlib.h>

#include "FS.h"
#include "data.h"
#include "time_manager.h"

CY_ISR_PROTO(power_interrupt);
CY_ISR_PROTO(sd_interrupt);

void sd_init(Time time);
void sd_time_set(Time time);
void sd_write();
void sd_read();
void sd_buffer(DataPacket * msg);
void sd_stop(void);
void sd_writetest();

#endif
