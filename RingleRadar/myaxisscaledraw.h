#ifndef MYAXISSCALEDRAW_H
#define MYAXISSCALEDRAW_H
#include <qwt_scale_draw.h>
#include <qwt_round_scale_draw.h>
class AzimuthScaleDraw: public QwtRoundScaleDraw
{
public:
    virtual QwtText label( double value ) const
    {
        QwtText text;
        QFont font;
        font.setBold(true);
        font.setPixelSize(10);
        text.setFont(font);
        QString str = "";
        str += QLocale().toString(value);
        str += "°";
        text.setText(str);
        return text;
    }
};

class MyAxisScaleDraw:public QwtScaleDraw
{
public:
    virtual QwtText label(double value) const
    {
        QwtText text;
        QFont font;
        font.setBold(true);
        font.setPixelSize(10);
        text.setFont(font);
        QString str = "";
        if(value >= 0.1)
        {
            str +=  QLocale().toString(value);
            str += "km";
        }
        else
        {
            value = value * 1000;
            str += QLocale().toString(value);
            str += "m";
        }
        text.setText(str);
        return text;

    }
};

#endif // MYAXISSCALEDRAW_H
