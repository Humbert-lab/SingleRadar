#include "mymarker.h"
#include <qwt_polar_plot.h>
MyMarker::MyMarker()
{
    init();

}
MyMarker::~MyMarker()
{
//    delete _symbol;   //delete 会出现问题
//    delete _label;
//    delete _currentpos;

}
void MyMarker::attach(QwtPolarPlot *plot)
{
    _plot = plot;
    _marker->attach(_plot);
}
void MyMarker::setLabel(const QMap<QString, bool> &choises)
{
    QString str = "";
    QMap<QString, bool>::const_iterator iter;
    for( iter = choises.constBegin(); iter!=choises.constEnd(); ++iter)
    {
        if(iter.value())
        {
            str += iter.key() + "\n";
            qDebug()<<iter.value();
        }

    }
    _label->setText(str);
    _label->setColor(QColor(0,255,0));
    _marker->setLabel(*_label);
}
void MyMarker::changePosition(const QwtPointPolar& pos)
{
    if(!pos.isValid() || pos.isNull())
        return;
    // if(pos.radius() > _plot->)
    _currentpos->setAzimuth(pos.azimuth());
    _currentpos->setRadius(pos.radius());
    _marker->setPosition(*_currentpos);
    if(_plot!=NULL)
        _plot->replot();
}
void MyMarker::scaned(bool isscaned)
{
    if(isscaned)
        _symbol->setColor(QColor(255,0,0));
    else
        _symbol->setColor(QColor(255,255,0));
}
void MyMarker::init()
{
    _plot = NULL;
    _marker = new QwtPolarMarker();
    _symbol = new QwtSymbol();
    _symbol->setStyle(QwtSymbol::Diamond);
    _symbol->setSize(QSize(10,10));
    _symbol->setColor(QColor(255,255,0));
    _symbol->setPen(QPen(Qt::red,1,Qt::DashDotLine));
    _label = new QwtText(QObject::tr("目标飞行物"));
    _label->setColor(QColor(0,255,0));
    _marker->setSymbol(_symbol);
    _marker->setLabel(*_label);
    _marker->setLabelAlignment(Qt::AlignRight);
    _currentpos = new QwtPointPolar(30,200);
    _marker->setPosition(*_currentpos);
}
