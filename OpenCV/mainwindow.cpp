#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageshow.h"
#include <threshold.h>
#include <vector>

#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Image_btn_clicked()
{
        ImageShow im;
        im.setModal(true);
        im.exec();
}

void MainWindow::on_video_btn_clicked()
{
    using namespace cv;


//    VideoCapture cap("/home/bardia/Desktop/boat.mp4"); // open the default camera
//    //Video Capture cap(path_to_video); // open the video file
//    if(!cap.isOpened())  // check if we succeeded
//        printf("soryy");

//    namedWindow("Video",WINDOW_AUTOSIZE);
//    for(;;)
//    {
//        Mat frame;
//        cap >> frame; // get a new frame from camera
//        imshow("Video", frame);
//        if(waitKey(30) >= 0) break;
//    }

    //printf("Sorryyy");
    cv::namedWindow( "Video_window", cv::WINDOW_AUTOSIZE );
    cv::VideoCapture cap("/home/bardia/Desktop/boat.mp4");
   // cap.open( "/home/bardia/Desktop/boat.mp4") ;
    if(!cap.isOpened()) printf("Can't open");

    cv::Mat frame;
    for(;;) {
    cap >> frame;
    if( frame.empty() ) break;
    cv::imshow( "Video_window", frame );
    if( cv::waitKey(33) >= 0 ) break;
    }
    cap.release();
}

void MainWindow::on_pushButton_clicked()
{
    using namespace cv;
    // Create black empty images
      Mat image = Mat::zeros( 500, 1000, CV_8UC3 );

      // Draw a line
//      line( image, Point( 15, 20 ), Point( 70, 50), Scalar( 110, 220, 0 ),  2, 8 );
//      arrowedLine(image, Point( 15, 40 ), Point( 70, 70) , Scalar(200 , 10 ,30) , 4 , CV_8U);
//      circle(image , Point(180 , 150) , 80 , Scalar(0 , 100 , 0) , 5);
//      ellipse( image, Point( 200, 200 ), Size( 100.0, 160.0 ), 45, 0, 360, Scalar( 255, 0, 0 ), 1, 8 );
//        ellipse( image, Point( 200, 200 ), Size( 100.0, 160.0 ), 135, 0, 360, Scalar( 255, 0, 0 ), 10, 8 );
//        ellipse( image, Point( 200, 200 ), Size( 150.0, 50.0 ), 135, 0, 360, Scalar( 0, 255, 0 ), 1, 8 );
//      rectangle( image, Point( 15, 20 ), Point( 70, 50), Scalar( 0, 55, 255 ), +1, 4 );
//      rectangle( image, Point( 115, 120 ), Point( 170, 150), Scalar( 100, 155, 25 ), -1, 8 );

      //pollygon


      {
          //      int w=400;
          //        // Draw a circle
          //        /** Create some points */
          //        Point rook_points[1][20];
          //        rook_points[0][0] = Point( w/4.0, 7*w/8.0 );
          //        rook_points[0][1] = Point( 3*w/4.0, 7*w/8.0 );
          //        rook_points[0][2] = Point( 3*w/4.0, 13*w/16.0 );
          //        rook_points[0][3] = Point( 11*w/16.0, 13*w/16.0 );
          //        rook_points[0][4] = Point( 19*w/32.0, 3*w/8.0 );
          //        rook_points[0][5] = Point( 3*w/4.0, 3*w/8.0 );
          //        rook_points[0][6] = Point( 3*w/4.0, w/8.0 );
          //        rook_points[0][7] = Point( 26*w/40.0, w/8.0 );
          //        rook_points[0][8] = Point( 26*w/40.0, w/4.0 );
          //        rook_points[0][9] = Point( 22*w/40.0, w/4.0 );
          //        rook_points[0][10] = Point( 22*w/40.0, w/8.0 );
          //        rook_points[0][11] = Point( 18*w/40.0, w/8.0 );
          //        rook_points[0][12] = Point( 18*w/40.0, w/4.0 );
          //        rook_points[0][13] = Point( 14*w/40.0, w/4.0 );
          //        rook_points[0][14] = Point( 14*w/40.0, w/8.0 );
          //        rook_points[0][15] = Point( w/4.0, w/8.0 );
          //        rook_points[0][16] = Point( w/4.0, 3*w/8.0 );
          //        rook_points[0][17] = Point( 13*w/32.0, 3*w/8.0 );
          //        rook_points[0][18] = Point( 5*w/16.0, 13*w/16.0 );
          //        rook_points[0][19] = Point( w/4.0, 13*w/16.0) ;

          //        const Point* ppt[1] = { rook_points[0] };
          //        int npt[] = { 20 };

          //        fillPoly( image, ppt, npt, 1, Scalar( 255, 255, 255 ), 8 );
      }


      imshow("Image",image);

      waitKey( 0 );
}
void MainWindow::on_grayimage_btn_clicked()
{
    using namespace cv;

    Mat image;
    image = imread("/media/bardia/52B0239FB0238895/wallpaper/flower.jpg", IMREAD_COLOR);

    if(! image.data )
    {
       //    cout <<  "Could not open or find the image" << std::endl ;
           //return -1;
    }

    // Create a new matrix to hold the gray image
    Mat gray;
    Mat type1;


    // convert RGB image to gray
    cvtColor(image, gray, COLOR_HLS2BGR);

    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );

    namedWindow( "result2 window", WINDOW_AUTOSIZE );
     cvtColor(image, type1, COLOR_BGR2XYZ);
    imshow( "result2 window", type1 );

    namedWindow( "Result1 window", WINDOW_AUTOSIZE );
    imshow( "Result1 window", gray );
}

void MainWindow::on_threshold_btn_clicked()
{
   Threshold th;
   th.setModal(true);
   th.exec();
}

void MainWindow::on_mediam_btn_clicked()
{
    using namespace cv;
    Mat src , dst;
    src = imread("/media/bardia/52B0239FB0238895/wallpaper/flower.jpg");

    medianBlur ( src, dst, 15 );
   //  GaussianBlur(src , dst , Size( 11, 1 ), 0, 0);
    //blur( src, dst, Size( 21, 21 ), Point(-1,-1) );
   // bilateralFilter ( src, dst, 101, 101*2, 101/2 );
         imshow("source", src);
         imshow("result", dst);

         waitKey(0);
}






void MainWindow::on_edge_btn_clicked()
{
    using namespace cv;

    Mat src1;
        src1 = imread("/media/bardia/52B0239FB0238895/wallpaper/wish.jpg", IMREAD_COLOR);
        namedWindow( "Original image",WINDOW_AUTOSIZE );
        imshow( "Original image", src1 );

        Mat grey;
        cvtColor(src1, grey, COLOR_BGR2GRAY);

        Mat sobelx;
        Sobel(grey, sobelx, CV_32F, 1, 0);

        double minVal, maxVal;
        minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
        //cout << "minVal : " << minVal << endl << "maxVal : " << maxVal << endl;

        Mat draw;
        sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));

        namedWindow("image", WINDOW_AUTOSIZE);
        imshow("image", draw);

        waitKey(0);
       // return 0;

}

void MainWindow::on_linedetect_btn_clicked()
{

    using namespace cv;

    Mat src = imread("/media/bardia/52B0239FB0238895/wallpaper/wish.jpg", 0);
//    if(src.empty())
//    {
//        help();
//        cout << "can not open " << filename << endl;
//        return -1;
//    }

    Mat dst, cdst;
    Canny(src, dst, 50, 200, 3);
    cvtColor(dst, cdst, COLOR_GRAY2BGR);


    //#if 0
   //  vector<Vec2f> lines;
   //QVector<Vec2f> lines;
   std::vector<Vec2f> lines;
    HoughLines(dst, lines, 1, CV_PI/180, 200, 0, 0 );

     for( size_t i = 0; i < lines.size(); i++ )
     {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( cdst, pt1, pt2, Scalar(255,0,0), 3,LINE_AA);
     }
  //  #else
//     vector<Vec4i> lines;
//     HoughLinesP(dst, lines, 1, CV_PI/180, 50, 50, 10 );
//     for( size_t i = 0; i < lines.size(); i++ )
//     {
//       Vec4i l = lines[i];
//       line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
//     }
   // #endif
    imshow("source", src);
    imshow("detected lines", cdst);

    waitKey();

   // return 0;
   }


void MainWindow::on_circledetect_btn_clicked()
{

    using namespace cv;
    using namespace std;
    Mat src, src_gray;

      /// Read the image
      src = imread("/media/bardia/52B0239FB0238895/wallpaper/circle.png" ); //

//      if( !src.data )
//        { return -1; }

      /// Convert it to gray
      cvtColor( src, src_gray, COLOR_BGR2GRAY );

      /// Reduce the noise so we avoid false circle detection
      GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );

      vector<Vec3f> circles;

      /// Apply the Hough Transform to find the circles
      HoughCircles( src_gray, circles, HOUGH_GRADIENT, 1, src_gray.rows/8, 10, 100, 0, 0 );

      /// Draw the circles detected
      for( size_t i = 0; i < circles.size(); i++ )
      {
          Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
          int radius = cvRound(circles[i][2]);
          // circle center
          circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
          // circle outline
          circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
       }

      /// Show your results
      namedWindow( "Hough Circle Transform ", WINDOW_AUTOSIZE );
      imshow( "Hough Circle Transform ", src );

      //waitKey(0);
}
