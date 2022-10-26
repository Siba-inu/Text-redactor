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
    void on_open_text_clicked();

    void on_save_text_clicked();

    void on_clear_text_clicked();

    void on_exit_text_clicked();

    void autosave();

    void hello();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
