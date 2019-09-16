# Arduino I2C Slave Address Scanner
This is a simple Arduino sketch for scanning slave address like FRAM (FM24CL16B), RTC module, I2C module for LCD, and more.

I've tested on most ATmega328p MCU based boards (5V, 16 MHz) like Arduino UNO and Nano. If another board like Pro Mini (3.3V, 8 MHz) is used, then it is needed to change MCU clock frequency in "Master_TWI.h" header file. If another MCU is used, it is needed to check its datasheet for I2C pins configuration (SDA and SCL pins).

# I2C Pinout Hookup
Two wires is needed to use I2C protocol: SDA(Serial Data), SCL(Serial Clock).

On ATmega328p MCU, I2C pinouts are as followed.
- SDA: PC4 (A4 - Analog input 4)
- SCL: PC5 (A5 - Analog input 5)

These two pins are needed pull-up resistor with Vcc (5V). Simply used 1 kOhm resistor, or calculate minimum or maximum resistance based on Vcc and bus frequency.

In this sketch, it doesn't need to connect with pull-up resistor because these two pins are internally pull-up with source code. Simply hookup with SCL and SDA pins directly to the slave device.
