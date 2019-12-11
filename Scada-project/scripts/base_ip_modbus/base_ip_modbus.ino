#include <SPI.h>
#include <Ethernet.h>
#include <Modbus.h>
#include <ModbusIP.h>

//Modbus Registers Offsets (0-9999)
const int LED1_COIL = 0;
const int LED2_COIL = 1;
const int LED3_COIL = 2;

//Used Pins
const int ledPin1 = 7;
const int ledPin2 = 6;
const int ledPin3 = 5;

//ModbusIP object
ModbusIP mb;

void setup() {

// The media access control (ethernet hardware) address for the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 

// The IP address for the shield
byte ip[] = { 192, 168, 15, 102 };   

//Config Modbus IP 
mb.config(mac, ip);

//Set ledPin mode
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);

// Add LAMP1_COIL register - Use addCoil() for digital outputs
mb.addCoil(LED1_COIL);
mb.addCoil(LED2_COIL);
mb.addCoil(LED3_COIL);

}

void loop() {

//Call once inside loop() - all magic here
mb.task();

//Attach ledPin to LAMP1_COIL register
digitalWrite(ledPin1, mb.Coil(LED1_COIL));
digitalWrite(ledPin2, mb.Coil(LED2_COIL));
digitalWrite(ledPin3, mb.Coil(LED3_COIL));
}
