#include "myplot.h"
#include <qwt_polar_canvas.h>
#include <qwt_polar_plot.h>
#include <qwt_polar_grid.h>
#include <qwt_polar_curve.h>
#include <myqwtpolarmagnifier.h>
#include <myqwtpolarpanner.h>
#include <QDateTime>
#include "myaxisscaledraw.h"
#include "constant.h"
#include <QTimer>
#include "mydata.h"
#include <QMouseEvent>
MyPlot::MyPlot()
{
    init();
    setMouseTracking(true); //不点击鼠标也能够捕获鼠标移动事件
    canvas()->setMouseTracking(true);
    connect(_timer,SIGNAL(timeout()),this,SLOT(changeScanLineData()));

}
MyPlot::~MyPlot()
{
   // delete _data;  //delete 掉 会出错
}
void MyPlot::init()
{
    lastpoint.setAzimuth(30);
    lastpoint.setRadius(200);
  //  setTitle(QObject::tr("雷达P显"));
    setBackgroundRole(QPalette::Base);
    setPlotBackground(QBrush(Qt::black));
    setStyleSheet("background:black");
    setAutoFillBackground(true);
    setScale(QwtPolar::ScaleAzimuth,radarValue::AZIMUTH_MAX_VALUE,
             radarValue::AZIMUTH_MIN_VALUE,30); //change to closewise
    setScale(QwtPolar::ScaleRadius,0,300);
    setAzimuthOrigin(M_PI/2);
    gridInit();
    _magnifier = new MyQwtPolarMagnifier(this->canvas());
    _panner = new MyQwtPolarPanner(this->canvas());
    scanLineInit();
    this->canvas()->setCursor(Qt::ArrowCursor); //画布 设置才有效
    _RPM = 1;
    _timer = new QTimer(this);
    _timer->setInterval(500/(_RPM*3));
   // _timer->setInterval(50);
}
void MyPlot::gridInit()
{
    _grid = new QwtPolarGrid();
    _grid->setFont(QFont("Times",16,QFont::Bold));
    _grid->setPen(QPen(Qt::green,1,Qt::DashDotLine));
    _grid->setAxisPen(QwtPolar::AxisAzimuth,QPen(Qt::red,1));

    _grid->setAzimuthScaleDraw( new AzimuthScaleDraw() );
    MyAxisScaleDraw* rightdraw = new MyAxisScaleDraw();
    rightdraw->setAlignment(QwtScaleDraw::BottomScale);
    _grid->setScaleDraw(QwtPolar::AxisRight,rightdraw);
    MyAxisScaleDraw *topDraw = new MyAxisScaleDraw();
    topDraw->setAlignment(QwtScaleDraw::LeftScale);
    _grid->setScaleDraw(QwtPolar::AxisTop,topDraw);

    _grid->showAxis(QwtPolar::AxisAzimuth,true);
    _grid->showAxis(QwtPolar::AxisLeft,false);
    _grid->showAxis(QwtPolar::AxisRight,true);
    _grid->showAxis(QwtPolar::AxisTop,true);
    _grid->showAxis(QwtPolar::AxisBottom,false);

    _grid->setAxisPen(QwtPolar::AxisRight,QPen(Qt::red,1,Qt::DashDotLine));//坐标系中右边的线
    _grid->setAxisPen(QwtPolar::AxisTop,QPen(Qt::red,1,Qt::DashDotLine));
    _grid->attach(this);
}
void MyPlot::scanLineInit()
{
    _scanline = new QwtPolarCurve();
    _scanline->setPen(QPen(Qt::red,2));
    _data = new MyData();

    _scanline->setData(_data);

    _scanline->attach(this);
}
void MyPlot::changePower(const uint &power)
{
    _data->setLength(power);
    setScale(QwtPolar::ScaleRadius,0,power);
    replot();
}
void MyPlot::changeCursor(bool grapable)
{
    this->canvas()->setCursor(grapable?Qt::OpenHandCursor:Qt::ArrowCursor);
}
void MyPlot::startWork(bool startable)
{
    startable?_timer->start():_timer->stop();
}
void MyPlot::changeSpeed(const uint &speed)
{
    if(speed <= 0)
    {
        _timer->stop();
        return;
    }
    _timer->start();
    _RPM = speed;
    int interval = 500/(_RPM*3);
    _timer->setInterval(interval);
}
void MyPlot::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->pos();  //程序界面坐标系，左上角为原点
    QwtPointPolar ppoint = this->canvas()->invTransform(point);
    emit showCoord(ppoint);
}
void MyPlot::simulateTail()
{
    lastpoint.setAzimuth(((int)(lastpoint.azimuth() + 1)) % radarValue::AZIMUTH_MAX_VALUE);
    emit changeMarkerPos(lastpoint);
}

void MyPlot::changeScanLineData()
{
    _data->updateAzimuth();
    if(abs(_data->_azimuth-lastpoint.azimuth()) < 3)
        emit scanMarker(true);
    else emit scanMarker(false);
    static int test = 0;
    if(test == 0)
    {
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString strTime = time.toString("yyyy-MM-dd hh:mm:ss");//设置系统时间显示格式
        qDebug()<<"start:"<<strTime<<endl;
    }else if(test == 360)
    {
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString strTime = time.toString("yyyy-MM-dd hh:mm:ss");//设置系统时间显示格式
        qDebug()<<"end:"<<strTime<<endl;
    }
    test++;
    replot();
}
