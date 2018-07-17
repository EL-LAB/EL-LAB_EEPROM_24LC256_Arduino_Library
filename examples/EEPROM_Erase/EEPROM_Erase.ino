/*
    EEPROM_Erase.ino

    This example erases the entire memory. It writes 0xFF
    to free the memory location. The write process is
    done only on those locations with data.

    Created: July 17th, 2018
    Author: El Lab de Electro: EL LAB
    Modified: -
    Author: -

    URL: https://github.com/EL-LAB/EL-LAB_EEPROM_24LC256_Arduino_Library
*/

#include "eeprom.h"

const uint16_t MAX_SIZE = 32768; // EEPROM memory size (bytes).

unsigned long timeA = 0;         // Erasing process duration.
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
  
  Serial.println("\nEEPROM memory will be erased in 5 seconds...");
  delay(5000);
  Serial.println("Erasing EEPROM memory...");
  
  // Writes 0xFF to "erase" the memory locations.
  timeA = millis(); // Start time.
  for (uint16_t address = 0x0000; address < MAX_SIZE; address++) {
    if (myEEPROM.read_byte(address) != 0xFF) { // Erase only those locations with data.
      myEEPROM.erase_byte(address);
    }
  }
  timeB = millis(); // Finish time.
  
  Serial.println("EEPROM memory erased.");
  
  // Time duration.
  Serial.print("\nTime elapsed: ");
  Serial.print((timeB - timeA) / 1000.0, 2);
  Serial.println(" sec.");
}

void loop()
{

}
