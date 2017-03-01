
/* Node-Beaver
	This node logs data via CAN and presents the data to the outside world.
 */

#include <project.h>
#include <time.h>
#include "time_manager.h"


int main(void) {
	CYGlobalIntEnable;      //Uncomment this line to enable global interrupts
    
    time_t rawtime;
    struct tm * time_cur;
    Time now;
    
	time_init();  //init everything
    time(&rawtime);
    time_cur = localtime(&rawtime);
    
    
    /*//using time.h
    now.year = (uint16_t) time_cur->tm_year - 100;  //since 1900
    now.month = (uint8_t) time_cur->tm_mon;
    now.day   = (uint8_t) time_cur->tm_mday;
    now.hour  = (uint8_t)  time_cur->tm_hour;
    now.minute = (uint8_t) time_cur->tm_min;
    now.second = (uint8_t) time_cur->tm_sec;
    */
    
    //manual time input
    now.year = 0x11;      //RTC only holds 2 digit years 20XX
    now.month = 0x02;
    now.day   = 0x18;
    now.hour  = 0x0A;       //24hour time
    now.minute = 0x2D;
    now.second = 0x00;
    
    time_set(now);
	for(;;)	{
        time_announce();
		CyDelay(1000);                 //refresh intervaal
	} // main loop

	return 0;
} // main()
