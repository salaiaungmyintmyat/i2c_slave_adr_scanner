/*
    I2C Slave Address Scanner
    -------------------------
    Description:
    It is used brute-force method to find the slave address.
    if TWI's status register(TWSR) has no error, then the address is marked as its slave address.
    If the register has error, then skip that address and find the next address number.

    Tested Boards: Arduino UNO, Nano (Atmega328p MCU)
    MCU Clock: 16 MHz

    *****************************************************************************
    **Notes - Don't forget to check MCU clock if another Arduino board is used.**
    **        (e.g. Pro Mini 3.3v, 8MHz)                                       **
    *****************************************************************************
    !!UPDATED: Convert to 7-bit word address for searching slave address.  
    
    Date: 30 Sep 2019
    
    Written by 
    Salai Aung Myint Myat
 */

#include "Master_TWI.h"

void setup() {
  Serial.begin(9600);
  i2cMaster_Init();     // Initialize I2C protocol

  Serial.println("Start");
}

void loop() {
  uint8_t address = 0;  // Start slave address number
  delay(1000);
  Serial.println("searching...");

  for (address = 0x00; address < 0xFF; address++) {
    i2cMaster_Start();
    i2cMaster_Adr_Write(address);
    i2cMaster_Stop();

    if (Error == 0)    break;     // If no error is found, then marks as slave address
  }

  if (Error == 0) {               // Print out that address number
    address = (address >> 1);     // Convert 7-bit addressing
    Serial.print("Found at = 0x");
    Serial.println(address, HEX);
  }
  else {                          // It can also not found, then check wire connection, unplug it and run this program again
    Serial.println("Not found");
  }
  
  Serial.println();
  delay(1000);
}
