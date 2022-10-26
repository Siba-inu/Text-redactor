#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTemporaryFile>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(autosave()));
    timer->start(1000);
    QTimer::singleShot(20000, this, SLOT(hello()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_text_clicked()
{
    QFile file("file.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        ui->textEdit->setText("File not found");
    }
    QTextStream stream(&file);
    ui->textEdit->setText(stream.readAll());
}


void MainWindow::on_save_text_clicked()
{
    QFile file("file.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << file.errorString();
    }
    QTextStream stream(&file);
    QString text = ui->textEdit->toPlainText();
    stream << text;
    file.close();
}


void MainWindow::on_clear_text_clicked()
{
    ui->textEdit->clear();
}


void MainWindow::on_exit_text_clicked()
{
    QFile file("file.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << file.errorString();
    }
    QTextStream stream(&file);
    QString text = ui->textEdit->toPlainText();
    stream << text;
    file.close();
    QApplication::exit();
}

void MainWindow::autosave()
{
    QTemporaryFile file(QLatin1String("mytemp"));
         file.setAutoRemove(true); // по умолчанию и так true
             if (file.open()) {
                 ui->label->setText(file.fileName());
             }
             else ui->label->setText("no files");
}

void MainWindow::hello()
{
    ui->textEdit->setText("Вы используете нашу программу уже 10 мин. Мы рады, что она вам понравилась");
    QPixmap pixmap("C:/Users/ASUS/Documents/textRedactor/resourse/color.png");
    ui->label_2->setPixmap(pixmap);
    QApplication::exit();
}

