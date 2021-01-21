# DLH-L60D
Library to read a DLH L60D sensor via SPI

This was written under time pressure, so it isn't the easiest library to use. I also don't have an easy example to show you. Usually I'd just write one up now that I have the time, but I don't have the sensor anymore, so I wouldn't be able to test if it works.

I2C pins 19 and 18 are hardcoded to be used ( i.e. Wire.begin(19,18) ), so you will have to change the library if you want that changed. Again, usually I'd just change that, but I no longer have the sensor to test any changes with, so I'm just leaving it as is. 

The FSS and OSS values need to be given as inputs along with the sensor operation mode. All of these values for your given version of the sensor should be availble in the sensor data sheet. 
