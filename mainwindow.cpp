#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "obszarrysowania.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->czerwony,SIGNAL(clicked()),ui->centralWidget, SLOT(czerowny()));
    QObject::connect(ui->niebieski,SIGNAL(clicked()),ui->centralWidget, SLOT(niebieski()));
    QObject::connect(ui->zielony,SIGNAL(clicked()),ui->centralWidget, SLOT(zielony()));
    QObject::connect(ui->zolty,SIGNAL(clicked()),ui->centralWidget, SLOT(zolty()));
    QObject::connect(ui->czyszczenie,SIGNAL(clicked()),ui->centralWidget, SLOT(czysc()));
    QObject::connect(ui->actionZapisz_jako,SIGNAL(triggered(bool)),ui->centralWidget,SLOT(save()));
    QObject::connect(ui->actionZakoncz,SIGNAL(triggered(bool)),ui->centralWidget,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
