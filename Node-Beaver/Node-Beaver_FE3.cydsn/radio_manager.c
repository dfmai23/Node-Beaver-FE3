/* Enables xbee transmission to another xbee wirelessly in SPI Operation
	SPI 
	XBEE in API Mode, read xbee documentation
*/
#include "radio_manager.h"

static uint8_t addr[8];


void radio_init_SPI(void) {
    xbee_spi_Start();
    set_des_addr(DES_ADDR);
}


//put des addr into array, MSB first for transmission
void set_des_addr(uint64_t newAddr) {
    int i=0;
    for (i=0;i<8;i++){
        addr[7-i]=(newAddr>>(8*i)) & 0xff;
    }
    return;
}


/*  to calculate: excluding frame delimiters and length bytes (msg[0-2]), 
	add all bytes keeping the lowest 8-bits of the result and subtract the result from 0xFF 

    to verify: add all bytes (including checksum, excluding delimiter and length) = 0xFF */
uint8_t checksum_calc(uint8_t* msg,int len){
    uint8_t cksum=0x00;
    uint8_t i=0;
    for (i=3;i<len;i++)
        cksum=cksum+msg[i];
    cksum = 0xFF - cksum;
    return cksum;
}

uint8_t checksum_verify(uint8_t* msg, int len) {
	uint8_t checksum = 0x00;
	uint8_t i=0;
	for(i=3; i<=len; i++)
		checksum = checksum + msg[i];
	return checksum;
}


void xbee_send(DataPacket * msg) {
	xbee_Tx_req(msg);
}//xbee_send()


void xbee_Tx_req(DataPacket* msg) {
    uint8_t API_frame[34];
    
    API_frame[0]=STARTER_DELIMITER;  //starter   
    API_frame[1]=0x00;           //MSB L 
    API_frame[2]=0x1D;           //LSB L number of bytes between length and checksum
    
    API_frame[3]=0x10;           //Frame type, TX Request
    API_frame[4]=0x00;           //Frame ID
    
    API_frame[5]=addr[0];        //desination address
    API_frame[6]=addr[1];
    API_frame[7]=addr[2];
    API_frame[8]=addr[3];
    API_frame[9]=addr[4];
    API_frame[10]=addr[5];
    API_frame[11]=addr[6];
    API_frame[12]=addr[7];
    
    API_frame[13]=0xFF;          //reserved 0xFFFE
    API_frame[14]=0xFE;
    API_frame[15]=0x00;          //broadcast radius, max num of hops a transmission can occur
    API_frame[16]=0x00;          //transmit options
    
    //RF data, CAN packet, 15bytes
    API_frame[17]=(msg->id>>8) & 0xFF;   		//id
    API_frame[18]=msg->id & 0xFF;  
    
    //API_frame[19]=msg->length;            		//length
    
    API_frame[19] = msg->millicounter >> 24;   //timestamp
    API_frame[20] = msg->millicounter >> 16;
    API_frame[21] = msg->millicounter >> 8;
    API_frame[22] = msg->millicounter;     
    
    API_frame[23]=msg->data[0];           		//data
    API_frame[24]=msg->data[1];
    API_frame[25]=msg->data[2];  
    API_frame[26]=msg->data[3];  
    API_frame[27]=msg->data[4];  
    API_frame[28]=msg->data[5];  
    API_frame[29]=msg->data[6];  
    API_frame[30]=msg->data[7];  
    
	API_frame[31]=0xFF;
	API_frame[32]=0x0A;
	
    API_frame[33]=checksum_calc(API_frame,33);

	xbee_spi_PutArray(API_frame, 34);
}


void xbee_Tx_req_test(){
	int i;
	for(i=100; i<101; i++) {
		//uint8_t test_msg[33] = {0x7E, 0x00, 0x1D, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x09, 0x99, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x2D};
	    uint8_t msg[34];
	    
	    msg[0] = STARTER_DELIMITER; //starter
	    msg[1] = 0x00;      //MSB len
	    msg[2] = 0x1E;      //LSB len                    
	    
	    msg[3] = 0x10;      //frame type
	    msg[4] = 0x00;      //frame id
	    
		msg[5] = addr[0];      //receiver addr
	    msg[6] = addr[1]; 
	    msg[7] = addr[2];
	    msg[8] = addr[3];
	    msg[9] = addr[4]; 
	    msg[10] = addr[5];
	    msg[11] = addr[6];
	    msg[12] = addr[7];
		
		/*
	    msg[5] = 0x00;      //receiver addr
	    msg[6] = 0x13; 
	    msg[7] = 0xA2;
	    msg[8] = 0x00;
	    msg[9] = 0x41; 
	    msg[10] = 0x52;
	    msg[11] = 0xE9;
	    msg[12] = 0x17;
	    */
		/*
	    msg[5] = 0x00;      //receiver addr
	    msg[6] = 0x00; 
	    msg[7] = 0x00;
	    msg[8] = 0x00;
	    msg[9] = 0x00; 
	    msg[10] = 0x00;
	    msg[11] = 0xFF;
	    msg[12] = 0xFF;
	    */
		
	    msg[13] = 0xFF;     //0xFFFE reserved
	    msg[14] = 0xFE;     
	    msg[15] = 0x00;     //broadcast radius
	    msg[16] = 0x00;     //transmit options
	    
	    //data, CAN packet 15bytes
	    msg[17] = 0x09;     //id
	    msg[18] = 0x99;
	    //msg[19] = 8;        //len
	    
	    msg[19] = 0x00;     //timestamp
	    msg[20] = 0x00;
	    msg[21] = 0x00;
	    msg[22] = 0x01;     
	    
	    msg[23]=1;           //data
	    msg[24]=2;
	    msg[25]=3;  
	    msg[26]=4;  
	    msg[27]=5;  
	    msg[28]=6;  
	    msg[29]=7;  
	    msg[30]=8;  
	    
		msg[31]=0xFF;
		msg[32]=0x0A;
		
	    msg[33]=checksum_calc(msg,33);
	  
	    LED_Write(1);
	    xbee_spi_PutArray(msg, 34);
	    LED_Write(0);
	}
    return;
}
    

