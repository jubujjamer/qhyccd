#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/qhyccd.h"

// Use exter C to unmangle function names in compiled .so
extern "C" {
  const char *pFirmware = "/usr/local/lib/qhy";

  double VERSION = 1.00;

  int camBinX = 1;
  int camBinY = 1;


  unsigned int roiStartX;
  unsigned int roiStartY;
  unsigned int roiSizeX;
  unsigned int roiSizeY;

  unsigned int overscanStartX;
  unsigned int overscanStartY;
  unsigned int overscanSizeX;
  unsigned int overscanSizeY;

  unsigned int effectiveStartX;
  unsigned int effectiveStartY;
  unsigned int effectiveSizeX;
  unsigned int effectiveSizeY;


  unsigned int channels;
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

  // set single frame mode
  uint32_t set_stream_mode(qhyccd_handle *pCamHandle, int cam_mode){
    uint32_t ret_value;
    // cam_mode = 0; // 0 == single frame mode, 1 = video mode
    ret_value = SetQHYCCDStreamMode(pCamHandle, cam_mode);
    return ret_value;
  }

  // initialize camera
  uint32_t init_camera(qhyccd_handle *pCamHandle){
    uint32_t ret_value;
    ret_value = InitQHYCCD(pCamHandle);
    return ret_value;
  }

  // set exposure time
  uint32_t set_exposure(qhyccd_handle *pCamHandle, int exp_time){
    uint32_t ret_value;
    ret_value = SetQHYCCDParam(pCamHandle, CONTROL_EXPOSURE, exp_time);
    return ret_value;
  }


    ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_GAIN);
    if (QHYCCD_SUCCESS == ret_value){
        ret_value = SetQHYCCDParam(pCamHandle, CONTROL_GAIN, gain);
        if (ret_value == QHYCCD_SUCCESS) {
          printf("CONTROL_GAIN set to: %d, success\n", gain);}
        else {
          printf("CONTROL_GAIN failure, error: %d\n", ret_value);}
    }
    else{
        printf("CONTROL_GAIN is not supported by this model.\n");}
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

      /*Get CCD info_ Chip size, Pixel Size and Image Size*/
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


}
