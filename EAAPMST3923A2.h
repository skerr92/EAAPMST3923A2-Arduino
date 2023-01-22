/*!
 * @file EAAPMST3923A2.h
 *
 * This is a library for the EAAPMST3923A2 Ambient Light & Proximity Sensor
 *
 * Designed specifically to work with the Oak Development Technologies
 * EAASTPM3923A2 based products
 * ----> urlhere
 *
 * The sensor uses I2C to communicate with additional pins that can be connected
 * to for other operational modes.
 *
 * Writen by Seth Kerr for Oak Development Technologies
 *
 * Please support additional open source libraries and hardware through your
 * purchases from Oak Development Technologies
 *
 * MIT License, can be used, modified, or copied under license terms
 *
 */

#ifndef EAAPMST3923A2_H
#define EAAPMST3923A2_H

#include "Arduino.h"

#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

#define I2C_ADDR (0x44) ///< default I2C Address (fixed)

/*!
    @brief registers for setting and reading sensor samples
*/

enum regs {
  PRODUCT_ID = (0x0), ///< Product ID for sensor
  CFG = (0x1),        ///< Config register
  INTERRUPT = (0x2),  ///< Interrupt register
  PS_LT = (0X3),      ///< Proximity Sensor Lower Threshold register
  PS_HT = (0X4),      ///< Proximity Sensor Higher Threshold register
  ALS_TH1 = (0X5),    ///< Ambient Light Sensor MSB Threshold register
  ALS_TH2 = (0X6),    ///< Ambient Light Sensor Mid Threshold register
  ALS_TH3 = (0x7),    ///< Ambient Light Sensor bottom Threshold register
  PS_DATA = (0x8),    ///< Proximity Sensor Data Register
  ALS_DT1 = (0x9),    ///< Ambient Light Sensor Upper Threshold register
  ALS_DT2 = (0xA),    ///< Ambient Light Sensor Lower Threshold register
  ALS_RNG = (0xB)     ///< Ambient Light Sensor Range register
}

class EAAPMST3923A2 {
public:
  EAAPMST3923A2();
  virtual ~EAAPMST3923A2();

  bool begin(uint8_t i2caddr = I2C_ADDR);

  uint8_t readRegister8(uint8_t reg);
  void writeRegister8(uint8_t reg, uint8_t value);
  void enableAls();
  void enablePs(uint8_t interval);
  void setRange(uint8_t);
  uint8_t getRange();
  uint8_t alsData();
  uint8_t psData();

private:
  Adafruit_I2CDevice *i2c_dev = NULL;
};

#endif