// QUsb.h
#include "CyAPI.h"
#include "stdint.h"

#ifndef _QUSB_H_
#define _QUSB_H_

#define QUSB_MAXCAMERACOUNT 16
#define QUSB_TXSIZE 524288
#define QUSB_TXCOUNT 16

#define SingleFrameUSBPacketSize 2048 * 20 *2
#ifdef __cplusplus 
extern "C" {
#endif	

class Transaction
{
public:
    OVERLAPPED ov;   
    PUCHAR cyContext;
    unsigned char* data;

    Transaction()
    {
        this->ov.hEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL);
        this->data = new unsigned char[QUSB_TXSIZE];
        this->cyContext = NULL;
    }
};

class UsbContext
{
public:
    CCyUSBDevice* pDev;
    Transaction txList[QUSB_TXCOUNT];
    HANDLE hAbortEvent;
    int lastTxIndex;

    UsbContext()
    {
        this->pDev = NULL;
        this->hAbortEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL);
        this->lastTxIndex = -1;
    }
};





void __cdecl QUsbEnumCam(HANDLE* hCamList,CCyUSBDevice* pDev);

bool __cdecl QUsbReadRawData(HANDLE hCam, unsigned char* data, int32_t len,uint32_t duration);



bool __cdecl QUsbBeginReadRawData(HANDLE hCam);
bool __cdecl QUsbWaitForData(HANDLE hCam, uint8_t** pData, int32_t* pLen);
bool __cdecl QUsbResumeRawDataRead(HANDLE hCam);
bool __cdecl QUsbAbortWait(HANDLE hCam);
bool __cdecl QUsbStopReadRawData(HANDLE hCam);



bool __cdecl QUsbBeginReadRawDataSingle(HANDLE hCam,uint32_t PacketSize);
bool __cdecl QUsbResumeRawDataReadSingle(HANDLE hCam,uint32_t PacketSize);
bool __cdecl QUsbWaitForDataSingle(HANDLE hCam, uint8_t** pData, int32_t* pLen,uint32_t PacketSize);
bool __cdecl QUsbStopReadRawDataSingle(HANDLE hCam);

#ifdef __cplusplus 
}
#endif

#endif
