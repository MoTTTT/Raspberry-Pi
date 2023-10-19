/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#ifndef TINY2040_LED_R_PIN
#define TINY2040_LED_R_PIN 18
#endif

#ifndef TINY2040_LED_G_PIN
#define TINY2040_LED_G_PIN 19
#endif

#ifndef TINY2040_LED_B_PIN
#define TINY2040_LED_B_PIN 20
#endif


int main() {
#ifndef TINY2040_LED_R_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN1 = TINY2040_LED_R_PIN;
    const uint LED_PIN2 = TINY2040_LED_G_PIN;
    const uint LED_PIN3 = TINY2040_LED_B_PIN;
    gpio_init(LED_PIN1);
    gpio_init(LED_PIN2);
    gpio_init(LED_PIN3);
    gpio_set_dir(LED_PIN1, GPIO_OUT);
    gpio_set_dir(LED_PIN2, GPIO_OUT);
    gpio_set_dir(LED_PIN3, GPIO_OUT);
    gpio_put(LED_PIN1, 1);
    gpio_put(LED_PIN2, 1);
    gpio_put(LED_PIN3, 1);
    while (true) {
        gpio_put(LED_PIN1, 0);
        sleep_ms(500);
        gpio_put(LED_PIN1, 1);
        gpio_put(LED_PIN2, 0);
        sleep_ms(500);
        gpio_put(LED_PIN2, 1);
        gpio_put(LED_PIN3, 0);
        sleep_ms(500);
        gpio_put(LED_PIN3, 1);
    }
#endif
}
