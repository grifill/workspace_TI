/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   main_combine.c
 * \author Gregory Filatov
 * \date   19 February 2026
 * \version 0.1.0
 *
 * \brief  Contains main (combine) function (examples TM4C123GH6PZ chip)
 *
 * Module: Combine function
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

// Examples - List
#include "gpio_leds.h"
#include "timer_leds.h"
#include "uart_hello.h"

int main(void) {

    example_timer_leds();
    //example_gpio_leds();
    //example_uart_hello();

    while(1) {
    }

    //return 0;
}

//*****************************************************************************
// The error routine that is called if the driver library encounters an error.
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif
