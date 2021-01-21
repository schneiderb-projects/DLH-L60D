/*
  Created by Brett Schneider
*/
#include "DLH2.h"

DLH2::DLH2(uint32_t command, double offset, double oss, int fss)
{
  measCommand = command;
  m_offset = offset;
  FSS = fss;
  OSS = oss;
}

void printBinNum(uint8_t num){
  for(int i=0; i<8; i++){
    Serial.print((num & ( 1 << i )) >> i);
  }
}

void DLH2::setMeasurementCommand(uint32_t command){
  measCommand = command;
}


double DLH2::readPressure(){
  
  uint32_t pressure = 0;
    
  Wire.begin(19,18);

  Wire.beginTransmission(0x29);
  
  Wire.write(measCommand); //Sets Numbers to average

  Wire.endTransmission();

  switch(measCommand){
	case 0xAA:
	 	delayMicroseconds(4100);
		break;
	case 0xAC:
		delay(8);
		break;
	case 0xAD:
		delay(15);
	 	delayMicroseconds(700);
		break;
	case 0xAE:
		delay(31);
	 	delayMicroseconds(100);
		break;
	case 0xAF:
		delay(61);
	 	delayMicroseconds(900);
		break;
  }
  
  
  Wire.requestFrom(0x29, 7); //Read 7 bytes

  uint8_t byteCounter = 0;
  while (Wire.available()) {
    uint8_t c = Wire.read();

    //Log binary code
    //Serial.begin(9600);
    //printBinNum(c); Serial.print(" ");

    uint32_t temp = c;
      
    if(byteCounter == 1){
      pressure = temp << 16;
    }
    if(byteCounter == 2){
      pressure += temp << 8;
    }
    if(byteCounter == 3){;
      //pressure += (temp & ( 1 << 6 )) >> 6;
      //pressure += ((temp & ( 1 << 7 )) >> 7)*2;
      pressure += temp;
    }
    
    byteCounter++;
  }
  
  double toReturn = 2.4909*1.25*(pressure - OSS)/(pow(2,24))*FSS+m_offset;
  return toReturn;
}
