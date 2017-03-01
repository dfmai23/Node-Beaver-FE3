/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <project.h>

// RTC (DS3231) I2C address
#define RTC_ADDR 0x68

// RTC register addresses
#define RTC_CONFIG 0x0E
#define RTC_HOURS 0x02
#define RTC_DATE 0x04

// This is a "CAN ID" but it is never anounced to the CAN network
#define ID_TIME 0x123       //135 decimal

typedef struct {
	uint8_t month, day, hour, minute, second;
	uint32_t millicounter;
	uint16_t year;
} Time;

CY_ISR_PROTO(time_refresh_vector);
void time_init(void);
Time time_get(void);
void time_set(Time now);
void time_announce();
Time time_retreive(void); // retreives full time from RTC


#endif
