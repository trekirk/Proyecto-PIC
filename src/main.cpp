<<<<<<< HEAD:main.cpp
#include "proy_lib.h"
#include <vector>
#include <iostream>
=======
#include "../include/proy_lib.h"
>>>>>>> jj:src/main.cpp

#define ESCAPE 27

using namespace vision;
<<<<<<< HEAD:main.cpp
using namespace std;
=======
using namespace practica2;
>>>>>>> jj:src/main.cpp

//void ShadowsDetector2(Mat bgImg, Mat fgImg, Mat imgShadow);
/** @function main */
int main( int argc, char** argv )
<<<<<<< HEAD:main.cpp
{ 
	
	Mat img1 = imread("m1.jpg", cv::IMREAD_COLOR);
	//Mat img1 = imread("mandril.jpg", cv::IMREAD_GRAYSCALE);
	//Mat img2 = imread("m2.jpg", cv::IMREAD_GRAYSCALE);
	Mat img2 = imread("rayosx.tif", cv::IMREAD_GRAYSCALE);
	// Mat img_1, img_2;
	
	// cvtColor(img1, img1, CV_BGR2HSV);
	// cvtColor(img2, img2, CV_BGR2HSV);

	// Mat h_chann1(img1.size(), CV_8UC1);
	// Mat h_chann(img2.size(), CV_8UC1);
	// Mat s_chann1(img1.size(), CV_8UC1);
	// Mat s_chann(img2.size(), CV_8UC1);
	// Mat v_chann1(img1.size(), CV_8UC1);
	// Mat v_chann(img2.size(), CV_8UC1);
	// Mat arr_chann1[] = { h_chann1, s_chann1, v_chann1};
	// Mat arr_chann[] = { h_chann, s_chann, v_chann};

	// split(img1, arr_chann1);
	// split(img2, arr_chann);

int histSize = 256;
float range[] = {0,256};
const float* histRange = {range};

Mat h_hist, s_hist, v_hist;

// calcHist(&h_chann, 1, 0, Mat(), h_hist, 1, &histSize, &histRange, true, false);
// calcHist(&s_chann, 1, 0, Mat(), s_hist, 1, &histSize, &histRange, true, false);
// calcHist(&v_chann, 1, 0, Mat(), v_hist, 1, &histSize, &histRange, true, false);

	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

	Mat equalizedHistImage(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

		// normalize(h_hist, h_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	// normalize(s_hist, s_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	// normalize(v_hist, v_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	Mat original_hist, normalized_hist;
	calcHist(&img2, 1, 0, Mat(), original_hist,1,&histSize, &histRange,true,false);
	
	cout << "Original histogram" << endl;

	for (int h = 0; h < histSize; h++)
	{
		float binVal = original_hist.at<float>(h);
		cout << " " << binVal;
	}

	cout << endl;
	Mat equalized_img, equalized_hist, equalized_normalized_hist;
	equalizeHist(img2, equalized_img);
	calcHist(&equalized_img, 1, 0, Mat(), equalized_hist, 1, &histSize, &histRange, true, false);

	cout << "Equal histogram" << endl;
	for(int h = 0; h < histSize; h++)
	{
		float binVal = equalized_hist.at<float>(h);
		cout << " " << binVal;
	}
	cout << endl;



	

	for(int i = 1; i < histSize; i++)
	{
		line(histImage,
		Point(bin_w*(i),hist_w),
		Point(bin_w*(i),hist_h - cvRound(normalized_hist.at<float>(i))),
		Scalar(255,0,0), bin_w, 8,0);
		
		line(equalizedHistImage,
		Point(bin_w*(i),hist_w),
		Point(bin_w*(i),hist_h - cvRound(equalized_normalized_hist.at<float>(i))),
		Scalar(255,0,0), bin_w, 8,0);

	}
	// cout << img1.channels() << endl;
	// cout << img2.channels() << endl;

	// cvtColor(img2, img2, CV_BGR2RGB);
	// cvtColor(img1, img1, CV_BGR2RGB);
	// equalizeHist(img1, img1);
	// equalizeHist(img2, img2);
	// medianBlur(img1, img_1, 3);
	// medianBlur(img2, img_2, 3);

    //matchORB(img_1, img_2);

    //cout<<"Funcionamiento correcto"<<endl;

	imshow("Original picture", img2);
    imshow("histogram", equalized_img);
    imshow("1", histImage);
    imshow("2", equalizedHistImage);
    // imshow("s", s_chann);
    // imshow("v", v_chann);
    //imshow("mandril gris", img1);
    waitKey(0);
    equalized_img.release();
    histImage.release();
    equalized_img.release();
    original_hist.release();
    normalized_hist.release();
    equalized_normalized_hist.release();
=======
{
    //matchSURF("baboon200_rotated.jpg", "baboon200.jpg");
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();

    //matchORB("baboon200_rotated.jpg", "baboon200.jpg");
    cout<<"Funcionamiento correcto"<<endl;
}

/** @function readme */

/*
int main()
{
    //object
   /* Mat img;

    img = cv::imread("mandril.jpg");

    if (!img.data){
        cout << "error loading image" << endl;
        return 1;
    }

    namedWindow("original", WINDOW_AUTOSIZE);

    imshow("original", img);

    waitKey(0);

    destroyWindow("original");
    return 0;
    cout<<"Buenas tardes tenga usted"<<endl;
    piruleta();

    Mat img_original;

    img_original = imread("mandril.jpg", 0);
    if (!img_original.data){
        cout << "error loading image" << endl;
        return 1;
    }

    namedWindow("original", WINDOW_AUTOSIZE);
    namedWindow("histogram", WINDOW_AUTOSIZE);

    int histSize = 256;
    float range[] = { 0, 255 };
    const float *ranges[] = { range };

    Mat hist;
    calcHist(&img_original, 1, 0, Mat(), hist, 1, &histSize, ranges, true, false);


    double total;
    total = img_original.rows *img_original.cols;
    for (int h = 0; h < histSize; h++)
    {
        float binVal = hist.at<float>(h);
        cout << " " << binVal;
    }

    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);

    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));

    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
            Point(bin_w*(i), hist_h - cvRound(hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
    }

    imshow("original", img_original);
    imshow("histogram", histImage);

    waitKey(0);

>>>>>>> jj:src/main.cpp
    destroyAllWindows();
    return 0;
}
	
// void ShadowsDetector2(Mat bgImg, Mat fgImg, Mat imgShadow){
//   //crear bg y fg en espacio hsv
//   Mat FgHsv, BgHsv;
 
//   //transformando a escala de color
//   cvtColor(bgImg, BgHsv, CV_RGB2HSV);
//   cvtColor(fgImg, FgHsv, CV_RGB2HSV);
 
//   vector Fg, Bg;
 
//   split(BgHsv, Bg);
//   split(FgHsv, Fg);
 
//   float	alpha = 0.4;
//   float	beta = 0.9;
//   int umbral_h = 25;
//   int umbral_s = 20;
 
//   Mat a1=Mat::zeros(bgImg.size(), CV_32FC1);
//   Mat a2=Mat::zeros(bgImg.size(), CV_32FC1);
//   Mat a3=Mat::zeros(bgImg.size(), CV_32FC1);
 
//   Mat Bg32 = Mat::zeros(bgImg.size(), CV_32FC1);
//   Mat Fg32 = Mat::zeros(bgImg.size(), CV_32FC1);
 
//   Bg[2].convertTo(Bg32, CV_32FC1);
//   Fg[2].convertTo(Fg32, CV_32FC1);
 
//   divide(Fg32, Bg32, a1);
//   absdiff(Fg[0], Bg[0], a2);
//   absdiff(Fg[1], Bg[1], a3);
 
//   Mat mask1 = Mat::zeros(bgImg.size(), CV_8U);
//   Mat mask2 = Mat::zeros(bgImg.size(), CV_8U);
 
//   inRange( a1, alpha, beta, imgShadow);
//   inRange( a2, -1000, umbral_s, mask1);
//   inRange( a3, -1000, umbral_h, mask2);
 
//   bitwise_and(imgShadow, mask1, imgShadow);
//   bitwise_and(imgShadow, mask2, imgShadow);
 
//   a1.release();
//   a2.release();
//   a3.release();
//   mask1.release();
//   mask2.release();
//   Bg32.release();
//   Fg32.release();
//   BgHsv.release();
//   FgHsv.release();
 
//   Fg.clear();
//   Bg.clear();
// }
