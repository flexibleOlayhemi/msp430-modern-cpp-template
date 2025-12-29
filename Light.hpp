/*
 * Light.hpp
 *
 *  Created on: Dec 27, 2025
 *      Author: User
 */
#pragma once

#include <msp430.h>
#include <cstdint>


namespace Hardware{

class Led{
public:
    static constexpr uint8_t LED = BIT0;

    static  void init(){
        P1DIR  |= LED;
        P1OUT &= ~LED;
    }

    static void toggle(){
        P1OUT ^= LED;
    }
};

}





