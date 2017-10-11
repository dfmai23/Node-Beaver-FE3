/* API to receive SPI messages through xbee              
         -pin on arduino-
MOSI          11  //output to xbee
MISO/DATA_IN  12  //input from xbee
SCLK          13 
SS            10  // using digital pin 10 for SPI slave select

transmitter will send a Tx Request (0x10) API frame and the receiver will receive as a Rx Indicator (0x90) API frame
meaning it has successfully captured the SPI transmission.
*/

const int ATTN = 8;
const int LED = 13;
#define speed_Hz  500000     //xbee can operate at a speed up to 3.5MHz
#define bit_order MSBFIRST   
#define data_mode SPI_MODE0   //data is sampled onthe leading edge and the leading edge rises

#include "SPI.h" // necessary library

uint8_t len = 33;
uint8_t i = 0;
uint8_t data[30];
uint8_t databyte;
uint8_t candata[16];
uint8_t FF = 0xFF;
uint8_t OA = 0x0A;

void setup() {
  Serial.begin(9600);
  SPI.begin();      //Initializes SPI bus: SCLK, MOSI, and SS to outputs, pull SCK and MOSI low, SS high, put SPI into Master Mode 
  pinMode(ATTN, INPUT);
  pinMode(LED, OUTPUT);
  SPISettings xBeeSetting(speed_Hz, bit_order, data_mode);
  SPI.beginTransaction(xBeeSetting);
  Serial.println("SPI initialized");
  delay(100);       //give the sensor time to set up
}
 

void loop() {
  if(digitalRead(ATTN) == LOW)  { //wait till ATTN is asserted
      digitalWrite(SS, LOW);      //assert xbee
      //readbyte();
      //read_API_frame();
      //read_can();
      read_raw();
      digitalWrite(SS, HIGH);      //unassert xbee
  } //if
  /*
  digitalWrite(SS, LOW);
  SPI.transfer(0x01);
  digitalWrite(SS, HIGH);      //unassert xbee
  SPI.endTransaction();
  delay(1000);
  */
}

void readbyte() {
  databyte = SPI.transfer(0);   //reading, so not transferring anything
  Serial.printf("%02X", databyte);
  Serial.print(' ');
  i++;
  if(i == 30) {
    Serial.println();
    i=0;
  }
}

void read_API_frame() {
  for(i=0; i<30; i++) {
    data[i] = SPI.transfer(0);
    Serial.printf("%02X", data[i]);
    Serial.print(' ');
  } //for
  Serial.println();
}

//server only needs the CAN data
void read_can() {
  for(i=0; i<30; i++) {
    data[i] = SPI.transfer(0);
  }
  for(i=0; i<14; i++) {
    Serial.printf("%02X", data[i+15]);
    Serial.print(' ');
  }
  Serial.println();
}

void read_raw() {
  for(i=0; i<30; i++) {
    data[i] = SPI.transfer(0);
  }
  for(i=0; i<14; i++) {
    Serial.write(data[i+15]);
  }
  Serial.write(FF);
  Serial.write(OA);
}

void read_raw2() {
  for(i=0; i<30; i++) {
    if(i>14 && i<29) { 
      Serial.write(SPI.transfer(0));
    }
  }
  Serial.write(FF);
  Serial.write(OA);
}

