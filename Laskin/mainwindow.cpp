#include "mainwindow.h"
#include "ui_mainwindow.h"
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
void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if (state == 0) {
        number1 += name.right(1);
        ui->Number1->setText(number1);
    }
    else{
        number2 += name.right(1);
        ui->Number2->setText(number2);
    }
}
void  MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    if (name == "Clear")
    {
        resetLineEdits();
    }
    else if (name == "Enter")
    {
        float num1 = number1.toFloat();
        float num2 = number2.toFloat();
        switch (operand){
        case 0:
            result = num1 + num2;
            break;
        case 1:
            result = num1 - num2;
            break;
        case 2:
            result = num1 * num2;
            break;
        case 3:
            result = num1 / num2;
            break;
        }
        ui->Result->setText(QString::number(result));
    }
}
void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    operand = name.right(1).toShort();
    state = 1;
}
void MainWindow::resetLineEdits()
{
    number1.clear();
    number2.clear();
    ui->Number1->setText("");
    ui->Number2->setText("");
    ui->Result->setText("");
    state = 0;
}
void MainWindow::on_N0_clicked() { numberClickedHandler(); }
void MainWindow::on_N1_clicked() { numberClickedHandler(); }
void MainWindow::on_N2_clicked() { numberClickedHandler(); }
void MainWindow::on_N3_clicked() { numberClickedHandler(); }
void MainWindow::on_N4_clicked() { numberClickedHandler(); }
void MainWindow::on_N5_clicked() { numberClickedHandler(); }
void MainWindow::on_N6_clicked() { numberClickedHandler(); }
void MainWindow::on_N7_clicked() { numberClickedHandler(); }
void MainWindow::on_N8_clicked() { numberClickedHandler(); }
void MainWindow::on_N9_clicked() { numberClickedHandler(); }
void MainWindow::on_Clear_clicked() { clearAndEnterClickHandler(); }
void MainWindow::on_Enter_clicked() { clearAndEnterClickHandler(); }
void MainWindow::on_Add0_clicked() { addSubMulDivClickHandler(); }
void MainWindow::on_Neg1_clicked() { addSubMulDivClickHandler(); }
void MainWindow::on_Mul2_clicked() { addSubMulDivClickHandler(); }
void MainWindow::on_Div3_clicked() { addSubMulDivClickHandler(); }
