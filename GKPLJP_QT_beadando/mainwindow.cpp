#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file_parser = parser::FileParser();
    loadData();
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

    QString data = "", name = "";
    data += "Path: " + url + "\n";
    data += "Height: " + (QString)img.height() + "\n"; //heigh and width not the image size!!!!!
    data += "Width: " + (QString)img.width();

    ui->info_image_data_label->setText(data);

    QList<QString> categories, tags; //default zero

    QList<QString> get_name = url.split("/");
    for(QString n : get_name)
    {
        name = n;
    }

    imgmanager::Image img_obj = imgmanager::Image(url, name, categories, tags);

    bool is_exists = false;
    for(auto item : storage)
    {
        if(item.getPath() == url)
        {
            is_exists = true;
        }
    }

    if(!is_exists)
    {
        storage.append(img_obj);
        message_text = "Image saved!";
    }
    else
    {
        message_text = "This image is exists in the archive!";
    }
}

void MainWindow::on_actionSave_triggered()
{
    saveData();
}

void MainWindow::saveData()
{
    file_parser.toFile(storage);
}

void MainWindow::loadData()
{
    storage = file_parser.toObject();
}
