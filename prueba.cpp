#include <iostream>
#include <opencv2/opencv.hpp>
#define ESCAPE 27

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
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
    return 0;*/

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
/*
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
        destroyWindow("modified");*/


        return 0;
}
