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

/*! @file qhy5iiig400m.h
 *  @brief QHY5IIIG400M class define
 */

#include "qhy5iiibase.h"

#ifndef QHY5IIIG400_M_DEF
#define QHY5IIIG400_M_DEF


/**
 * @brief QHY5IIIG400M class define
 *
 * include all functions for qhy5iiig400m
 */
class QHY5IIIG400M:public QHY5IIIBASE
{
public:
    QHY5IIIG400M();
    ~QHY5IIIG400M();
    
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

	uint32_t GetLiveFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData);
    
    /**
     @fn uint32_t SetChipUSBTraffic(qhyccd_handle *h,uint32_t i)
     @brief set hblank
     @param h camera control handle
     @param i hblank value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipUSBTraffic(qhyccd_handle *h,uint32_t i);
    
    uint32_t GetChipMemoryLength();

//private:
//    double pllratio; //!< inter pll ratio
//    uint32_t longtimeflag;
};
#endif
