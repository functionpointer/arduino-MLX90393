#pragma once

#include <stdint.h>
#include <stddef.h>

#ifdef USE_ARDUINO
#define MLX90393_ENABLE_ARDUINO
#endif

#ifdef ARDUINO
#define MLX90393_ENABLE_ARDUINO
#endif

class MLX90393Hal {
    public:
        MLX90393Hal() {}
        void set_address(uint8_t I2C_address) {this->I2C_address_ = I2C_address;}
        virtual void set_drdy_pin(int pin) {this->drdy_pin_ = pin;}
        virtual bool has_drdy_pin() {return this->drdy_pin_ != -1;}
        virtual bool transceive(const uint8_t *request, size_t request_size, uint8_t *response, size_t response_size);
        virtual bool read_drdy_pin();
        virtual void sleep_millis(uint32_t millis);
        virtual void sleep_micros(uint32_t micros);
    protected:
        uint8_t I2C_address_ = 0;
        int drdy_pin_ = -1;
};
