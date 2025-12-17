# Bare-Metal Analog Joystick Controller using PSoC 4100S Plus

## Overview
This project implements a **bare-metal analog joystick controller** on the **Infineon PSoC 4100S Plus** microcontroller.  
A potentiometer is used as an analog input device, whose position is sampled using the on-chip **12-bit SAR ADC** and transmitted to a host system via **UART** in real time.

The firmware is written entirely in **bare-metal C**, using **direct register-level programming**. A **TCPWM timer** is used to achieve deterministic sampling intervals, ensuring predictable and real-time behavior.

The project focuses on understanding low-level microcontroller operation, including clock configuration, startup code, linker scripts, interrupt-driven design, and peripheral interfacing on real hardware.

## Demo

The following demonstration shows the **end-to-end system**, where the PSoC 4100S Plus runs bare-metal firmware to acquire analog joystick input and transmit control data over UART to a host application.

![Analog Joystick Demo](docs/demo.gif)

*Real-time control of an endless runner game using the PSoC 4100S Plus bare-metal analog joystick controller.*

[Watch full demo video](docs/Analog_Joystick_Demo.mp4)

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
1. **Analog Input Acquisition**  
   A potentiometer connected to an ADC-capable pin acts as a joystick axis. The voltage level represents the joystick position.

2. **Deterministic Sampling Using Timer**  
   A TCPWM timer is configured to generate periodic interrupts at a fixed interval of 20ms. This ensures the ADC is sampled at consistent and predictable time intervals.

3. **ADC Conversion**  
   Inside the timer ISR, the on-chip 12-bit SAR ADC samples the analog voltage and converts it into a digital value.

4. **Data Processing**  
   The raw ADC value is scaled to represent joystick direction/position.

5. **UART Transmission**  
   The processed joystick value is transmitted over UART to a host system, enabling real-time control for external applications such as games or simulations.

## Build & Flash Instructions
1. Open the project in the preferred development environment or terminal.
2. Build the project using the provided Makefile or toolchain.
3. Flash the generated binary to the PSoC 4100S Plus using KitProg.
4. Open a serial terminal on the host system to observe joystick data transmitted over UART.

## Project Highlights
- Bare-metal firmware development
- Direct register-level configuration of peripherals
- Deterministic real-time behavior using hardware timers
- Modular driver-based firmware architecture
- Custom startup code and linker script usage
- Designed and tested on real hardware

## Future Improvements
- Hardware-triggered ADC sampling using TCPWM
- DMA-based ADC to UART data transfer
- Support for multi-axis joystick input
- UART command interface for runtime configuration
- Low-power mode integration
