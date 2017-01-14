#ifndef MYPLOT_H
#define MYPLOT_H
#include <qwt_polar_plot.h>
#include <QTimer>
#include <qwt_point_polar.h>
class MyQwtPolarMagnifier;
class MyQwtPolarPanner;
class QwtPolarCurve;
class QwtPolarGrid;
class MyData;
class MyPlot:public QwtPolarPlot
{
    Q_OBJECT
public:
    MyPlot();
    ~MyPlot();

    void init();
    void changePower(const uint &power);
    void changeCursor(bool grapable); //grapable==true 表示设置为抓取状态 false为常态
    void startWork(bool startable); //startable==true 表示启动扫描线
    void changeSpeed(const uint &speed); //speed r/min
protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
public slots:  
    void simulateTail();
    void changeScanLineData(); //主要是改变扫描线的Azimuth值 累次加一
signals:
    void changeMarkerPos(const QwtPointPolar&);
    void scanMarker(bool);
    void showCoord(const QwtPointPolar&);
private:
    void gridInit();
    void scanLineInit();
private:
    QwtPointPolar lastpoint;
    MyQwtPolarMagnifier* _magnifier;
    MyQwtPolarPanner* _panner;
    QwtPolarCurve* _scanline; // 雷达扫描线
    MyData* _data; //扫描显示数据
    QwtPolarGrid* _grid;
    QTimer *_timer;
    uint _RPM;  //扫描线转速 r/min
};

#endif // MYPLOT_H
