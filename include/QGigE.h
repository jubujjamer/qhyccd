#ifndef _Q_GIGE_H_
#define _Q_GIGE_H_

#include "stdint.h"
#include "qhyccdstruct.h"

#ifdef __cplusplus
extern "C" {
#endif


#define QGIGE_MAXCAMERACOUNT 16


#define QGIGE_CAMTYPE_UNKNOWN DEVICETYPE_UNKNOW
#define QGIGE_CAMTYPE_SOLAR800G DEVICETYPE_SOLAR800G
#define QGIGE_CAMTYPE_QHY15 DEVICETYPE_QHY15G
#define QGIGE_CAMTYPE_A0340 DEVICETYPE_A0340G
#define QGIGE_CAMTYPE_A08050    DEVICETYPE_QHY08050G
#define QGIGE_CAMTYPE_TEST694   DEVICETYPE_QHY694G
#define QGIGE_CAMTYPE_TEST16050 DEVICETYPE_QHY27G
#define QGIGE_CAMTYPE_TEST814   DEVICETYPE_QHY23G
#define QGIGE_CAMTYPE_A16000    DEVICETYPE_QHY16000G
#define QGIGE_CAMTYPE_A814      DEVICETYPE_QHY814G
#define QGIGE_CAMTYPE_A45GX     DEVICETYPE_QHY45GX


#define QGIGE_DEPTH_8BIT 10
#define QGIGE_DEPTH_16BIT 20

#define QGIGE_READOUTSPEED_HIGH 10
#define QGIGE_READOUTSPEED_MEDIUM 20
#define QGIGE_READOUTSPEED_LOW 30

#ifdef WIN32
void __stdcall QGigEInit(HANDLE* hGigEList, uint32_t* pCamCount);
void __stdcall QGigEUninit();

uint32_t __stdcall QGigEGetCamType(HANDLE hGigE);
GUID __stdcall QGigEGetCamGuid(HANDLE hGigE);

bool __stdcall QGigESetBinning(HANDLE hGigE, uint8_t h, uint8_t v);
bool __stdcall QGigESetDepth(HANDLE hGigE, uint8_t depth);
bool __stdcall QGigESetReadoutSpeed(HANDLE hGigE, uint8_t readoutSpeed);
bool __stdcall QGigESetExposure(HANDLE hGigE, double exp);
bool __stdcall QGigESetGain(HANDLE hGigE, uint16_t gain);
bool __stdcall QGigESetFinetune(HANDLE hGigE, uint8_t* finetune);
bool __stdcall QGigESetRaw(HANDLE hGigE, bool raw);

bool __stdcall QGigEBeginLive(HANDLE hGigE);
bool __stdcall QGigEGetLiveFrame(HANDLE hGigE, void* data, uint32_t* pW, uint32_t* pH, uint32_t* pBpp);
void __stdcall QGigEStopLive(HANDLE hGigE);
bool __stdcall QGigECapture(HANDLE hGigE, void* data, uint32_t* pW, uint32_t* pH, uint32_t* pBpp);
void __stdcall QGigEAbortCapture(HANDLE hGigE);

bool __stdcall QGigESetTrigerFunction(HANDLE hGigE,bool value);

bool __stdcall QGigESetTargetTemperature(HANDLE hGigE, double temp);
bool __stdcall QGigESetCoolingPower(HANDLE hGigE,uint8_t power);
bool __stdcall QGigEBeginCooling(HANDLE hGigE);
void __stdcall QGigEStopCooling(HANDLE hGigE);
bool __stdcall QGigEGetCoolerStatus(HANDLE hGigE, double* pTemp, uint8_t* pPower);

bool __stdcall QGigESendRequest(HANDLE hGigE, bool hasResponse, uint16_t cmd, uint8_t* data, uint32_t len);

bool __stdcall QGigEAdWrite(HANDLE hGigE, uint16_t addr, uint32_t value);

bool __stdcall QGigEEepromRead(HANDLE hGigE, uint8_t index, uint8_t* data, uint16_t len);
bool __stdcall QGigEEepromWrite(HANDLE hGigE, uint8_t index, uint8_t* data, uint16_t len);

bool __stdcall QGigESend2Uart(HANDLE hGigE, int8_t* data, uint16_t len);
bool __stdcall QGigEReceiveFromUart(HANDLE hGigE, int8_t* data, uint16_t len);
    
#endif
    
#ifdef __cplusplus
}
#endif

#endif
