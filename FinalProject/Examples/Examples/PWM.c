#include<stdio.h>
#include<bcm2835.h>
#include"I2C.h"


// Sends a software reset (SWRST) command to all the servo drivers on the bus
void softwareReset() {
  Adafruit_I2C general_call_i2c = Adafruit_I2C(0x00);
  general_call_i2c.writeRaw8(0x06);
}

// Initializes the PCA9685 and puts it into a usable state
void PWMInit(unsigned int address) {
  i2c = Adafruit_I2C(address);
  
  setAllPWM(pwm, 0, 0);
  write8(MODE2, OUTDRV);
  write8(MODE1, ALLCALL);
  sleep(0.005); // wait for oscillator

  int mode1 = readU8(MODE1);
  mode1 = mode1 & ~SLEEP; // wake up (reset sleep)
  write8(MODE1, mode1);
  sleep(0.005); // wait for oscillator
}


void setPWMFreq(int freq) {
  double prescaleval = 25000000.0; // 25MHz
  prescaleval /= 4096.0; // 12-bit
  prescaleval /= (double) freq;
  prescaleval -= 1.0;

  if (pwm->debug) {
    printf("Setting PWM frequency to %d Hz\n", freq);
    printf("Estimated pre-scale: %f\n", prescaleval);
  }
  int prescale = floor(prescaleval + 0.5);
  if (debug) {
    printf("Final pre-scale: %d\n", prescale);
  }

  int oldmode = readU8(MODE1);
  int newmode = (oldmode & 0x7F) | 0x10; // sleep
  write8(MODE1, newmode); // go to sleep
  write8(PRESCALE, (int) floor(prescale));
  write8(MODE1, oldmode);
  sleep(0.005);
  write8(MODE1, oldmode | 0x80);
}


void setPWM(int channel, int on, int off) {
  write8(LED0_ON_L + 4 * channel, on & 0xFF);
  write8(LED0_ON_H + 4 * channel, on >> 8);
  write8(LED0_OFF_L + 4 * channel, off & 0xFF);
  write8(LED0_OFF_H + 4 * channel, off >> 8);
}

void setAllPWM(int on, int off) {
  write8(ALL_LED_ON_L, on & 0xFF);
  write8(ALL_LED_ON_H, on >> 8);
  write8(ALL_LED_OFF_L, off & 0xFF);
  write8(ALL_LED_OFF_H, off >> 8);
}


void  write8(unsigned char reg, unsigned char value){
	char buff[2];
    buff[0] = reg;
    buff[1] = value;
	uint8_t result;
	result = bcm2835_i2c_write(buff,2);
    // Check for errors
    if (result != BCM2835_I2C_REASON_OK)
    {
        // Print an error message based on the error code
        switch (result)
        {
            case BCM2835_I2C_REASON_ERROR_NACK:
                printf("Error: Received NACK\n");
                break;
            case BCM2835_I2C_REASON_ERROR_CLKT:
                printf("Error: Received Clock Stretch Timeout\n");
                break;
            case BCM2835_I2C_REASON_ERROR_DATA:
                printf("Error: Not all data was transferred\n");
                break;
            default:
                printf("Error: Unknown error code\n");
                break;
        }
    }
}



unsigned int readU8(unsigned char reg)
{
    // Declare a 2-byte buffer
    uint8_t buff[2];

    // Set the first element of the buffer to the register value
    buff[0] = register;

    // Read the value from the register using bcm2835_i2c_read()
    int result = bcm2835_i2c_read(buff, 1);

    // Check for errors
    if (result != BCM2835_I2C_REASON_OK)
    {
        // Print an error message based on the error code
        switch (result)
        {
            case BCM2835_I2C_REASON_ERROR_NACK:
                printf("Error: Received NACK\n");
                break;
            case BCM2835_I2C_REASON_ERROR_CLKT:
                printf("Error: Received Clock Stretch Timeout\n");
                break;
            case BCM2835_I2C_REASON_ERROR_DATA:
                printf("Error: Not all data was transferred\n");
                break;
            default:
                printf("Error: Unknown error code\n");
                break;
        }

        // Return 0 in case of an error
        return 0;
    }

    // Return the value from the first element of the buffer
    return buff[0];
}
