/* Node-Beaver
	 This node logs data via CAN and presents the data to the outside world.
 */

#include <project.h>

#include "data.h"
#include "time_manager.h"
#include "can_manager.h"
#include "usb_manager.h"
#include "sd_manager.h"
#include "radio_manager.h"


int main(void) {
	CYGlobalIntEnable;      //Uncomment this line to enable global interrupts
    
    //LED_Write(1);             //hook up test LED
	time_init();                //init everything
	can_init();
	usb_init();
	sd_init(time_get());
    radio_init_SPI();           //xbee SPI    FE3
    
	for(;;)	{
        //can_test_send();
        can_test_receive();
        //xbee_Tx_req_test();
		CyDelay(1000);                 //refresh intervaal
	} // main loop

	return 0;
} // main()

/* when a can message is recieved will immediately save messages to external devices
	- transmit over xbee
	- write to sd
	- write to usb	*/
void msg_recieve(DataPacket * msg) {
	if(can_process(msg)) {	//if message is new data value
		xbee_send(msg);
		sd_buffer(msg);
		//usb_write(msg);
	}
}
