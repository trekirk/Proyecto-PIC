#include "../include/proy_lib.h"

namespace vision
{
  void readme()
  { 
    std::cout << " Usage: ./ORB_detector <img1> <img2>" << std::endl; 
  }

  void matchSURF(Mat img1, Mat img2)
  {


    if( !img_1.data || !img_2.data )
    { std::cout<< " --(!) Error reading images " << std::endl; return; }

    //-- Step 1: Detect the keypoints using SURF Detector
    int minHessian = 400;

    Ptr<SURF> detector = SURF::create( minHessian );

    vector<KeyPoint> keypoints_1, keypoints_2;

    detector->detect( img_1, keypoints_1 );
    detector->detect( img_2, keypoints_2 );
/*
    //-- Draw keypoints
    Mat img_keypoints_1; Mat img_keypoints_2;

    drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    drawKeypoints( img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );

    //-- Show detected (drawn) keypoints
    imshow("Keypoints 1", img_keypoints_1 );
    imshow("Keypoints 2", img_keypoints_2 );*/

    // computing descriptors
    Mat descriptors1, descriptors2;
    detector->compute(img_1, keypoints_1, descriptors1);
    detector->compute(img_2, keypoints_2, descriptors2);

  //Initialise BruteForceMatcher: For each descriptor in the first set, this matcher finds the closest descriptor in the second set by trying each on (=brute)
    BFMatcher matcher(NORM_L2);
    vector< DMatch > matches;
    matcher.match(descriptors1, descriptors2, matches);

  // drawing the results
    namedWindow("matches", 1);
    Mat img_matches;
    drawMatches(img_1, keypoints_1, img_2, keypoints_2, matches, img_matches);
    imshow("matches", img_matches);

    waitKey(0);

    return;
  }

  void matchORB(Mat img1, Mat img2)
  {

    readme();
   
    namedWindow("ima1", WINDOW_AUTOSIZE);
    namedWindow("ima2", WINDOW_AUTOSIZE);

    imshow("ima1", img1);
    imshow("ima2", img2);
    
    if(img1.empty() || img2.empty())
    {
        printf("Can't load all the images! \n");
        return;
    }   

  //Initialise the ORB features detector()
    Ptr<ORB> detector_extractor = ORB::create(100, 1.1);
    vector<KeyPoint> keypoints1, keypoints2;
    detector_extractor->detect(img1, keypoints1);
    detector_extractor->detect(img2, keypoints2);

  // computing descriptors
    Mat descriptors1, descriptors2;
    detector_extractor->compute(img1, keypoints1, descriptors1);
    detector_extractor->compute(img2, keypoints2, descriptors2);

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
    return;
  }

    void contours(Mat img)
    {
      Mat img_canny, drawing;
      
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
     
      // Mat imgResult = sharp - imgLaplacian;

      // imshow("New image", imgResult);

  }
}

namespace practica2
{
  int ejercicio1(){
    Mat gray_img, color_img;
    gray_img = imread ("mandril.jpg", IMREAD_GRAYSCALE);
    if (!gray_img.data) {
      cout << "error loading image" << endl;
      return 1;
    }
   color_img = imread( "mandril_c.jpg", IMREAD_COLOR);
    if (!color_img.data){
      cout << "error loading image" << endl;
        return 1;
    }
    cout << "gray channels: " << gray_img.channels() << endl;
    cout<< "color channels: " << color_img.channels() << endl;

    namedWindow("gray", WINDOW_AUTOSIZE);
    namedWindow("color", WINDOW_AUTOSIZE);

    imshow ("gray" , gray_img);
    imshow ("color" , color_img);

    waitKey(0);
    destroyAllWindows();

    return 0;
  }

  int ejercicio2(){
    Mat color_img;
    color_img = imread ("mandril_c.jpg", IMREAD_COLOR);
    if (! color_img.data){
      cout << "error loading image" << endl;
      return 1;
    } 

    cvtColor (color_img, color_img, CV_BGR2RGB);

    Mat r_channel(color_img.size(), CV_8UC1);
    Mat g_channel(color_img.size(), CV_8UC1);
    Mat b_channel(color_img.size(), CV_8UC1);
    Mat array_channels[] = { r_channel, g_channel, b_channel };
    split(color_img, array_channels);

    namedWindow("color", WINDOW_AUTOSIZE);
    namedWindow("R", WINDOW_AUTOSIZE);
    namedWindow("G", WINDOW_AUTOSIZE);
    namedWindow("B", WINDOW_AUTOSIZE);

    imshow("color" , color_img);
    imshow("R" , r_channel);
    imshow("G" , g_channel);
    imshow("B" , b_channel);

    waitKey(0);

    destroyAllWindows();

    return 0;
  }
  int ejercicio3(){
    Mat color_img, hsv_img;

    color_img = imread ("mandril_c.jpg", IMREAD_COLOR);
    if (!color_img.data){
      cout << "error loading image" << endl;
       return 1;
    }

    cvtColor(color_img, hsv_img, CV_BGR2HSV);
    Mat h_channel(hsv_img.size(), CV_8UC1);
    Mat s_channel(hsv_img.size(), CV_8UC1);
    Mat v_channel(hsv_img.size(), CV_8UC1);
    Mat array_channels[] = { h_channel, s_channel, v_channel};
    split (hsv_img, array_channels);


    int histSize = 256;

    float range [] = {0, 256};
    const float* histRange = {range};

    Mat h_hist, s_hist, v_hist;
    calcHist(&h_channel, 1, 0, Mat(), h_hist, 1, &histSize, &histRange, true, false);
    calcHist(&s_channel, 1, 0, Mat(), s_hist, 1, &histSize, &histRange, true, false);
    calcHist(&v_channel, 1, 0, Mat(), v_hist, 1, &histSize, &histRange, true, false);

    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound ((double)hist_w /histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar (0,0,0));

    normalize(h_hist, h_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat ());
    normalize(s_hist, s_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat ());
    normalize(v_hist, v_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat ());

    for (int i = 1; i < histSize; i++)
    {
      line(histImage, Point(bin_w*(i-1), hist_h - cvRound(h_hist.at<float>(i-1))),
          Point(bin_w*(i), hist_h - cvRound(h_hist.at<float>(i))),
          Scalar(255,0,0), 2,8,0);
      line(histImage, Point(bin_w*(i-1), hist_h - cvRound(h_hist.at<float>(i-1))),
          Point(bin_w*(i), hist_h - cvRound(h_hist.at<float>(i))),
          Scalar(0,255,0), 2,8,0);
      line(histImage, Point(bin_w*(i-1), hist_h - cvRound(h_hist.at<float>(i-1))),
          Point(bin_w*(i), hist_h - cvRound(h_hist.at<float>(i))),
          Scalar(0,0,255), 2,8,0);
    }
    namedWindow("color", WINDOW_AUTOSIZE);
    namedWindow("H", WINDOW_AUTOSIZE);
    namedWindow("S", WINDOW_AUTOSIZE);
    namedWindow("V", WINDOW_AUTOSIZE);

    imshow("color" , color_img);
    imshow("H" , h_channel);
    imshow("S" , s_channel);
    imshow("V" , v_channel);
    imshow("histogram: Red=H Green=S Blue=V", histImage);

    waitKey(0);

    destroyAllWindows();

    return 0;
  }
  int ejercicio4(){
    Mat original_img = imread("rayosx.tif", IMREAD_GRAYSCALE);
    if(!original_img.data){
      cout<<"error loading image" << endl;
      return 1;
    }

    int histSize = 256;

    float range[] = {0, 256};
    const float* histRange = { range };

    int hist_w = 512;
    int hist_h = 400;

    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0,0,0));

    Mat original_hist, normalized_hist;
    calcHist(&original_img, 1, 0, Mat(), original_hist, 1, &histSize, & histRange, true, false);

    cout <<"Original histogram" << endl;
    for (int h = 0; h < histSize; h++)
    {
      float binVal = original_hist.at<float>(h);
      cout << "" << binVal;
    }
    cout << endl;

    Point min_point, max_point;
    double min, max;
    minMaxLoc(original_hist, &min, &max, &min_point, &max_point, Mat());

    cout << "Minimum value" << min << "at index" << min_point.y << endl;
    cout << "Maximum value" << max << "at index" << max_point.y << endl << endl;

    normalize(original_hist, normalized_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    cout<< "Normalized histogram" << endl;
    for (int h = 0; h < histSize; h++)
    {
      float binVal = normalized_hist.at<float>(h);
      cout<<""<< binVal;
    }
    cout<< endl;

    minMaxLoc(normalized_hist, &min, &max, &min_point, &max_point, Mat());

    cout << "Minimum value" << min << "at index" << min_point.y << endl;
    cout << "Maximum value" << max << "at index" << max_point.y << endl;

    for (int i = 0; i < histSize; i++)
    {
      line(histImage,
      Point(bin_w*(i), hist_w), 
      Point(bin_w*(i), hist_h - cvRound(normalized_hist.at<float>(i))), 
      Scalar(255, 0, 0), bin_w, 8, 0);
    }

    namedWindow("Original Picture", WINDOW_AUTOSIZE);
    namedWindow("Histogram Picture", WINDOW_AUTOSIZE);

    imshow("Original Picture", original_img);
    imshow("Histogram Picture", histImage);

    waitKey(0);

    histImage.release();
    original_hist.release();
    destroyAllWindows();

    return 0;
  }
}
