#pragma once
#ifdef USE_ARDUINO
#include "MLX90393_i2c.h"
#include <Wire.h>


class MLX909303_wire : public MLX90393_i2c {
  public:
    void set_twoWire(TwoWire *wirePort) {this->i2cPort_ = wirePort;}
    bool transceive(uint8_t *request, size_t request_size, uint8_t *response, size_t response_size);
  protected:
    TwoWire *i2cPort_ = nullptr;

};
#endif

