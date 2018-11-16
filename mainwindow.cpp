#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QfileInfo>
#include <Qfile>
#include <QTextStream>

#include "parser.h"
#include "stackjw.h"
QString expression = "", result = "";
Parser brain;
string line, line2, line3;
int Number1, Number2;
bool addBool = false, subBool = false, mulBool = false, divBool = false, powBool = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    line = "";
    line2 = "";
    line3 = "";
    cout<<"call read"<<endl;
    QString filename = "../../../mapdata.txt";
    cout << "mainwindow 25" << endl;
    QFile qf(filename);
    QFileInfo qfinfo(filename);
    if(qfinfo.exists() && qfinfo.isFile()){
        cout << "mainwindow 25" << endl;
        if(qf.open(QIODevice::ReadWrite)){
            QTextStream steam(&qf);
            QString line;
            int time = 0;
            while(!steam.atEnd()){{
                    line = steam.readLine();
                    cout << "time:: " << ++time << endl;
                    cout << "mainwindow 31: " << line.toStdString()<< endl;
                    string strline = line.toUtf8().constData();
                    cout << "mainwindow 32: " << strline << endl;
                    cout << "strline.size(): " << strline.size() << endl;
                    brain.READ(strline);
                }
            }
            ui->setupUi(this);
        }
    }
}
MainWindow::~MainWindow()
{
    brain.WRITE();
    delete ui;
}

void MainWindow::cleanScreen(){
    expression = result = "";
    line = "";
    line3 = "";
    ui->textEdit->setText(expression);
}

void MainWindow::clear(){
    expression = result = "";
    line = "";
    line2 = "";
    line3 = "";
    ui->textEdit->setText(expression);
}

void MainWindow::space(){
    expression = expression + " ";
    ui->textEdit->setText(expression);
}

void MainWindow::equals(){
    expression = expression + " = ";
    ui->textEdit->setText(expression);
}

void MainWindow::add(){
    expression = expression + "+";
    ui->textEdit->setText(expression);
}

void MainWindow::sub(){
    expression = expression + "-";
    ui->textEdit->setText(expression);
    brain.WRITE();
}

void MainWindow::mul(){
    expression = expression + "*";
    ui->textEdit->setText(expression);
}

void MainWindow::div(){
    expression = expression + "/";
    ui->textEdit->setText(expression);
}

void MainWindow::pow(){
    expression = expression + "^";
    ui->textEdit->setText(expression);
}

void MainWindow::one(){
    expression = expression + "1";
    ui->textEdit->setText(expression);
}

void MainWindow::two(){
    expression = expression + "2";
    ui->textEdit->setText(expression);
}

void MainWindow::three(){
    expression = expression + "3";
    ui->textEdit->setText(expression);
}

void MainWindow::four(){
    expression = expression + "4";
    ui->textEdit->setText(expression);
}

void MainWindow::five(){
    expression = expression + "5";
    ui->textEdit->setText(expression);
}

void MainWindow::six(){
    expression = expression + "6";
    ui->textEdit->setText(expression);
}

void MainWindow::seven(){
    expression = expression + "7";
    ui->textEdit->setText(expression);
}

void MainWindow::eight(){
    expression = expression + "8";
    ui->textEdit->setText(expression);
}

void MainWindow::nine(){
    expression = expression + "9";
    ui->textEdit->setText(expression);
}

void MainWindow::zero(){
    expression = expression + "0";
    ui->textEdit->setText(expression);
}

void MainWindow::leftP(){
    expression = expression + "(";
    ui->textEdit->setText(expression);
}

void MainWindow::rightP(){
    expression = expression + ")";
    ui->textEdit->setText(expression);
}

void MainWindow::dot(){
    expression = expression + ".";
    ui->textEdit->setText(expression);
}

void MainWindow::on_pushButton_clicked(){      //'1'
    one();
}
void MainWindow::on_pushButton_2_clicked(){      //'2'
    two();
}
void MainWindow::on_pushButton_3_clicked(){      //'3'
    three();
}
void MainWindow::on_pushButton_4_clicked(){      //'4'
    four();
}
void MainWindow::on_pushButton_5_clicked(){      //'5'
    five();
}
void MainWindow::on_pushButton_6_clicked(){      //'6'
    six();
}
void MainWindow::on_pushButton_7_clicked(){      //'7'
    seven();
}
void MainWindow::on_pushButton_8_clicked(){      //'8'
    eight();
}
void MainWindow::on_pushButton_9_clicked(){      //'9'
    nine();
}
void MainWindow::on_pushButton_10_clicked(){    //'0'
    zero();
}
void MainWindow::on_pushButton_19_clicked(){     //'('
    leftP();
}
void MainWindow::on_pushButton_18_clicked(){    //')'
    rightP();
}
void MainWindow::on_pushButton_20_clicked(){    //' '
    space();
}
void MainWindow::on_pushButton_12_clicked(){    //'+'
    add();
}
void MainWindow::on_pushButton_13_clicked(){    //'-'
    sub();
}
void MainWindow::on_pushButton_14_clicked(){    //'*'
    mul();
}
void MainWindow::on_pushButton_15_clicked(){    //'/'
    div();
}
void MainWindow::on_pushButton_16_clicked(){    //'.'
    dot();
}
void MainWindow::on_pushButton_AC_clicked(){     //clear
    clear();
}
void MainWindow::on_pushButton_Equals_clicked(){
    equals();
}
void MainWindow::on_pushButton_Pow_clicked(){
    pow();
}
void MainWindow::on_pushButton_A_clicked(){
    expression = expression  + "A";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_B_clicked(){
    expression = expression  + "B";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_C_clicked(){
    expression = expression  + "C";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_D_clicked(){
    expression = expression  + "D";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_E_clicked(){
    expression = expression  + "E";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_F_clicked(){
    expression = expression + "F";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_G_clicked(){
    expression = expression + "G";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_H_clicked(){
    expression = expression + "H";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_I_clicked(){
    expression = expression + "I";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_J_clicked(){
    expression = expression + "G";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_K_clicked(){
    expression = expression + "K";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_L_clicked(){
    expression = expression + "L";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_M_clicked(){
    expression = expression + "M";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_N_clicked(){
    expression = expression + "N";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_O_clicked(){
    expression = expression + "O";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_P_clicked(){
    expression = expression + "P";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_Q_clicked(){
    expression = expression + "Q";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_R_clicked(){
    expression = expression + "R";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_S_clicked(){
    expression = expression + "S";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_T_clicked(){
    expression = expression + "T";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_U_clicked(){
    expression = expression + "U";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_V_clicked(){
    expression = expression + "V";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_W_clicked(){
    expression = expression + "W";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_X_clicked(){
    expression = expression + "X";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_Y_clicked(){
    expression = expression + "Y";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_Z_clicked(){
    expression = expression + "Z";
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_Enter_clicked()
{
    string line = ui->textEdit->toPlainText().toUtf8().constData();
        line2 = brain.getUserInput2(line);
        cleanScreen();
        expression = expression + QString::fromStdString(line2);
        ui->textEdit->setText(expression);
        line2 = "";
        expression = "";
}
void MainWindow::on_pushButton_Back_clicked(){
    expression.chop(1);
    ui->textEdit->setText(expression);
}
void MainWindow::on_pushButton_ClearAll_clicked(){
    brain.getUserInput2("CLEAR");
    expression = "CLEARED";
    ui->textEdit->setText(expression);
    expression = "";
}
void MainWindow::on_pushButton_ClearAll_2_clicked(){
    string line = ui->textEdit->toPlainText().toUtf8().constData();
    line2 = "CLEAR "+line;
    cout << "[" << line2 <<"]" << endl;
    brain.getUserInput2(line2);

    expression = QString::fromStdString(line) + " CLEARED";
    ui->textEdit->setText(expression);
    expression = "";
}
void MainWindow::on_pushButton_EXIT_clicked(){
    close();
    qApp->quit();
}
