Copy code
#include <stdio.h>
#include<bcm2835.h>
#include"I2C.h"

int main(int argc, char** argv) {

    int i2cInit(int address, int buss);

    void write8(unsigned char 0x01, unsigned char 0x04);

    unsigned int readU8(unsigned char 0x01);

  return 0;
}