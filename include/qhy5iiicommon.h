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

/*! @file qhy367m.h
 *  @brief QHY367M class define
 */

#include "qhy5iiibase.h"

#ifndef QHY5IIICOMMONBASE_DEF
#define QHY5IIICOMMONBASE_DEF

/**
 * @brief QHY367M class define
 *
 * include all functions for qhy367m
 */
class QHY5IIICOMMON:public QHY5IIIBASE {
public:
    QHY5IIICOMMON();
    virtual ~QHY5IIICOMMON();

    uint32_t BeginLiveExposure(qhyccd_handle *h);
    uint32_t StopLiveExposure(qhyccd_handle *h);

	uint32_t InitChipRegs(qhyccd_handle *h);
    uint32_t SetChipGain(qhyccd_handle *h,double gain);
    uint32_t SetChipWBRed(qhyccd_handle *h,double red);
    uint32_t SetChipWBGreen(qhyccd_handle *h,double green);
    uint32_t SetChipWBBlue(qhyccd_handle *h,double blue);
    uint32_t SetChipExposeTime(qhyccd_handle *h,double i);
    uint32_t GetControlMinMaxStepValue(CONTROL_ID controlId,double *min,double *max,double *step);
    uint32_t SetChipOffset(qhyccd_handle *h,double offset);
    uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits);
    uint32_t SetChipResolution(qhyccd_handle *handle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY);
    uint32_t GetChipMemoryLength();
    uint32_t IsChipHasFunction(CONTROL_ID controlId);
};
#endif
