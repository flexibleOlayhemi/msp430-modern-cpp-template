MSP430 Interrupt-Driven LED (Modern C++)

Focus: Zero-cost hardware abstraction and low-power interrupt handling. the project utilizes #pragma once for header guards to minimize pre-processor overhead and improve build times compared to traditional #ifndef gaurd.

Tech Stack
Language: C++20 (Embedded Subset)
Hardware: TI MSP430G2553 (LaunchPad)
Compiler: msp430-elf-gcc
Build System: CMake

Features
Zero-Cost Abtraction: Used a static class for LED control to ensure no memory is used for the object
Low Power Design: Uses LPM0 to keep the CPU  asleep until the Timer Interrupt triggers.
Namespacing: Organized hardware  drivers under the Hardware:: namespace to avoid global name collisions.
Power Optimized: Integrated Ultra Low Power best practice by terminating unused GPIOs to prevent floating-input current draw.
