#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Image_btn_clicked();

    void on_video_btn_clicked();

    void on_pushButton_clicked();

    void on_grayimage_btn_clicked();

    void on_threshold_btn_clicked();

    void on_mediam_btn_clicked();

    void on_edge_btn_clicked();

    void on_linedetect_btn_clicked();

    void on_circledetect_btn_clicked();

    void on_histogram_btn_clicked();

    void on_dialation_btn_clicked();

    void on_erosion_btn_clicked();

    void on_facedetect_btn_clicked();

    void on_bitwise_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
