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

void STDCALL Init_3A_AutoExposure(qhyccd_handle *h, double curaec, double curagc);

void STDCALL Release_3A_AutoExposure();

void STDCALL AECAGC(qhyccd_handle *camhandle,IplImage *img, int MessureMethod, int ControlMode);

void STDCALL Init_3A_AutoWhiteBalance(qhyccd_handle *h);

uint32_t STDCALL AutoControlWhiteBlance(qhyccd_handle *h,IplImage *img,uint32_t isglobal,uint32_t x,uint32_t y);

void STDCALL Release_3A_AutoWhiteBalance();

void STDCALL Init_3A_AutoFocus(qhyccd_handle *h);

uint32_t STDCALL GetFocusCandy(IplImage *img, IplImage *outputImg, int x, int y);

void STDCALL Release_3A_AutoFocus();

#endif