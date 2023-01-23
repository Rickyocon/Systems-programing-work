#include<stdio.h>
#include<bcm2835.h>
#include"PWM.h"

#ifndef MOTOR_HAT
#define MOTOR_HAT

typedef struct MOTOR{
	int pwm;
	int in2;
	int in1;
}motor;

motor motors[4];

#define FORWARD 	1
#define BACKWARD 	2
#define BRAKE		3
#define RELEASE		4

#define SINGLE		1
#define	DOUBLE		2
#define INTERLEAVE	3
#define MICROSTEP	4

void initMotors();

void initHat();

void run(unsigned char command, unsigned char motorID);

void setPin(unsigned char pin, unsigned char value);


#endif
