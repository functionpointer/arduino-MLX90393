#pragma once
#include "MLX90393Hal.h"
#ifdef MLX90393_ENABLE_ARDUINO
#include <Wire.h>


class MLX90393ArduinoHal : public MLX90393Hal {
  public:
    void set_twoWire(TwoWire *wirePort) {this->i2cPort_ = wirePort;}
    bool transceive(const uint8_t *request, size_t request_size, uint8_t *response, size_t response_size);
    void set_drdy_pin(int pin) override;
    bool read_drdy_pin();
    void sleep_millis(uint32_t millis);
    void sleep_micros(uint32_t micros);
  protected:
    TwoWire *i2cPort_ = nullptr;

};

#endif