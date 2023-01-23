// gcc -o input input.c -l bcm2835
// sudo ./input



#include <bcm2835.h>
#include <stdio.h>
#include "MyLib.h"

// Input on RPi pin GPIO pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11
#define PIN1 RPI_BPLUS_GPIO_J8_12 (GPIO pin 18)
#define PIN2 RPI_BPLUS_GPIO_J8_16 (GPIO pin 23)

int main(int argc, char **argv)
{
	// If you call this, it will not actually access the GPIO
	// Use for testing
	//bcm2835_set_debug(1);

	if (!bcm2835_init())
	return 1;
	
	ReadButtonPress(PIN);
	count = count%2;

	//set gpio pin 18 as an output 
	bcm2835_gpio_fesl(PIN1, BCM2835_GPIO_FSEL_OUTP);

	//set gpio pin 23 as an output
	bcm2835_gpio_fesl(PIN2, BCM2835_GPIO_FSEL_OUTP);
	
	while (1)
	{
		//If button is pressed an odd amount of times
		if(count == 1)
		{
			//Right LED
			bcm2835_gpio_write(PIN1, HIGH)
			bcm2835_gpio_write(PIN2, LOW)

		}
		//If button is pressed an even amount of times
		else
		{
			//left LED
			bcm2835_gpio_write(PIN2, HIGH)
			bcm2835_gpio_write(PIN1, LOW)

		}

	}
	bcm2835_close();
	return 0;
	
} //main

