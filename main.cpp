/*
 * main.cpp
 *
 *  Created on: Dec 27, 2025
 *      Author: User
 */

#include "Light.hpp"
#include "System.hpp"

using namespace Hardware;

//Defining LED using the template
using RedLed = Led<BIT0>;

int main(){
    WDTCTL = WDTPW | WDTHOLD;


    System::initLowPower();
    RedLed::init();

    TA0CCTL0 = CCIE;

    TA0CCR0 =  50000;

    TA0CTL = TASSEL_2 + MC_1 + ID_3;

    __bis_SR_register(LPM0_bits + GIE);

    return 0;
}


#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A_ISR(void){
    RedLed::toggle();  //zero-RAM overhead
}


