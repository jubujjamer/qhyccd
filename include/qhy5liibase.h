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

#include "qhy5iibase.h"

#ifndef QHY5LIIBASE_DEF
#define QHY5LIIBASE_DEF

/**
 * @brief QHY5LII_C class define
 *
 * include all functions for qhy5lii-c
 */
class QHY5LIIBASE:public QHY5IIBASE {
public:
    QHY5LIIBASE();
    virtual ~QHY5LIIBASE();
   
    virtual uint32_t BeginSingleExposure(qhyccd_handle *h);
    virtual uint32_t CancelExposing(qhyccd_handle *h);
    virtual uint32_t CancelExposingAndReadout(qhyccd_handle *h);
    virtual uint32_t BeginLiveExposure(qhyccd_handle *h);
    virtual uint32_t StopLiveExposure(qhyccd_handle *h);

    virtual uint32_t GetSingleFrame(qhyccd_handle *h, uint32_t *pW, uint32_t *pH, uint32_t * pBpp, uint32_t *pChannels, uint8_t *ImgData);
    virtual uint32_t GetLiveFrame(qhyccd_handle *h,uint32_t *pW,uint32_t *pH,uint32_t * pBpp,uint32_t *pChannels,uint8_t *ImgData);

    /**
     @fn void InitCmos(qhyccd_handle *h)
     @brief Init the registers
     @param h camera control handle
     */
    void InitCmos(qhyccd_handle *h);

	double GetChipCoolTemp(qhyccd_handle *h);
    /**
     @fn uint32_t SetChipGain(qhyccd_handle *h,double gain)
     @brief set the gain to camera
     @param h camera control handle
     @param gain gain value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    
	uint32_t SetChipGain(qhyccd_handle *h,double gain);

    uint32_t SetChipWBRed(qhyccd_handle *h,double red);

    uint32_t SetChipWBGreen(qhyccd_handle *h,double green);

    uint32_t SetChipWBBlue(qhyccd_handle *h,double blue);

    /**
     @fn uint32_t SetChipExposeTime(qhyccd_handle *h,double time)
     @brief set the expose time to camera
     @param h camera control handle
     @param time expose time value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipExposeTime(qhyccd_handle *h,double time);
    
    /**
     @fn uint32_t SetChipSpeed(qhyccd_handle *h,uint32_t i)
     @brief set the transfer speed to camera
     @param h camera control handle
     @param i speed level
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipSpeed(qhyccd_handle *h,uint32_t i);    
    
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
     @fn uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits)
     @brief set the camera depth bits
     @param h camera control handle
     @param bits depth bits
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipBitsMode(qhyccd_handle *h,uint32_t bits);
    
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
    @fn uint32_t SetChipResolution(qhyccd_handle *handle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize)
    @brief set camera ouput resolution
    @param handle camera control handle
    @param x the top left position x
    @param y the top left position y
    @param xsize the image width
    @param ysize the image height
    @return
    on success,return QHYCCD_SUCCESS\n
    another QHYCCD_ERROR code on other failures
    */
    uint32_t SetChipResolution(qhyccd_handle *handle,uint32_t x,uint32_t y,uint32_t xsize,uint32_t ysize);
    
    /**
     @fn uint32_t SetChipUSBTraffic(qhyccd_handle *h,uint32_t i)
     @brief set hblank
     @param h camera control handle
     @param i hblank value
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    uint32_t SetChipUSBTraffic(qhyccd_handle *h,uint32_t i);
  
    /**
     @fn double SetPll(qhyccd_handle *h,uint8_t clk)
     @brief set the cmos inter pll
     @param h camera control handle
     @param clk clock
     @return
     success return QHYCCD_SUCCESS \n
     another QHYCCD_ERROR code on other failures
     */
    double SetPll(qhyccd_handle *h,uint8_t clk);
    
    /**
     @fn void SWIFT_MSBLSB(uint8_t *ImgData)
     @brief switch the image pixel data to right position
     @param ImgData image buffer
     */
    void SWIFT_MSBLSB(uint8_t *ImgData);

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

	 void UpdateParameters(qhyccd_handle *h);
	 void ResetParameters();

	uint32_t expmode;  //!< expose time mode
	double pllratio; //!< inter pll ratio
	uint32_t longtimeflag;

    uint32_t timerregs,oldtimerregs,reg3012,oldreg3012,reg300c,oldreg300c;
	uint32_t reg30b0,oldreg30b0,reg3ee4,oldreg3ee4;
	uint32_t reg3058,oldreg3058,reg305a,oldreg305a,reg305c,oldreg305c,reg3056,oldreg3056;
	uint32_t reg305e,oldreg305e;
	uint32_t reg3064,oldreg3064;
	uint32_t reg302a,oldreg302a,reg302c,oldreg302c,reg302e,oldreg302e,reg3030,oldreg3030,reg3082,oldreg3082;
    uint32_t reg3002,oldreg3002,reg3004,oldreg3004,reg3006,oldreg3006,reg3008,oldreg3008,reg300a,oldreg300a,reg301a,oldreg301a;

	uint32_t oldchipoutputsizex,oldchipoutputsizey,oldchipoutputbits;
	uint32_t oldusbspeed;
	uint32_t oldlongtimeflag;
};
#endif
