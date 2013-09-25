/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/


#include "OneSheeld.h"
#include "HardwareSerial.h"

// public functions
OneSheeldClass::OneSheeldClass() {}
void OneSheeldClass::begin(long baudRate)
{
  Serial.begin(baudRate);
}
void OneSheeldClass::write(char shieldID,char functionCommand, char* data)
{
  int dataLength;
  Serial.write(STX); // send STX  to start the packet
  Serial.write(shieldID);
  Serial.write(functionCommand);
  if (strlen(data)>140)
  dataLength=140;
  else 
  dataLength=strlen(data);
  for(int i=0; i<dataLength; i++) {
    Serial.write(data[i]);        
  }
  
  Serial.write(ETX); // send ETX  to start the packet
}
void OneSheeldClass::write(char* data)
{
  write(GENERAL_DATA,NOT_FUNCTION,data);
}
// instantiate object for users
OneSheeldClass OneSheeld;