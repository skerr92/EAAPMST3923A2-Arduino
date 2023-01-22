/*!
 * @file EAAPMST3923A2.cpp
 *
 * @mainpage Oak Development Technologies EAAPMST3923A2 Arduino Driver
 *
 * @section intro_sec Introduction
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
 * @section author Author
 *
 * Writen by Seth Kerr for Oak Development Technologies
 *
 * Please support additional open source libraries and hardware through your
 * purchases from Oak Development Technologies
 *
 * @section license License
 *
 * MIT License, can be used, modified, or copied under license terms
 *
 */

#include "EAAPMST3923A2.h"

/*!
 * @brief Constructor
 * @return
 */
EAAPMST3923A2::EAAPMST3923A2() {}

/*!
    @brief Destructor
    @return
*/
EAAPMST3923A2::~EAAPMST3923A2() {}

/*!
    @brief initializes communication with the sensor over the I2C bus
           at the given address. The default address is 0x44
    @param i2caddr The I2C Address for the sensor

    @return bool on if begin was successful or not
*/

bool EAAPMST3923A2::begin(uint8_t i2caddr = I2C_ADDR) {
  if (i2c_dev) {
    delete i2c_dev;
  }
  i2c_dev = new Adafruit_I2CDevice(i2caddr);
  if (nullptr == i2c_dev) {
    Serial.println("EAAPMST3923A2 not initialized");
    return false;
  }
  if (!i2c_dev->begin()) {
    return false;
  }
  return true;
}

/*!
    @brief  Gets the 8 bit register value from the called register.
            This function requests the register contents over i2c.
    @param    reg
              Is the register address from where we read from
    @return The 8 bit value of the register read is returned.
*/

uint8_t EAAPMST3923A2::readRegister8(uint8_t reg) {
  if (nullptr == i2c_Dev) {
    Serial.println("EAAPMST3923A2 not initialized");
    return (0xf);
  } else {
    Adafruit_BusIO_Register read_reg = Adafruit_BusIO_Register(i2c_dev, reg, 1);
  }
  uint8_t r_val;
  return read_reg.read(&r_val, 0x8); // change to value returned from register
}

/*!
    @brief  Writes the 8 bit input value from to called register.
            This function requests the register contents over i2c.
    @param    reg
              Is the register address from where we read from
    @param    value
              Is the value we want to write to the register specified
    @return
*/

void EAAPMST3923A2::writeRegister8(uint8_t reg, uint8_t value) {
  if (nullptr == i2c_dev) {
    Serial.println("EAAPMST3923A2 not initialized");
    return;
  } else {
    Adafruit_BusIO_Register write_reg =
        Adafruit_BusIO_Register(i2c_dev, reg, 1);
  }
  write_reg.write(value, 0x8);
}

/*!
    @brief Enabled the Ambient Light functionality of the sensor and disables
           the proximity sensing capabilities
    @return
*/

void EAAPMST3923A2::enableAls() { writeRegister8(CFG, 0x04); }
/*!
    @brief Enabled the Proximity sensing functionality of the sensor and
   disables the ambient light sensing capabilities
    @param interval
            Sets the interval for detecting proximity sensing. Accepts a value
            between 0 and 7 for the longest sampling (800ms) interval and the
            shortest sampling (continuous) interval.
    @return void
*/
void EAAPMST3923A2::enablePs(uint8_t interval) {
  switch (interval) {
  case 0:
    writeRegister8(CFG, 0x80);
    break;
  case 1:
    writeRegister8(CFG, 0x90);
    break;
  case 2:
    writeRegister8(CFG, 0xA0);
    break;
  case 3:
    writeRegister8(CFG, 0xB0);
    break;
  case 4:
    writeRegister8(CFG, 0xC0);
    break;
  case 5:
    writeRegister8(CFG, 0xD0);
    break;
  case 6:
    writeRegister8(CFG, 0xE0);
    break;
  case 7:
    writeRegister8(CFG, 0xF0);
    break;
  default:
    writeRegister8(CFG, 0xB0);
  }
}

/*!
    @brief Sets the lux range of the ambient light sensor in a range from 50 LUX
   up to 800 LUX

    @param val a value between 0 and 4 which determines the step range of the
   ambient light sensor. 0 being 800 LUX and 4 being the smallest step range of
                50 LUX.
    @return void
*/

void EAAPMST3923A2::setRange(uint8_t val) {
  switch (val) {
  case 0:
    writeRegister8(ALS_RNG, 0x00);
    break;
  case 1:
    writeRegister8(ALS_RNG, 0x01);
    break;
  case 2:
    writeRegister8(ALS_RNG, 0x02);
    break;
  case 3:
    writeRegister8(ALS_RNG, 0x03);
    break;
  case 4:
    writeRegister8(ALS_RNG, 0x04);
    break;
  default:
    writeRegister8(ALS_RNG, 0x00);
  }
}

/*!
    @brief Returns the current ambient light sensor LUX range set by setRange()
    @return returns current als lux range
*/

uint8_t EAAPMST3923A2::getRange() { return (readRegister8(ALS_RNG) & 0xf); }

/*!
    @brief Returns the MSB of the ambient light sensor registers.
    @return returns MSB of ALS data
*/

uint8_t EAAPMST3923A2::alsData() { return (readRegister8(ALS_DT1) & 0xf); }

/*!
    @brief Returns the MSB of the proximity sensor registers.
    @return returns proximity sensor data
*/

uint8_t EAAPMST3923A2::psData() { return (readRegister8(PS_DATA) & 0xf); }