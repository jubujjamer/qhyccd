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
 * @file qhy28.h
 * @brief QHY28 class define
 */

#include "qhyabase.h"

#ifndef __QHY28DEF_H__
#define __QHY28DEF_H__

/**
 * @brief QHY28 class define
 *
 * include all functions for QHY27
 */
class QHY28:public QHYABASE
{
public:
    QHY28();
    ~QHY28();

	uint32_t SetChipResolution(qhyccd_handle *h,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
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

	uint32_t SetFocusSetting(qhyccd_handle *h, uint32_t focusCenterX, uint32_t focusCenterY);
};
#endif

