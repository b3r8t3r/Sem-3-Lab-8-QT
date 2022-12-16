#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Viginer.h"
#include "gronsfeld.h"
#include "atbash.h"

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


void MainWindow::on_ViginerEncryptButton_clicked()
{
    string message = ui->viginer_input_lineEdit->text().toStdString();
    string key = ui->viginer_key_lineEdit->text().toStdString();
    Viginer encrypt(message, key);
    encrypt.Encrypt();
    QString encrypted = QString::fromStdString(encrypt.GetMessage());
    ui->viginer_output_lineEdit->setText(encrypted);

}


void MainWindow::on_ViginerDecryptButton_clicked()
{
    string message = ui->viginer_input_lineEdit->text().toStdString();
    string key = ui->viginer_key_lineEdit->text().toStdString();
    Viginer decrypt(message, key);
    decrypt.Decrypt();
    QString decrypted = QString::fromStdString(decrypt.GetMessage());
    ui->viginer_output_lineEdit->setText(decrypted);
}


void MainWindow::on_gronsfeld_encrypt_button_clicked()
{
    string message  = ui->gronsfeld_input_lineEdit->text().toStdString();
    int key = ui->gronsfeld_key_spinBox->text().toInt();
    Gronsfeld encrypt(message, key);
    encrypt.Encrypt();
    QString encrypted = QString::fromStdString(encrypt.GetMessage());
    ui->gronsfeld_output_lineEdit->setText(encrypted);
}


void MainWindow::on_gronsfeld_decrypt_button_clicked()
{
    string message  = ui->gronsfeld_input_lineEdit->text().toStdString();
    int key = ui->gronsfeld_key_spinBox->text().toInt();
    Gronsfeld decrypt(message, key);
    decrypt.Decrypt();
    QString decrypted = QString::fromStdString(decrypt.GetMessage());
    ui->gronsfeld_output_lineEdit->setText(decrypted);
}



void MainWindow::on_atbash_encrypt_button_clicked()
{
    //string message  = ui->gronsfeld_output_lineEdit->text().toStdString();
    string message = ui->atbash_input_lineEdit->text().toStdString();
    Atbash encrypt(message);
    encrypt.Encrypt();
    QString encrypted = QString::fromStdString(encrypt.GetMessage());
    ui->atbash_output_lineEdit->setText(encrypted);
}


void MainWindow::on_atbash_decrypt_button_clicked()
{
    string message = ui->atbash_input_lineEdit->text().toStdString();
    Atbash decrypt(message);
    decrypt.Decrypt();
    QString decrypted = QString::fromStdString(decrypt.GetMessage());
    ui->atbash_output_lineEdit->setText(decrypted);
}

