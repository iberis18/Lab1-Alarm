#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGridLayout"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet(stl);
    setWindowTitle("Будильник");
    tmr = new QTimer;
    connect(tmr, SIGNAL(timeout()), this, SLOT(timer()));
    tmr->start(1000);
    nmbr = new QLCDNumber;

    spnbx1 = new QSpinBox;
    spnbx2 = new QSpinBox;
    spnbx1->setRange(0, 23);
    spnbx1->setWrapping(true);
    spnbx2->setRange(0, 59);
    spnbx2->setWrapping(true);

    QDateTime dt = QDateTime::currentDateTime();
    spnbx1->setValue(dt.time().hour());
    spnbx2->setValue(dt.time().minute());

    chckbx = new QCheckBox;
    txt = new QLineEdit;
    lbl1 = new QLabel;
    lbl2 = new QLabel;
    lbl3 = new QLabel;
    lbl1->setText("Установите время: ");
    lbl2->setText("Введите описание: ");
    lbl3->setText("Включить будильник?");
    txt->setText("Пора обедать!");

    QGridLayout* glt = new QGridLayout();
    glt->addWidget(nmbr, 0,0, 1,3);
    glt->addWidget(lbl1, 1,0);
    glt->addWidget(spnbx1, 1,1);
    glt->addWidget(spnbx2, 1,2);
    glt->addWidget(lbl2, 2,0);
    glt->addWidget(txt, 2,1, 1,2);
    glt->addWidget(chckbx, 3,1);
    glt->addWidget(lbl3, 3,0);

    QWidget* wdgt = new QWidget();
    wdgt->setLayout(glt);
    this->setCentralWidget(wdgt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timer()
{
    QDateTime dt = QDateTime::currentDateTime();
    nmbr->display(dt.toString("HH:mm"));
    if (chckbx->isChecked())
        if (dt.time().hour() == spnbx1->value() && dt.time().minute() == spnbx2->value())
        {
            QMessageBox mb;
            mb.setWindowTitle("Будильник");
            mb.setStyleSheet(stl);
            mb.setInformativeText(txt->text() + "\nОтложить будильник на 5 минут?");
            mb.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
            int result = mb.exec();
            if(result == QMessageBox::Cancel)
            {
                chckbx->setChecked(false);
                spnbx1->setValue(dt.time().hour());
                spnbx2->setValue(dt.time().minute());
            }
            else
                if (result == QMessageBox::Ok)
                    if (dt.time().minute() < 55)
                        spnbx2->setValue(dt.time().minute() + 5);
                    else
                    {
                        spnbx1->setValue(dt.time().hour() + 1);
                        spnbx2->setValue(-55 + dt.time().minute());
                    }
        }
}

