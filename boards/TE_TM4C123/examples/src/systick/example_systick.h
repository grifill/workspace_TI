/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   uart_hello.h
 * \author Gregory Filatov
 * \date   19 February 2026
 * \version 0.1.0
 *
 * \brief  Contains UART-Hello Example for TM4C123GH6PZ chip
 *
 * Module: Simple example
 *
 * Purpose: Example, education
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */

#ifndef UART_HELLO_H_
#define UART_HELLO_H_

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
#include "driverlib/uart.h"

// Main example function
int example_uart_hello(void);





#endif /* UART_HELLO_H_ */
