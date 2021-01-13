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
    gpio_pin_configure(gpio_dev, 9, GPIO_INPUT);  // MISO
    gpio_pin_configure(gpio_dev, 10, GPIO_INPUT);  // SCK
    gpio_pin_configure(gpio_dev, 11, GPIO_INPUT);  // MOSI
    gpio_pin_configure(gpio_dev,  7, GPIO_INPUT);  // CS flash

    // Set FLASH lines as INPUT
    gpio_pin_configure(gpio_dev, 19, GPIO_INPUT);  // WP flash
    gpio_pin_configure(gpio_dev, 18, GPIO_INPUT);  // HOLD flash

    // Set nrf52 uart lines as INPUT, so they dont interfere
    gpio_pin_configure(gpio_dev, 6, GPIO_INPUT);  
    gpio_pin_configure(gpio_dev, 12, GPIO_INPUT); 

    // nrf91 reset line should be floating
    gpio_pin_configure(gpio_dev, 8, GPIO_INPUT); 

    while (1) {
    }
}
