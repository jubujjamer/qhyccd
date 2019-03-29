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

#ifndef _QHY5III183BASE_
#define _QHY5III183BASE_

#include "qhy5iiicoolbase.h"

#define TOTAL_PIXELS_WIDTH  5640
#define TOTAL_PIXELS_HEIGHT 3710

class QHY5III183BASE:public QHY5IIICOOLBASE {
public:
    QHY5III183BASE();
    ~QHY5III183BASE();
/*
    #ifdef WIN32
        static void ExposureThreadRoutine(void *pDevHandle);
    #else
        static void *ExposureThreadRoutine(void *pDevHandle);
    #endif   
        void StartExposureThread(qhyccd_handle *pDevHandle);
*/
//    uint32_t BeginSingleExposure(qhyccd_handle *pDevHandle);
    uint32_t CancelExposingAndReadout(qhyccd_handle *pDevHandle);
    uint32_t CancelExposing(qhyccd_handle *pDevHandle);

    uint32_t BeginLiveExposure(qhyccd_handle *pDevHandle);
    uint32_t StopLiveExposure(qhyccd_handle *pDevHandle);
    
//    uint32_t GetSingleFrame(qhyccd_handle *pDevHandle, uint32_t *pW, uint32_t *pH, uint32_t *pBpp, uint32_t *pChannels, uint8_t *pImgData);  
    uint32_t GetLiveFrame(qhyccd_handle *pDevHandle, uint32_t *pW, uint32_t *pH, uint32_t *pBpp, uint32_t *pChannels, uint8_t *pImgData);

    uint32_t DisConnectCamera(qhyccd_handle *pDevHandle);
    
    uint32_t InitChipRegs(qhyccd_handle *pDevHandle);
    uint32_t SetChipGain(qhyccd_handle *pDevHandle,double gain);
    uint32_t SetChipExposeTime(qhyccd_handle *pDevHandle, double i);
    uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId,double *min, double *max, double *step);
    uint32_t SetChipUSBTraffic(qhyccd_handle *pDevHandle,uint32_t i);
    uint32_t SetChipOffset(qhyccd_handle *pDevHandle,double offset);
    uint32_t SetChipBitsMode(qhyccd_handle *pDevHandle,uint32_t bits);
    uint32_t SetChipResolution(qhyccd_handle *pDevHandle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    uint32_t SetFocusSetting(qhyccd_handle *pDevHandle,uint32_t focusCenterX, uint32_t focusCenterY);
    uint32_t SetStreamMode(qhyccd_handle *pDevHandle,uint8_t mode);
    uint32_t GetUsedDdr(qhyccd_handle *pDevHandle, uint32_t *pDdr);
    void UpdateParameters(qhyccd_handle *pDevHandle);
    void ResetParameters();
    void WriteCMOS(qhyccd_handle *pDevHandle,uint16_t index,uint16_t val);
    
protected:
    
#ifdef LINUX
     pthread_t m_expThreadHandle;
#endif

    double oldcamgain;
    double pllratio, oldpllratio; 
    
    uint8_t oldcamddr;
    uint8_t oldlockframe, lockframe;
    uint8_t oldampv_onff, ampv_onff;
    uint8_t forcestop;

    uint16_t vwinpos, oldvwinpos, vwidcut, oldvwidcut;
    
    uint32_t hmax_ref, vmax_ref;
    uint32_t vmax,hmax, oldvmax, oldhmax;
    uint32_t framelength, oldframelength;
    uint32_t oldchipoutputsizex, oldchipoutputsizey, oldchipoutputbits;
    uint32_t patchvnumber, oldpatchvnumber;
    uint32_t shr, svr, spl, oldshr, oldsvr, oldspl;
    uint32_t oldcamoffset;
    uint32_t oldusbtraffic;
    uint32_t oldampv_min, ampv_min, oldampv_max, ampv_max;
    uint32_t ApproxDDR, ApproxDDR_Target;
};
#endif
