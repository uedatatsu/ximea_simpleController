///////////////
//ximea_simpleController
//ごく簡単にximeaカメラから画像を取得するプログラム by ueda
//作成日：2019-05-17
//////////////

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	XimeaCamera cam;
	cv::Mat captureImage;
	int camera_width, camera_height;

	cam.init(0);
	captureImage = cam.capture().clone();
	camera_width = captureImage.cols;
	camera_height = captureImage.rows;

	while (true) {
		captureImage = cam.capture();
		cv::imshow("window",captureImage);
		char key = cv::waitKey(30);
		if (key == 'q') {
			exit(0);
		}
	}

}

