#include "myqwtpolarmagnifier.h"
#include <qwt_scale_div.h>
#include <qwt_polar_plot.h>
#include <QWheelEvent>
#include <QPoint>
class MyQwtPolarMagnifier::PrivateData
{
public:
    PrivateData():
        isEnabled( false ),
        wheelFactor( 0.9 ),
        wheelModifiers( Qt::NoModifier ),
        mouseFactor( 0.95 ),
        mouseButton( Qt::RightButton ),
        mouseButtonModifiers( Qt::NoModifier ),
        keyFactor( 0.9 ),
        zoomInKey( Qt::Key_Plus ),
        zoomInKeyModifiers( Qt::NoModifier ),
        zoomOutKey( Qt::Key_Minus ),
        zoomOutKeyModifiers( Qt::NoModifier ),
        mousePressed( false )
    {
    }

    bool isEnabled;

    double wheelFactor;
    Qt::KeyboardModifiers wheelModifiers;

    double mouseFactor;

    Qt::MouseButton mouseButton;
    Qt::KeyboardModifiers mouseButtonModifiers;

    double keyFactor;

    int zoomInKey;
    Qt::KeyboardModifiers zoomInKeyModifiers;

    int zoomOutKey;
    Qt::KeyboardModifiers  zoomOutKeyModifiers;

    bool mousePressed;
    bool hasMouseTracking;
    QPoint mousePos;
};
MyQwtPolarMagnifier::MyQwtPolarMagnifier(QwtPolarCanvas *  canvas):
    QwtPolarMagnifier(canvas)
{
    d_data = new PrivateData();
    lowerlimit = -10680;
    angle = 0;
}

MyQwtPolarMagnifier::~MyQwtPolarMagnifier()
{
   delete d_data;
}
void MyQwtPolarMagnifier::widgetWheelEvent(QWheelEvent *wheelEvent)
{
    QwtPolarPlot* plt = plot();
    QwtScaleDiv *scaleDiv = plt->scaleDiv(QwtPolar::ScaleRadius);
//    if(scaleDiv==NULL)
//        qDebug()<<"empty"<<endl;
//    int array = 0;
//    QList<double> list = scaleDiv->ticks(QwtScaleDiv::MinorTick);
//    foreach (double pa, list) {
//       qDebug()<<pa<<" ";
//    }
//    const double center =
//            scaleDiv->lowerBound() + scaleDiv->range() / 2;

//    qDebug()<<"lowerBound:"<<scaleDiv->lowerBound()
//           <<"   upperBound:"<<scaleDiv->upperBound();
//    qDebug()<<"range:"<<scaleDiv->range();
//    qDebug()<<"center:"<<center;
//    qDebug()<<"scaleMaxMajor:"<<plt->scaleMaxMajor(QwtPolar::ScaleRadius)
//           <<"  scaleMaxMinor:"<<plt->scaleMaxMinor(QwtPolar::ScaleRadius);
//    QwtScaleEngine* engine = plt->scaleEngine (QwtPolar::ScaleRadius);
//    qDebug()<<"lowerMa:"<<engine->lowerMargin()<<
//              "  upperMg:"<<engine->upperMargin()<<endl;

   // plt->setScaleDiv(QwtScaleDiv::MajorTick, center - width_2, center + width_2 );

    if ( d_data->wheelFactor != 0.0 )
    {
        /*
            A positive delta indicates that the wheel was
            rotated forwards away from the user; a negative
            value indicates that the wheel was rotated
            backwards toward the user.
            Most mouse types work in steps of 15 degrees,
            in which case the delta value is a multiple
            of 120 (== 15 * 8).
         */
            int scaleAngle = 0;
            if ( wheelEvent->delta() > 0 )
            {

                if(angle < 0)
                {
                    angle += wheelEvent->delta();
                    if(angle >= 0)
                    {
                        scaleAngle = wheelEvent->delta() - (angle - 0);
                        angle = 0;
                    }
                    else scaleAngle = wheelEvent->delta();
                }
            }
            else
            {

                if(angle > lowerlimit)
                {
                      angle += wheelEvent->delta();
                      if(angle <= lowerlimit)
                      {
                          scaleAngle = wheelEvent->delta() - (angle - lowerlimit);
                          angle = lowerlimit;
                      }
                      else scaleAngle = wheelEvent->delta();
                }
            }
            double f = d_data->wheelFactor;
            int times = qAbs(scaleAngle / 120.0);
            if(wheelEvent->delta() > 0)
                 f = 1 / f;
            qDebug()<<"scaleAngle:"<<scaleAngle<<" times"<<times;
            qDebug()<<"angle:"<<angle<<" factor:"<<f<<endl;
            if(angle >= lowerlimit)
            {
               while(times--)
                  rescale( f );
            }
    }

}
