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

#include <Adafruit_I2CDevice.h>
#include <Wire.h>

#define I2C_ADDR 0x44 ///< default I2C Address (fixed)

/*!
    @brief registers for setting and reading sensor samples
*/

#define PRODUCT_ID (0x0) ///< Product ID for sensor
#define CFG (0x1)        ///< Config register
#define INTERRUPT (0x2)  ///< Interrupt register
#define PS_LT (0X3)      ///< Proximity Sensor Lower Threshold register
#define PS_HT (0X4)      ///< Proximity Sensor Higher Threshold register
#define ALS_TH1 (0X5)    ///< Ambient Light Sensor MSB Threshold register
#define ALS_TH2 (0X6)    ///< Ambient Light Sensor Mid Threshold register
#define ALS_TH3 (0x7)    ///< Ambient Light Sensor bottom Threshold register
#define PS_DATA (0x8)    ///< Proximity Sensor Data Register
#define ALS_DT1 (0x9)    ///< Ambient Light Sensor Upper Threshold register
#define ALS_DT2 (0xA)    ///< Ambient Light Sensor Lower Threshold register
#define ALS_RNG (0xB)    ///< Ambient Light Sensor Range register

class EAAPMST3923A2 {
public:
  EAAPMST3923A2(void);
  virtual ~EAAPMST3923A2(void);

  bool begin(TwoWire *theWire = &Wire);

  uint8_t readRegister8(uint8_t reg);
  void writeRegister8(uint8_t reg, uint8_t value);
  void enableAls(void);
  void enablePs(uint8_t interval);
  void setRange(uint8_t);
  uint8_t getRange(void);
  uint8_t alsData(void);
  uint8_t psData(void);

private:
  Adafruit_I2CDevice *i2c_dev = NULL;
};

#endif