/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   uart_hello.c
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

#include "uart_hello.h"

static void UARTSend(const uint8_t *pui8Buffer, uint32_t ui32Count) {
    while(ui32Count--) {
        MAP_UARTCharPut(UART0_BASE, *pui8Buffer++);
    }
}

int example_uart_hello(void) {

    // Set the clocking to run directly from the crystal
    MAP_SysCtlClockSet(SYSCTL_SYSDIV_1 |
                       SYSCTL_USE_OSC |
                       SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);

    // Enable the peripherals used by this example
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Set GPIO A0 and A1 as UART pins
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    MAP_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Configure the UART for 115,200, 8-N-1 operation
    MAP_UARTConfigSetExpClk(UART0_BASE, MAP_SysCtlClockGet(), 115200,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    // Prompt for text to be entered
    UARTSend("\r\n Hello TE-TM4C123 \n", 21);

    while(1) {
    }

    //return 0;
}
