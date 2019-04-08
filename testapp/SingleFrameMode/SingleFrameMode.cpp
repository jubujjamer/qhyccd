// #define OPEN_CV
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../include/qhyccd.h"

#ifdef OPEN_CV
#include <opencv2/opencv.hpp>
#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#endif

int main(int argc, char *argv[]) {

    // parse command line:
    if (7 != argc) {
	printf("Use     : %s image_count exp_time gain offset usb_traffic cmos_speed\n", argv[0]);
	printf("Example : %s 8 10000 5 20 10 0\n", argv[0]);
	printf("Where   : image_count: 8, exp_time: 10000 [us] gain: 5 [ADU], offset: 10 [ADU], usb_traffic: 10 <1;250>, cmos_speed: 0 (0: 12MHz, 1: 24MHz, 2: 48MHz).\n");
	getchar();
	return 1;
    }

    //for (int i = 0; i < argc; i++) {
    //	printf("%d : %s\n", i, argv[i]);
    //}

    // convert command line parameters

    // 1. number of images
    int image_count = atoi(argv[1]);

    // 2. exposure time
    int exp_time = atoi(argv[2]);

    // 3. gain
    int gain = atoi(argv[3]);

    // 4. offset
    int offset = atoi(argv[4]);

    // 5 usb_traffic
    int usb_traffic = atoi(argv[5]);

    // 6. cmos_speed
    int cmos_speed = atoi(argv[6]);

    const char *pFirmware = "/usr/local/lib/qhy";

    double VERSION = 1.00;

    int camBinX = 1;
    int camBinY = 1;

    double chipWidthMM;
    double chipHeightMM;
    double pixelWidthUM;
    double pixelHeightUM;

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

    unsigned int maxImageSizeX;
    unsigned int maxImageSizeY;
    unsigned int bpp;
    unsigned int channels;

#ifdef OPEN_CV
    cv::Mat cvImg;
    int cvImgType;
    bool bNamedWindow = false;
#else
    unsigned char *pImgData = 0;
#endif

    int oldMemLength = 0;

    int cam_count;
    int cam_idx;
    int cam_mode;
    char cam_id[32];
    qhyccd_handle *pCamHandle = 0;
    uint32_t ret_value;

    printf("SingleFrameMode test application, Version: %.2f\n", VERSION);
    printf("This is a simple test application which takes series of images from the first detected QHYCCD USB camera.\n");
    printf("Press any key to start application...\n");
    getchar();

    // first we have to call the InitQHYCCDResource function to initialize SDK
    ret_value = InitQHYCCDResource();
    if (QHYCCD_SUCCESS == ret_value) {
        printf("SDK resources initialized.\n");
    } else {
        printf("Cannot initialize SDK resources, error: %d\n", ret_value);
        return 1;
    }

    do {
        // MacOSX
        // printf("OSXInitQHYCCDFirmware start...\n");
        // OSXInitQHYCCDFirmware(pFirmware);
        // printf("OSXInitQHYCCDFirmware end...\n");

        // scan cameras
		if ((cam_count = ScanQHYCCD()) < 1) {
            printf("No camera found...\n");
            continue;
		}

		// select the first QHYCCD camera and get its ID.
		cam_idx = 0;
		ret_value = GetQHYCCDId(cam_idx, cam_id);
		if (QHYCCD_SUCCESS != ret_value) {
            printf("Cannot get camera ID value: %d,  cameraID = %s\n", (cam_idx + 1), cam_id);
            continue;
		}

        // open camera
        pCamHandle = OpenQHYCCD(cam_id);
        if (0 == pCamHandle) {
            printf("OpenQHYCCD: failure.\n");
            continue;
        }

        // set single frame mode
        cam_mode = 0; // 0 == single frame mode, 1 = video mode
        ret_value = SetQHYCCDStreamMode(pCamHandle, cam_mode);
        if (QHYCCD_SUCCESS != ret_value) {
            printf("SetQHYCCDStreamMode: %d failure, error: %d\n", cam_mode, ret_value);
            continue;
		}

        // initialize camera
        ret_value = InitQHYCCD(pCamHandle);
		if (QHYCCD_SUCCESS != ret_value) {
            printf("InitQHYCCD failure, error: %d\n", ret_value);
            continue;
		}

        // set exposure time
        ret_value = SetQHYCCDParam(pCamHandle, CONTROL_EXPOSURE, exp_time);
        printf("SetQHYCCDParam CONTROL_EXPOSURE set to       : %d, success.\n", exp_time);
        if (QHYCCD_SUCCESS != ret_value) {
            printf("SetQHYCCDParam CONTROL_EXPOSURE failure, error: %d\n", ret_value);
            continue;
        }

        // check/set gain
        ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_GAIN);
        if (QHYCCD_SUCCESS == ret_value) {
            ret_value = SetQHYCCDParam(pCamHandle, CONTROL_GAIN, gain);
            if (ret_value == QHYCCD_SUCCESS) {
                printf("SetQHYCCDParam CONTROL_GAIN set to           : %d, success\n", gain);
            } else {
                printf("SetQHYCCDParam CONTROL_GAIN failure, error: %d\n", ret_value);
            }
        } else {
            printf("SetQHYCCDParam CONTROL_GAIN                  : This function is not supported by this model.\n\n");
        }

        // check/set offset
        ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_OFFSET);
        if (QHYCCD_SUCCESS == ret_value) {
            ret_value = SetQHYCCDParam(pCamHandle, CONTROL_OFFSET, offset);
            if (QHYCCD_SUCCESS == ret_value) {
                printf("SetQHYCCDParam CONTROL_OFFSET set to         : %d, success.\n", offset);
            } else {
                printf("SetQHYCCDParam CONTROL_OFFSET failed.\n");
            }
        } else {
            printf("SetQHYCCDParam CONTROL_OFFSET                : This function is not supported by this model.\n");
        }

        // check/set usb traffic
        ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_USBTRAFFIC);
        if (QHYCCD_SUCCESS == ret_value) {
            ret_value = SetQHYCCDParam(pCamHandle, CONTROL_USBTRAFFIC, usb_traffic);
            if (QHYCCD_SUCCESS == ret_value) {
                printf("SetQHYCCDParam CONTROL_USBTRAFFIC set to     : %d, success.\n", usb_traffic);
            } else {
                printf("SetQHYCCDParam CONTROL_USBTRAFFIC failure, error: %d\n", ret_value);
            }
        } else {
            printf("SetQHYCCDParam CONTROL_USBTRAFFIC            : This function is not supported by this model.\n");
        }

        // check/set control speed
		ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_SPEED);
		if (QHYCCD_SUCCESS == ret_value) {
            ret_value = SetQHYCCDParam(pCamHandle, CONTROL_SPEED, cmos_speed);
            if (QHYCCD_SUCCESS == ret_value) {
                printf("SetQHYCCDParam CONTROL_SPEED set to          : %d, success.\n", cmos_speed);
            } else {
			printf("Set CONTROL_SPEED failure, error: %d\n", ret_value);
            }
		} else {
            printf("SetQHYCCDParam CONTROL_SPEED                 : This function is not supported by this model.\n");
		}

        /*
        // get overscan area
        ret_value = GetQHYCCDOverScanArea(pCamHandle, &overscanStartX, &overscanStartY, &overscanSizeX, &overscanSizeY);
        if (QHYCCD_SUCCESS == ret_value) {
            printf("GetQHYCCDOverScanArea:\n");
            printf("Overscan Area startX x startY : %d x %d\n", overscanStartX, overscanStartY);
            printf("Overscan Area sizeX  x sizeY  : %d x %d\n", overscanSizeX, overscanSizeY);
        } else {
            printf("GetQHYCCDOverScanArea failure, error: %d\n", ret_value);
            continue;
        }
        // get effective area
        ret_value = GetQHYCCDOverScanArea(pCamHandle, &effectiveStartX, &effectiveStartY, &effectiveSizeX, &effectiveSizeY);
        if (QHYCCD_SUCCESS == ret_value) {
            printf("GetQHYCCDEffectiveArea:\n");
            printf("Effective Area startX x startY: %d x %d\n", effectiveStartX, effectiveStartY);
            printf("Effective Area sizeX  x sizeY : %d x %d\n", effectiveSizeX, effectiveSizeY);
        } else {
            printf("GetQHYCCDOverScanArea failure, error: %d\n", ret_value);
            continue;
        }
        */

        // get chip info
        ret_value = GetQHYCCDChipInfo(pCamHandle, &chipWidthMM, &chipHeightMM,
					 &maxImageSizeX, &maxImageSizeY, &pixelWidthUM, &pixelHeightUM, &bpp);
        if (QHYCCD_SUCCESS == ret_value) {
            printf("GetQHYCCDChipInfo:\n");
            printf("Chip  size width x height                    : %.3f x %.3f [mm]\n", chipWidthMM, chipHeightMM);
            printf("Pixel size width x height                    : %.3f x %.3f [um]\n", pixelWidthUM, pixelHeightUM);
            printf("Image size width x height                    : %d x %d\n", maxImageSizeX, maxImageSizeY);
        } else {
            printf("GetQHYCCDChipInfo failure, error: %d\n", ret_value);
            continue;
        }

        // set ROI
        roiStartX = 0;
        roiStartY = 0;
        roiSizeX = maxImageSizeX;
        roiSizeY = maxImageSizeY;

        // check if color/mono camera
        ret_value = IsQHYCCDControlAvailable(pCamHandle, CAM_COLOR);
        if (ret_value == BAYER_GB || ret_value == BAYER_GR || ret_value == BAYER_BG || ret_value == BAYER_RG) {
            printf("This is a color camera                       : %s\n", cam_id);
            SetQHYCCDDebayerOnOff(pCamHandle, true);
            SetQHYCCDParam(pCamHandle, CONTROL_WBR, 20);
            SetQHYCCDParam(pCamHandle, CONTROL_WBG, 20);
            SetQHYCCDParam(pCamHandle, CONTROL_WBB, 20);
        } else {
            printf("This is a mono camera                        : %s\n", cam_id);
        }

        // set image resolution
        ret_value = SetQHYCCDResolution(pCamHandle, roiStartX, roiStartY, roiSizeX, roiSizeY);
        if (QHYCCD_SUCCESS == ret_value) {
            printf("SetQHYCCDResolution roiStartX x roiStartY    : %d x %d\n", roiStartX, roiStartY);
            printf("SetQHYCCDResolution roiSizeX  x roiSizeY     : %d x %d\n", roiSizeX, roiSizeY);
        } else {
            printf("SetQHYCCDResolution failure, error: %d\n", ret_value);
            continue;
        }

        // set binning mode
        ret_value = SetQHYCCDBinMode(pCamHandle, camBinX, camBinY);
        if (QHYCCD_SUCCESS == ret_value) {
            printf("SetQHYCCDBinMode camBinX x camBinY           : %d x %d\n", camBinX, camBinY);
        } else {
            printf("SetQHYCCDBinMode failure, error: %d\n", ret_value);
            continue;
        }

        // set bit resolution
        ret_value = IsQHYCCDControlAvailable(pCamHandle, CONTROL_TRANSFERBIT);
        if (QHYCCD_SUCCESS == ret_value) {
            ret_value = SetQHYCCDBitsMode(pCamHandle, 16);
            if (QHYCCD_SUCCESS == ret_value) {

#ifdef OPEN_CV
                // set opencv image type
        cv::Mat cvImg;
				cvImgType = CV_16UC1;
                // set opencv image size
				cvImg.create(roiSizeY, roiSizeX, cvImgType);
				// sanity check
				if (cvImg.data) {
                    printf("cvImg size cols x rows                       : %d x %d\n", cvImg.cols, cvImg.rows);
				} else {
                    printf("Could create cvImg object...\n");
                    continue;
				}
#endif
                printf("SetQHYCCDParam CONTROL_TRANSFERBIT set to    : %d, success.\n", CONTROL_TRANSFERBIT);
            } else {
                printf("SetQHYCCDParam CONTROL_TRANSFERBIT failure, error: %d\n", ret_value);
                continue;
            }
        }

		printf("\nDo series of %d exposures:\n\n", image_count);

		for (int i = 0; i < image_count; i++) {

            printf("Image no: %d\n", i+1);

            // single frame
            ret_value = ExpQHYCCDSingleFrame(pCamHandle);
            if (QHYCCD_ERROR != ret_value) {
                if (QHYCCD_READ_DIRECTLY != ret_value) {
                    sleep(1);
                }
            } else {
                printf("ExpQHYCCDSingleFrame failure, error: %d\n", ret_value);
                break;
            }

            // check end of exposure
            //uint32_t exp_downcount;
            //
            //do {
            //    exp_downcount = GetQHYCCDExposureRemaining(pCamHandle);
            //    printf("GetQHYCCDExposureRemaining                   : %d [us]\n", exp_downcount);
            //    sleep(1);
            //} while (exp_downcount > 0);

#ifdef OPEN_CV

            // get single frame
            ret_value = GetQHYCCDSingleFrame(
                    pCamHandle,
                    &roiSizeX,
                    &roiSizeY,
                    &bpp,
                    &channels,
                    cvImg.ptr<uint8_t>(0));

#else
            // get requested memory length
            uint32_t length = GetQHYCCDMemLength(pCamHandle);
            //printf("GetQHYCCDMemLength: %d [bytes]\n", length);

            if (0 == pImgData) {
				pImgData = new unsigned char[length];
				oldMemLength = length;
				printf("Frame memory of %d bytes allocated...\n", length);
            } else if (oldMemLength != length) {
				delete [] pImgData;
				pImgData = new unsigned char[length];
				oldMemLength = length;
				printf("Frame memory of %d bytes allocated...\n", length);
            }

            // get single frame
            ret_value = GetQHYCCDSingleFrame(pCamHandle, &roiSizeX, &roiSizeY, &bpp, &channels, pImgData);

#endif

            if (QHYCCD_SUCCESS == ret_value) {

#ifdef OPEN_CV
                // show frame
            	//printf("GetQHYCCDSingleFrame: %d x %d, bpp: %d, channels: %d, done...\n", roiSizeX, roiSizeY, bpp, channels);
								// cv::Mat gray_image;
 								// cv::cvtColor( cvImg, gray_image, CV_BGR2GRAY );
								cv::imwrite( "Gray_Image.tiff", cvImg);
								cv::imshow("imgWin", cvImg);
                cvWaitKey(10);
#else
            	printf("GetQHYCCDSingleFrame: %d x %d, bpp: %d, channels: %d, done...\n", roiSizeX, roiSizeY, bpp, channels);
#endif
				//process image here
            } else {
				printf("GetQHYCCDSingleFrame failure, error: %d\n", ret_value);
            }

		} // for number of images

    } while (0);

    ret_value = CancelQHYCCDExposingAndReadout(pCamHandle);
    if (QHYCCD_SUCCESS != ret_value) {
       	printf("CancelQHYCCDExposingAndReadout failure, error: %d\n", ret_value);
    }

    // close camera handle
    ret_value = CloseQHYCCD(pCamHandle);
    if (QHYCCD_SUCCESS == ret_value) {
        printf("Close QHYCCD success.\n");
    } else {
        printf("Close QHYCCD failure, error: %d\n", ret_value);
    }

    // We have to call ReleaseQHYCCDResource function to release libusb
    // and other sdk resources
    ret_value = ReleaseQHYCCDResource();
    if (QHYCCD_SUCCESS == ret_value) {
        printf("SDK resources released.\n");
    } else {
        printf("Cannot release SDK resources, error %d.\n", ret_value);
    }

#ifdef OPEN_CV
    if (bNamedWindow) {
        cv::destroyWindow("imgWin");
    }
#else
    if (0 != pImgData) {
		delete [] pImgData;
    }
#endif

    printf("Press any key to exit application...\n");
    getchar();
    return 0;
}
