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

/*! @file qhy367m.h
 *  @brief QHY367M class define
 */


#ifndef _QHY5III128BASE_
#define _QHY5III128BASE_

#include "qhy5iiicoolbase.h"

class QHY5III128BASE:public QHY5IIICOOLBASE {
	
public:
    QHY5III128BASE();
    ~QHY5III128BASE();

#ifdef WIN32
    static void ExposureThreadRoutine(void *pDevHandle);
#else
    static void *ExposureThreadRoutine(void *pDevHandle);
#endif   
    void StartExposureThread(qhyccd_handle *pDevHandle);
    
    uint32_t BeginSingleExposure(qhyccd_handle *pDevHandle);
    uint32_t CancelExposingAndReadout(qhyccd_handle *pDevHandle);
    uint32_t BeginLiveExposure(qhyccd_handle *pDevHandle);
    uint32_t StopLiveExposure(qhyccd_handle *pDevHandle);
    uint32_t GetSingleFrame(qhyccd_handle *pDevHandle, uint32_t *pW, uint32_t *pH, uint32_t * pBpp, uint32_t *pChannels, uint8_t *ImgData);
    uint32_t DisConnectCamera(qhyccd_handle *pHandle);

    void CMOS_TakePhoto(qhyccd_handle *h);
    uint32_t InitChipRegs(qhyccd_handle *h);
    void SpiPath(qhyccd_handle *handle,uint8_t val);
    void CMOSReset(qhyccd_handle *handle);
    void FX3SPIMode(qhyccd_handle *handle);
    void FPGASPIMode(qhyccd_handle *handle);
    void SetFreqDiv(qhyccd_handle *handle,uint8_t val);
    void IMX193_TakePhoto(qhyccd_handle *handle);
    void SetFPGACrop(qhyccd_handle *handle,uint32_t x,uint32_t y);
    void SetFPGAOutputBits(qhyccd_handle *handle,uint32_t val);
    void WriteCMOSOffset(qhyccd_handle *handle,uint32_t val);
    void WriteCMOSGain(qhyccd_handle *handle,uint32_t val);
    void WriteFPGADigitalGain(qhyccd_handle *handle,uint32_t val);
    void WriteCMOSAnalogGainRed(qhyccd_handle *handle,uint32_t val);
    void WriteCMOSAnalogGainBlue(qhyccd_handle *handle,uint32_t val);
    void WriteCMOSAnalogGainGreen(qhyccd_handle *handle,uint32_t val);
    void AMPVControl(qhyccd_handle *handle,uint8_t val);
    void InitSPISleep(qhyccd_handle *handle);
    void WriteCMOS(qhyccd_handle *handle,uint16_t index,uint16_t val);
    void WriteCMOSSHS(qhyccd_handle *handle,uint32_t val);
    void SetCMOSCrop(qhyccd_handle *handle,uint32_t ystart,uint32_t ysize);
    void SetSleepStart(qhyccd_handle *handle,uint16_t val);
    void SetSleepEnd(qhyccd_handle *handle,uint16_t val);
    void SetSleepFrames(qhyccd_handle *handle,uint16_t val);
    uint32_t SetChipGain(qhyccd_handle *h,double gain);
    uint32_t SetChipWBRed(qhyccd_handle *h,double red);
    uint32_t SetChipWBGreen(qhyccd_handle *h,double green);
    uint32_t SetChipWBBlue(qhyccd_handle *h,double blue);
    uint32_t SetChipUSBTraffic(qhyccd_handle *h,uint32_t i);
    uint32_t SetChipExposeTime(qhyccd_handle *h,double i);
    uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId,double *min,double *max,double *step);
    uint32_t SetChipOffset(qhyccd_handle *h,double offset);
    uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits);
    uint32_t SetChipResolution(qhyccd_handle *handle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    uint32_t SetChipBinMode(qhyccd_handle *h, uint32_t wbin, uint32_t hbin) ;
    
    uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY);
    void Sensor14bit_V_1_3(qhyccd_handle *h);
    void Sensor10bit_V_1_3_h_3bin(qhyccd_handle *h);
    void ResetParameters();
    void UpdateParameters(qhyccd_handle *h);
    uint32_t GeDDRBufferThreshold();
    uint32_t GetUsedDdr(qhyccd_handle *pDevHandle, uint32_t *pDdr);   
private:
#ifdef WIN32
    HANDLE hCountExpTimeThread;
#endif
    
#ifdef LINUX
     pthread_t m_expThreadHandle;
#endif
         
    double pllratio,oldpllratio; //!< inter pll ratio
    uint32_t hmax_ref,vmax_ref;
    uint32_t vmax,hmax,oldvmax,oldhmax;
    uint32_t framelength,oldframelength;
    uint32_t oldchipoutputsizex,oldchipoutputsizey,oldchipoutputbits;
    uint32_t patchvnumber,oldpatchvnumber;
    uint32_t shr,svr,spl,oldshr,oldsvr,oldspl;
    double oldcamgain;
    uint32_t oldcamoffset;
    uint32_t oldusbtraffic;
    uint8_t oldreg08,reg08,oldreg01,reg01;
    uint8_t oldlockframe,lockframe;
    uint8_t oldcamviewmode;
    uint8_t oldcamampv;
    uint16_t oldcamddr;
    uint8_t forceupdate;
    uint8_t locknum,oldlocknum;
    double oldcamred2green,oldcamgreen,oldcamblue2green;
    uint32_t sleepframes,oldsleepframes,initsingleframe;
    uint32_t cutleftsize,cutrightsize,cuttopsize,cutbottomsize;
    uint32_t ApproxDDR, ApproxDDR_Target;
};
#endif
