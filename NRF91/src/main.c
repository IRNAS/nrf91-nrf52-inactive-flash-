/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <drivers/gpio.h>

void main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);

	const struct device *gpio_dev;
	gpio_dev = device_get_binding("GPIO_0");


    // Set SPI lines as INPUT
    gpio_pin_configure(gpio_dev, 27, GPIO_INPUT);  // MISO
    gpio_pin_configure(gpio_dev, 28, GPIO_INPUT);  // SCK
    gpio_pin_configure(gpio_dev, 29, GPIO_INPUT);  // MOSI
    gpio_pin_configure(gpio_dev,  2, GPIO_INPUT);  // CS flash

    // Set FLASH lines as INPUT
    gpio_pin_configure(gpio_dev, 31, GPIO_INPUT);  // WP flash
    gpio_pin_configure(gpio_dev,  0, GPIO_INPUT);  // HOLD flash

    // Set nrf52 uart lines as INPUT, so they dont interfere
    gpio_pin_configure(gpio_dev, 22, GPIO_INPUT);  
    gpio_pin_configure(gpio_dev, 23, GPIO_INPUT); 

    // nrf52 reset line should be floating
    gpio_pin_configure(gpio_dev, 15, GPIO_INPUT); 

    // Configuring LR1110 lines so it does not interfere with flash ops
    gpio_pin_configure(gpio_dev, 16, GPIO_OUTPUT);  // LR1110 reset
    gpio_pin_configure(gpio_dev, 18, GPIO_OUTPUT);  // LR1110 nss
    gpio_pin_configure(gpio_dev, 19, GPIO_OUTPUT);  // LR1110 pwr en
	gpio_pin_set(gpio_dev, 16, 1);
	gpio_pin_set(gpio_dev, 18, 1);
	gpio_pin_set(gpio_dev, 19, 1);

    while (1) {
    }
}
