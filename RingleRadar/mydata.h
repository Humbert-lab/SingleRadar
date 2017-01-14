#ifndef MYDATA_H
#define MYDATA_H
#include <Qwt/qwt_series_data.h>
#include <qwt_series_data.h>
#include <qwt_point_polar.h>
#include <QObject>

class MyData:public QwtSeriesData<QwtPointPolar>
{

public:
    MyData();
    ~MyData();
    void setLength(const int& length);
    void setAzimuth(const double& azimuth);
    void updateAzimuth();
private:
    virtual size_t size() const;
    virtual QwtPointPolar sample(size_t i) const;
    virtual QRectF boundingRect() const;
public:
    int _length;
    mutable int _azimuth;
};

#endif // MYDATA_H
