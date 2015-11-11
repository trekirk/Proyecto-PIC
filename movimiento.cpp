#include <opencv/cv.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string.h>

using namespace std;
using namespace cv;

 int main()
{
  Mat img, img_canny, drawing;
  img = imread("/home/juanmanuel/Documentos/OCV_projects/diablo.png");
  namedWindow( "Demonio Tasmania", cv::WINDOW_AUTOSIZE );
  namedWindow( "Demonio Tasmania1", cv::WINDOW_AUTOSIZE );
  vector<vector<Point> > cnt;
  cvtColor(img, img, CV_BGR2GRAY);
  imshow("Demonio Tasmania", img);
  
  //  Mat kernel = (Mat_<float>(3,3) <<
  //               0.0113,  0.0838,  0.0113,
  //               0.0838,  0.6193,  0.0838,
  //               0.0113,  0.0838,  0.0113);  
  // Mat imgGauss;
  // Mat sharp = img; // copy source image to another temporary one
  // filter2D(sharp, imgGauss, CV_32F, kernel);
  // img.convertTo(sharp, CV_8UC3);
  // imshow("Sharp", sharp);
  Canny(img, img_canny, 170, 255);
  findContours(img_canny, cnt,CV_RETR_LIST , CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
  drawing = Mat::zeros(img_canny.size(), CV_8UC3);
  for (size_t i = 0; i< cnt.size(); i++)
  {
    Scalar color = CV_RGB(0, 255, 0);
    drawContours(drawing, cnt, (int)i, color, 1, 8, 0, 0, Point());
  }
  imshow("Demonio Tasmania1", drawing);
  waitKey(0);
  return 0;
 
  // Mat imgResult = sharp - imgLaplacian;

  // imshow("New image", imgResult);

}