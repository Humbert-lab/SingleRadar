#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <qwt_polar_plot.h>
#include <QStatusBar>
#include "myplot.h"
namespace Ui {
class Form;
}
class ParamDisplay;

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
private:
    void init();
    void toolBarInit();
    void rightWidgetInit();
public slots:
    void showGrab_message();
    void showUnzoom_message();
    void showParam_message();
    void showstart_message();
    void showCoord_message(const QwtPointPolar& point);
    void grabAct_clicked();
    void unzoomAct_clicked();
    void paramAct_clicked();
    void startAct_clicked();
    void coordBtn_clicked();
    void RPMBtn_clicked();
    void powerBtn_clicked();
private:
    Ui::Form *ui;
    QPushButton *setcoord_btn; //设置坐标的按钮
    QPushButton *setRPM_btn; //设置转速的按钮
    QPushButton *setpower_btn; //设置雷达扫描范围

    QLabel *longitude_lab; //显示经度的标签
    QLabel *latitude_lab; //显示纬度的标签
    QLabel *RPM_lab;   //显示扫描转速的标签 RPM:Revolutions Per minute
    QLabel *power_lab; //显示功率范围的标签
    QLabel *RPMunit_lab;// 转速扫描单位标签 r/min
    QLabel *powerunit_lab; //功率扫描范围标签 km

    QLabel *azimuth_lab; //状态栏显示azimuth的标签
    QLabel *radius_lab;
    QStatusBar* substatusbar;

    QLineEdit *longitude_edt; //经度编辑框
    QLineEdit *latitude_edt; //纬度编辑框
    QSpinBox *RPM_sp; // 转速调整
    QSpinBox *power_sp; //功率范围调整

    QToolBar *toolbar; //工具栏
    QAction *grab_act; //改变鼠标形状 按钮
    QAction *unzoom_act; //归心摆正按钮
    QAction *param_act; //设置目标飞行物显示参数
    QAction *start_act;

    QStatusBar *statusbar;

    QHBoxLayout* hlayout;
    QHBoxLayout* coord_lyt; //坐标布局
    QHBoxLayout* RPM_lyt; //转速布局
    QHBoxLayout* power_lyt; //功率布局
    QVBoxLayout* vlayout;
    QVBoxLayout* vlayout_1;  //参数设置布局
    QGroupBox* groupBox;
    QTextEdit * textedit;
    MyPlot *plot;
    ParamDisplay* paramdlg;


};

#endif // FORM_H
