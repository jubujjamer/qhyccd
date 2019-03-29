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

/*! @file minicam5s_c.h
 *  @brief MINICAM5S_C class define
 */

#include "minicam5base.h"

#ifndef MINICAM5S_C_DEF
#define MINICAM5S_C_DEF


/**
 * @brief MINICAM5S_C class define
 *
 * include all functions for miniCam5s-c
 */
class MINICAM5S_C:public MINICAM5BASE
{
public:
    MINICAM5S_C();
    ~MINICAM5S_C();
  
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
     @fn uint32_t IsChipHasFunction(CONTROL_ID id)
     @brief check the camera has the function or not
     @param id function id
     @return
     HAVE return QHYCCD_HAVE \n
     NOT HAVE return QHYCCD_NOTHAVE
     */
    uint32_t IsChipHasFunction(CONTROL_ID id);

    uint32_t SetChipGain(qhyccd_handle *h,double gain);
    
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

	/**
     @fn virtual uint32_t GetChipMemoryLength()
     @brief get the image cost memory length
     @return
     success return memory length \n
     another QHYCCD_ERROR code on other failures
     */
     uint32_t GetChipMemoryLength();
  
};
#endif
