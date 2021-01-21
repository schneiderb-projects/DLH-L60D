# DLH-L60D
Library to read a DLH L60D sensor via I2C.

I have only tested this using the L60D version of the sensor, althoug I think it will work with all the I2C versions of this sensor.

This was written under time pressure, so it isn't the easiest library to use. I also don't have an example to show because I don't have permission to share the code this driver was used with. Usually I'd just write one up now that I have the time, but I don't have the sensor anymore, so I wouldn't be able to test if it works. It's pretty simple though, basically initialize the DLH and then call the readPressure() function.

I2C pins 19 and 18 are hardcoded to be used ( i.e. Wire.begin(19,18) ), so you will have to change the library if you want that changed. Again, usually I'd just change that, but I no longer have the sensor to test any changes with, so I'm just leaving it as is. 

Usage: 

  Initialize using constuctor: DLH::DLH(uint32_t command, double offset, double oss, int fss);
    Arguments:
      command: used to set the sensor sampling mode. Options are: 0xAA, 0xAC, 0xAD, 0xAE, 0xAF. See the data sheet to determine which ones is the correct mode for you
      
  offset, oss, fss: see the sensor datasheet to determine these values
