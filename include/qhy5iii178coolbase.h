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

/*! @file qhy5iii178coolbase.h
 *  @brief QHY5III178COOLBASE_DEF class define
 */

#ifndef _QHY5III178COOLBASE_
#define _QHY5III178COOLBASE_

#include "qhy5iiiddrcoolbase.h"

/**
 * @brief QHY5III178COOLBASE_DEF class define
 *
 * include all functions for qhy5iii178base
 */
class QHY5III178COOLBASE:public QHY5IIIDDRCOOLBASE {
public:
    QHY5III178COOLBASE();
    ~QHY5III178COOLBASE();

	uint32_t BeginSingleExposure(qhyccd_handle *h);
    uint32_t CancelExposing(qhyccd_handle *h);
	uint32_t CancelExposingAndReadout(qhyccd_handle *h);
	uint32_t GetSingleFrame(qhyccd_handle *h, uint32_t *pW, uint32_t *pH, uint32_t * pBpp, uint32_t *pChannels, uint8_t *ImgData);
	uint32_t BeginLiveExposure(qhyccd_handle *h);
	uint32_t StopLiveExposure(qhyccd_handle *h);

	void WriteCMOS(qhyccd_handle *handle,uint16_t index,uint16_t val);
	void WriteCMOSSHS(qhyccd_handle *handle,uint32_t val);
	void WriteCMOSOffset(qhyccd_handle *handle,uint32_t val);
	void WriteCMOSGain(qhyccd_handle *handle,uint32_t val);
    uint32_t SetChipGain(qhyccd_handle *h,double gain);
    uint32_t SetChipExposeTime(qhyccd_handle *h,double i);
    uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId,double *min,double *max,double *step);
    uint32_t SetChipOffset(qhyccd_handle *h,double offset);
    uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits);
    uint32_t SetChipResolution(qhyccd_handle *handle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY);
    uint32_t SetStreamMode(qhyccd_handle *handle,uint8_t mode);
    uint32_t DisConnectCamera(qhyccd_handle *h);
	static void ThreadCountExposureTime(void *p);
	void ThreadCountExposureTimeStart(qhyccd_handle *h);
    uint32_t GeDDRBufferThreshold();

private:
    unsigned int ApproxDDR;
    unsigned int ApproxDDR_Target;
};

#endif
