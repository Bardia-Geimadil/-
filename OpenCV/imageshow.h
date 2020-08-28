#ifndef IMAGESHOW_H
#define IMAGESHOW_H

#include <QDialog>

namespace Ui {
class ImageShow;
}

class ImageShow : public QDialog
{
    Q_OBJECT

public:
    explicit ImageShow(QWidget *parent = nullptr);
    ~ImageShow();

private slots:
    void on_Show_btn_clicked();

private:
    Ui::ImageShow *ui;
};

#endif // IMAGESHOW_H
