/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   timer_leds.c
 * \author Gregory Filatov
 * \date   19 February 2026
 * \version 0.1.0
 *
 * \brief  Contains Timer Example for TM4C123GH6PZ chip
 *
 * Module: Simple example
 *
 * Purpose: Example, education
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#include "timer_leds.h"


void SysTick_Handler(void);

int example_timer_leds(void) {

    // Set the clocking to run directly from the crystal
    MAP_SysCtlClockSet(SYSCTL_SYSDIV_1 |
                       SYSCTL_USE_OSC |
                       SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);


    // Enable the peripherals used by this example
    // Enable the GPIO port that is used for the on-board LED
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);

    // Check if the peripheral access is enabled
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOG)) {
    }

    SysTickEnable();
    SysTickPeriodSet(16000000 - 1);


    // Enable the GPIO pin for the LED (PG3),
    // set the direction as output, and enable the GPIO pin for digital function
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_3);

    while(1) {
        if(SysTickValueGet() > 15000000) {
            GPIOPinToggle(GPIO_PORTG_BASE, GPIO_PIN_3);
        }
    }

    //return 0;
}

/*
void SysTick_Handler(void);

int main()
{
    SYSCTL->RCGCGPIO |= (1U << 5);  // enable clock for GPIOF
    GPIOF->DEN |= LED_RED; // enable digital function on pin 1
    GPIOF->DIR |= LED_RED; // set pin 1 as output

    SysTick->LOAD = 16000000 - 1; // set reload value for 1 second delay
    SysTick->VAL = 0; // clear the current value and the COUNT flag
    SysTick->CTRL = (1U << 2) | (1U << 1) | 1U; // enable systick timer with system clock and interrupt

    __enable_irq(); // enable global interrupts

    while(1)
    {
        // do nothing
    }
}

void SysTick_Handler(void)
{
    GPIOF->DATA ^= LED_RED; // toggle LED pin
}
*/
