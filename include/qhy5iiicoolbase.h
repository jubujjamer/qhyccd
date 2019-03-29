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

#include "qhycam.h"
#include "qhyccdcamdef.h"
#include "qhyccderr.h"
#include "log4z.h"
#include "cmosdll.h"
#include "stdint.h"
#include "qhy5iiibase.h"

#ifndef __QHY5IIICOOLBASEDEF_H__
#define __QHY5IIICOOLBASEDEF_H__

class QHY5IIICOOLBASE : public QHY5IIIBASE {

public:
    uint8_t firstcheckfilters;
    
public:
    QHY5IIICOOLBASE();
    virtual ~QHY5IIICOOLBASE();

    double GetChipCoolTemp(qhyccd_handle *pDevHandle);
    double GetChipCoolPWM();   
    uint32_t AutoTempControl(qhyccd_handle *pDevHandle,double ttemp);
    uint32_t SetChipCoolPWM(qhyccd_handle *pDevHandle,double PWM);
    uint32_t SendOrder2CFW(qhyccd_handle *pDevHandle,char *order,uint32_t length);
    uint32_t GetCFWStatus(qhyccd_handle *pDevHandle,char *status);
    uint32_t IsCFWPlugged(qhyccd_handle *pDevHandle);
    uint32_t GetCFWSlotsNum(qhyccd_handle *pDevHandle);
    uint32_t CancelExposing(qhyccd_handle *pDevHandle);
    uint32_t CancelExposingAndReadout(qhyccd_handle *pDevHandle);
};

#endif
