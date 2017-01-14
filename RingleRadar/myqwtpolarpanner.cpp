#include "myqwtpolarpanner.h"
#include <QPoint>
#include "myplot.h"
#include <qwt_polar_canvas.h>
#include <qwt_polar_plot.h>
#include <QMouseEvent>
MyQwtPolarPanner::MyQwtPolarPanner(QwtPolarCanvas* canvas):QwtPolarPanner(canvas)
{

}
MyQwtPolarPanner::~MyQwtPolarPanner()
{

}
void MyQwtPolarPanner::widgetMousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton
       &&canvas()->cursor().shape() == Qt::OpenHandCursor)
    {
        QCursor cursor(Qt::ClosedHandCursor);
        canvas()->setCursor(cursor);

        QPoint point = event->pos();  //程序界面坐标系，左上角为原点
        origin = point;
    }
    event->accept();
}
void MyQwtPolarPanner::widgetMouseMoveEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton
       &&canvas()->cursor().shape() == Qt::ClosedHandCursor)
    {
        QPoint gpoint = event->globalPos(); //电脑屏幕坐标系 左上角为原点
   }

   // MyPlot* plot = dynamic_cast<MyPlot*>(this->plot());
    //emit plot->showCoord();
    event->accept();
    //   movePlot(point.x,point.y);
}
void MyQwtPolarPanner::widgetMouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton
       &&canvas()->cursor().shape() == Qt::ClosedHandCursor)
    {
        QCursor cursor(Qt::OpenHandCursor);
        canvas()->setCursor(cursor);
        QPoint point = event->pos();  //程序界面坐标系，左上角为原点
        int offsetx = point.x() - origin.x();
        int offsety = point.y() - origin.y();
        movePlot(offsetx,offsety);
    }
    event->accept();
}
void MyQwtPolarPanner::paintEvent(QPaintEvent *pe)
{

}
