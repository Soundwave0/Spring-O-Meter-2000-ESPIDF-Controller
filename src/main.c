#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "SOMDriver.h"
 
void app_main(void)
{
    HX711_config();//input configuration parameters
    printf("works beautifully");

}