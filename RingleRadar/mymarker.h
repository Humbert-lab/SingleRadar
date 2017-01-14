#ifndef MYMARKER_H
#define MYMARKER_H
#include <qwt_polar_marker.h>
#include <qwt_symbol.h>
#include <qwt_text.h>
#include <qwt_polar_marker.h>
#include <QObject>

class MyMarker:public QObject
{
    Q_OBJECT
public:
   explicit MyMarker();
   ~MyMarker();
   void attach(QwtPolarPlot *plot);

public slots:
    void changePosition(const QwtPointPolar& pos);
    void scaned(bool isscaned);
    void setLabel(const QMap<QString,bool>& choises);
private:
    void init();

private:
    QwtPolarMarker* _marker;
    QwtPolarPlot* _plot;
    QwtSymbol* _symbol;
    QwtText* _label;
    QwtPointPolar* _currentpos;

};

#endif // MYMARKER_H
