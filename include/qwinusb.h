#ifndef QHYCCD_WINUSB_H
#define QHYCCD_WINUSB_H

#define WINUSB_ALREADY_SUPPORT_NUM 10

extern char *winusbcamname[WINUSB_ALREADY_SUPPORT_NUM];

#ifdef WIN32

GUID * STDCALL name2GUID(PCHAR name);
uint32_t STDCALL QWinusbOpenDriver(HANDLE * phInDeviceHandle,GUID *cameraguid);
uint32_t STDCALL QWinusbGetCamType(char *camnamestr);
uint32_t STDCALL QWinusbCloseDriver(HANDLE handle);

#endif


#endif