/*
    EEPROM_Capacity.ino

    This example reads the entire memory and prints
    the current free space in memory.

    Created: July 17th, 2018
    Author: El Lab de Electro: EL LAB
    Modified: -
    Author: -

    URL: https://github.com/EL-LAB/EL-LAB_EEPROM_24LC256_Arduino_Library
*/

#include "eeprom.h"

const uint16_t MAX_SIZE = 32768; // EEPROM memory size (bytes).
uint16_t FREE_SPACES = 0;        // Addresses with no data (0xFF).

unsigned long timeA = 0;         // Reading process duration.
unsigned long timeB = 0;

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

  Serial.println("\nReading EEPROM memory...");

  // Reading process
  timeA = millis(); // Start time.
  for (uint16_t address = 0x0000; address < MAX_SIZE; address++) {
    if (myEEPROM.read_byte(address) == 0xFF) {
      FREE_SPACES++; // Counts how many free locations are in memory.
    }
  }
  timeB = millis(); // Finish time.

  // Results
  Serial.print("\tMemory capacity: ");
  Serial.print(MAX_SIZE, DEC);
  Serial.println(" bytes.");
  
  Serial.print("\tFree space: ");
  Serial.print(FREE_SPACES, DEC);
  Serial.println(" bytes.");

  Serial.print("\tMemory used: ");
  Serial.print(100.0 * ((float)(MAX_SIZE - FREE_SPACES) / (float)MAX_SIZE), 2);
  Serial.println("%.");

  Serial.print("\nTime elapsed: ");
  Serial.print((timeB - timeA) / 1000.0, 2);
  Serial.println(" sec.");
}

void loop()
{

}
