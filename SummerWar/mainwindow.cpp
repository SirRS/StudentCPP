#include "mainwindow.h"
#include "ui_mainwindow.h"

static QString text;
static QString beauty;

static QString history[30];
static QString history_data[30];
static int step = 0;
static int top = 0;
static bool save = 0;
static bool is_pow = 0;
static int pow_border = 0;

void save_step(QString text, QString beautiful)
{
    save = 0;
    if (step == 29){
        for (int i = 0; i < 20; i++){
            history[i] = history[i+9];
            history_data[i] = history_data[i+9];
        }
        step = 20;
    }
    history[step] = beautiful;
    history_data[step] = text;
    step++;
}

void pow() {
    if (is_pow == 0) {
        pow_border = 0;
    }
    if (is_pow == 1){
        QString symbol;
        if (beauty[beauty.length()-1] == '('){
            pow_border++;
            symbol = "<sup>"+beauty[beauty.length()-1]+"</sup>";
        }
        if (beauty[beauty.length()-1] == ')'){
            pow_border--;
            if (pow_border == 0){
                is_pow = 0;
            }
            symbol = "<sup>"+beauty[beauty.length()-1]+"</sup>";
        }
        if (beauty[beauty.length()-1] != '(' && beauty[beauty.length()-1] != ')'){
            symbol = "<sup>"+beauty[beauty.length()-1]+"</sup>";
        }
        QString t;
        for (int i = 0; i < beauty.length()-1;i++){
            t[i] = beauty[i];
        }
        beauty = t + symbol;
    }
}

void beauty_log_sqrt_mod(int key){
    QString log; int i;
    if(beauty[beauty.length()-1] == ')'){
        int s = 0; i = beauty.length()-1;
        do{
            if(beauty[i] == '(') {
                s--;
            }
            if(beauty[i] == ')') {
                s++;
            }
            log = QVariant(beauty[i]).toString() + log;
            i--;
        }while(i > -1 && s != 0);
        i--;
    }
    else {
        bool x = 1;
        for(i = beauty.length()-1; i > -1 && x != 0;i--){
           x = 0;
           if(beauty[i] > 47 && beauty[i] < 58){
               log = QVariant(beauty[i]).toString() + log; x = 1;
           }
        }
    }
    if (i < 0 ){
        i--;
    }
    QString new_text;
    for (int k = 0; k < i + 2; k++){
        new_text=new_text+beauty[k];
    }
    if (key == 1) {
        beauty = new_text+"log" + "<sub>" + log + "</sub>";
    }
    if (key == 0){
        beauty = new_text + "<sup>" + log + "</sup>" + "√";
    }
    if (key == -1){
        beauty = new_text + "<sup>" + log + "</sup>" + "mod";
    }
}

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
    ui->label->setText(calculator.execute(text));
    save_step(ui->label->text(),ui->label->text());
    beauty = ""; text = "";
}

void MainWindow::on_pushButton_zero_clicked()
{
    text = text + '0';
    beauty = beauty + '0';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_one_clicked()
{
    text = text + '1';
    beauty = beauty + '1';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_two_clicked()
{
    text = text + '2';
    beauty = beauty + '2';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_three_clicked()
{
    text = text + '3';
    beauty = beauty + '3';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_four_clicked()
{
    text = text + '4';
    beauty = beauty + '4';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_five_clicked()
{
    text = text + '5';
    beauty = beauty + '5';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_six_clicked()
{
    text = text + '6';
    beauty = beauty + '6';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_seven_clicked()
{
    text = text + '7';
    beauty = beauty + '7';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_eight_clicked()
{
    text = text + '8';
    beauty = beauty + '8';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_nine_clicked()
{
    text = text + '9';
    beauty = beauty + '9';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_dot_clicked()
{
    text = text + '.';
    beauty = beauty + '.';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_openbr_clicked()
{
    text = text + '(';
    beauty = beauty + '(';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_closebr_clicked()
{
    text = text + ')';
    beauty = beauty + ')';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_mult_clicked()
{
    text = text + '*';
    beauty = beauty + "×";
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_divide_clicked()
{
    text = text + '/';
    beauty = beauty + "÷";
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_plus_clicked()
{
    text = text + '+';
    beauty = beauty + '+';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_minus_clicked()
{
    text = text + '-';
    beauty = beauty + '-';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_power_clicked()
{
    text = ui->label->text()+'^';
    is_pow = 1;
    text = text + '(';
    beauty = beauty + '(';
    pow();
     ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    beauty_log_sqrt_mod(0);
    text = text + '#';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_remainder_clicked()
{
    beauty_log_sqrt_mod(-1);
    text = text + '%';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}


void MainWindow::on_pushButton_log_clicked()
{
    beauty_log_sqrt_mod(1);
    text = text + '&';
    if (pow_border != 0) {
        pow();
    }
    ui->label->setText(beauty);
    save_step(text,beauty);
}

void MainWindow::on_pushButton_clearall_clicked()
{
    ui->label->setText(""); text = ""; beauty = "";
    save_step(text,beauty);
}

void MainWindow::on_pushButton_undo_clicked()
{
    if(step > 0){
        if (save == 0) {
            step--;
            top = step;
        }
        ui->label->setText(history[step-1]);
        step--;
        save = 1;
    }
    text = history_data[step];
    beauty = history[step];
}

void MainWindow::on_pushButton_redo_clicked()
{
    if (save == 1 && top > step){
        ui->label->setText(history[step+1]);
        step++;
    }
    text = history_data[step];
    beauty = history[step];
}
