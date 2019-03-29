#ifdef WIN32

#pragma once

#include "CyAPI.h"
#include "stdint.h"

class CamContext;

void EnumCam(CamContext* contextList,CCyUSBDevice *pDev);
uint32_t __stdcall IoThread(void* pParams);
uint32_t __stdcall DbgIoThread(void* pParams);
BOOL I2CRead(HANDLE hCam, uint16_t index, uint16_t* pValue);
BOOL I2CCacheRead(HANDLE hCam, uint16_t index, uint16_t* pValue);
BOOL I2CWrite(HANDLE hCam, uint16_t index, uint16_t value);
BOOL I2CBatchRead(HANDLE hCam, uint16_t index, uint8_t* data, uint16_t len);
BOOL I2CCacheBatchRead(HANDLE hCam, uint16_t index, uint8_t* data, uint16_t len);
BOOL I2CBatchWrite(HANDLE hCam, uint16_t index, uint8_t* data, uint16_t len);
BOOL I2CBatchWriteEx(HANDLE hCam, uint8_t i2caddr,uint8_t* data, uint16_t len);
uint16_t GetFirmwareVersion(HANDLE hCam);
BOOL EepromRead(HANDLE hCam, uint8_t index, uint8_t* data, uint16_t len);
BOOL EepromWrite(HANDLE hCam, uint8_t index, uint8_t* data, uint16_t len);
BOOL SetMode(HANDLE hCam);
BOOL SetBin(HANDLE hCam);
BOOL SetSubframe(HANDLE hCam);
BOOL SetDepth(HANDLE hCam);
BOOL SetTransferSpeed(HANDLE hCam);
BOOL SetExposeTime(HANDLE hCam);
BOOL SetGain(HANDLE hCam);
BOOL BeginTransfer(HANDLE hCam);
void StopTransfer(HANDLE hCam);
void AbortTransfer(HANDLE hCam);
BOOL SetHBlanking(HANDLE hCam);
BOOL SetHighGainBoost(HANDLE hCam);
BOOL SetFinetune(HANDLE hCam);
BOOL GetSingleFrame(HANDLE hCam,uint8_t *data,uint32_t len,uint32_t duration);

#endif