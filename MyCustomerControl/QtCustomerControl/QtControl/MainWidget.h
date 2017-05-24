#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "mygauge1.h"
#include "mygauge2.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void init();

private slots:
    // ! 1
    void onMyGauge1LineEditValueChange(QString);
    // ! 2
    void onMyGauge2LineEditValueChange(QString);
private:
    Ui::Widget *ui;
    // ! 1
    myGauge1*         m_pMyGauge1;
    QLineEdit*          m_pMyGauge1LineEdit;
    // ! 2
    myGauge2*        m_pMyGauge2;
    QLineEdit*          m_pMyGauge2LineEdit;
};

#endif // MAINWIDGET_H
