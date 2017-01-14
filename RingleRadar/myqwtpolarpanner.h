#ifndef MYQWTPOLARPANNER_H
#define MYQWTPOLARPANNER_H
#include <qwt_polar_panner.h>
class MyQwtPolarPanner:public QwtPolarPanner
{
public:
    explicit MyQwtPolarPanner(QwtPolarCanvas* canvas);
    ~MyQwtPolarPanner();
protected:

    void widgetMousePressEvent(QMouseEvent * event);
    void widgetMouseMoveEvent(QMouseEvent *event);
    void widgetMouseReleaseEvent(QMouseEvent *event);

    void paintEvent (QPaintEvent * pe);
private:
   QPoint origin;


};
#endif // MYQWTPOLARPANNER_H
