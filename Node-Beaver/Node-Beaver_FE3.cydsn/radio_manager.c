/* Enables xbee transmission to another xbee wirelessly
    UART and SPI Operation
*/

#include "radio_manager.h"

static uint8_t addr[8];

void radio_init_SPI(void) {
    xbee_spi_Start();
    set_des_addr(DES_ADDR);
}

// SPI ---------------------------------------------------------------
// XBEE in API Mode, read xbee documentation
uint8_t translator(uint8_t data){
    uint8_t Lside=data&0xf;
    uint8_t Hside=(data>>4)&0xf;
    return 0;
}

//put des addr into array, MSB first
void set_des_addr(uint64_t newAddr) {
    int i=0;
    for (i=0;i<8;i++){
        addr[7-i]=(newAddr>>(8*i)) & 0xff;
    }
    return;
}

void XBee_TX_req(const DataPacket* msg){
    int i=0;
    uint8_t send_msg[33];
    
    send_msg[0]=STARTER_DELIM;  //starter   
    send_msg[1]=0x00;           //MSB L 
    send_msg[2]=0x1D;           //LSB L number of bytes between length and checksum
    
    send_msg[3]=0x10;           //Frame type, TX Request
    send_msg[4]=0x01;           //Frame ID
    
    send_msg[5]=addr[0];        //desination addr 8
    send_msg[6]=addr[1];
    send_msg[7]=addr[2];
    send_msg[8]=addr[3];
    send_msg[9]=addr[4];
    send_msg[10]=addr[5];
    send_msg[11]=addr[6];
    send_msg[12]=addr[7];
    
    send_msg[13]=0xff;          //reserved 0xFFFE
    send_msg[14]=0xfe;
    send_msg[15]=0x00;          //broadcast radius, max num of hops a transmission can occur
    send_msg[16]=0x00;          //transmit options
    
    //RF data, CAN packet, 15bytes
    send_msg[17]=(msg->id>>8) & 0xff;   //id
    send_msg[18]=msg->id & 0xff;  
    
    send_msg[19]=msg->length;            //length
    
    send_msg[20] = ((msg->millicounter) >> 24) & 0xff;   //time
    send_msg[21] = ((msg->millicounter) >> 16) & 0xff;
    send_msg[22] = ((msg->millicounter) >> 8) & 0xff;
    send_msg[23] = (msg->millicounter) & 0xff;     
    
    send_msg[24]=msg->data[0];           //data
    send_msg[25]=msg->data[1];
    send_msg[26]=msg->data[2];  
    send_msg[27]=msg->data[3];  
    send_msg[28]=msg->data[4];  
    send_msg[29]=msg->data[5];  
    send_msg[30]=msg->data[6];  
    send_msg[31]=msg->data[7];  
    
    send_msg[32]=checksum(send_msg,32);

    xbee_spi_WriteTxData(STARTER_DELIM);
    for (i = 1; i < 33; i++) {
        xbee_spi_WriteTxData(send_msg[i]);
    }
    
    while (!(xbee_spi_ReadTxStatus() & xbee_spi_STS_TX_FIFO_EMPTY)) {
    }
    
    CyDelayUs(2);
    return;
}

/*  to calculate: not including frame delimiters and length, add all bytes keeping the lowest 8-bits of
    the result and subtract the result from 0xFF 

    to verify: add all bytes (including checksum, not including delimiter and length) = 0xFF */
uint8_t checksum(uint8_t* msg,int len){
    uint8_t cksum=0x00;
    uint8_t i=0;
    for (i=3;i<len;i++){
        cksum=cksum+msg[i];
    }
    cksum = 0xFF - cksum;
    return cksum;
}

void dummy_put(){
    int i=0;
    //uint8_t send_msg[40]={0x7e,0x00,0x24,0x10,0x01,0x00,0x13,0xa2,0x00,0x40,0xc8,0x4f,0xbf,0xff,0xfe,0x00,0x00,0x73,0x65,0x6e,0x64,0x20,0x66,0x72,0x6f,0x6d,0x20,0x61,0x6c,0x69,0x65,0x6e,0x20,0x70,0x6c,0x61,0x6e,0x65,0x74,0xdb};
    //uint8_t mymsg[29]={0x7E, 0x00 , 0x19 , 0x10 , 0x01 , 0x00 , 0x13 , 0xA2 , 0x00 , 0x40 , 0xC8 , 0x4F , 0xBF , 0xFF , 0xFE , 0x00 , 0x00 , 0x48 , 0x65 , 0x6C , 0x6C , 0x6F , 0x20 , 0x57 , 0x6F , 0x72 , 0x6C , 0x64 , 0x0A};
    uint8_t msg[33];
    
    msg[0] = STARTER_DELIM; //starter
    msg[1] = 0x00;      //MSB len
    msg[2] = 0x24;      //LSB len                    
    
    msg[3] = 0x10;      //frame type
    msg[4] = 0x01;      //frame id
    /*
    msg[5] = 0x00;      //receiver addr
    msg[6] = 0x13; 
    msg[7] = 0xA2;
    msg[8] = 0x00;
    msg[9] = 0x41; 
    msg[10] = 0x52;
    msg[11] = 0xE9;
    msg[23] = 0x17;
    */
    
    msg[5] = 0x00;      //receiver addr
    msg[6] = 0x00; 
    msg[7] = 0x00;
    msg[8] = 0x00;
    msg[9] = 0x00; 
    msg[10] = 0x00;
    msg[11] = 0xFF;
    msg[23] = 0xFF;
    
    msg[13] = 0xFF;     //0xFFFE reserved
    msg[14] = 0xFE;     
    msg[15] = 0x00;     //broadcast radius
    msg[16] = 0x00;     //transmit options
    
    //data, CAN packet 15bytes
    msg[17] = 0x01;     //id
    msg[18] = 0x23;
    msg[19] = 8;        //len
    
    msg[20] = 0x00;     //time
    msg[21] = 0x00;
    msg[22] = 0x00;
    msg[23] = 0x00;     
    
    msg[24]=1;           //data
    msg[25]=2;
    msg[26]=3;  
    msg[27]=4;  
    msg[28]=5;  
    msg[29]=6;  
    msg[30]=7;  
    msg[31]=8;  
    
    msg[32]=checksum(msg,32);
  
    LED_Write(1);
    /*
    for (i=0;i<33;i++){
        xbee_spi_WriteTxData(msg[i]);
    }*/
    xbee_spi_PutArray(msg, 33);
    LED_Write(0);
    return;
}


void radio_put(const DataPacket* data_queue, uint16_t data_head, uint16_t data_tail) {
    uint16_t data_ptr;
    //_XBee_tx_req_(&(data_queue[0])); // test

    for(data_ptr=data_head; data_ptr!=data_tail; data_ptr=(data_ptr+1)%DATA_QUEUE_LENGTH){
       //_XBee_tx_req_(&(data_queue[data_ptr]));
       dummy_put();
    }
} // radio_put()
    

