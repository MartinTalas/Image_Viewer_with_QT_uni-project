#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include "image.h"
#include "fileparser.h"

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
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;

    //messages
    QString message_text;
    //storage
    QList<imgmanager::Image> storage;

    //file parser
    parser::FileParser file_parser;

    //save data
    void saveData();

    //load data
    void loadData();

};
#endif // MAINWINDOW_H
