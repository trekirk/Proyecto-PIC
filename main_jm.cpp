#include "proy_lib.h"

using namespace vision;



int main()
{
	Mat img_m1, img_m1_1, img_m2, img_m2_1;
	img_m1 = imread("/home/juanmanuel/Documentos/GitRepository/Proyecto-PIC/build/m1.jpg");
	img_m2 = imread("/home/juanmanuel/Documentos/GitRepository/Proyecto-PIC/build/m2.jpg");

	//vector<vector<Point> >  cnt;
	
	cvtColor(img_m1, img_m1_1, CV_BGR2GRAY);
	cvtColor(img_m2, img_m2_1, CV_BGR2GRAY);
	equalizeHist(img_m1_1, img_m1_1);
	equalizeHist(img_m2_1, img_m2_1);
	
	namedWindow("Movil1", cv::WINDOW_AUTOSIZE);
	namedWindow("Movil2", cv::WINDOW_AUTOSIZE);

	// Canny(img_m1_1, img_m2, 100, 255);
	// findContours(img_m2, cnt,CV_RETR_LIST , CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	// for (size_t i = 0; i< cnt.size(); i++)
	// {
	//   Scalar color = CV_RGB(0, 255, 0);
	//   drawContours(img_m1, cnt, (int)i, color, 1, 8, 0, 0, Point());
	// }
	matchORB("/home/juanmanuel/Documentos/GitRepository/Proyecto-PIC/build/m1.jpg", "/home/juanmanuel/Documentos/GitRepository/Proyecto-PIC/build/m2.jpg");

	imshow("Movil1", img_m1_1);
	imshow("Movil2", img_m2_1);

	waitKey(0);
	
	return 0;



}