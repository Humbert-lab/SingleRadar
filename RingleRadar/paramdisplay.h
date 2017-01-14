#ifndef PARAMDISPLAY_H
#define PARAMDISPLAY_H

#include <QDialog>
#include <QAbstractButton>
#include <QMap>

namespace Ui {
class ParamDisplay;
}

class ParamDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ParamDisplay(QWidget *parent = 0);
    ~ParamDisplay();
signals:
    choisesChanged(const QMap<QString,bool>&);

private slots:
    void on_title_clicked();

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

private:
    Ui::ParamDisplay *ui;
    QMap<QString,bool> choises;
    QMap<QString,bool> tempchoises;
};

#endif // PARAMDISPLAY_H
