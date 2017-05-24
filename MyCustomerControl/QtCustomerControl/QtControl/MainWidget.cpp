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
