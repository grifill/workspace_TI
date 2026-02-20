/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   func_gpio.c
 * \author Gregory Filatov
 * \date   20 February 2026
 * \version 0.1.0
 *
 * \brief  Contains user-library GPIO functions for Tiva-C controllers
 *
 * Module: Library GPIO
 *
 * Purpose: Tiva-C GPIO user functions
 *
 * Functionality:
 *     Library
 * ---------------------------------------------------------------------------
 */
#include "func_gpio.h"

void GPIOPinToggle(uint32_t ui32Port, uint8_t ui8Pins) {

    // Check the arguments.
    ASSERT(_GPIOBaseValid(ui32Port));

    // Write the pins.
    HWREG(ui32Port + (GPIO_O_DATA + (ui8Pins << 2))) ^= ui8Pins;
}
