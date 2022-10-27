#include <bcm2835.h>
#include <stdio.h>
 
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN1 RPI_GPIO_P1_11
// Blinks on RPi Plug P1 pin 12 (which is GPIO pin 18)
#define PIN2 RPI_GPIO_P1_12
 
int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    //bcm2835_set_debug(1);
 
    if (!bcm2835_init())
      return 1;
 
    // Set pin1 to be an output
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_OUTP);
    // Set pin2 to be an output
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);
 
    // Blink
    while (1)
    {
        // Turn it on
        bcm2835_gpio_write(PIN1, HIGH);
        
        // wait a bit
        bcm2835_delay(350);
        
        // turn it off
        bcm2835_gpio_write(PIN1, LOW);
        
        // wait a bit
        bcm2835_delay(350);



        // Turn it on
        bcm2835_gpio_write(PIN2, HIGH);
        
        // wait a bit
        bcm2835_delay(350);
        
        // turn it off
        bcm2835_gpio_write(PIN2, LOW);
        
        // wait a bit
        bcm2835_delay(350);
    }
    bcm2835_close();
    return 0;
}
 