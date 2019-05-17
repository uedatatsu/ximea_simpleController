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

		// Start acquisition
		stat = xiStartAcquisition(xiH);
		HandleResult(stat, "xiStartAcquisition");
	}

	cv::Mat capture() {
		stat = xiGetImage(xiH, 5000, &img);
		cv::Mat cvimg(cv::Size((int)img.width, (int)img.height), CV_8UC1);
		cvimg.data = (unsigned char*)img.bp;
		return cvimg;
	}

};