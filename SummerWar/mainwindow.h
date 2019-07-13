#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class calculator{
private:
    double chisl[20];
    QChar znak[20];
    int chn = 0;
    int znn = 0;
    void sdvig(int *i) {
        for (int k = *i; k != znn; k++) {
            znak[k] = znak[k + 1]; chisl[k] = chisl[k + 1];
        }
        znn = znn - 1; *i = *i - 1;
    }
    void sdvigznak(int *i) {
        for (int k = *i; k != znn; k++) {
            znak[k] = znak[k + 1];
        }
        znn = znn - 1;
    }

    void priority1(int *i, bool *proof) {
        if (znak[*i] == '/' || znak[*i] == '*' || znak[*i] == '#' || znak[*i] == '^' || znak[*i] == '%' || znak[*i] == '&') {
                if (znak[*i] == '&') {
                    if (chisl[*i] == 0. || chisl[*i + 1] == 0.) { *proof = 0; chisl[*i] = 1; chisl[*i + 1] = 1; }
                    chisl[*i + 1] = double(log(chisl[*i]) / log(chisl[*i + 1]));
                }
                if (znak[*i] == '#') {
                    if (chisl[*i + 1] < 0) { *proof = 0; chisl[*i] = 1; chisl[*i + 1] = 1; }
                    chisl[*i + 1] = pow(double(chisl[*i + 1]), (double(1) / chisl[*i]));
                }
                if (znak[*i] == '^') {
                    chisl[*i + 1] = pow(double(chisl[*i]), double(chisl[*i + 1]));
                }
                if (znak[*i] == '%') {
                    if (chisl[*i + 1] == 0.) { *proof = 0; chisl[*i] = 1; chisl[*i + 1] = 1; }
                    chisl[*i + 1] = fmod(chisl[*i], chisl[*i + 1]);
                }
                if (znak[*i] == '*') {
                    chisl[*i + 1] = double(chisl[*i] * chisl[*i + 1]);
                }
                if (znak[*i] == '/') {
                    if (chisl[*i + 1] == 0.) { *proof = 0; chisl[*i] = 1; chisl[*i + 1] = 1; }
                    chisl[*i + 1] = double(chisl[*i]) / double(chisl[*i + 1]);
                }
            sdvig(&*i);
        }
    }

    void priority2(int *i) {
        if (znak[*i] == '+') { chisl[*i + 1] = double(chisl[*i] + chisl[*i + 1]);}
        if (znak[*i] == '-') { chisl[*i + 1] = double(chisl[*i] - chisl[*i + 1]);}
        sdvig(&*i);
    }

    void skobki(int *i, bool *proof) {
        sdvigznak(&*i);
        for (int k = *i; znak[k] != ')'; k++) {
            if (znak[k] == '(') { skobki(&k, &*proof); k--; }
        }
        for (int k = *i; znak[k] != ')'; k++) { priority1(&k, &*proof); }
        for (int k = *i; znak[k] != ')'; k++) { priority2(&k); }
        sdvigznak(&*i);
    }
public:
    QString execute(QString vvod){
        bool proof = 1;
        if (vvod.isEmpty()){
            proof = 0; return "Nothing there";
        }
        if (proof == 1){
            if(vvod[0] == '-'){
                chisl[0] = 0; chn = 1;
            }
            int sk = 0;
            for (int i = 0; i < vvod.size() && proof == 1; i++) {
                    proof = 0;
                    if (vvod[i] == ' '){
                        proof = 1;
                    }
                    if (vvod[i] == '+' || vvod[i] == '-' || vvod[i] == '*' || vvod[i] == '/' || vvod[i] == '%' || vvod[i] == '#' || vvod[i] == '^') {
                        proof = 1; znak[znn] = vvod[i]; znn++;
                        if ((vvod[i + 1] < 48 || vvod[i + 1] >57) && vvod[i + 1] != '(') { proof = 0; }
                    }
                    if (vvod[i] == '(') {
                        proof = 1; sk++; znak[znn] = vvod[i]; znn++;
                        if ((vvod[i + 1] < 48 || vvod[i + 1] >57) && vvod[i + 1] != '(') { proof = 0; }
                    }
                    if (vvod[i] == ')') {
                        proof = 1; sk--; znak[znn] = vvod[i]; znn++; if (sk < 0) { proof = 0; }
                        if (vvod[i + 1] == '(') { znak[znn] = '*'; znn++; }
                    }
                    if (47 < vvod[i] && vvod[i] < 58 ) {
                        proof = 1; chisl[chn] = vvod[i].digitValue();
                        for (int k = i + 1; 47 < vvod[k] && vvod[k] < 58; k++) {
                            chisl[chn] = chisl[chn] * 10 + vvod[k].digitValue(); i = k;
                        }
                        if (vvod[i + 1] == '.' || vvod[i + 1] == ',') {
                            int des = 10;
                            if (vvod[i + 2] < 48 || vvod[i + 2] >57) { proof = 0; }
                            for (int k = i + 2; 47 < vvod[k] && vvod[k] < 58; k++) {
                                double x = double(vvod[k].digitValue()) / des;
                                chisl[chn] = double(chisl[chn] + x);
                                des = des * 10; i = k;
                            }
                        }
                        chn++;
                    }
                }
                if (sk != 0) { proof = 0;}

                for (int i = 0; (i < znn) && proof != 0; i++) {
                    if (znak[i] == '(') { skobki(&i, &proof); }
                }
                for (int i = 0; i < znn && proof != 0; i++) {
                    priority1(&i, &proof);
                }

                for (int i = 0; i < znn && proof != 0; i++) {
                    priority2(&i);
                }

            vvod = QString::number(chisl[0]);
        }
        if (proof == 0) vvod = "Error";
        return vvod;
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_execute_clicked();

    void on_pushButton_zero_clicked();

    void on_pushButton_one_clicked();

    void on_pushButton_two_clicked();

    void on_pushButton_three_clicked();

    void on_pushButton_four_clicked();

    void on_pushButton_five_clicked();

    void on_pushButton_six_clicked();

    void on_pushButton_seven_clicked();

    void on_pushButton_eight_clicked();

    void on_pushButton_nine_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_openbr_clicked();

    void on_pushButton_closebr_clicked();

    void on_pushButton_mult_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_power_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_remainder_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_clearall_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
