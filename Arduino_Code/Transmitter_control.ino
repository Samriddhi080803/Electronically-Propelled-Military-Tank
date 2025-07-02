

Transmitter Controller Code:
//TRANS
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


//create an RF24 object
RF24 radio (9, 8); // CE pin 25, CSN pin 26, MOSI pin 23, MISO pin 19, sck pin 18

//address through which two modules communicate.
const byte address [6]= "00001";
uint8_t data[4]; // important note variable length should be same for transmitter and receiver board, otherwise data will not receive correct
int Button_dn_r = 2;
int Button_up_r = 3;
int Button_stp_clk = 4;
int Button_stp_ccw = 5;
int Button_dn_1 = 6;
int Button_up_1 = 7;

bool dn_r_value = 0;
bool up_r_value = 0;
bool dn_1_value = 0;
bool up_1_value = 0;
bool step_clk_value = 0;
bool step_ccw_value = 0;
void setup()
{
Serial.begin(9600);
pinMode(Button_dn_r, INPUT);
pinMode(Button_up_r, INPUT);
pinMode(Button_dn_1, INPUT);
pinMode(Button_up_1, INPUT);
pinMode(Button_stp_clk, INPUT);
pinMode(Button_stp_ccw, INPUT);

radio.begin();

//set the address
radio.openWritingPipe (address); 
radio.setPALevel (RF24_PA_MIN);

//Set module as transmitter
radio.stoplistening();
}
void loop()
{

dn_r_value = digitalRead(Button_dn_r); 
up_r_value = digitalRead(Button_up_r); 
dn_1_value = digitalRead(Button_dn_1); 
up_1_value digitalRead(Button_up_1); 
step_clk_value = digitalRead(Button_stp_clk); 
step_ccw_value = digitalRead(Button_stp_ccw);
Serial.print("dn_r_value:	"); Serial.println(dn_r_value)
Serial.print("up_r_value:	"); Serial.println(dn_r_value)
Serial.print("dn_1_value:	"); Serial.println(dn_r_value)
Serial.print("up_1_value:	"); Serial.println(dn_r_value)

Serial.print("step_clk_value:	"); Serial.println(step_clk_value);
Serial.print("step_ccw_value:	"); Serial.println(step_clk_value);
//Send message to receiver

if (dn_r_value == 1)
{
int data=10;
radio.write(&data, sizeof(data));
}
else if (up_r_value 1)
{
int data=20;
radio.write(&data, sizeof(data));
}
else if (dn_1_value == 1)
{
int data=30;
radio.write(&data, sizeof(data));
}
else if (up_1_value 1)
{
int data=40;
radio.write(&data, sizeof(data));
}
else if  (step_clk_value == 1);
{
int data=50;
radio.write(&data, sizeof(data));
}
else if (step_ccw_value == 1)
{
int data=60;
radio.write(&data, sizeof(data));
}

delay(500);

}
