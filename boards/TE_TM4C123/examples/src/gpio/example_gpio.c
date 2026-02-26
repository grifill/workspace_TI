/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   gpio_leds.c
 * \author Gregory Filatov
 * \date   19 February 2026
 * \version 0.1.0
 *
 * \brief  Contains GPIO-LEDS Example for TM4C123GH6PZ chip
 *
 * Module: Simple example
 *
 * Purpose: Example, education
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */

#include "gpio_leds.h"

int example_gpio_leds(void) {

    volatile uint32_t i = 0;

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

    // Enable the GPIO pin for the LED (PG3),
    // set the direction as output, and enable the GPIO pin for digital function
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_3);
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_6);
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_7);

    while(1) {

        // Led1 On, other Off
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, GPIO_PIN_3);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_6, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_7, 0);
        for(i = 0; i < DELAY_CYCLE; i++) {}

        // Led2 On, other Off
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, GPIO_PIN_2);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_6, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_7, 0);
        for(i = 0; i < DELAY_CYCLE; i++) {}

        // Led3 On, other Off
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_6, GPIO_PIN_6);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_7, 0);
        for(i = 0; i < DELAY_CYCLE; i++) {}

        // Led3 On, other Off
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_6, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_7, GPIO_PIN_7);
        for(i = 0; i < DELAY_CYCLE; i++) {}

    }

    //return 0;
}
