////////////////////////////////////////////////////////////////////////////
// Example code that exercises the LandBoards_tcn75A library
////////////////////////////////////////////////////////////////////////////

#include <LandBoards_tcn75A.h>
#include "Wire.h"

landboards_TCN75A myTemp;

////////////////////////////////////////////////////////////////////////////
// setup()
////////////////////////////////////////////////////////////////////////////

void setup()
{
  myTemp.begin(0x0);		// Begin communications with the I2C part at address 0
  Serial.begin(115200);
  myTemp.writeConfigRegister(0x00);
}

////////////////////////////////////////////////////////////////////////////
// loop()
////////////////////////////////////////////////////////////////////////////

void loop()
{
  readConfigReg();
  readShadowConfigReg();
  testTSetReg();
  testHystReg();
  testTemp();
}

////////////////////////////////////////////////////////////////////////////
// readConfigReg()
////////////////////////////////////////////////////////////////////////////

void readConfigReg(void)
{
  uint8_t configReg;
  configReg = myTemp.readConfigRegister();
  Serial.print("Config register = 0x");
  Serial.println(configReg, HEX);
}

////////////////////////////////////////////////////////////////////////////
// readTemp()
////////////////////////////////////////////////////////////////////////////

void readTemp(void)
{
  Serial.print("Temperature = ");
  Serial.println(myTemp.getTemp());
}

////////////////////////////////////////////////////////////////////////////
// readShadowConfigReg
////////////////////////////////////////////////////////////////////////////

void readShadowConfigReg(void)
{
  uint8_t configShadowReg;
  configShadowReg = myTemp.readShadowConfigRegister();
  Serial.print("Shadow config register value = 0x");
  Serial.println(configShadowReg, HEX);
}

////////////////////////////////////////////////////////////////////////////
// testTSetReg()
////////////////////////////////////////////////////////////////////////////

void testTSetReg(void)
{
  uint16_t tReg;
  myTemp.writeTSetRegister(0xa580);
  tReg = myTemp.readTSetRegister();
  Serial.print("tReg register, wrote: 0xA580, read back 0x");
  Serial.println(tReg, HEX);
}

////////////////////////////////////////////////////////////////////////////
// testTSetReg()
////////////////////////////////////////////////////////////////////////////

void testHystReg(void)
{
  uint16_t tReg;
  myTemp.writeTHystRegister(0x5a00);
  tReg = myTemp.readTHystRegister();
  Serial.print("tHyst register, wrote: 0x5A00, read back 0x");
  Serial.println(tReg, HEX);
}

////////////////////////////////////////////////////////////////////////////
// testTemp() 
////////////////////////////////////////////////////////////////////////////

void testTemp(void)
{
  Serial.println("Setting temperature resolution to 12 bits");
  myTemp.setResolution((uint8_t) TCN75A_RES12BIT);
  delay(500);
  readTemp();
  Serial.println("Setting temperature resolution to 11 bits");
  myTemp.setResolution((uint8_t) TCN75A_RES11BIT);
  delay(500);
  readTemp();
  Serial.println("Setting temperature resolution to 10 bits");
  myTemp.setResolution((uint8_t) TCN75A_RES10BIT);
  delay(500);
  readTemp();
  Serial.println("Setting temperature resolution to 9 bits");
  myTemp.setResolution((uint8_t) TCN75A_RES9BIT);
  delay(500);
  readTemp();
}

