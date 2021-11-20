
#include "MLX90393Hal.h"
#ifdef MLX90393_ENABLE_ARDUINO
#include "MLX90393ArduinoHal.h"
#include "stdint.h"
#include <Arduino.h>

bool MLX90393ArduinoHal::transceive(const uint8_t *request, size_t request_size, uint8_t *response, size_t response_size) {
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

void MLX90393ArduinoHal::set_drdy_pin(int pin) {
  MLX90393Hal::set_drdy_pin(pin);
  if (pin >= 0){
    pinMode(pin, INPUT);
  }  else {
  }
}

bool MLX90393ArduinoHal::read_drdy_pin() {
  Serial.println("digread");
  return digitalRead(this->drdy_pin_) == HIGH;
}

void MLX90393ArduinoHal::sleep_millis(uint32_t millis) {
  delay(millis);
}

void MLX90393ArduinoHal::sleep_micros(uint32_t micros) {
  delayMicroseconds(micros);
}

#endif