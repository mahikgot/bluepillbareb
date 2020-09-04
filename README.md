# Bare Metal STM32F103C8
## Introduction

This repository would contain code for the STM32F103C8 microcontroller that would work at the registry level without using any external libraries.

Tools used:
* [GNU ARM Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain)
* [make](https://www.gnu.org/software/make/)
* [OpenOCD](http://openocd.org/)

## Guide
1. Use `make` to build the project. This will create all the object files and binaries into the build/ folder of the project.
2. Use `make flash` to flash the program into your board using OpenOCD.
3. Use `make port` to open an OpenOCD port for debugging. I use GDB from the GNU Arm toolchain to debug. [Here's](https://hackaday.com/2012/09/27/beginners-look-at-on-chip-debugging/) a simple demonstration.
4. Use `make clean` to delete build directory after you are done.
