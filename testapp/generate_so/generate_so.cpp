#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/qhyccd.h"

// Use exter C to unmangle function names in compiled .so
extern "C" {
  const char *pFirmware = "/usr/local/lib/qhy";

  double VERSION = 1.00;

  // Overscan is not yet implemented
  unsigned int overscanStartX;
  unsigned int overscanStartY;
  unsigned int overscanSizeX;
  unsigned int overscanSizeY;

  unsigned int effectiveStartX;
  unsigned int effectiveStartY;
  unsigned int effectiveSizeX;
  unsigned int effectiveSizeY;

  // bool bNamedWindow = false;
  int oldMemLength = 0;

  /* Init SDK resources */
  uint32_t init_resource(void){
      uint32_t ret_value;
      // first we have to call the InitQHYCCDResource function to initialize SDK
      ret_value = InitQHYCCDResource();
      return ret_value;
    }

  /* Scan available cameras*/
  int scan_cameras(){
    int cam_count;
    cam_count = ScanQHYCCD();
    return cam_count;
    }

  /* Get camera ID */
  char cam_id[32];
  char * get_camera_id(int cam_idx){
    uint32_t ret_value;
    ret_value = GetQHYCCDId(cam_idx, cam_id);
    return cam_id;
  }

  // open camera
  qhyccd_handle *open_camera(char * cam_id){
    qhyccd_handle *pCamHandle = 0;
    pCamHandle = OpenQHYCCD(cam_id);
    return pCamHandle;
    }

  // Set single frame mode
  uint32_t set_stream_mode(qhyccd_handle *pCamHandle, int cam_mode){
    uint32_t ret_value;
    // cam_mode = 0; // 0 == single frame mode, 1 = video mode
    ret_value = SetQHYCCDStreamMode(pCamHandle, cam_mode);
    return ret_value;
  }

  /* initialize camera
  This function will initialize the camera hardware and other basic settings.
  It should be call after SetQHYCCDStreamMode(). After calling this function,
  the camera hardware will be ready to use. The SDK will initialize some basic
  settings like the image bit depth, ROI, exposure time etc. These parameters
  can also be changed later with the Parameter Command (SetQHYCCDParam()).*/
  uint32_t init_camera(qhyccd_handle *pCamHandle){
    uint32_t ret_value;
    ret_value = InitQHYCCD(pCamHandle);
    return ret_value;
  }

  // Setting exposure time
  uint32_t set_exposure(qhyccd_handle *pCamHandle, int exp_time){
    uint32_t ret_value;
    ret_value = SetQHYCCDParam(pCamHandle, CONTROL_EXPOSURE, exp_time);
    return ret_value;
  }

  // Setting gain
  uint32_t set_gain(qhyccd_handle *pCamHandle, int gain){
    uint32_t ret_value;
    ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_GAIN);
    if (QHYCCD_SUCCESS == ret_value){
        ret_value = SetQHYCCDParam(pCamHandle, CONTROL_GAIN, gain);}
    return ret_value;
    }

    // Setting offset
    uint32_t set_offset(qhyccd_handle *pCamHandle, int offset){
      uint32_t ret_value;
      ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_OFFSET);
      if (QHYCCD_SUCCESS == ret_value) {
          ret_value = SetQHYCCDParam(pCamHandle, CONTROL_OFFSET, offset);
          if (QHYCCD_SUCCESS == ret_value) {
              printf("CONTROL_OFFSET set to: %d, success.\n", offset);}
          else {
              printf("CONTROL_OFFSET failed.\n");}
      }
      else {
          printf("CONTROL_OFFSET not supported by this model.\n");}
      return ret_value;
    }

    // check/set usb traffic
    uint32_t set_usb_traffic(qhyccd_handle *pCamHandle, int usb_traffic){
      uint32_t ret_value;
      ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_USBTRAFFIC);
      if (QHYCCD_SUCCESS == ret_value) {
          ret_value = SetQHYCCDParam(pCamHandle, CONTROL_USBTRAFFIC, usb_traffic);
          if (QHYCCD_SUCCESS == ret_value) {
              printf("CONTROL_USBTRAFFIC set to: %d, success.\n", usb_traffic);
          } else {
              printf("CONTROL_USBTRAFFIC failure, error: %d\n", ret_value);
          }
      } else {
          printf("CONTROL_USBTRAFFIC not supported by this model.\n");}
          return ret_value;

  }

    // check/set control speed
    uint32_t set_control_speed(qhyccd_handle *pCamHandle, int cmos_speed){
      uint32_t ret_value;
      ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_SPEED);
      if (QHYCCD_SUCCESS == ret_value) {
              ret_value = SetQHYCCDParam(pCamHandle, CONTROL_SPEED, cmos_speed);
              if (QHYCCD_SUCCESS == ret_value) {
                  printf("CONTROL_SPEED set to: %d, success.\n", cmos_speed);
              } else {
        printf("Set CONTROL_SPEED failure, error: %d\n", ret_value);}
      } else {
              printf("CONTROL_SPEED not supported by this model.\n");}
      return ret_value;
      }

      /*Get CCD info, Chip size, Pixel Size and Image Size*/
      uint32_t get_ccd_info(qhyccd_handle *pCamHandle){
        uint32_t ret_value;
        double chipWidthMM;
        double chipHeightMM;
        double pixelWidthUM;
        double pixelHeightUM;
        unsigned int maxImageSizeX;
        unsigned int maxImageSizeY;
        unsigned int bpp;
        ret_value = GetQHYCCDChipInfo(pCamHandle, &chipWidthMM, &chipHeightMM, &maxImageSizeX, &maxImageSizeY, &pixelWidthUM, &pixelHeightUM, &bpp);
        printf("GetQHYCCDChipInfo:\n");
        printf("Chip  size width x height: %.3f x %.3f [mm]\n", chipWidthMM, chipHeightMM);
        printf("Pixel size width x height: %.3f x %.3f [um]\n", pixelWidthUM, pixelHeightUM);
        printf("Image size width x height: %d x %d\n", maxImageSizeX, maxImageSizeY);
        return ret_value;
    }

    /*Dummy*/
    uint32_t is_color(qhyccd_handle *pCamHandle){
      uint32_t ret_value;
      ret_value = IsQHYCCDControlAvailable(pCamHandle, CAM_COLOR);
      if (ret_value == BAYER_GB || ret_value == BAYER_GR || ret_value == BAYER_BG || ret_value == BAYER_RG) {
          SetQHYCCDDebayerOnOff(pCamHandle, true);
          SetQHYCCDParam(pCamHandle, CONTROL_WBR, 20);
          SetQHYCCDParam(pCamHandle, CONTROL_WBG, 20);
          SetQHYCCDParam(pCamHandle, CONTROL_WBB, 20);}
      return ret_value;}

    /* Setting camera ROI.
    These settings depend on the camera binning (see set_bin_mode())
    In the example this parameters are set as

    SetQHYCCDResolution(pCamHandle, 0, 0, maxImageSizeX, maxImageSizeY)
    */
    uint32_t set_resolution(qhyccd_handle *pCamHandle, unsigned int roiStartX, unsigned int roiStartY, unsigned int roiSizeX ,unsigned int roiSizeY){
      uint32_t ret_value;
      ret_value = SetQHYCCDResolution(pCamHandle, roiStartX, roiStartY, roiSizeX, roiSizeY);
      return ret_value;}

    /*Setting binning mode. In EZCap the available values are camBinX=camBinY=1 or 2*/
    uint32_t set_bin_mode(qhyccd_handle *pCamHandle, int camBinX, int camBinY){
      uint32_t ret_value;
      ret_value = SetQHYCCDBinMode(pCamHandle, camBinX, camBinY);
      return ret_value;}

    /*Set bit depth of the images.
    This funcion is not documented. I'll check some values to see watch it's behavior.
    In the example bits = 16 is used. CHECK
    */
    uint32_t set_bits_mode(qhyccd_handle *pCamHandle){
      uint32_t ret_value;
      char bits = 16;
      ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_TRANSFERBIT);
      if (QHYCCD_SUCCESS == ret_value) {
          ret_value = SetQHYCCDBitsMode(pCamHandle, bits);}
      return ret_value;}

    /*Start exposure*/
    uint32_t expose_frame(qhyccd_handle *pCamHandle){
      uint32_t ret_value;
      ret_value = ExpQHYCCDSingleFrame(pCamHandle);
      if (QHYCCD_ERROR != ret_value) {
          if (QHYCCD_READ_DIRECTLY != ret_value) {
              sleep(1);}
          }
      return ret_value;
    }

    /*Get memory length.
    */
    uint32_t get_memory_length(qhyccd_handle *pCamHandle){
      uint32_t length = GetQHYCCDMemLength(pCamHandle);
      return length;}

    /*Get single frame.
    I put length as an argument, but it should match with that of
    GetQHYCCDMemLength().
    I don't know if ROI sizes should match with those from set_resolution.
    I don't know why pImgData are defined as unsigned chars, as they should be
    16 bits arrays. One possibility is that the lenght doubles the real length
    of the array. CHECK.
    */
    unsigned char * get_single_frame(qhyccd_handle *pCamHandle, unsigned int roiSizeX, unsigned int roiSizeY, unsigned int bpp, unsigned int channels, uint32_t length){
      uint32_t ret_value;
      unsigned char *pImgData = 0;
      pImgData = new unsigned char[length];
      ret_value = GetQHYCCDSingleFrame(pCamHandle, &roiSizeX, &roiSizeY, &bpp, &channels, pImgData);
      return pImgData;}

    /*Canceling exposure*/
    uint32_t cancel_exposure(qhyccd_handle *pCamHandle){
      uint32_t ret_value;
      ret_value = CancelQHYCCDExposingAndReadout(pCamHandle);
      return ret_value;}

    /*Closing the camera port*/
    uint32_t close_camera(qhyccd_handle *pCamHandle){
      uint32_t ret_value;
      ret_value = CloseQHYCCD(pCamHandle);
      return ret_value;}

    /*Release the SDK resources*/
    uint32_t release(void){
      uint32_t ret_value;
      ret_value = ReleaseQHYCCDResource();
      return ret_value;}

    /*Dummy*/
    uint32_t dummy(qhyccd_handle *pCamHandle){
      uint32_t ret_value;
      // ret_value = Dummy(pCamHandle);
      return ret_value;}

}
