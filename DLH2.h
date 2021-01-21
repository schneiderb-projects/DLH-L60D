/*
  Created by Brett Schneider
*/

#ifndef DLH_h2
#define DLH_h2

#include "Arduino.h"
#include <Wire.h>

class DLH2
{
    public:
        
        /*
        Single    0xAA
        Average2  0xAC
        Average4  0xAD
        Average8  0xAE
        Average16 0xAF
        */
        DLH2(uint32_t command, double offset, double oss, int fss, int option);
        
        //value = 0-262143
        double readPressure();

        void setMeasurementCommand(uint32_t command);
    private:
        uint32_t _deviceAddress = 0x29;
        uint32_t measCommand = 0xAF;
	double m_offset = 0;
	double OSS = 1677721.6;
	int FSS = 60;
	int OPT= 1;
};

#endif
