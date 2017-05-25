#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include "mygauge1.h"
#include "mygauge2.h"
#include "mygauge3.h"
#include "mycoolbar.h"
#include "qcustomplot.h"

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
    // ! 6
    void initCustomPlot2();

public:

private slots:
    // ! 1
    void onMyGauge1LineEditValueChange(QString);
    // ! 2
    void onMyGauge2LineEditValueChange(QString);
    // ! 3
    void onMyGauge3LineEditMinValueChange(QString);
    void onMyGauge3LineEditMaxValueChange(QString);
    void onMyGauge3Value(qreal);
    // ! 4
    void onMyCoolBarLineEditValue(int);
    // ! 5
    void addRandomGraph();
    // ! 7
    void initCustomPlot3();
private:
    Ui::Widget *ui;
    // ! 1
    myGauge1*         m_pMyGauge1;
    QLineEdit*          m_pMyGauge1LineEdit;
    // ! 2
    myGauge2*        m_pMyGauge2;
    QLineEdit*          m_pMyGauge2LineEdit;
    // ! 3
    myGauge3*        m_pMyGauge3;
    QLineEdit*          m_pMyGauge3LineEditMax;
    QLineEdit*          m_pMyGauge3LineEditMin;
    QLineEdit*          m_pMyGauge3LineEditCurVal;
    // ! 4
    myCoolBar*       m_pMyCoolBar;
    QLineEdit*         m_pMyCoolBarLineEditCurVal;
};

#endif // MAINWIDGET_H
