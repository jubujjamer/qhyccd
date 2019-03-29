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
 * @file qhy12.h
 * @brief QHY12 class define
 */

#include "qhybase.h"

#ifndef __QHY12DEF_H__
#define __QHY12DEF_H__

/**
 * @brief QHY12 class define
 *
 * include all functions for QHY12
 */
class QHY12:public QHYBASE
{
public:
    QHY12();
    ~QHY12();
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
     @fn uint32_t SetChipSpeed(qhyccd_handle *h,uint32_t i)
     @brief set the transfer speed to camera
     @param h camera control handle
     @param i speed level
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipSpeed(qhyccd_handle *h,uint32_t i);
    
    /**
     @fn uint32_t SetChipOffset(qhyccd_handle *h,double offset)
     @brief set the camera offset
     @param h camera control handle
     @param offset offset value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipOffset(qhyccd_handle *h,double offset);
    
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
     @fn double GetChipCoolTemp(qhyccd_handle *h)
     @brief get the current ccd/cmos temprature
     @param h camera control handle
     @return
     success return the current cool temprature \n
     another QHYCCD_ERROR code on other failures
     */
    double GetChipCoolTemp(qhyccd_handle *h);
    
    /**
     @fn double GetChipCoolPWM()
     @brief get the current ccd/cmos temprature
     @return
     success return the current cool temprature \n
     another QHYCCD_ERROR code on other failures
     */
    double GetChipCoolPWM();
    
    /**
     @fn uint32_t CorrectWH(uint32_t *w,uint32_t *h)
     @brief correct width and height if the setting width or height is not correct
     @param w set width
     @param h set height
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t CorrectWH(uint32_t *w,uint32_t *h);
    
    /**
     @fn double InitBIN11Mode(uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize)
     @brief init the bin11 mode setting
     @param x  the image top left x position
     @param y  the image top left y position
     @param xsize the image width
     @param ysize the image height
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN11Mode(uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    
    /**
     @fn double InitBIN22Mode(uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize)
     @brief init the bin22 mode setting
     @param x  the image top left x position
     @param y  the image top left y position
     @param xsize the image width
     @param ysize the image height
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN22Mode(uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    
    /**
     @fn double InitBIN44Mode(uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize)
     @brief init the bin44 mode setting
     @param x  the image top left x position
     @param y  the image top left y position
     @param xsize the image width
     @param ysize the image height
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN44Mode(uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    
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
    uint32_t SetChipResolution(qhyccd_handle *handle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    
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
     @fn uint32_t CancelExposing(qhyccd_handle *handle)
     @param handle camera control handle
     @return
     on success,return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t CancelExposing(qhyccd_handle *handle);

    /**
     @fn uint32_t CancelExposingAndReadout(qhyccd_handle *h)
     @brief stop single exposure
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t CancelExposingAndReadout(qhyccd_handle *h);
    
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
     @fn uint32_t AutoTempControl(qhyccd_handle *h,double ttemp)
     @brief auto temprature control
     @param h camera control handle
     @param ttemp target temprature(degree Celsius)
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t AutoTempControl(qhyccd_handle *h,double ttemp);
    
    /**
     @fn uint32_t SetChipCoolPWM(qhyccd_handle *h,double PWM)
     @brief set cool power
     @param h camera control handle
     @param PWM power(0-255)
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipCoolPWM(qhyccd_handle *h,double PWM);
    
    /**
     @fn void ConvertDataBIN11(uint8_t * Data,uint32_t x, uint32_t y, uint16_t PixShift)
     @brief move the pixel raw data to correction position,and bin if need
     @param Data raw image data
     @param x image width
     @param y image height
     @param PixShift this is a way to fix the bad pixel data by the usb transfer
     */
    void ConvertDataBIN11(uint8_t * Data,uint32_t x, uint32_t y, uint16_t PixShift);
    
    /**
     @fn void ConvertDataBIN22(uint8_t * Data,uint32_t x, uint32_t y, uint16_t PixShift)
     @brief move the pixel raw data to correction position,and bin if need
     @param Data raw image data
     @param x image width
     @param y image height
     @param PixShift this is a way to fix the bad pixel data by the usb transfer
     */
    void ConvertDataBIN22(uint8_t * Data,uint32_t x, uint32_t y, uint16_t PixShift);
    
    /**
     @fn void ConvertDataBIN44(uint8_t * Data,uint32_t x, uint32_t y, uint16_t PixShift)
     @brief move the pixel raw data to correction position,and bin if need
     @param Data raw image data
     @param x image width
     @param y image height
     @param PixShift this is a way to fix the bad pixel data by the usb transfer
     */
    void ConvertDataBIN44(uint8_t * Data,uint32_t x, uint32_t y, uint16_t PixShift);

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

    void ConvertQHY12DataFocus(uint8_t *Data,uint32_t PixShift);


};
#endif

