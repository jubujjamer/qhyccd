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

#ifndef _QHY5III165BASE_
#define _QHY5III165BASE_

#include "qhy5iiicoolbase.h"

class QHY5III165BASE : public QHY5IIICOOLBASE {
public:
    QHY5III165BASE();
    ~QHY5III165BASE();
    
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
    uint32_t DisConnectCamera(qhyccd_handle *pDevHandle);
   
    uint32_t GetUsedDdr(qhyccd_handle *pDevHandle, uint32_t *pDdr);
    uint32_t InitChipRegs(qhyccd_handle *pDevHandle);
    void InitRegs(qhyccd_handle *pDevHandle);
    void UpdateParameters(qhyccd_handle *pDevHandle);
    void ResetParameters();
    void InitSPISleep(qhyccd_handle *pDevHandle);
    void WriteCMOSSHS(qhyccd_handle *pDevHandle, int32_t val);
    void SetCMOSCrop(qhyccd_handle *pDevHandle, uint32_t ystart, uint32_t ysize);
    uint32_t SetDDR(qhyccd_handle *pDevHandle, double value);
    void SetFreqDiv(qhyccd_handle *pDevHandle, uint8_t val);
    void CalcFreqDiv(qhyccd_handle *pDevHandle);
    void WriteCMOSAnalogGainRed(qhyccd_handle *pDevHandle, uint16_t val);
    void WriteCMOSAnalogGainGreen(qhyccd_handle *pDevHandle, uint16_t val);
    void WriteCMOSAnalogGainBlue(qhyccd_handle *pDevHandle, uint16_t val);
    void WriteCMOSOffset(qhyccd_handle *pDevHandle, uint16_t val);
    void WriteFPGADigitalGain(qhyccd_handle *pDevHandle, uint16_t val);

    uint32_t GeDDRBufferThreshold();
    void FX3SPIMode(qhyccd_handle *pDevHandle);
    void FPGASPIMode(qhyccd_handle *pDevHandle);
    void WriteCMOS(qhyccd_handle *pDevHandle, uint16_t index, uint16_t val);
  
    /**
     @fn uint32_t SetChipGain(qhyccd_handle *h,double gain)
     @brief set the gain to camera
     @param h camera control handle
     @param gain gain value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipGain(qhyccd_handle *pDevHandle, double gain);
    uint32_t SetChipWBRed(qhyccd_handle *pDevHandle, double red);
    uint32_t SetChipWBGreen(qhyccd_handle *pDevHandle, double green);
    uint32_t SetChipWBBlue(qhyccd_handle *pDevHandle, double blue);

    /**
     @fn uint32_t SetChipExposeTime(qhyccd_handle *h,double i)
     @brief set the expose time to camera
     @param h camera control handle
     @param i expose time value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipExposeTime(qhyccd_handle *pDevHandle, double i);

    void SetChipExposeTime_Internal(qhyccd_handle *pDevHandle, double i);
    
    /**
     @fn uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId,double *min,double *max,double *step)
     @brief get the min,max and step value for function
     @param controlId the control id
     @param min the min value for function
     @param max the max value for function
     @param step single step value for function
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId,double *min,double *max,double *step);
    uint32_t SetChipOffset(qhyccd_handle *pDevHandle, double offset);

    /**
     @fn uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits)
     @brief set the camera depth bits
     @param h camera control handle
     @param bits depth bits
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipBitsMode(qhyccd_handle *pDevHandle, uint32_t bits);
    uint32_t SetChipUSBTraffic(qhyccd_handle *pDevHandle, uint32_t i);
    
   /** 
    @fn uint32_t SetChipResolution(qhyccd_handle *handle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize)
    @brief set camera ouput resolution
    @param handle camera control handle
    @param x the top left position x
    @param y the top left position y
    @param xsize the image width
    @param ysize the image height
    @return
    on success,return QHYCCD_SUCCESS\n
    another QHYCCD_ERROR code on other failures
    */
    uint32_t SetChipResolution(qhyccd_handle *pDevHandle, uint32_t x, uint32_t y, uint32_t xsize, uint32_t ysize);
        
private:
//#ifdef WIN32
//     HANDLE hCountExpTimeThread;
//#endif
     
#ifdef LINUX
     pthread_t m_expThreadHandle;
#endif
     
    double pllratio,oldpllratio; 
    double oldcamred2green,oldcamgreen,oldcamblue2green,oldcamgain;
    double oldcamampv;
    // double oldframetime,frametime;
    // double oldcamtime;

    uint32_t hmax_ref,vmax_ref;
    uint32_t vmax,hmax,oldvmax,oldhmax;
    uint32_t framelength,oldframelength;
    uint32_t oldchipoutputsizex,oldchipoutputsizey,oldchipoutputbits;
    uint32_t patchvnumber,oldpatchvnumber;
    uint32_t oldcamoffset;
    //uint32_t oldusbtraffic;
    uint32_t initsingleframe;
    uint32_t cutleftsize,cutrightsize,cuttopsize,cutbottomsize;
    
    uint32_t shr,svr,spl,oldshr,oldsvr,oldspl;

    uint16_t oldsleepframes, sleepframes, oldcamddr;

    uint8_t oldreg08,reg08,oldreg01,reg01;
    uint8_t oldlockframe,lockframe;
    //uint32_t ApproxDDR, ApproxDDR_Target;
};
#endif
