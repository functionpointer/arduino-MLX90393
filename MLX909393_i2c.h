#pragma once

#include <stdint.h>
#include <stddef.h>

class MLX90393_i2c {
    public:
        MLX90393_i2c() {}
        void set_address(uint8_t I2C_address) {this->I2C_address_ = I2C_address;}
        virtual bool transceive(uint8_t *request, size_t request_size, uint8_t *response, size_t response_size);
    protected:
        uint8_t I2C_address_ = 0;
};
