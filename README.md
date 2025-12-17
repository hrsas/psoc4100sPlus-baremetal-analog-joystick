# Bare-Metal Analog Joystick Controller using PSoC 4100S Plus

## Overview
This project implements a **bare-metal analog joystick controller** on the **Infineon PSoC 4100S Plus** microcontroller.  
A potentiometer is used as an analog input device, whose position is sampled using the on-chip **12-bit SAR ADC** and transmitted to a host system via **UART** in real time.

The firmware is written entirely in **bare-metal C**, using **direct register-level programming**. A **TCPWM timer** is used to achieve deterministic sampling intervals, ensuring predictable and real-time behavior.

The project focuses on understanding low-level microcontroller operation, including clock configuration, startup code, linker scripts, interrupt-driven design, and peripheral interfacing on real hardware.
## Hardware Used

## Software Architecture

## How It Works

## Build & Flash Instructions

## Project Highlights

## Future Improvements
