# EL LAB: EEPROM 24LC256 Arduino Library
This library allows writing and reading data to the EEPROM memory 24LC256 using the I2C interface.

There is additional information about the library and its uses in the following sections:
- [Arduino Examples](https://github.com/EL-LAB/EL-LAB_EEPROM_24LC256_Arduino_Library#arduino-examples)
- [Library Functions](https://github.com/EL-LAB/EL-LAB_EEPROM_24LC256_Arduino_Library#library-functions)

## Arduino Examples
#### [EEPROM_Byte](/examples/EEPROM_Byte/EEPROM_Byte.ino)
This example shows how to write and read bytes in the EEPROM memory. The code will read, write and erase data to see how it changes in memory. The number of bytes to read, write and erase can be defined by the user.
#### [EEPROM_Capacity](/examples/EEPROM_Byte/EEPROM_Capacity.ino)
This example reads the entire memory and prints the current free space in memory.
#### [EEPROM_Erase](/examples/EEPROM_Byte/EEPROM_Erase.ino)
This example erases the entire memory. It writes `0xFF` to free the memory location. The write process is done only on those locations with data (a value different than `0xFF`).
#### [EEPROM_String](/examples/EEPROM_Byte/EEPROM_String.ino)
This example writes a string in memory. Then, the given string is read from memory. The string to write/read cannot be more than 30 bytes. This limitation relies on the I2C buffer size used by the `Wire.h` Arduino library.

## Library Functions
This library includes the following functions to initialize, write, read and erase data from the EEPROM memory 24LC256:
#### begin()
It starts the I2C communication on the board and checks if the EEPROM memory 24LC256 is available. It doesn't require any argument and it returns `TRUE` if the memory is found or `FALSE` otherwise.
```C++
bool begin(void);
```
#### write_byte()
It writes a byte (8 bits) in a memory location. This function receives 2 arguments which are the memory address where the data will be stored and the data to store. This function doesn't return anything.
```C++
void write_byte(uint16_t address, byte data);
```
#### read_byte()
It gets the data (a byte) stored in a memory location. This function receives 1 argument which is the memory address where the data is located at. It returns the byte stored in the memory location provided.
```C++
byte read_byte(uint16_t address);
```
#### erase_byte()
It erases the data stored in a memory location. This function performs a write operation to overwrite the data with the value `0xFF`. The value `0xFF` is considered as a free space in memory. This function receives 1 argument which is the memory address where the data will be erased. This function doesn't return anything.
```C++
void erase_byte(uint16_t address);
```
#### write_string()
It allows to write up to 30 bytes at the same time. Instead of writing information byte by byte, this function could be used to write the entire string in memory. It receives 3 arguments which are the memory address where the first byte of the string will be stored, the string to be stored and the lenght of that string. This function doesn't return anything.

**NOTE:** Since the I2C buffer size used by the `Wire.h` Arduino library, the string cannot be more than 30 bytes length. If it's more than 30 bytes, then the memory will store garbage data in the memory locations starting from the 31 byte.
```C++
void write_string(uint16_t address, byte* data_string, byte length);
```
