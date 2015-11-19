#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <opencv/cv.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/xfeatures2d/nonfree.hpp"

#define ESCAPE 27

using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;

namespace vision
{
	void readme();
	void matchORB(string image1, string image2);
	void matchSURF(string image1, string image2);
}

namespace practica2
{
	int ejercicio1();
	int ejercicio2();
	int ejercicio3();
	int ejercicio4();
}