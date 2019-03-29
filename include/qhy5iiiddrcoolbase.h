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

#include "qhy5iiicoolbase.h"

#ifndef QHY5IIIDDRCOOLBASE_DEF
#define QHY5IIIDDRCOOLBASE_DEF

class QHY5IIIDDRCOOLBASE : public QHY5IIICOOLBASE {
public:    
    double pllratio; 
    uint32_t hmax_ref,vmax_ref;
    uint32_t hmax,vmax;
    uint16_t vwinpos,vwidcut;
    uint32_t patchvnumberstart;

    public:
    QHY5IIIDDRCOOLBASE();
    virtual ~QHY5IIIDDRCOOLBASE();
    
    uint32_t BeginSingleExposure(qhyccd_handle *h);
    uint32_t CancelExposing(qhyccd_handle *h);
    uint32_t CancelExposingAndReadout(qhyccd_handle *h);
    uint32_t BeginLiveExposure(qhyccd_handle *h);
    uint32_t StopLiveExposure(qhyccd_handle *h);
    
    uint32_t DisConnectCamera(qhyccd_handle *h);
};

#endif
