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

/*! @file qhy5iibase.h
 *  @brief QHY5IIBASE class define
 */

#include "qhybase.h"

#ifndef QHY5IIBASE_DEF
#define QHY5IIBASE_DEF


/**
 * @brief QHY5RII_M class define
 *
 * include all functions for miniCam5s-m
 */
class QHY5IIBASE:public QHYBASE {
public:
    QHY5IIBASE();
    virtual ~QHY5IIBASE();
    
	static void ThreadCountExposureTime(void *p);
 	static void ThreadCancelExposingAndReadout(void *p);

    virtual uint32_t BeginSingleExposure(qhyccd_handle *h);
    virtual uint32_t CancelExposing(qhyccd_handle *handle);
    virtual uint32_t CancelExposingAndReadout(qhyccd_handle *h);
    virtual uint32_t BeginLiveExposure(qhyccd_handle *h);
    virtual uint32_t StopLiveExposure(qhyccd_handle *h);

    virtual uint32_t GetSingleFrame(qhyccd_handle *h, uint32_t *pW, uint32_t *pH, uint32_t * pBpp, uint32_t *pChannels, uint8_t *ImgData);
    virtual uint32_t GetLiveFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData);
       
 	void ThreadCountExposureTimeStart(void *p);
	void ThreadCancelExposingAndReadoutStart(qhyccd_handle *h);
    
    /**
     @fn uint32_t ConnectCamera(qhyccd_device *d,qhyccd_handle **h)
     @brief connect to the connected camera
     @param d camera deivce
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t ConnectCamera(qhyccd_device *d,qhyccd_handle **h);
    
    /**
     @fn uint32_t DisConnectCamera(qhyccd_handle *h)
     @brief disconnect to the connected camera
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t DisConnectCamera(qhyccd_handle *h);

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
     @fn uint32_t ReSetParams2cam(qhyccd_handle *h)
     @brief re set the params to camera,because some behavior will cause camera reset
     @param h camera control handle
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t ReSetParams2cam(qhyccd_handle *h);
    
    /**
     @fn uint32_t SetChipBinMode(qhyccd_handle *h,uint32_t wbin,uint32_t hbin)
     @brief set the camera image bin mode
     @param h camera control handle
     @param wbin width bin
     @param hbin height bin
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipBinMode(qhyccd_handle *h,uint32_t wbin,uint32_t hbin);

    /**
     @fn uint32_t Send2GuiderPort(qhyccd_handle *h,uint32_t Direction,uint16_t PulseTime)
     @brief send the command to camera's guide port
     @param h camera control handle
     @param Direction RA DEC
     @param PulseTime the time last for command
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t Send2GuiderPort(qhyccd_handle *h,uint32_t Direction,uint16_t PulseTime);
    

    /** @fn uint32_t GetChipInfo(double *chipw,double *chiph,uint32_t *imagew,uint32_t *imageh,double *pixelw,double *pixelh)
      @brief get the camera's ccd/cmos chip info
      @param h camera control handle
      @param chipw chip size width
      @param chiph chip size height
      @param imagew chip output image width
      @param imageh chip output image height
      @param pixelw chip pixel size width
      @param pixelh chip pixel size height
      @param bpp chip pixel depth
    */
    uint32_t GetChipInfo(double *chipw,double *chiph,uint32_t *imagew,uint32_t *imageh,double *pixelw,double *pixelh,uint32_t *bpp);
    

    /** @fn uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY)
      @brief Set the camera on focus mode
      @param h camera control handle
      @param focusCenterX
      @param focusCenterY
      @return
	  on success,return QHYCCD_SUCCESS \n
	  another QHYCCD_ERROR code on other failures
     */
     uint32_t SetFocusSetting(qhyccd_handle *h,uint32_t focusCenterX, uint32_t focusCenterY);


     uint32_t SetStreamMode(qhyccd_handle *handle,uint8_t mode);

	 uint32_t SetGuideModeOnOff(qhyccd_handle *h,double mode);

public:
#ifdef WIN32
	 HANDLE hCountExpTimeThread;
	 HANDLE hCancelExposingAndReadoutThread;
#endif
    //uint32_t pllratio; //!< inter pll ratio
    //uint32_t longtimeflag;
    //uint32_t reg300c;
    //uint32_t rgbgainb,rgbgainc;
    //uint32_t rgbgainbluea,rgbgainreda;
	//double wbred,wbblue,wbgreen;
	//uint8_t  islive;
    uint8_t specialdropbychip;
	uint8_t useGuideIn16bitMode;
};
#endif
