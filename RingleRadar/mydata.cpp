#include "mydata.h"
#include "constant.h"

MyData::MyData()
{
    _length = 300;
    _azimuth = 0;
}
MyData::~MyData()
{

}
void MyData::setLength(const int &length)
{
    _length = length;
}
void MyData::updateAzimuth()
{
    _azimuth = (_azimuth + 1) % radarValue::AZIMUTH_MAX_VALUE;
}
void MyData::setAzimuth(const double& azimuth)
{
    _azimuth = azimuth;
}
size_t MyData::size() const
{
    return (_length + 1);
}
QwtPointPolar MyData::sample(size_t i) const
{
    double theta = _azimuth / (radarValue::AZIMUTH_MAX_VALUE / 2) * M_PI;
    double r;
    r = qAbs(i / cos(theta));
    if(r>(_length + 1))
        r  = _length;
    QwtPointPolar point(_azimuth,r);
    return point;
}
QRectF MyData::boundingRect() const
{
    return QRectF(); // 暂时不用
}
