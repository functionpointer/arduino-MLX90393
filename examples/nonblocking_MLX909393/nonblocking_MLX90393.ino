#include <Wire.h>
#include <Arduino.h>
#include <MLX90393.h>

// prints Bx By Bz (in uT) and temperature (C) to serial console after receiving a character

MLX90393 mlx;

void setup(){
  Wire.begin();
  //Wire.begin(18 /*SDA*/, 19 /*SCL*/);

  // DRDY line connected to A3 (omit third parameter to used timed reads)
  //uint8_t status = mlx.begin(0, 0, A3);

  // using timed reads
  uint8_t status = mlx.begin(0, 0);
  Serial.begin(9600);
}

void loop(){
  switch(mlx.isMeasurementReady()) {
    case MEASUREMENT_NOT_STARTED:
      mlx.startMeasurement(X_FLAG | Y_FLAG | Z_FLAG | T_FLAG);
      break;
    case MEASUREMENT_READY:
      MLX90393::txyz data;
      mlx.readDataIfReady(data);
      Serial.print(data.x);
      Serial.print(" ");
      Serial.print(data.y);
      Serial.print(" ");
      Serial.print(data.z);
      Serial.print(" ");
      Serial.println(data.t);
      break;
    case MEASUREMENT_IN_PRORESS:
      // keep waiting
      break;
  }
  // do whatever else you want here
}
