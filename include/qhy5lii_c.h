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

/*! @file qhy5lii_c.h
 *  @brief QHY5LII_C class define
 */

#include "qhy5liibase.h"

#ifndef QHY5LII_C_DEF
#define QHY5LII_C_DEF

/**
 * @brief QHY5LII_C class define
 *
 * include all functions for qhy5lii-c
 */
class QHY5LII_C:public QHY5LIIBASE
{
public:
    QHY5LII_C();
    virtual ~QHY5LII_C();
   
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
     @fn virtual uint32_t GetChipMemoryLength()
     @brief get the image cost memory length
     @return
     success return memory length \n
     another QHYCCD_ERROR code on other failures
     */
     uint32_t GetChipMemoryLength();


    
	 uint32_t SetChipGain(qhyccd_handle *h,double gain);

private:
};
#endif
