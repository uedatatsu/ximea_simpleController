#pragma once
#include <xiApi.h>
#include <opencv2/opencv.hpp>		

#define HandleResult(res, place)                 \
  if (res != XI_OK) {                            \
    printf("Error after %s (%d)\n", place, res); \
    exit(1);                                     \
  }

class XimeaCamera {
public:
	XimeaCamera() {};
	~XimeaCamera() {};

private:
	HANDLE xiH = NULL;
	XI_RETURN stat = XI_OK;
	// Allocate memory for ximea image
	XI_IMG img;

public:
	int isColor = 0;
	void init(int _cameraID) {
		memset(&img, 0, sizeof(img));
		img.size = sizeof(XI_IMG);

		// Connect to camera
		stat = xiOpenDevice(0, &xiH);
		HandleResult(stat, "xiOpenDevice");

		// Configuration
		stat = xiSetParamInt(xiH, XI_PRM_EXPOSURE, 20000);
		HandleResult(stat, "xiGetParam (exposure)");
		stat = xiSetParamFloat(xiH, XI_PRM_GAIN, 3);
		HandleResult(stat, "xiGetParam (gain)");
		stat = xiSetParamFloat(xiH, XI_PRM_GAMMAY, 1.0);
		HandleResult(stat, "xiGetParam (gamma y)");

		// Check color or mono
		stat = xiGetParamInt(xiH, XI_PRM_IMAGE_IS_COLOR, &isColor);
		HandleResult(stat, "xiGetParam (isColor)");

		// for color cameras
		if (isColor) {
			stat = xiSetParamInt(xiH, XI_PRM_IMAGE_DATA_FORMAT, XI_RGB24);
			HandleResult(stat, "xiGetParam (imgdataformat)");
			stat = xiSetParamInt(xiH, XI_PRM_AUTO_WB, 1);
			HandleResult(stat, "xiGetParam (auto_wb)");
		}
		// for mono cameras
		else {
			stat = xiSetParamInt(xiH, XI_PRM_IMAGE_DATA_FORMAT, XI_MONO8);
			HandleResult(stat, "xiGetParam (imgdataformat)");
		}

		// Start acquisition
		stat = xiStartAcquisition(xiH);
		HandleResult(stat, "xiStartAcquisition");
	}

	cv::Mat capture() {
		int format = CV_8UC1;
		if (isColor)format = CV_8UC3;
		stat = xiGetImage(xiH, 5000, &img);
		cv::Mat cvimg(cv::Size((int)img.width, (int)img.height), format);
		cvimg.data = (unsigned char*)img.bp;
		return cvimg;
	}

};