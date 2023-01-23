#include<stdio.h>
#include<bcm2835.h>
#include"I2C.h"


void run(unsigned char command, unsigned char motorID) 
{

  motor->MC = controller;
  motor->motornum = num;
  motor->PWMpin = motor->IN1pin = motor->IN2pin = 0;

  if (num == 0) {
    motor->PWMpin = 8;
    motor->IN2pin = 9;
    motor->IN1pin = 10;
  } else if (num == 1) {
    motor->PWMpin = 13;
    motor->IN2pin = 12;
    motor->IN1pin = 11;
  } else if (num == 2) {
    motor->PWMpin = 2;
    motor->IN2pin = 3;
    motor->IN1pin = 4;
  } else if (num == 3) {
    motor->PWMpin = 7;
    motor->IN2pin = 6;
    motor->IN1pin = 5;
  } else {
    fprintf(stderr, "MotorHAT Motor must be between 1 and 4 inclusive\n");
    exit(EXIT_FAILURE);
  }

  if (command == FORWARD) {
    setPin(IN2pin, 0);
    setPin(IN1pin, 1);
  }
  if (command == BACKWARD) {
    setPin(IN1pin, 0);
    setPin(IN2pin, 1);
  }
  if (command == RELEASE) {
    setPin(IN1pin, 0);
    setPin(IN2pin, 0);
  }
}



void setPin(unsigned char pin, unsigned char value) 
{
  if ((pin < 0) || (pin > 15)) {
    fprintf(stderr, "PWM pin must be between 0 and 15 inclusive\n");
    exit(EXIT_FAILURE);
  }
  if ((value != 0) && (value != 1)) {
    fprintf(stderr, "Pin value must be 0 or 1!\n");
    exit(EXIT_FAILURE);
  }
  if (value == 0) {
    _pwm.setPWM(pin, 0, 4096);
  }
  if (value == 1) {
    _pwm.setPWM(pin, 4096, 0);
  }
}