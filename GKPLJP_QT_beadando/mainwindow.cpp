#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_actionOpen_triggered()
{
    QString url = QFileDialog::getOpenFileName(this, "Select a file to open", QString(), "Image files (*.png *.jpeg *.jpeg *.gif *.bmp)");

    if(url.isEmpty())
    {
       return;
    }
    QPixmap img(url);

    ui->info_image_label->setPixmap(img);
    ui->info_image_label->setScaledContents(true);

    QString data = "";
    data += "Path: " + url + "\n";
    data += "Height: " + (QString)img.height() + "\n"; //heigh and width not the image size!!!!!
    data += "Width: " + (QString)img.width();
    ui->info_image_data_label->setText(data);
    /*
    QFile infile(filename);
    infile.open(QIODevice::ReadOnly);
    QTextStream stream(&infile);
    QString content = stream.readAll();
    std::string s = content.toStdString();
    std::cout << s;
    */
}

