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
 * @file qhy16000.h
 * @brief QHY16000 class define
 */

#include "qhybase.h"

#ifndef __QHY16000DEF_H__
#define __QHY16000DEF_H__

/**
 * @brief QHY16000 class define
 *
 * include all functions for QHY16000
 */
class QHY16000:public QHYBASE
{
public:
    QHY16000();
    ~QHY16000();
    
    /**
     @fn uint32_t InitChipRegs(qhyccd_handle *h)
     @brief Init the registers and some other things
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitChipRegs(qhyccd_handle *h);

    /**
     @fn uint32_t DisConnectCamera(qhyccd_handle *h)
     @brief disconnect to the connected camera
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t DisConnectCamera(qhyccd_handle *h);

    /**
     @fn uint32_t IsChipHasFunction(CONTROL_ID id)
     @brief check the camera has the function or not
     @param id function id
     @return
     HAVE return QHYCCD_HAVE \n
     NOT HAVE return QHYCCD_NOTHAVE
     */
    uint32_t IsChipHasFunction(CONTROL_ID id);
    
    /**
     @fn uint32_t SetChipGain(qhyccd_handle *h,double gain)
     @brief set the gain to camera
     @param h camera control handle
     @param gain gain value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipGain(qhyccd_handle *h,double gain);
    
    /**
     @fn uint32_t SetChipExposeTime(qhyccd_handle *h,double i)
     @brief set the expose time to camera
     @param h camera control handle
     @param i expose time value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipExposeTime(qhyccd_handle *h,double i);
        
    /**
     @fn uint32_t SetChipBinMode(qhyccd_handle *h,uint32_t wbin,uint32_t hbin)
     @brief set the camera offset
     @param h camera control handle
     @param wbin width bin
     @param hbin height bin
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipBinMode(qhyccd_handle *h,uint32_t wbin,uint32_t hbin);
       
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

    /**
     @fn double InitBIN11Mode(qhyccd_handle *h)
     @brief init the bin11 mode setting
	 @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN11Mode(qhyccd_handle *h);

    /**
     @fn double InitBIN44Mode(qhyccd_handle *h)
     @brief init the bin44 mode setting
	 @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN44Mode(qhyccd_handle *h);

    /**
     @fn uint32_t BeginSingleExposure(qhyccd_handle *h)
     @brief begin single exposure
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t BeginSingleExposure(qhyccd_handle *h);
    
    /**
     @fn uint32_t StopSingleExposure(qhyccd_handle *h)
     @brief stop single exposure
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t StopSingleExposure(qhyccd_handle *h);
    
    /**
     @fn uint32_t GetSingleFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData)
     @brief get single frame image data
     @param h camera control handle
     @param pW real width
     @param pH real height
     @param pBpp real depth bits
     @param pChannels real channels
     @param ImgData image data buffer
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t GetSingleFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData);
    
    /**
     @fn uint32_t BeginLiveExposure(qhyccd_handle *h)
     @brief begin live exposure
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t BeginLiveExposure(qhyccd_handle *h);
    
    /**
     @fn uint32_t StopLiveExposure(qhyccd_handle *h)
     @brief stop live exposure
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t StopLiveExposure(qhyccd_handle *h);
    
    /**
     @fn uint32_t GetLiveFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData)
     @brief get live frame image data
     @param h camera control handle
     @param pW real width
     @param pH real height
     @param pBpp real depth bits
     @param pChannels real channels
     @param ImgData image data buffer
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t GetLiveFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData);
    
    /** @fn uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY)
      @brief Set the camera on focus mode
      @param h camera control handle
      @param focusCenterX
      @param focusCenterY
      @return
	  on success,return QHYCCD_SUCCESS \n
	  another QHYCCD_ERROR code on other failures
     */
     uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY);

	 uint32_t I2CWriteByte(qhyccd_handle *h,uint8_t index, uint8_t value);

	 uint32_t I2CWriteWord(qhyccd_handle *h,uint8_t index, uint16_t value);

	 bool flagbin44;
	 uint8_t *rawarray2;
};
#endif

