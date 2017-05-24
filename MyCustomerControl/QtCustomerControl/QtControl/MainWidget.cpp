#include "MainWidget.h"
#include "ui_MainWidget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    // ! 1
    m_pMyGauge1 = new myGauge1(this);
    m_pMyGauge1->setGeometry(0, 0, 300, 300);
    m_pMyGauge1LineEdit = new QLineEdit(this);
    m_pMyGauge1LineEdit->setGeometry(100, 310, 100, 20);
    connect(m_pMyGauge1LineEdit, SIGNAL(textChanged(QString)), this, SLOT(onMyGauge1LineEditValueChange(QString)));
    m_pMyGauge1LineEdit->setStyleSheet("QLineEdit{border: 1px solid gray;border-radius:5px; background:rgba(255,255,255,0);\
                                                                 padding: 0px 10px 0px 20px; background:yellow; selection-background-color: darkgray;}");
    m_pMyGauge1LineEdit->setValidator(new QIntValidator(0, 100, this));

    // ! 2
    m_pMyGauge2 = new myGauge2(this);
    m_pMyGauge2->setGeometry(350, 0, 300, 300);
    m_pMyGauge2LineEdit = new QLineEdit(this);
    m_pMyGauge2LineEdit->setGeometry(450, 310, 100, 20);
    connect(m_pMyGauge2LineEdit, SIGNAL(textChanged(QString)), this, SLOT(onMyGauge2LineEditValueChange(QString)));
    m_pMyGauge2LineEdit->setStyleSheet("QLineEdit{border: 1px solid gray;border-radius:5px; background:rgba(255,255,255,0);\
                                       padding: 0px 10px 0px 20px; background: blue; selection-background-color: darkgray;}");
    m_pMyGauge2LineEdit->setValidator(new QIntValidator(0, 100, this));

    // ! 3
    m_pMyGauge3 = new myGauge3(this);
    m_pMyGauge3->setGeometry(700, 0, 500, 100);
    m_pMyGauge3LineEditMin = new QLineEdit(this);
    m_pMyGauge3LineEditMax = new QLineEdit(this);
    m_pMyGauge3LineEditCurVal = new QLineEdit(this);
    m_pMyGauge3LineEditCurVal->setEnabled(false);
    m_pMyGauge3LineEditCurVal->setFocusPolicy(Qt::NoFocus);
    m_pMyGauge3LineEditMin->setGeometry(750, 110, 80, 20);
    m_pMyGauge3LineEditMax->setGeometry(830, 110, 80, 20);
    m_pMyGauge3LineEditCurVal->setGeometry(950, 110, 100, 20);
    m_pMyGauge3LineEditMin->setStyleSheet("QLineEdit{border: 1px solid gray;border-radius:5px; background:rgba(255,255,255,0);\
                                          padding: 0px 10px 0px 20px; background: red; selection-background-color: darkgray;}");
    m_pMyGauge3LineEditMax->setStyleSheet("QLineEdit{border: 1px solid gray;border-radius:5px; background:rgba(255,255,255,0);\
                                          padding: 0px 10px 0px 20px; background: green; selection-background-color: darkgray;}");
    m_pMyGauge3LineEditCurVal->setStyleSheet("QLineEdit{border: 1px solid gray;border-radius:5px; background:rgba(255,255,255,0);\
                                             padding: 0px 10px 0px 20px; background: #386544; selection-background-color: darkgray;}");
    m_pMyGauge3LineEditMin->setPlaceholderText("Min");
    m_pMyGauge3LineEditMax->setPlaceholderText("Max");
    m_pMyGauge3LineEditCurVal->setPlaceholderText("Value");
    connect(m_pMyGauge3, SIGNAL(valueChanged(qreal)), this, SLOT(onMyGauge3Value(qreal)));
    connect(m_pMyGauge3LineEditMin, SIGNAL(textChanged(QString)), this, SLOT(onMyGauge3LineEditMinValueChange(QString)));
    connect(m_pMyGauge3LineEditMax, SIGNAL(textChanged(QString)), this, SLOT(onMyGauge3LineEditMaxValueChange(QString)));
    m_pMyGauge3LineEditMin->setValidator(new QIntValidator(0, 200, this));
    m_pMyGauge3LineEditMax->setValidator(new QIntValidator(0, 200, this));
}

void Widget::onMyGauge1LineEditValueChange(QString text)
{
    int nValue = text.toInt();
    m_pMyGauge1->setValue(nValue);
}

void Widget::onMyGauge2LineEditValueChange(QString text)
{
    int nValue = text.toInt();
    m_pMyGauge2->setValue(nValue);
}

void Widget::onMyGauge3LineEditMinValueChange(QString text)
{
    if(m_pMyGauge3LineEditMax->text().isEmpty())
        return;
    m_pMyGauge3->setRange(text.toInt(), m_pMyGauge3LineEditMax->text().toInt());
}

void Widget::onMyGauge3LineEditMaxValueChange(QString text)
{
    if(m_pMyGauge3LineEditMin->text().isEmpty())
        return;
    m_pMyGauge3->setRange(m_pMyGauge3LineEditMin->text().toInt(), text.toInt());
}

void Widget::onMyGauge3Value(qreal value)
{
    m_pMyGauge3LineEditCurVal->setText(QString::number(value));
}
