# Inactive mcu setup for flash

This repository is meant to be used with [`zephyr-spi-flash-en25-driver`](https://github.com/IRNAS/zephyr-spi-flash-en25-driver) repo.
As board has two MCUs (NRF9160 and NRF52811) that can communicate with onboard flash, we have to make sure that while one MCU is running `zephyr-spi-flash-en25-driver` code, the other is quiet and is not holding SPI lines.

## How to use

If you want NRF9160 to test flash communication, first flash the code in `NRF52` folder to the NRF52811 microcontroller and then run flash test in `zephyr-spi-flash-en25-driver`.
If you want NRF528111 to test flash communication is vice versa.
