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

#include "qhybase.h"
#include "stdint.h"

#ifdef WIN32

EXPORTC uint32_t STDCALL VirutalCamInit(qhyccd_handle *h);

EXPORTC uint32_t STDCALL VirualCamRelease();

EXPORTC uint32_t STDCALL VirualCamPlayVideoDevice(int32_t no);

EXPORTC uint32_t STDCALL VirualCamPlayBuffer(uint8_t *buffer,uint32_t width,uint32_t height);

EXPORTC uint32_t STDCALL VirualCamAddOverlay(bool on,uint8_t *buffer,uint32_t width,uint32_t height);

EXPORTC uint32_t STDCALL VirualCamAddText(bool on,char *oltext,char *ftname,int32_t ftsize,int32_t ftstyle,int32_t ftcolor,int32_t bkcolor,int32_t px,int32_t py,int32_t bktype,int32_t whichone);

EXPORTC uint32_t STDCALL VirualCamStopPlay();

EXPORTC uint32_t STDCALL VirualCamChnageDefaultSettings(uint32_t fps,uint8_t videosize);

EXPORTC uint32_t STDCALL VirtualCamGet_CurrentVideoDuration(uint32_t *duration);

EXPORTC uint32_t STDCALL VirtualCamGet_CurrentVideoPosition(uint32_t *position);

EXPORTC uint32_t STDCALL VirtualCamGet_IsPlaying(bool *isplaying);

#endif