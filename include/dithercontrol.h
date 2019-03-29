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
 * @file dithercontrol.h
 * @brief QHYCCD SDK control PHD2 dither
 */

#include "qhyccdstruct.h"


#ifndef __QHYCCDDITHERDEF_H__
#define __QHYCCDDITHERDEF_H__

EXPORTC uint32_t STDCALL CheckPHD2Status(char *retstr);
EXPORTC uint32_t STDCALL Connect2PHD2();
EXPORTC uint32_t STDCALL DisConnect2PHD2();
EXPORTC uint32_t STDCALL ControlPHD2Dither(uint32_t level,double settle);
EXPORTC uint32_t STDCALL PausePHD2Dither();

#endif