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

template<uint8_t BitMask>
class Led{
public:
    //static constexpr uint8_t LED = BIT0;

    static  void init(){
        P1DIR  |= BitMask;
        P1OUT &= ~BitMask;
    }

    static void toggle(){
        P1OUT ^= BitMask;
    }

    static void on(){
        P1OUT |= BitMask;
    }

    static void off(){
        P1OUT &= ~BitMask;
    }
};

}





