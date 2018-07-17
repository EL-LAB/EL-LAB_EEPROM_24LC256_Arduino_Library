/*
    EEPROM_Byte.ino

    This example shows how to write and read bytes 
    in the EEPROM memory.

    The code will read and write different data 
    to see how it changes in memory.

    Created: July 17th, 2018
    Author: El Lab de Electro: EL LAB
    Modified: -
    Author: -

    URL: 
*/

#include "eeprom.h"

// Change this to define how many bytes to write.
uint16_t BYTES_TO_WRITE = 15;
byte DUMMY_DATA = 0xAA;

EEPROM myEEPROM(0x50); // I2C address.

void setup()
{
  Serial.begin(9600);

  // Checking connection
  if (myEEPROM.begin()) {
    Serial.println("EEPROM memory detected.");
  }
  else {
    Serial.println("EEPROM memory not detected!");
    return;
  }
  
  Serial.println("Reading EEPROM memory...");
  
  // First read of current data in memory.
  for (uint16_t address = 0x0000; address <= BYTES_TO_WRITE; address++) {
    Serial.print("\tAddress: ");
    Serial.print(address, HEX);
    Serial.print(":");
    Serial.println(myEEPROM.read_byte(address), HEX);
  }
  
  Serial.println("\nWriting EEPROM memory...\n");
  
  // First write of new data into the memory.
  for (uint16_t address = 0x0000; address <= BYTES_TO_WRITE; address++) {
    myEEPROM.write_byte(address, (byte) DUMMY_DATA);
  }
  
  Serial.println("Reading EEPROM memory...");
  
  // Second read of new data in memory.
  for (uint16_t address = 0x0000; address <= BYTES_TO_WRITE; address++) {
    Serial.print("\tAddress: ");
    Serial.print(address, HEX);
    Serial.print(":");
    Serial.println(myEEPROM.read_byte(address), HEX);
  }
  
  Serial.println("\nErasing EEPROM memory...\n");
  
  // Erasing data written into the memory.
  for (uint16_t address = 0x0000; address <= BYTES_TO_WRITE; address++) {
    myEEPROM.erase_byte(address);
  }
  
  Serial.println("Reading EEPROM memory...");
  
  // Third read of free locations in memory.
  for (uint16_t address = 0x0000; address <= BYTES_TO_WRITE; address++) {
    Serial.print("\tAddress: ");
    Serial.print(address, HEX);
    Serial.print(":");
    Serial.println(myEEPROM.read_byte(address), HEX);
  }
  
  Serial.println("\nDone!");
}

void loop()
{

}
