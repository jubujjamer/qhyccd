/*
 QHYCCD SDK
 
 Copyright (c) 2014 QHYCCD.
 All Rights Reserved.
 
 This program is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by the Free
 Software Foundation; either version 2 of the License, or (at your option)
 any later version.
 
 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 more details.
 
 You should have received a copy of the GNU General Public License along with
 this program; if not, write to the Free Software Foundation, Inc., 59
 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 
 The full GNU General Public License is included in this distribution in the
 file called LICENSE.
 */

/*!
 * @file qhy5iiibase.h
 * @brief QHYCCD QHY5IIIBASE class define
 */

#include "qhycam.h"
#include "qhyccdcamdef.h"
#include "qhyccderr.h"
#include "log4z.h"
#include "cmosdll.h"
#include "stdint.h"
#include "qhybase.h"

#ifdef LINUX
#include <pthread.h>
#endif

#ifndef __QHY5IIIBASEDEF_H__
#define __QHY5IIIBASEDEF_H__

/**
 * the QHY5IIIBASE class description
 */
class QHY5IIIBASE : public QHYBASE {
public:
    QHY5IIIBASE();
    virtual ~QHY5IIIBASE();

    uint32_t BeginSingleExposure(qhyccd_handle *h);
    uint32_t CancelExposing(qhyccd_handle *handle);
    uint32_t CancelExposingAndReadout(qhyccd_handle *h);
    uint32_t BeginLiveExposure(qhyccd_handle *h);
    uint32_t StopLiveExposure(qhyccd_handle *h);
    uint32_t GetSingleFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData);
    uint32_t GetLiveFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData);
    
    uint32_t ConnectCamera(qhyccd_device *d,qhyccd_handle **h);
    uint32_t DisConnectCamera(qhyccd_handle *h);
    uint32_t InitChipRegs(qhyccd_handle *h);
    uint32_t ReSetParams2cam(qhyccd_handle *h);
    uint32_t SetChipWBRed(qhyccd_handle *h,double red);
    uint32_t SetChipWBGreen(qhyccd_handle *h,double green);
    uint32_t SetChipWBBlue(qhyccd_handle *h,double blue);
    static void ThreadCancelExposingAndReadout(void *p);
    void ThreadCancelExposingAndReadoutStart(qhyccd_handle *h);
    uint32_t SetChipUSBTraffic(qhyccd_handle *h,uint32_t i);
    uint32_t SetChipSpeed(qhyccd_handle *h,uint32_t i);
    uint32_t SetChipBinMode(qhyccd_handle *h,uint32_t wbin,uint32_t hbin);
    uint32_t Send2GuiderPort(qhyccd_handle *h,uint32_t Direction,uint16_t PulseTime);
    void DDRResetControl(qhyccd_handle *handle,uint8_t val);
    void ClearDDRPulse(qhyccd_handle *handle);
    void SetDDRFullSize(qhyccd_handle *handle,uint32_t val);
    void WriteFPGA(qhyccd_handle *handle,uint16_t index,uint16_t val);
    void SetSleepStart(qhyccd_handle *handle,uint16_t val);
    void SetSleepEnd(qhyccd_handle *handle,uint16_t val);
    void SetSleepFrames(qhyccd_handle *handle,uint16_t val);
    void SpiPath(qhyccd_handle *handle,uint8_t val);
    void SetIDLE(qhyccd_handle *handle);
    void ReleaseIDLE(qhyccd_handle *handle);
    void CMOSReset(qhyccd_handle *handle);
    void EnableLock(qhyccd_handle *handle);
    void DisableLock(qhyccd_handle *handle);
    void SetLockFrames(qhyccd_handle *handle,uint16_t val);
    void IgnoreFrames(qhyccd_handle *handle,uint8_t val);
    void SetPatchVPosition(qhyccd_handle *handle,uint32_t val);
    void SetPatchFramePosition(qhyccd_handle *handle,uint8_t val);
    void EnableDDR(qhyccd_handle *handle);
    void DisableDDR(qhyccd_handle *handle);
    void EnableReadFromDDR(qhyccd_handle *handle);
    void DisableReadFromDDR(qhyccd_handle *handle);
    unsigned int readDDRNum(qhyccd_handle *handle);
    void SetHMAX(qhyccd_handle *handle,uint32_t val);
    void SetVMAX(qhyccd_handle *handle,uint32_t val);
    void AMPVControl(qhyccd_handle *handle,uint8_t val);
    void SetAMPVStartPosition(qhyccd_handle *handle,uint32_t val);
    void SetAMPVEndPosition(qhyccd_handle *handle,uint32_t val);
    void SetFPGAOutputBits(qhyccd_handle *handle,uint32_t val);
    void SetFPGACrop(qhyccd_handle *handle,uint32_t x,uint32_t y);
    void WriteFPGADigitalGain(qhyccd_handle *handle,uint32_t val);
    void ManualAMPON(qhyccd_handle *handle);
    void ManualAMPOFF(qhyccd_handle *handle);

public:
#ifdef WIN32
    HANDLE hCancelExposingAndReadoutThread;
#endif
    uint8_t specialdropbychip;
    uint8_t readnum;
    bool qhy367sleepthread;
};

#endif
