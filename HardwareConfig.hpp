/*
 * HardwareConfig.hpp
 *
 *  Created on: Dec 29, 2025
 *      Author: User
 */

#pragma once
#include "Light.hpp"

namespace Config{
    namespace Pins{
        static constexpr uint8_t RedLed = BIT0;
    }

    using StatusLed = Hardware::Led<Pins::RedLed>;
}
