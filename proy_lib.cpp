#include "proy_lib.h"

namespace vision
{
  void readme()
  { 
    std::cout << " Usage: ./ORB_detector <img1> <img2>" << std::endl; 
  }

  void matchSURF(string image1, string image2)
  {

    Mat img_1 = imread( image1, IMREAD_GRAYSCALE );
    Mat img_2 = imread( image2, IMREAD_GRAYSCALE );

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

  void matchORB(string image1, string image2)
  {

    readme();
    Mat img1 = imread(image1);
    Mat img2 = imread(image2);
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
    Ptr<ORB> detector_extractor = ORB::create();
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

    void contours(string image)
    {
      Mat img, img_canny, drawing;
      img = imread(image);
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
