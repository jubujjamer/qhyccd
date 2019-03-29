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

#include "qhy5iiiddrcoolbase.h"

#ifndef QHY5III290COOLBASE_DEF
#define QHY5III290COOLBASE_DEF

class QHY5III290COOLBASE:public QHY5IIIDDRCOOLBASE {
public:
    QHY5III290COOLBASE();
    ~QHY5III290COOLBASE();
    
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
	void writeCMOS(qhyccd_handle *h,unsigned short index,unsigned char value);
    
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
 
  
    uint32_t SetChipOffset(qhyccd_handle *h,double offset);

    /**
     @fn uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits)
     @brief set the camera depth bits
     @param h camera control handle
     @param bits depth bits
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits);
    
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
};
#endif
