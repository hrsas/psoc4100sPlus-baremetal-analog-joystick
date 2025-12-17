# Bare-Metal Analog Joystick Controller using PSoC 4100S Plus

## Overview
This project implements a **bare-metal analog joystick controller** on the **Infineon PSoC 4100S Plus** microcontroller.  
A potentiometer is used as an analog input device, whose position is sampled using the on-chip **12-bit SAR ADC** and transmitted to a host system via **UART** in real time.

The firmware is written entirely in **bare-metal C**, using **direct register-level programming**. A **TCPWM timer** is used to achieve deterministic sampling intervals, ensuring predictable and real-time behavior.

The project focuses on understanding low-level microcontroller operation, including clock configuration, startup code, linker scripts, interrupt-driven design, and peripheral interfacing on real hardware.

## Hardware Used
- **Microcontroller**: Infineon PSoC 4100S Plus (Arm Cortex-M0+)
- **Development Board**: CY8CKIT-149 PSoC 4100S Plus Prototyping Kit
- **Analog Input**: Potentiometer (used as joystick axis)
- **Communication Interface**: UART (via KitProg3 USB-UART)
- **Power Supply**: USB (5 V via development kit)

## Software Architecture
The firmware is organized in a modular manner to clearly separate application logic, hardware abstraction, and system-level initialization:

- **Startup**: Custom startup code and vector table initialization
- **Clock System**: System clock configuration and peripheral clock setup
- **Device Drivers**:
  - GPIO driver for digital I/O
  - Timer (TCPWM) driver for periodic interrupts
  - SAR ADC for analog input conversion
- **Libraries**:
  - Minimal libc support for `printf` and dynamic memory
  - CMSIS support files
- **Application Layer**:
  - ADC sampling logic
  - UART data transmission
  - Joystick value processing
- **Linker Script**:
  - Custom memory layout for flash and SRAM

## How It Works

## Build & Flash Instructions

## Project Highlights

## Future Improvements
