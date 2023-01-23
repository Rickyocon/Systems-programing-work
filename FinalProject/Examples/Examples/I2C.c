#include<stdio.h>
#include<regex.h>
#include<fcntl.h>
#include<unistd.h>
#include<bcm2835.h>
#include"I2C.h"

#define BUFFERSIZE 4096



extern int i2cInit(int address, int buss){
	Address *theAddress;
	
	theAddress = (Address*)malloc(sizeof(Address));
	
	theAddress->address = address;
	theAddress->bussNumber = buss;
	
	//i2c initialization should also go here.
	
	if (!bcm2835_init())
    	{
     		printf("bcm2835_init failed. Are you running as root??\n");
      		return 1;
    	}//if bcm_init
	
	if (!bcm2835_i2c_begin())
    	{
		printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return 1;
	}//if i2c_begin

	bcm2835_i2c_setSlaveAddress(address); //set HAT address to 0x41
	return 0;
	
	
}



