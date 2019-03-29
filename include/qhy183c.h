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

#include "qhy5iii183base.h"

#ifndef _QHY183C_
#define _QHY183C_

class QHY183C:public QHY5III183BASE {
public:
    QHY183C();
    ~QHY183C();

    uint32_t BeginSingleExposure(qhyccd_handle *pDevHandle);
    uint32_t GetSingleFrame(qhyccd_handle *pDevHandle, uint32_t *pW, uint32_t *pH, uint32_t *pBpp, uint32_t *pChannels, uint8_t *pImgData);  

//    uint32_t BeginLiveExposure(qhyccd_handle *pDevHandle);
//    uint32_t StopLiveExposure(qhyccd_handle *pDevHandle);
//    uint32_t GetLiveFrame(qhyccd_handle *pDevHandle, uint32_t *pW, uint32_t *pH, uint32_t *pBpp, uint32_t *pChannels, uint8_t *pImgData);
        
    uint32_t IsChipHasFunction(CONTROL_ID id);
    uint32_t GetChipMemoryLength();
};
#endif
