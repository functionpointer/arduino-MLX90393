#pragma once

#include <Arduino.h>

class MLX90393_i2c {
    public:
        MLX90393_i2c();
        uint8_t sendCommand(uint8_t cmd);

}