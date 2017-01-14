#include "paramdisplay.h"
#include "ui_paramdisplay.h"
#include <QAbstractButton>
#include <QDebug>
ParamDisplay::ParamDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParamDisplay)
{
    ui->setupUi(this);
    ui->title->setCheckState(Qt::Checked);
    choises.insert(QString("title"),true);
    choises.insert(QString("parame1"),false);
    choises.insert(QString("parame2"),false);
    tempchoises = choises;
}

ParamDisplay::~ParamDisplay()
{
    delete ui;
}


void ParamDisplay::on_title_clicked()
{
    if(ui->title->checkState()==Qt::Checked)
        tempchoises["title"] = true;
    else
        tempchoises["title"] = false;
}

void ParamDisplay::on_pushButton_ok_clicked()
{
    choises = tempchoises;
    emit choisesChanged(choises);
    close();
}

void ParamDisplay::on_pushButton_cancel_clicked()
{
    tempchoises = choises;
    ui->title->setCheckState(choises["title"]?Qt::Checked:Qt::Unchecked);
    ui->checkBox_2->setCheckState(choises["parame1"]?Qt::Checked:Qt::Unchecked);
    ui->checkBox_3->setCheckState(choises["parame2"]?Qt::Checked:Qt::Unchecked);
    close();
}

void ParamDisplay::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->checkState()==Qt::Checked)
        tempchoises["parame1"] = true;
    else
        tempchoises["parame1"] = false;
}

void ParamDisplay::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->checkState()==Qt::Checked)
        tempchoises["parame2"] = true;
    else
        tempchoises["parame2"] = false;
}
