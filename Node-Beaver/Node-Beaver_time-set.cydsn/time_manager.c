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
#include "time_manager.h"

volatile Time current_time;
volatile uint8_t refresh_status = 0;


/* CY_ISR(time_refresh_vector)
	Runs every 10 seconds and retreives the current time from the RTC and the
	millisecond counter from millis_timer.
	Sets the refresh_status flag, which will trigger time_announce() to inject a
	message containing the current time to the data_queue.  */
CY_ISR(time_refresh_vector) {
	current_time = time_retreive(); // get time from rtc
	refresh_status = 1;
} // CY_ISR(time_refresh_vector)


/* time_init()
	Takes and Returns nothing.
	Initializes i2c with RTC and configures the RTC. Starts the timers and
	time_refresh_vector interrupt.
	RTC PART: MAXIM DS3231  */
void time_init(void) {
	rtc_i2c_Start(); // start i2c to RTC

	// configure RTC
	rtc_i2c_MasterSendStart(RTC_ADDR, 0);   // 0, send write command
	rtc_i2c_MasterWriteByte(RTC_CONFIG);
	rtc_i2c_MasterWriteByte(0x40); // 1Hz clock
	rtc_i2c_MasterSendStop();

	// Set 24 hour
	uint8_t byte;
	rtc_i2c_MasterSendStart(RTC_ADDR, 0); // Move to hours register.
	rtc_i2c_MasterWriteByte(RTC_HOURS);     //set register pointer
	rtc_i2c_MasterSendStop();

	rtc_i2c_MasterSendStart(RTC_ADDR, 1); // save hours register
	byte = rtc_i2c_MasterReadByte(0);     // Zero, response with NACK
	rtc_i2c_MasterSendStop();

	rtc_i2c_MasterSendStart(RTC_ADDR, 0); // Set 24 hour bit
	rtc_i2c_MasterWriteByte(RTC_HOURS);
	rtc_i2c_MasterWriteByte(0x40 | byte);   //bit number 6 defines 12/24 hours
	rtc_i2c_MasterSendStop();

	//time_one_sec_isr_StartEx(time_one_sec_vector); // enable rtc isr
	//while(!init_status); // wait for second synchronization

	time_refresh_isr_StartEx(time_refresh_vector); // enable 10 second isr

	// Start timers
	millis_timer_Start();
	time_refresh_timer_Start();
} // time_init()



/* time_announce()
	Takes time and puts into a DataPacket queue.
	Returns nothing.
    The actual time and millisecond counter is set by the time_refresh_vector interrupt.
*/
void time_announce() {
    if(refresh_status == 1) {
		refresh_status = 0;
	} //if
} // time_announce()



/* time_get()
	Takes nothing. Returns the current time with millicounter. */
Time time_get(void) {
	current_time = time_retreive();
	return current_time;
} // time_get()


void time_set(Time now) {
	// Set 24 hour
	uint8_t byte;

	rtc_i2c_MasterSendStart(RTC_ADDR, 0);
	rtc_i2c_MasterWriteByte(0x00); // move to top of register file

	byte = now.second % 10; // seconds
	byte |= (now.second / 10) << 4; // 10 seconds
	rtc_i2c_MasterWriteByte(byte);

	byte = now.minute % 10; // minute
	byte |= (now.minute/ 10) << 4; // 10 minute
	rtc_i2c_MasterWriteByte(byte);

	byte = now.hour % 10; // hour
	byte |= (now.hour / 10) << 4; // 10 hour
	rtc_i2c_MasterWriteByte(byte);

	rtc_i2c_MasterSendStop(); // End Receiving

	// skip day

	rtc_i2c_MasterSendStart(RTC_ADDR, 0);
	rtc_i2c_MasterWriteByte(RTC_DATE); // move to Date

	byte = now.day % 10; // day
	byte |= (now.day / 10) << 4; // 10 day
	rtc_i2c_MasterWriteByte(byte);

	byte = now.month % 10; // month
	byte |= (now.month / 10) << 4; // 10 month
	rtc_i2c_MasterWriteByte(byte);

	byte = now.year % 10; // year
	byte |= (now.year / 10) << 4; // 10 year
	rtc_i2c_MasterWriteByte(byte);

	rtc_i2c_MasterSendStop(); // End Receiving
} // time_set()



/* time_retreive()
	Takes nothing. Returns the current time.

	Communicates with an external RTC with i2c to obtain the current time.
	Sets the register pointer in the RTC to 0 and then reads the data sequencially
	from the register. The RTC auto-increments after reading each byte. Converts
	the binary encoded decimal to simple binary representation. Reads the
	millisecond counter into the current time.

	RTC PART: MAXIM DS3231
*/
Time time_retreive(void) {
	Time tmp_time;
	uint8_t byte;

	// Set register pointer to 0
	rtc_i2c_MasterSendStart(RTC_ADDR, 0);
	rtc_i2c_MasterWriteByte(0x00);
	rtc_i2c_MasterSendStop();
	
	// Read data from registers
	rtc_i2c_MasterSendStart(RTC_ADDR, 1); // Begin receiving

	byte = rtc_i2c_MasterReadByte(1);
	tmp_time.second = byte & 0x0F; // seconds
	tmp_time.second += 10 * (byte >> 4); // 10 seconds

	byte = rtc_i2c_MasterReadByte(1);
	tmp_time.minute = byte & 0x0F; // minutes
	tmp_time.minute += 10 * (byte >> 4); // 10 seconds

	byte = rtc_i2c_MasterReadByte(1);
	tmp_time.hour = byte & 0x0F; // hours 
	tmp_time.hour += 10 * ((byte&0x3F) >> 4); // 10 hours

	byte = rtc_i2c_MasterReadByte(1); // skip day

	byte = rtc_i2c_MasterReadByte(1);
	tmp_time.day = byte & 0x0F; // date
	tmp_time.day += 10 * (byte >> 4); // 10 date

	byte = rtc_i2c_MasterReadByte(1);
	tmp_time.month = byte & 0x0F; // Month/Century 
	tmp_time.month += 10 * ((byte & 0x01) >> 4); // 10 Month

	byte = rtc_i2c_MasterReadByte(0);
	tmp_time.year = byte & 0x0F; // Year
	tmp_time.year += 10 * (byte >> 4); // 10 Years

	rtc_i2c_MasterSendStop(); // End Receiving

	tmp_time.millicounter = millis_timer_ReadCounter();

	return tmp_time; 
} // time_retreive()
