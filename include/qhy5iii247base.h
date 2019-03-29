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

#ifndef _QHY5III247BASE_
#define _QHY5III247BASE_

#include "qhy5iiicoolbase.h"

class QHY5III247BASE:public QHY5IIICOOLBASE {
public:
    QHY5III247BASE();
    ~QHY5III247BASE();
    
    uint32_t BeginSingleExposure(qhyccd_handle *h);
    uint32_t CancelExposingAndReadout(qhyccd_handle *pDevHandle);
    uint32_t BeginLiveExposure(qhyccd_handle *pDeviceHandle);
    uint32_t StopLiveExposure(qhyccd_handle *pDeviceHandle);
    uint32_t GetSingleFrame(qhyccd_handle *pDeviceHandle, uint32_t *pW, uint32_t *pH, uint32_t * pBpp, uint32_t *pChannels, uint8_t *ImgData);
    
    static void ThreadCountExposureTime(void *p);
    void ThreadCountExposureTimeStart(qhyccd_handle *pDeviceHandle);
    uint32_t DisConnectCamera(qhyccd_handle *pDevHandle);
    
    uint32_t InitChipRegs(qhyccd_handle *pDeviceHandle);
    void UpdateParameters(qhyccd_handle *pDeviceHandle);
    void ResetParameters();
    void FX3SPIMode(qhyccd_handle *pDeviceHandle);
    void FPGASPIMode(qhyccd_handle *pDeviceHandle);
    void SetFreqDiv(qhyccd_handle *pDeviceHandle, uint8_t val);
    void IMX193_TakePhoto(qhyccd_handle *pDeviceHandle);
    void SetFPGACrop(qhyccd_handle *pDeviceHandle, uint32_t x, uint32_t y);
    void WriteCMOSOffset(qhyccd_handle *pDeviceHandle, uint32_t val);
    void WriteCMOSGain(qhyccd_handle *pDeviceHandle, uint32_t val);
    void InitSPISleep(qhyccd_handle *pDeviceHandle);
    void WriteCMOS(qhyccd_handle *pDeviceHandle, uint16_t index, uint16_t val);
    void WriteCMOSSHS(qhyccd_handle *pDeviceHandle, uint32_t val);

    /**
     @fn uint32_t SetChipGain(qhyccd_handle *h,double gain)
     @brief set the gain to camera
     @param h camera control handle
     @param gain gain value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipGain(qhyccd_handle *pDeviceHandle, double gain);
    uint32_t SetChipWBRed(qhyccd_handle *pDeviceHandle, double red);
    uint32_t SetChipWBGreen(qhyccd_handle *pDeviceHandle, double green);
    uint32_t SetChipWBBlue(qhyccd_handle *pDeviceHandle, double blue);

    /**
     @fn uint32_t SetChipExposeTime(qhyccd_handle *pDeviceHandle,double i)
     @brief set the expose time to camera
     @param h camera control handle
     @param i expose time value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    void SetChipExposeTime_Internal(qhyccd_handle *pDeviceHandle, double i);
    uint32_t SetChipExposeTime(qhyccd_handle *pDeviceHandle, double i);
    
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
    uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId,double *min, double *max, double *step);
 
    uint32_t SetChipOffset(qhyccd_handle *pDeviceHandle, double offset);

    /**
     @fn uint32_t SetChipBitsMode(qhyccd_handle *pDeviceHandle,uint32_t bits)
     @brief set the camera depth bits
     @param h camera control handle
     @param bits depth bits
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipBitsMode(qhyccd_handle *pDeviceHandle, uint32_t bits);
    uint32_t SetChipUSBTraffic(qhyccd_handle *pDeviceHandle, uint32_t i);
    void SetCMOSCrop(qhyccd_handle *pDeviceHandle, uint32_t ystart, uint32_t ysize);
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
    uint32_t SetChipResolution(qhyccd_handle *pDeviceHandle, uint32_t x, uint32_t y, uint32_t xsize, uint32_t ysize);

private:
    double pllratio,oldpllratio; 
    double /*oldcamblue2green,oldcamred2green,oldcamgreen,*/ oldcamgain;
    uint32_t hmax_ref,vmax_ref;
    uint32_t vmax,hmax,oldvmax,oldhmax;
    uint32_t vmax_valid,oldvmax_valid,hmax_valid,oldhmax_valid;
    uint32_t framelength,oldframelength;
    uint32_t oldchipoutputsizex,oldchipoutputsizey,oldchipoutputbits;
    uint32_t patchvnumber,oldpatchvnumber;
    uint32_t oldcamoffset;
    uint32_t oldusbtraffic;
    uint32_t sleepframes,oldsleepframes,initsingleframe;
    uint32_t cutleftsize,cutrightsize,cuttopsize,cutbottomsize;
    uint32_t shr,svr,spl,oldshr,oldsvr,oldspl;
    uint16_t oldcamddr;
    uint8_t oldlockframe,lockframe;
    uint8_t digitalgain,olddigitalgain;
    uint8_t oldcamviewmode;
    uint32_t ApproxDDR;
    uint32_t ApproxDDR_Target;
    int flag_after_roi_change;
};

#endif
