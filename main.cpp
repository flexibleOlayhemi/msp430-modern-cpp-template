/*
 * main.cpp
 *
 *  Created on: Dec 27, 2025
 *      Author: User
 */

#include "HardwareConfig.hpp"
#include "System.hpp"

using namespace Config;


int main(){
    WDTCTL = WDTPW | WDTHOLD;


    Hardware::System::initLowPower();
    Console::init();
    StatusLed::init();
    ErrorLed::init();
    UserBtn::init();

    SystemTimer::init(50000);

    Console::print("MSP430 Ready. Press Button...\r\n");


    __bis_SR_register(LPM0_bits + GIE);


}


#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A_ISR(void){
    StatusLed::toggle();  //zero-RAM overhead
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1_ISR(void){
    if (UserBtn::isSource()){
        ErrorLed::toggle();
        Console::println("Button Pressed - LED Toggled!");
        UserBtn::clearFlag();
    }
}


