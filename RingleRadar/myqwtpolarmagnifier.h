#ifndef MYQWTPOLARMAGNIFIER_H
#define MYQWTPOLARMAGNIFIER_H

#include <Qwtpolar/qwt_polar_magnifier.h>
class MyQwtPolarMagnifier:public QwtPolarMagnifier
{
public:
    explicit MyQwtPolarMagnifier(QwtPolarCanvas *  canvas);
    ~MyQwtPolarMagnifier();
protected:
    void widgetWheelEvent (QWheelEvent *  wheelEvent);

private:
    class PrivateData;
    PrivateData *d_data;
    int lowerlimit;
    int angle;
};


#endif // MYQWTPOLARMAGNIFIER_H
