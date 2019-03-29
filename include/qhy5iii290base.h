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

#define JS

#include "qhy5iiicoolbase.h"

#ifndef QHY5III290BASE_DEF
#define QHY5III290BASE_DEF

class QHY5III290BASE:public QHY5IIICOOLBASE {
public:
    QHY5III290BASE();
    ~QHY5III290BASE();

#ifndef JS
    uint32_t BeginSingleExposure(qhyccd_handle *pDevHandle);
    uint32_t CancelExposing(qhyccd_handle *pDevHandle);
    uint32_t CancelExposingAndReadout(qhyccd_handle *pDevHandle);
    uint32_t BeginLiveExposure(qhyccd_handle *pDevHandle);
    uint32_t StopLiveExposure(qhyccd_handle *pDevHandle);
#endif
    
    //uint32_t DisConnectCamera(qhyccd_handle *pDevHandle);
    void ResetParameters();
    void UpdateParameters(qhyccd_handle *pDevHandle);
    
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
    uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId, double *min, double *max, double *step);
 
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

    /** @fn uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY)
      @brief Set the camera on focus mode
      @param h camera control handle
      @param focusCenterX
      @param focusCenterY
      @return
      on success,return QHYCCD_SUCCESS \n
      another QHYCCD_ERROR code on other failures
     */
     uint32_t SetFocusSetting(qhyccd_handle *pDevHandle, uint32_t focusCenterX, uint32_t focusCenterY);

private:
    double pllratio;
    uint32_t hmax_ref, vmax_ref;
    
    
    double oldpllratio;
    //double oldtotalcamred2green, totalcamred2green, oldtotalcamgreen, totalcamgreen;
    double /*oldtotalcamblue2green, totalcamblue2green,*/ oldcamgain;
    double oldcamampv;

    int32_t shs, oldshs; //svr, spl, oldsvr, oldspl not used

    uint32_t vmax, hmax, oldvmax, oldhmax;
    //uint32_t vmax_valid, hmax_valid, oldvmax_valid, oldhmax_valid;
    //uint32_t framelength, oldframelength;
    uint32_t oldchipoutputsizex, oldchipoutputsizey, oldchipoutputbits;
    //uint32_t patchvnumber, oldpatchvnumber;
    uint32_t oldcamoffset;
    //uint32_t oldusbtraffic;
    uint32_t ampv_min, oldampv_min, ampv_max, oldampv_max;

    //uint16_t chiproiy, oldchiproiy, chiproiysize, oldchiproiysize;
    uint16_t winph, oldwinph, winwh, oldwinwh, winpv, oldwinpv, winwv, oldwinwv;
    
    //uint8_t oldreg08, reg08, oldreg01, reg01;
    //uint8_t oldlockframe, lockframe;
    //uint8_t oldcamviewmode;
    
};
#endif