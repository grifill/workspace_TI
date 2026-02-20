/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   func_gpio.h
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
#ifndef FUNC_GPIO_H_
#define FUNC_GPIO_H_

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/debug.h"


///
/// \brief   Writes a value to the specified GPIO pin(s)
/// \details The function is used to toggle GPIO pins
///
/// \param[in] ui32Port is the base address of the GPIO port
/// \param[in] is the bit-packed representation of the pin(s)
///
/// \return None
///
void GPIOPinToggle(uint32_t ui32Port, uint8_t ui8Pins);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#include <stdbool.h>
#include <stdint.h>

#endif // FUNC_GPIO_H_
