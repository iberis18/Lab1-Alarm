#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLCDNumber"
#include "QSpinBox"
#include "QCheckBox"
#include "QDateTime"
#include "QTime"
#include "QTimer"
#include "QLabel"
#include "QLineEdit"
#include "QMessageBox"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLCDNumber* nmbr;
    QSpinBox* spnbx1, *spnbx2;
    QCheckBox* chckbx;
    QTimer* tmr;
    QLabel* lbl1, *lbl2, *lbl3;
    QLineEdit* txt;
    QString stl = "font-size: 12pt";

private slots:
    void timer();
};
#endif // MAINWINDOW_H
