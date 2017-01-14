#include "form.h"
#include "ui_form.h"
#include <qwt_polar_canvas.h>
#include "paramdisplay.h"
#include "mymarker.h"
#include "constant.h"

#include <QMessageBox>
#include <QPalette>
#include <QDebug>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    init();

    connect(setcoord_btn,SIGNAL(clicked()),this,SLOT(coordBtn_clicked()));
    connect(setRPM_btn,SIGNAL(clicked()),this,SLOT(RPMBtn_clicked()));
    connect(setpower_btn,SIGNAL(clicked()),this,SLOT(powerBtn_clicked()));
    connect(grab_act,SIGNAL(triggered(bool)),this,SLOT(grabAct_clicked()));
    connect(grab_act,SIGNAL(hovered()),this,SLOT(showGrab_message()));
    connect(unzoom_act,SIGNAL(triggered()),this,SLOT(unzoomAct_clicked()));
    connect(unzoom_act,SIGNAL(hovered()),this,SLOT(showUnzoom_message()));

    connect(start_act,SIGNAL(triggered()),this,SLOT(startAct_clicked()));
    connect(start_act,SIGNAL(hovered()),this,SLOT(showstart_message()));

    connect(param_act,SIGNAL(triggered()),this,SLOT(paramAct_clicked()));
    connect(param_act,SIGNAL(hovered()),this,SLOT(showParam_message()));

    QTimer* timer = new QTimer();
    timer->setInterval(100);
    MyMarker* marker = new MyMarker();
    marker->attach(plot);
    connect(paramdlg,SIGNAL(choisesChanged(const QMap<QString,bool>&)),marker,SLOT(setLabel(const QMap<QString,bool>&)));
    connect(timer,SIGNAL(timeout()),plot,SLOT(simulateTail()));
    connect(plot,SIGNAL(changeMarkerPos(const QwtPointPolar&)),marker,SLOT(changePosition(const QwtPointPolar&)));
    connect(plot,SIGNAL(scanMarker(bool)),marker,SLOT(scaned(bool)));
    connect(plot,SIGNAL(showCoord(const QwtPointPolar&)),this,SLOT(showCoord_message(const QwtPointPolar&)));
    timer->start();

}

Form::~Form()
{
    delete ui;
}
void Form::init()
{
    toolBarInit();
    rightWidgetInit();
    statusbar = new QStatusBar(this);
    QLabel *label1 = new QLabel(tr("Azimth:"));
    label1->setMaximumWidth(uiValue::LABELMAX_WIDTH_1);
    QLabel *label2 = new QLabel(tr("radius:"));
    label2->setMaximumWidth(uiValue::LABELMAX_WIDTH_1);
    azimuth_lab = new QLabel(statusbar);
    azimuth_lab->setMaximumWidth(uiValue::LABELMAX_WIDTH_2);
    radius_lab = new QLabel(statusbar);
    radius_lab->setMaximumWidth(uiValue::LABELMAX_WIDTH_2);
   // other_lab = new QLabel(statusbar);
    substatusbar = new QStatusBar(statusbar);
    statusbar->addPermanentWidget(substatusbar,10);
    statusbar->addPermanentWidget(label1,1);
    statusbar->addPermanentWidget(azimuth_lab,2);
    statusbar->addPermanentWidget(label2,1);
    statusbar->addPermanentWidget(radius_lab,2);
    paramdlg = new ParamDisplay(this);

    hlayout = new QHBoxLayout();
    vlayout = new QVBoxLayout();

    plot = new MyPlot();

    textedit = new QTextEdit();
    groupBox = new QGroupBox();
    groupBox->setTitle(tr("操作日志"));
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(textedit);
    groupBox->setLayout(layout);

    hlayout->addWidget(plot);
    hlayout->addLayout(vlayout_1);
    hlayout->setStretchFactor(plot,4);
    hlayout->setStretchFactor(vlayout_1,1);

    vlayout->addWidget(toolbar);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(groupBox);
    vlayout->addWidget(statusbar);
  //  vlayout->setStretchFactor(toolbar,1);
    vlayout->setStretchFactor(hlayout,7);
    vlayout->setStretchFactor(groupBox,1);

    setLayout(vlayout);

}
void Form::toolBarInit()
{
    toolbar = new QToolBar(this);

    grab_act = new QAction(tr("抓取"),this);
    grab_act->setIcon(QIcon(QPixmap(":/res/image/grab.jpg")));

    grab_act->setStatusTip(tr("抓取"));
    grab_act->setCheckable(true);
    unzoom_act = new QAction(tr("归心摆正"),this);
    unzoom_act->setIcon(QIcon(QPixmap(imagePath::unzoomPath)));
    param_act = new QAction(tr("参数设置"),this);
    param_act->setIcon(QIcon(QPixmap(imagePath::paramePath)));
    start_act = new QAction(tr("启动"),this);
    start_act->setIcon(QIcon(QPixmap(imagePath::startPath)));
    start_act->setCheckable(true);


    toolbar->addAction(grab_act);
    toolbar->addAction(unzoom_act);
    toolbar->addAction(param_act);
    toolbar->addAction(start_act);

}
void Form::rightWidgetInit()
{

    setcoord_btn = new QPushButton(tr("设置"));
    setpower_btn = new QPushButton(tr("设置"));
    setRPM_btn = new QPushButton(tr("设置"));

    longitude_lab = new QLabel(tr("经度："));
    latitude_lab = new QLabel(tr("纬度："));
    power_lab = new QLabel(tr("功率："));
    RPM_lab = new QLabel(tr("转速："));
    powerunit_lab = new QLabel(tr("km"));
    RPMunit_lab = new QLabel(tr("r/min"));

    longitude_edt = new QLineEdit(tr(""),NULL);
    latitude_edt = new QLineEdit(tr(""),NULL);
    power_sp = new QSpinBox();
    power_sp->setRange(radarValue::POWER_MIN_VALUE,radarValue::POWER_MAX_VALUE);
    power_sp->setValue(300);
    RPM_sp = new QSpinBox();
    RPM_sp->setValue(1);

    coord_lyt = new QHBoxLayout();
    RPM_lyt = new QHBoxLayout();
    power_lyt = new QHBoxLayout();
    vlayout_1 = new QVBoxLayout();

    coord_lyt->addWidget(longitude_lab);
    coord_lyt->addWidget(longitude_edt);
    coord_lyt->addWidget(latitude_lab);
    coord_lyt->addWidget(latitude_edt);
    coord_lyt->addWidget(setcoord_btn);


    RPM_lyt->addWidget(RPM_lab);
    RPM_lyt->addWidget(RPM_sp);
    RPM_lyt->addWidget(RPMunit_lab);
    RPM_lyt->addWidget(setRPM_btn);

    power_lyt->addWidget(power_lab);
    power_lyt->addWidget(power_sp);
    power_lyt->addWidget(powerunit_lab);
    power_lyt->addWidget(setpower_btn);
    coord_lyt->setSizeConstraint(QLayout::SetMinimumSize);
    vlayout_1->addStretch(1);
    vlayout_1->addLayout(coord_lyt);
    vlayout_1->addLayout(RPM_lyt);
    vlayout_1->addLayout(power_lyt);

}
void Form::showGrab_message()
{

    if(grab_act->isChecked())
        substatusbar->showMessage(statusMessage::UNGRAB_MESSAGE,1000);
    else
        substatusbar->showMessage(statusMessage::GRAB_MESSAGE,1000);
}
void Form::showUnzoom_message()
{
    substatusbar->showMessage(statusMessage::UNZOOM_MESSAGE,1000);
}
void Form::showParam_message()
{
    substatusbar->showMessage(statusMessage::SETPARAME_MESSAGE,1000);
}
void Form::showstart_message()
{

    if(start_act->isChecked())
        substatusbar->showMessage(statusMessage::STOPSCAN_MESSAGE,1000);
    else
        substatusbar->showMessage(statusMessage::STARTSCAN_MESSAGE,1000);

}
void Form::showCoord_message(const QwtPointPolar& ppoint)
{
    QString azimuth_str = "";
    QString radius_str = "";
    azimuth_str += QLocale().toString(ppoint.azimuth()) + "°";
    radius_str += QLocale().toString(ppoint.radius()) + "km";
    azimuth_lab->setText(azimuth_str);
    radius_lab->setText(radius_str);
}
void Form::grabAct_clicked()
{
    plot->changeCursor(grab_act->isChecked());

}
void Form::unzoomAct_clicked()
{
    plot->unzoom();
    plot->replot();
}
void Form::paramAct_clicked()
{
    paramdlg->showNormal();
}
void Form::startAct_clicked()
{
    plot->startWork(start_act->isChecked());
    start_act->isChecked()?start_act->setText(tr("暂停")):start_act->setText(tr("启动"));
    start_act->isChecked()?start_act->setIcon(QIcon(QPixmap(imagePath::startPath)))
                         : start_act->setIcon(QIcon(QPixmap(imagePath::stopPath)));
}

void Form::coordBtn_clicked()
{
    qDebug()<<width()<<" "<<height()<<endl;
    QMessageBox::information(this,tr("坐标设置提示"),tr("设置成功"));
}
void Form::RPMBtn_clicked()
{
    qDebug()<<RPM_sp->text().toUInt();
    uint speed = RPM_sp->text().toUInt();
    plot->changeSpeed(speed);
    QMessageBox::information(this,tr("转速设置提示"),tr("设置成功"));
}
void Form::powerBtn_clicked()
{
    uint power = power_sp->value();
    plot->changePower(power);
    QMessageBox::information(this,tr("功率设置提示"),tr("设置成功"));
}
