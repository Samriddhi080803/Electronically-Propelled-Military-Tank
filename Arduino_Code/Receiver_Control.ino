
//Receiver
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio (9, 8); // CE, CSN

//address through which two modules communicate.
const byte address [6] = "00001";
uint8_t data; // important note variable length should be same
for transmitter and receievr board, otherwise data will not receive correct

int motor_r2 = 4;
int motor_r1 = 5;
int motor_12 = 6;
int motor_11= 7; 
#define step_enable A0

const int dirPin = 3; 
const int steppin = 2;
const int stepsPerRevolution = 20;

void setup()
{
while (!Serial);
  Serial.begin(9600);
radio.begin();

//set the address
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);

//Set module as receiver
radio.startlistening();
pinMode(motor_11, OUTPUT);
pinMode(motor_12, OUTPUT);
pinMode(motor_r1, OUTPUT);
pinMode(motor_r2, OUTPUT);
digitalWrite(motor_r1, LOW);
digitalWrite(motor_r2, LOW);
digitalWrite(motor_11, LOW); 
digitalWrite(motor_12, LOW);

pinMode(stepPin, OUTPUT);
pinMode(dirPin, OUTPUT);
pinMode(step_enable, OUTPUT);
digitalWrite(step_enable, HIGH);
}

void loop()
{
//Read the data if available in buffer
if (radio.available())
{
	radio.read(&data, sizeof(data));

	Serial.println(data);
}

if (data == 10)
{
	digitalWrite(motor_r1, HIGH);
	digitalWrite(motor_r2, LOW);
   	delay(1000);
	digitalWrite(motor_r1, LOW);
	digitalWrite(motor_r2, LOW);
}
if (data == 20)
{
	digitalWrite(motor_r1, LOW);
	digitalWrite(motor_r2, HIGH);
   	delay(1000);
	digitalWrite(motor_r1, LOW);
	digitalWrite(motor_r2, LOW);
}
if (data == 30)
{
	digitalWrite(motor_l1, HIGH);
	digitalWrite(motor_l2, LOW);
   	delay(1000);
	digitalWrite(motor_l1, LOW);
	digitalWrite(motor_l2, LOW);
}
if (data == 40)
{
	digitalWrite(motor_l1, LOW);
	digitalWrite(motor_l2, HIGH);
   	delay(1000);
	digitalWrite(motor_l1, LOW);
	digitalWrite(motor_l2, LOW);
}
if (data == 50)
{
 digitalWrite(step_enable, LOW);
 
 Serial.printIN("Clockwise");
 digitalWrite(dirPin, LOW);
for(int x = 0; x < stepsPerRevolution; x++)
  {
	digitalWrite(stepPin, HIGH);
	delayMicroseconds(500);
	digitalWrite(stepPin, LOW);
	delayMicroseconds(500);
  }
delay(1000); // wait a second
}
else if (data == 60)
{
  SerialprintIn("anti----clockwise");
  digitalWrite(step_enable, LOW);
  digitalWrite(dirPin, HIGH);
for(int x = 0; x < stepsPerRevolution; x++)
  {
 	digitalWrite(stepPin, HIGH);
	delayMicroseconds(500);
	digitalWrite(stepPin, LOW);
	delayMicroseconds(500);
  }  
  delay(1000); // Wait a second
}

else digitalWrite(step_enable, HIGH);

data = 0;
}

