#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <QDialog>

namespace Ui {
class Threshold;
}

class Threshold : public QDialog
{
    Q_OBJECT

public:
    explicit Threshold(QWidget *parent = nullptr);
    ~Threshold();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Threshold *ui;
};

#endif // THRESHOLD_H
