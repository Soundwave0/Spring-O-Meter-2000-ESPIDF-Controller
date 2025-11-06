#ifndef SOMDriver_h
#define SOMDriver_h
#include "HX711.h"
//configures the HX711 hardware parameters and initializes the readings
esp_err_t HX711_config();
esp_err_t TMC2208_config();
#endif