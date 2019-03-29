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
 * @file solar800g.h
 * @brief SOLAR800G class define
 */

#include "qhybase.h"

#ifdef WIN32
//#include "QGigE.h"
#endif

#ifndef __SOLAR800GDEF_H__
#define __SOLAR800GDEF_H__

/**
 * @brief SOLAR800G class define
 *
 * include all functions for SOLAR800G
 */
class SOLAR800G:public QHYBASE
{
public:
    SOLAR800G();
    ~SOLAR800G();
    /**
     @fn uint32_t ConnectCamera(qhyccd_device *d,qhyccd_handle **h)
     @brief connect to the connected camera
     @param d camera deivce
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t ConnectCamera(qhyccd_device *d,qhyccd_handle **h);
    
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
     @fn uint32_t ReSetParams2cam(qhyccd_handle *h)
     @brief re set the params to camera,because some behavior will cause camera reset
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t ReSetParams2cam(qhyccd_handle *h);
    
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

	*/
	uint32_t SetChipDepth(qhyccd_handle *h,uint32_t depth);
    
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
     @fn uint32_t Send2CFWPort(qhyccd_handle *h,uint32_t pos)
     @brief send the command to camera's color filter wheel port
     @param h camera control handle
     @param pos the color filter position
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t Send2CFWPort(qhyccd_handle *h,uint32_t pos);
    
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
     @fn uint32_t GetChipMemoryLength()
     @brief get the min cost memory for the image
     @return
     success return the total memory space(unit:byte) \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t GetChipMemoryLength();
    
    /**
     @fn double GetChipExposeTime()
     @brief get the current exposetime
     @return
     success return the current expose time (unit:us) \n
     another QHYCCD_ERROR code on other failures
     */
    double GetChipExposeTime();
    
    /**
     @fn double GetChipGain()
     @brief get the current gain
     @return
     success return the current expose gain\n
     another QHYCCD_ERROR code on other failures
     */
    double GetChipGain();
    
    /**
     @fn double GetChipSpeed()
     @brief get the current transfer speed
     @return
     success return the current speed level \n
     another QHYCCD_ERROR code on other failures
     */
    double GetChipSpeed();
    
    
    /**
     @fn double GetChipBitsMode()
     @brief get the current camera depth bits
     @return
     success return the current camera depth bits \n
     another QHYCCD_ERROR code on other failures
     */
    double GetChipBitsMode();
    
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
     @fn double InitBIN11Mode()
     @brief init the bin11 mode setting
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN11Mode();
    
    /**
     @fn double InitBIN22Mode()
     @brief init the bin22 mode setting
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN22Mode();
    
    /**
     @fn double InitBIN44Mode()
     @brief init the bin44 mode setting
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t InitBIN44Mode();
    
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
     @fn uint32_t SendOrder2CFW(qhyccd_handle *handle,char *order,uint32_t length)
     @brief send the command to camera's color filter wheel port
     @param handle camera control handle
     @param order the color filter position
	 @param length  the order string length
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SendOrder2CFW(qhyccd_handle *handle,char *order,uint32_t length);

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

	 /** 
	  @fn uint32_t SetStreamMode(qhyccd_handle *handle,uint8_t mode)
      @brief Set the camera's mode to chose the way reading data from camera
      @param handle camera control handle
	  @param mode the stream mode \n
	  0x00:default mode,single frame mode \n
	  0x01:live mode \n
	  @return
	  on success,return QHYCCD_SUCCESS \n
	  another QHYCCD_ERROR code on other failures
     */
	 uint32_t SetStreamMode(qhyccd_handle *handle,uint8_t mode);

	 uint32_t SetTrigerFunction(qhyccd_handle *handle,bool value);

};
#endif

