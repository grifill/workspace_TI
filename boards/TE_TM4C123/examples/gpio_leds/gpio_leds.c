/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   gpio_leds.c
 * \author Gregory Filatov
 * \date   26 January 2026
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
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"

//*****************************************************************************
// The error routine that is called if the driver library encounters an error.
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


int main(void) {

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
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_3);
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_6);
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_7);

    while(1) {

        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, GPIO_PIN_2);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, GPIO_PIN_3);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, GPIO_PIN_6);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, GPIO_PIN_7);
        for(i = 0; i < 100000; i++) {
        }
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_3, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_6, 0);
        GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_7, 0);
        for(i = 0; i < 100000; i++) {
        }

    }

    //return 0;
}
