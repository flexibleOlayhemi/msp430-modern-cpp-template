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

    Console::print("MSP430 Ready. Press Button...\r\n");

    TA0CCTL0 = CCIE;

    TA0CCR0 =  50000;

    TA0CTL = TASSEL_2 + MC_1 + ID_3;

    __bis_SR_register(LPM0_bits + GIE);

    return 0;
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


