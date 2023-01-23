
#include <EAAPMST3923A2.h>

EAAPMST3923A2 test = EAAPMST3923A2();

void setup()
{
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