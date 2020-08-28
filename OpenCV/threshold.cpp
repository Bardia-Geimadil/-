#include "threshold.h"
#include "ui_threshold.h"

#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h>


Threshold::Threshold(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Threshold)
{
    ui->setupUi(this);
}

Threshold::~Threshold()
{
    delete ui;
}

int threshold_value = 0;
int threshold_type = 3;;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;



using namespace cv;
Mat src, src_gray, dst;
char* window_name = "Threshold Demo";

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char* trackbar_value = "Value";

void Threshold_Demo( int, void* );

//https://docs.opencv.org/2.4/doc/tutorials/imgproc/threshold/threshold.html
void Threshold::on_pushButton_clicked()
{

    /// Load an image
      src = imread( "/media/bardia/52B0239FB0238895/wallpaper/paper3.jpg", 1 );
        namedWindow( "main", WINDOW_AUTOSIZE );
        imshow("main" , src);

      /// Convert the image to Gray
      cvtColor( src, src_gray, COLOR_RGB2GRAY );

      /// Create a window to display results
      namedWindow( window_name, WINDOW_AUTOSIZE );

      /// Create Trackbar to choose type of Threshold
      createTrackbar( trackbar_type,
                      window_name, &threshold_type,
                      max_type, Threshold_Demo );

      createTrackbar( trackbar_value,
                      window_name, &threshold_value,
                      max_value, Threshold_Demo );

      /// Call the function to initialize
      Threshold_Demo( 0, 0 );

      /// Wait until user finishes program
      while(true)
      {
        int c;
        c = waitKey( 20 );
        if( (char)c == 27 )
          { break; }
       }
    }


    void Threshold_Demo( int, void* )
    {
      /* 0: Binary
         1: Binary Inverted
         2: Threshold Truncated
         3: Threshold to Zero
         4: Threshold to Zero Inverted
       */

      threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );

      imshow( window_name, dst );

}
