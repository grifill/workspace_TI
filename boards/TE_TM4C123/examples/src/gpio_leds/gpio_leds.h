/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   gpio_leds.h
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

#ifndef GPIO_LEDS_H_
#define GPIO_LEDS_H_

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

#define DELAY_CYCLE  (100000)

// Main example function
int example_gpio_leds(void);



#endif /* GPIO_LEDS_H_ */
