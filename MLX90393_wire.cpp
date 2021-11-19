
#ifdef USE_ARDUINO
#include "MLX90393_wire.h"
#include "stdint.h"

bool MLX909303_wire::transceive(uint8_t *request, size_t request_size, uint8_t *response, size_t response_size) {
  this->i2cPort_->beginTransmission(this->I2C_address_);
  for(size_t i=0;i<request_size;i++) {
    int8_t written = this->i2cPort_->write(request[i]);
    if(written!=1) {
      return false;
    }
  }
  this->i2cPort_->endTransmission();
  int8_t received = this->i2cPort_->requestFrom(this->I2C_address_, response_size);
  if(received!=response_size) {
    return false;
  }
  for(size_t i=0;i<response_size;i++) {
    if(!this->i2cPort_->available()) {
      return false;
    }
    response[i]=this->i2cPort_->read();
  }
  return true;
}

#endif
