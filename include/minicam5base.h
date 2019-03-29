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

/*! @file minicam5f_m.h
 *  @brief MINICAM5S_M class define
 */

#include "qhy5liibase.h"

#ifndef MINICAM5BASE_DEF
#define MINICAM5BASE_DEF


/**
 * @brief MINICAM5S_M class define
 *
 * include all functions for miniCam5s-m
 */
class MINICAM5BASE:public QHY5LIIBASE
{
public:
    MINICAM5BASE();
    ~MINICAM5BASE();
            
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
     @fn void SetAnalogGain(double gain)
     @brief set gain to camera,here it is the bottom
     @param gain gain value
     */
    void SetAnalogGain(qhyccd_handle *h,double gain);

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

	 /** 
	  @fn uint32_t GetCFWStatus(qhyccd_handle *handle,char *status)
      @brief get the color filter wheel status
      @param handle camera control handle
	  @param status the color filter wheel position status
	  @return
	  on success,return QHYCCD_SUCCESS \n
	  another QHYCCD_ERROR code on other failures
    */
	uint32_t GetCFWStatus(qhyccd_handle *handle,char *status);

private:
    //uint32_t expmode;  //!< expose time mode
    //double pllratio; //!< inter pll ratio
    //uint32_t longtimeflag;

	double lastTargetTemp;
	double  lastPWM;
};
#endif
