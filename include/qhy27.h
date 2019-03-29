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
 * @file qhy27.h
 * @brief QHY27 class define
 */

#include "qhyabase.h"

#ifndef __QHY27DEF_H__
#define __QHY27DEF_H__

/**
 * @brief QHY27 class define
 *
 * include all functions for QHY27
 */
class QHY27:public QHYABASE
{
public:
    QHY27();
    ~QHY27();
    
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
      @fn uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY)
      @brief Set the camera on focus mode
      @param h camera control handle
      @param focusCenterX
      @param focusCenterY
      @return
	  on success,return QHYCCD_SUCCESS \n
	  another QHYCCD_ERROR code on other failures
     */
     uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY);
   
     double GetChipCoolPWM();

     uint32_t AutoTempControl(qhyccd_handle *h,double ttemp);

     uint32_t SetChipCoolPWM(qhyccd_handle *h,double PWM);

     double GetChipCoolTemp(qhyccd_handle *h);

	 /** 
	  @fn uint32_t SendOrder2CFW(qhyccd_handle *handle,char *order,uint32_t length)
      @brief control color filter wheel 
      @param handle camera control handle
	  @param order order send to color filter wheel
	  @param length the order string length
	  @return
	  on success,return QHYCCD_SUCCESS \n
	  another QHYCCD_ERROR code on other failures
    */
	 uint32_t SendOrder2CFW(qhyccd_handle *handle,char *order,uint32_t length);

private:
     double lastTargetTemp;
     double  lastPWM;
};
#endif

