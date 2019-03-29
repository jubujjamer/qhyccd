#pragma once

#define QCAM_RAWDATACACHESIZE (75000000)
#define QCAM_FRAMECACHESIZE 1
#define QCAM_MAXCORECOUNT 16

class Mutex
{
private:
	CRITICAL_SECTION cs;

public:
	Mutex()
	{
		::InitializeCriticalSection(&this->cs);
	}

	~Mutex()
	{
		::DeleteCriticalSection(&this->cs);
	}

	void Lock()
	{
		::EnterCriticalSection(&this->cs);
	}

	void Unlock()
	{
		::LeaveCriticalSection(&this->cs);
	}
};

class CamContext
{
public:
	unsigned char ioType;
	HANDLE hCam;
	int camType;
	int resX, resY;
	int frameLen;
	unsigned char depth;

	BOOL live;
	unsigned char *rawDataCache;
	HANDLE hIoThread;
	BOOL raw;

	CamContext()
	{
		this->hCam = INVALID_HANDLE_VALUE;
	}

};

void InitContext(int framesize,CCyUSBDevice* pDev);
CamContext* GetContext(HANDLE hCam);
