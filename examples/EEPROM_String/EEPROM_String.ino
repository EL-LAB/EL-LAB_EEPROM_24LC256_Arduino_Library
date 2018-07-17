/*
    EEPROM_String.ino

    This example writes a string in memory. Then,
    the given string is read from memory.

    Created: July 17th, 2018
    Author: El Lab de Electro: EL LAB
    Modified: -
    Author: -

    URL: https://github.com/EL-LAB/EL-LAB_EEPROM_24LC256_Arduino_Library
*/

#include "eeprom.h"

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

  // String to write in memory.
  // IMPORTANT: The string must be less or equal than 30 bytes!
  char data_string[] = "This is my EEPROM memory.";
  
  Serial.print("\nWriting ");
  Serial.print(sizeof(data_string), DEC);
  Serial.print(" bytes: ");
  Serial.print('"');
  Serial.print(data_string);
  Serial.println('"');
  
  // Writing starts from address 0x0000 (first address).
  myEEPROM.write_string(0x0000, (byte*) data_string, sizeof(data_string));
  
  Serial.print("\nReading ");
  Serial.print(sizeof(data_string), DEC);
  Serial.print(" bytes: ");
  Serial.print('"');

  // Reads the string to make sure it was stored in memory.
  // IMPORTANT: It's not possible to read more than 32 bytes!
  for (uint16_t address = 0x0000; address < sizeof(data_string); address++) {
    Serial.print((char) myEEPROM.read_byte(address));
  }
  Serial.println('"');
  Serial.println("");
}

void loop()
{

}
