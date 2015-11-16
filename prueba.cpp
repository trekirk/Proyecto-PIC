#include <iostream>
#include <cstdio>
#include <opencv/cv.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string.h>
#include "movimiento.cpp"

#include <stdio.h>
#include <vector>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#define ESCAPE 27

using namespace cv;
using namespace std;

void readme();

/** @function main */
int main( int argc, char** argv )
{


        Mat img1 = imread("mandril.jpg",IMREAD_GRAYSCALE);
        Mat img2 = imread("mandril.jpg",IMREAD_GRAYSCALE);
        namedWindow("original", WINDOW_AUTOSIZE);
        namedWindow("histogram", WINDOW_AUTOSIZE);
        imshow("original", img1);
        imshow("histogram", img2);
        
        if(img1.empty() || img2.empty())
        {
            printf("Can't load all the images!");
            return -1;
        }   

//Initialise the Wrapping Class for Surf()
    ORB cacota;
    Ptr<FeatureDetector> detector = FeatureDetector::create("SURF");
    vector<KeyPoint> keypoints1, keypoints2;
    cacota.detect(img1, keypoints1);
    cacota.detect(img2, keypoints2);

    // computing descriptors
    Ptr<DescriptorExtractor> extractor = DescriptorExtractor::create("SURF");
    Mat descriptors1, descriptors2;
    cacota.compute(img1, keypoints1, descriptors1);
    cacota.compute(img2, keypoints2, descriptors2);

//Initialise BruteForceMatcher: For each descriptor in the first set, this matcher finds the closest descriptor in the second set by trying each on (=brute)
    BFMatcher matcher(NORM_L2);
    vector< DMatch > matches;
    matcher.match(descriptors1, descriptors2, matches);

// drawing the results
    namedWindow("matches", 1);
    Mat img_matches;
    drawMatches(img1, keypoints1, img2, keypoints2, matches, img_matches);
    imshow("matches", img_matches);

    waitKey(0);

    return 0;}


//void readme();

/** @function main */
/*int main( int argc, char** argv )
{
    cv::initModule_nonfree();
    if( argc != 3 )
    { readme(); return -1; }

    Mat img_1 = imread( argv[1], IMREAD_GRAYSCALE );
    Mat img_2 = imread( argv[2], IMREAD_GRAYSCALE );

    if( !img_1.data || !img_2.data )
    { std::cout<< " --(!) Error reading images " << std::endl; return -1; }

    //-- Step 1: Detect the keypoints using SURF Detector
    int minHessian = 400;

    SurfFeatureDetector detector( minHessian );

    vector<KeyPoint> keypoints_1, keypoints_2;

    detector.detect( img_1, keypoints_1 );
    detector.detect( img_2, keypoints_2 );

    //-- Draw keypoints
    Mat img_keypoints_1; Mat img_keypoints_2;

    drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    drawKeypoints( img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );

    //-- Show detected (drawn) keypoints
    imshow("Keypoints 1", img_keypoints_1 );
    imshow("Keypoints 2", img_keypoints_2 );

    waitKey(0);

    return 0;
}

/** @function readme */
/*void readme()
{ std::cout << " Usage: ./SURF_detector <img1> <img2>" << std::endl; }
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

    destroyAllWindows();
    return 0;

    Mat img_original, img_modified;
        img_original = imread("mandril.jpg");
        img_original.copyTo(img_modified);
        if (!img_original.data){
            cout << "error loading image" << endl;
            return 1;
        }
        Point center(img_modified.rows / 2, img_modified.cols / 2);
        int radius = 25;
        line(img_original, Point(0, 1)/*, center, Point(0, 0), Scalar(255, 0, 0));

        rectangle(img_modified, center, Point(img_modified.rows,
            img_modified.cols), Scalar(0, 0, 255));

        namedWindow("original", WINDOW_AUTOSIZE);
        namedWindow("modified", WINDOW_AUTOSIZE);

        imshow("original", img_original);
        imshow("modified", img_modified);

        waitKey(0);

        destroyWindow("original");
        destroyWindow("modified");


        return 0;
}*/
