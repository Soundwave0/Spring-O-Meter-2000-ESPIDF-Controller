#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"


#define BLINK_GPIO 2

void app_main(void)
{
    /* Configure the GPIO pin for the LED */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    /* Blink the LED every 1 second */
    while(1) {
        /* Set the GPIO level to high (LED ON) */
        gpio_set_level(BLINK_GPIO, 1);
        /* Wait for 2000 ms */
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        /* Set the GPIO level to low (LED OFF) */
        gpio_set_level(BLINK_GPIO, 0);
        /* Wait for 1000 ms */
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}