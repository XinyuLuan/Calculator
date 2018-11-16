#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVariant>
#include <QString>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void cleanScreen();
    void clear();
    void space();
    void equals();
    void add();
    void sub();
    void mul();
    void div();
    void pow();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    void zero();
    void leftP();
    void rightP();
    void dot();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_Equals_clicked();
    void on_pushButton_A_clicked();
    void on_pushButton_B_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_D_clicked();
    void on_pushButton_E_clicked();
    void on_pushButton_F_clicked();
    void on_pushButton_G_clicked();
    void on_pushButton_H_clicked();
    void on_pushButton_I_clicked();
    void on_pushButton_J_clicked();
    void on_pushButton_K_clicked();
    void on_pushButton_L_clicked();
    void on_pushButton_M_clicked();
    void on_pushButton_N_clicked();
    void on_pushButton_O_clicked();
    void on_pushButton_P_clicked();
    void on_pushButton_Q_clicked();
    void on_pushButton_R_clicked();
    void on_pushButton_S_clicked();
    void on_pushButton_T_clicked();
    void on_pushButton_U_clicked();
    void on_pushButton_V_clicked();
    void on_pushButton_W_clicked();
    void on_pushButton_X_clicked();
    void on_pushButton_Y_clicked();
    void on_pushButton_Z_clicked();
    void on_pushButton_Enter_clicked();
    void on_pushButton_Back_clicked();
    void on_pushButton_ClearAll_clicked();
    void on_pushButton_ClearAll_2_clicked();
    void on_pushButton_EXIT_clicked();
    void on_pushButton_Pow_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
