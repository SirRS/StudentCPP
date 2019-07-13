#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_execute_clicked()
{
    calculator calculator;
    ui->lineEdit->setText(calculator.execute(ui->lineEdit->text()));
}

void MainWindow::on_pushButton_zero_clicked()
{
    QString text;  text = ui->lineEdit->text()+'0';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_one_clicked()
{
    QString text;  text = ui->lineEdit->text()+'1';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_two_clicked()
{
    QString text;  text = ui->lineEdit->text()+'2';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_three_clicked()
{
    QString text;  text = ui->lineEdit->text()+'3';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_four_clicked()
{
    QString text;  text = ui->lineEdit->text()+'4';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_five_clicked()
{
    QString text;  text = ui->lineEdit->text()+'5';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_six_clicked()
{
    QString text;  text = ui->lineEdit->text()+'6';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_seven_clicked()
{
    QString text;  text = ui->lineEdit->text()+'7';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_eight_clicked()
{
    QString text;  text = ui->lineEdit->text()+'8';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_nine_clicked()
{
    QString text;  text = ui->lineEdit->text()+'9';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_dot_clicked()
{
    QString text;  text = ui->lineEdit->text()+'.';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_openbr_clicked()
{
    QString text;  text = ui->lineEdit->text()+'(';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_closebr_clicked()
{
    QString text;  text = ui->lineEdit->text()+')';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_mult_clicked()
{
    QString text;  text = ui->lineEdit->text()+'*';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_divide_clicked()
{
    QString text;  text = ui->lineEdit->text()+'/';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_plus_clicked()
{
    QString text;  text = ui->lineEdit->text()+'+';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_minus_clicked()
{
    QString text;  text = ui->lineEdit->text()+'-';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_power_clicked()
{
    QString text;  text = ui->lineEdit->text()+'^';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    QString text;  text = ui->lineEdit->text()+'#';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_remainder_clicked()
{
    QString text;  text = ui->lineEdit->text()+'%';
    ui->lineEdit->setText(text);
}


void MainWindow::on_pushButton_log_clicked()
{
    QString text;  text = ui->lineEdit->text()+'&';
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_clear_clicked()
{
    QString text, line; line = ui->lineEdit->text();
    for (int i = 0; i < line.size() - 1; i++){
        text[i] =line[i];
    }
    ui->lineEdit->setText(text);
}

void MainWindow::on_pushButton_clearall_clicked()
{
    ui->lineEdit->setText("");
}
