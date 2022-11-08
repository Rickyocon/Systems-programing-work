#include <bcm2835.h>
#include <stdio.h>
 
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN1 RPI_GPIO_P1_11
//Blinks on RPi plug p1 pin 12 (which is gpio pin 18)
//#define PIN2 RPI_GPIO_P1_12


// Blinks on RPi Plug P1 pin 13 (which is GPIO pin 27)
#define PIN2 RPI_BPLUS_GPIO_J8_13

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    //bcm2835_set_debug(1);
 
    if (!bcm2835_init())
      return 1;
 
    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);

    // Blink
    while (1)
    {

        // Turn on pin 1
        bcm2835_gpio_write(PIN1, HIGH);
        
        // wait a bit
        bcm2835_delay(100);
        
        // turn it off
        bcm2835_gpio_write(PIN1, LOW);
        
        // wait a bit
        bcm2835_delay(100);

	// Turn on pin 1
        bcm2835_gpio_write(PIN1, HIGH);
        
        // wait a bit
        bcm2835_delay(100);
        
        // turn it off
        bcm2835_gpio_write(PIN1, LOW);
        
        // wait a bit
        bcm2835_delay(100);

	// Turn on pin 1
        bcm2835_gpio_write(PIN1, HIGH);
        
        // wait a bit
        bcm2835_delay(100);
        
        // turn it off
        bcm2835_gpio_write(PIN1, LOW);
        
        // wait a bit
        bcm2835_delay(100);





	// Turn on pin 2
        bcm2835_gpio_write(PIN2, HIGH);
        
        // wait a bit
        bcm2835_delay(100);
        
        // turn it off
        bcm2835_gpio_write(PIN2, LOW);
        
        // wait a bit
        bcm2835_delay(100);

	// Turn on pin 2
        bcm2835_gpio_write(PIN2, HIGH);
        
        // wait a bit
        bcm2835_delay(100);
        
        // turn it off
        bcm2835_gpio_write(PIN2, LOW);
        
        // wait a bit
        bcm2835_delay(100);

	// Turn on pin 2
        bcm2835_gpio_write(PIN2, HIGH);
        
        // wait a bit
        bcm2835_delay(100);
        
        // turn it off
        bcm2835_gpio_write(PIN2, LOW);
        
        // wait a bit
        bcm2835_delay(100);



    }

    bcm2835_close();
    return 0;
} //main
