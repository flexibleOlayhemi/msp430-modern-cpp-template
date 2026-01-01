/*
 * HardwareConfig.hpp
 *
 *  Created on: Dec 29, 2025
 *      Author: User
 */

#pragma once
#include "Light.hpp"

namespace Config{

    using RegPtr = volatile uint8_t*;

    using RedLed = Hardware::Led<RegPtr,&P1OUT,&P1DIR,BIT0>;

    //using StatusLed = Hardware::Led<Pins::RedLed>;
}
