#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    std::string Visiner_Encrypt(std::string message, std::string key);
    ~MainWindow();

private slots:
    void on_ViginerEncryptButton_clicked();

    void on_ViginerDecryptButton_clicked();

    void on_gronsfeld_encrypt_button_clicked();

    void on_gronsfeld_decrypt_button_clicked();

    void on_atbash_encrypt_button_clicked();

    void on_atbash_decrypt_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
