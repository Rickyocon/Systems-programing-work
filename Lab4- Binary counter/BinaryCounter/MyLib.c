#include "MyLib.h"

int ReadButtonPress(int PIN)
{
	// Set PIN to be an input
	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
	//  add a pullup
	bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_UP);
	// and enble low
	bcm2835_gpio_len(PIN);
	count = 0;

	while (1)
	{
	if (bcm2835_gpio_eds(PIN))
	{
		// Now clear the eds flag by setting it to 1
		bcm2835_gpio_set_eds(PIN);

		//Read some data
		uint8_t value = bcm2835_gpio_lev(PIN);
		printf("Read form pin 17: %d\n", value);
		if(value == 1)
		{
			count = count + 1;	
		}
		printf("The button was pressed %d times\n", count);
		
        }
	delay(500);
	}
	return count;
}	


