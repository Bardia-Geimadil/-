#include "imageshow.h"
#include "ui_imageshow.h"

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>

ImageShow::ImageShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageShow)
{
    ui->setupUi(this);
}

ImageShow::~ImageShow()
{
    delete ui;
}

void ImageShow::on_Show_btn_clicked()
{

    using namespace cv;

    Mat image = imread("/home/bardia/opentest/test.jpg");
    namedWindow("MyWindow" , WINDOW_AUTOSIZE);
    imshow("MyWindow" , image);
    this->hide();

}
