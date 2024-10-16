# arduino-MLX90393
Arduino library for MLX90393 magnetometer sensor.

Published on platformio: https://platformio.org/lib/show/13048/arduino-MLX90393

# Framworks other than arduino

This library is mostly platform agnostic.
The only arduino specific code is encapsulated by a Hal class.
Basically delay, I2C transceive and DRDY pin handling.

If you're not running arduino, you can use this library by implementing [MLX90393Hal](https://github.com/functionpointer/arduino-MLX90393/blob/master/MLX90393Hal.h), and then calling `begin_with_hal()`.

See the ESPHome implementation for an example: https://github.com/esphome/esphome/tree/dev/esphome/components/mlx90393

# Usage examples

See [examples](examples)

# Documentation for contributers

See [internals.md](internals.md)
