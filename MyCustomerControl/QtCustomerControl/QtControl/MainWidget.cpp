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

    // ! 4
    m_pMyCoolBar = new myCoolBar(this);
    m_pMyCoolBar->setGeometry(700, 170, 500, 50);
    m_pMyCoolBarLineEditCurVal = new QLineEdit(this);
    m_pMyCoolBarLineEditCurVal->setGeometry(900, 230, 80, 20);
    m_pMyCoolBarLineEditCurVal->setStyleSheet("QLineEdit{border: 1px solid gray;border-radius:5px; background:rgba(255,255,255,0);\
                                              padding: 0px 10px 0px 20px; background: #968d5c; selection-background-color: darkgray;}");
    m_pMyCoolBarLineEditCurVal->setEnabled(FALSE);
    connect(m_pMyCoolBar, SIGNAL(valueChanged(int)), this, SLOT(onMyCoolBarLineEditValue(int)));

    // ! 5
    srand(QDateTime::currentDateTime().toTime_t());
    ui->customPlot->setGeometry(1250, 10, 660, 300);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->customPlot->xAxis->setRange(-8, 8);
    ui->customPlot->yAxis->setRange(-5, 5);
    ui->customPlot->axisRect()->setupFullAxesBox();

    ui->customPlot->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement(ui->customPlot, "Interaction Example", QFont("sans", 17, QFont::Bold));
    ui->customPlot->plotLayout()->addElement(0, 0, title);

    ui->customPlot->xAxis->setLabel("x Axis");
    ui->customPlot->yAxis->setLabel("y Axis");
    ui->customPlot->legend->setVisible(true);

    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->legend->setSelectedFont(legendFont);
    ui->customPlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items

    addRandomGraph();
    addRandomGraph();
    addRandomGraph();
    addRandomGraph();
    ui->customPlot->rescaleAxes();

    // ! 6
    initCustomPlot2();
    }

    void Widget::initCustomPlot2()
    {
        ui->customPlot2->legend->setVisible(true);
        int n = 500;
        QVector<double> time(n), value1(n), value2(n);
        QDateTime start = QDateTime(QDate(2014, 6, 11));
        start.setTimeSpec(Qt::UTC);
        double startTime = start.toTime_t();
        double binSize = 3600*24; // 1天的数据
        time[0] = startTime;
        value1[0] = 60;
        value2[0] = 20;
        qsrand(9);//生成随机数时给指定的种子，那么生成的随机数都是相同的，因此每次运行后得到的结果都是不变的
        for (int i=1; i<n; ++i)
        {
          time[i] = startTime + 3600*i;
          value1[i] = value1[i-1] + (qrand()/(double)RAND_MAX-0.5)*10;
          value2[i] = value2[i-1] + (qrand()/(double)RAND_MAX-0.5)*3;
        }

        // 初始化一个蜡烛图指针:
        QCPFinancial *candlesticks = new QCPFinancial(ui->customPlot2->xAxis, ui->customPlot2->yAxis);
        candlesticks->setName("Candlestick");
        candlesticks->setChartStyle(QCPFinancial::csCandlestick);//设置图表类型为蜡烛图
        candlesticks->data()->set(QCPFinancial::timeSeriesToOhlc(time, value1, binSize, startTime));//设置数据
        candlesticks->setWidth(binSize*0.9);//设置每一个数据项的绘制宽度
        candlesticks->setTwoColored(true);//设置是否显示两种颜色
        candlesticks->setBrushPositive(QColor(245, 245, 245));//设置收>开画刷
        candlesticks->setBrushNegative(QColor(40, 40, 40));//设置收<开画刷
        candlesticks->setPenPositive(QPen(QColor(0, 0, 0)));//设置收>开画笔
        candlesticks->setPenNegative(QPen(QColor(0, 0, 0)));//设置收>开画笔

        // 初始化一个美国线图指针:
        QCPFinancial *ohlc = new QCPFinancial(ui->customPlot2->xAxis, ui->customPlot2->yAxis);
        ohlc->setName("OHLC");
        ohlc->setChartStyle(QCPFinancial::csOhlc);//设置图表类型为美国线
        ohlc->data()->set(QCPFinancial::timeSeriesToOhlc(time, value2, binSize/3.0, startTime)); //为了区分于蜡烛图显示，
        ohlc->setWidth(binSize*0.2);
        ohlc->setTwoColored(true);

        // 创建一个坐标轴矩形
        QCPAxisRect *volumeAxisRect = new QCPAxisRect(customPlot);
        customPlot->plotLayout()->addElement(1, 0, volumeAxisRect);
        volumeAxisRect->setMaximumSize(QSize(QWIDGETSIZE_MAX, 100));
        volumeAxisRect->axis(QCPAxis::atBottom)->setLayer("axes");
        volumeAxisRect->axis(QCPAxis::atBottom)->grid()->setLayer("grid");
        // 设置自己构造的坐标轴矩形属性
        customPlot->plotLayout()->setRowSpacing(0);
        volumeAxisRect->setAutoMargins(QCP::msLeft|QCP::msRight|QCP::msBottom);
        volumeAxisRect->setMargins(QMargins(0, 0, 0, 0));
        // 生成两种颜色的柱状图
        customPlot->setAutoAddPlottableToLegend(false);//是否自动生成图例
        QCPBars *volumePos = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
        QCPBars *volumeNeg = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
        for (int i=0; i<n/5; ++i)
        {
          int v = qrand()%20000+qrand()%20000+qrand()%20000-10000*3;
          (v < 0 ? volumeNeg : volumePos)->addData(startTime+3600*5.0*i, qAbs(v)); //构造随机数据
        }
        volumePos->setWidth(3600*4);
        volumePos->setPen(Qt::NoPen);
        volumePos->setBrush(QColor(100, 180, 110));
        volumeNeg->setWidth(3600*4);
        volumeNeg->setPen(Qt::NoPen);
        volumeNeg->setBrush(QColor(180, 90, 90));

        // 设置自己构造的坐标轴矩形的x轴和QCustomPlot中的坐标轴矩形(默认的会生成一个)x轴同步，两个坐标轴永远显示的坐标范围是一样的
        connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), volumeAxisRect->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
        connect(volumeAxisRect->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis, SLOT(setRange(QCPRange)));
        // 构造一个新的坐标轴刻度计算类
        QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
        dateTimeTicker->setDateTimeSpec(Qt::UTC);
        dateTimeTicker->setDateTimeFormat("dd. MMMM");
        volumeAxisRect->axis(QCPAxis::atBottom)->setTicker(dateTimeTicker);//赋予自己构造的坐标轴矩形的x轴一个新的刻度计算类
        volumeAxisRect->axis(QCPAxis::atBottom)->setTickLabelRotation(15);
        customPlot->xAxis->setBasePen(Qt::NoPen);
        customPlot->xAxis->setTickLabels(false);//不显示坐标轴文本
        customPlot->xAxis->setTicks(false); //  不显示坐标轴  (这个接口实现的不友好，后续文章我会具体说到)
        customPlot->xAxis->setTicker(dateTimeTicker);//赋予默认的坐标轴矩形的x轴一个新的刻度计算类
        customPlot->rescaleAxes();
        customPlot->xAxis->scaleRange(1.025, customPlot->xAxis->range().center());
        customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());

        // 设置两个坐标轴矩形左右对齐
        QCPMarginGroup *group = new QCPMarginGroup(customPlot);
        customPlot->axisRect()->setMarginGroup(QCP::msLeft|QCP::msRight, group);
        volumeAxisRect->setMarginGroup(QCP::msLeft|QCP::msRight, group);
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

void Widget::onMyCoolBarLineEditValue(int value)
{
    m_pMyCoolBarLineEditCurVal->setText(QString::number(value));
}

void Widget::addRandomGraph()
{
    int n = 50; // number of points in graph
    double xScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double yScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double xOffset = (rand()/(double)RAND_MAX - 0.5)*4;
    double yOffset = (rand()/(double)RAND_MAX - 0.5)*10;
    double r1 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r2 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r3 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r4 = (rand()/(double)RAND_MAX - 0.5)*2;
    QVector<double> x(n), y(n);
    for (int i=0; i<n; i++)
    {
      x[i] = (i/(double)n-0.5)*10.0*xScale + xOffset;
      y[i] = (qSin(x[i]*r1*5)*qSin(qCos(x[i]*r2)*r4*3)+r3*qCos(qSin(x[i])*r4*2))*yScale + yOffset;
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph()->setName(QString("New graph %1").arg(ui->customPlot->graphCount()-1));
    ui->customPlot->graph()->setData(x, y);
    ui->customPlot->graph()->setLineStyle((QCPGraph::LineStyle)(rand()%5+1));
    if (rand()%100 > 50)
      ui->customPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(rand()%14+1)));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(rand()/(double)RAND_MAX*2+1);
    ui->customPlot->graph()->setPen(graphPen);
    ui->customPlot->replot();
}
