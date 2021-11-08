uint8_t
MLX90393_wire::
sendCommand(uint8_t cmd)
{
  _i2cPort->beginTransmission(I2C_address);
  if (_i2cPort->write(cmd) != 1){ return STATUS_ERROR; }
  if (_i2cPort->endTransmission()){ return STATUS_ERROR; }
  if (_i2cPort->requestFrom(I2C_address, uint8_t(1)) != 1){ return STATUS_ERROR; }

  return _i2cPort->read();
}

bool MLX90393_wire::transceive(uint8_t cmd, uint8_t *response, size_t response_size) {

}

uint8_t
MLX90393::
readRegister(uint8_t address, uint16_t& data)
{
  _i2cPort->beginTransmission(I2C_address);
  if (_i2cPort->write(CMD_READ_REGISTER) != 1){ return STATUS_ERROR; }
  if (_i2cPort->write((address & 0x3f)<<2) != 1){ return STATUS_ERROR; }
  if (_i2cPort->endTransmission()){ return STATUS_ERROR; }
  if (_i2cPort->requestFrom(I2C_address, uint8_t(3)) != 3){ return STATUS_ERROR; }

  uint8_t status;
  if (!_i2cPort->available()){ return STATUS_ERROR; }
  status = _i2cPort->read();

  uint8_t b_h;
  if (!_i2cPort->available()){ return STATUS_ERROR; }
  b_h = _i2cPort->read();

  uint8_t b_l;
  if (!_i2cPort->available()){ return STATUS_ERROR; }
  b_l = _i2cPort->read();

  data = (uint16_t(b_h)<<8) | b_l;
  cache_set(address, data);
  return status;
}

uint8_t
MLX90393::
writeRegister(uint8_t address, uint16_t data)
{
  cache_invalidate(address);

  _i2cPort->beginTransmission(I2C_address);
  if (_i2cPort->write(CMD_WRITE_REGISTER) != 1){ return STATUS_ERROR; }
  if (_i2cPort->write((data & 0xff00) >> 8) != 1){ return STATUS_ERROR; }
  if (_i2cPort->write(data & 0x00ff) != 1){ return STATUS_ERROR; }
  if (_i2cPort->write((address & 0x3f)<<2) != 1){ return STATUS_ERROR; }
  if (_i2cPort->endTransmission()){ return STATUS_ERROR; }
  if (_i2cPort->requestFrom(I2C_address, uint8_t(1)) != 1){ return STATUS_ERROR; }
  if (!_i2cPort->available()){ return STATUS_ERROR; }

  const uint8_t status = _i2cPort->read();
  if (isOK(status)) {
    cache_set(address, data);
  }
  return status;
}