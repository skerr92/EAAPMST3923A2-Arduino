#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_BusIO_Register.h>
#include <Wire.h>

#include <EAAPMST3923A2.h>

void setup()
{
   EAAPMST3923A2 test = EAAPMST3923A2();
   Serial.begin(115200);
   while (!Serial) { delay(10); 
   if (test.begin())
   {
        Serial.println("setup passed");
   }
}

void loop()
{
    
}