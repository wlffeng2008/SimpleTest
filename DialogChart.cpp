#include "DialogChart.h"
#include "ui_DialogChart.h"
#include <QChartView>
#include <QtCharts>
#include <QAbstractAxis>
#include <QVBoxLayout>

#include <QUrl>
#include <QDateTime>
#include <QClipboard>

#include <QCamera>
//#include <QMediaServiceCameraInfoInterface>
#include <QMediaRecorder>
//#include <QCameraViewfinder>

DialogChart::DialogChart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogChart)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::WindowMinMaxButtonsHint) ;

    // QList<QMediaService> cameras = QMediaService();

    // QCamera *camera = new QCamera(cameras.first());
    // QCameraViewfinder *viewfinder = new QCameraViewfinder();
    // camera->setViewfinder(viewfinder);
    // viewfinder->show();

    /*QChartView *pCV = new QChartView(this) ;

    QVBoxLayout *pVBox = new QVBoxLayout(this) ;
    setLayout(pVBox) ;
    pVBox->addWidget(pCV) ;
    pVBox->setMargin(0) ;
    pVBox->setContentsMargins(0,0,0,0) ;

    QChart *pCh = pCV->chart() ;

    QSplineSeries *series0 = new QSplineSeries() ;
    for(int i=0; i<1000; i++)
    {
        series0->append(QPoint(i,rand()%400)) ;
    }
    series0->setUseOpenGL(true);
    series0->setName("凌云志");
    pCh->addSeries(series0);

    series0 = new QSplineSeries() ;
    for(int i=0; i<500; i++)
    {
        series0->append(QPoint(i,rand()%600)) ;
    }
    series0->setUseOpenGL(true);
    series0->setName("清风扬");
    pCh->addSeries(series0);
    pCh->setTitle("天涯海角") ;

    pCh->createDefaultAxes();

    QList<QAbstractAxis *>AX = pCh->axes() ;
    AX[0]->setTitleText("123456") ;
    AX[1]->setTitleText("Height") ;
    pCV->setMouseTracking(true);*/

    //pCV->chart()->
    //cubicSplineInterpolate() ;

    //setMouseTracking(true) ;

}

DialogChart::~DialogChart()
{
    delete ui;
}

void DialogChart::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDraging)
    {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData();

        QString strText="Hello,draging! "  + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")  + "\n" ;
        // 设置文本数据QDir::tempPath() +
        mimeData->setText(strText);

        QString strFile= "d:/drag_content.txt";
        QFile tempFile(strFile);
        if (tempFile.open(QIODevice::Append))
        {

            tempFile.write(strText.toUtf8());
            tempFile.close();

            QList<QUrl> urls;
            urls << QUrl::fromLocalFile(strFile);
            mimeData->setUrls(urls);
        }

        drag->setMimeData(mimeData);
        m_bDraging = false ;

        connect(drag,&QDrag::actionChanged,this,[=](Qt::DropAction action){
            qDebug() << action ;
        }) ;
        connect(drag,&QDrag::targetChanged,this,[=](QObject *newTarget){
            qDebug() << newTarget ;
        }) ;

        Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);

        // 拖拽完成后删除临时文件
        if (dropAction != Qt::IgnoreAction) {
            //tempFile.remove();
        }

        QClipboard *clip = QApplication::clipboard();
        const QMimeData *md = clip->mimeData() ;
        qDebug() << md;
        if(md->hasUrls())
        {
            QList<QUrl> urls = md->urls() ;
            qDebug() << urls ;
        }

        mimeData->deleteLater() ;
        drag->deleteLater() ;
    }

    QDialog::mouseMoveEvent(event);
}

void DialogChart::mouseReleaseEvent(QMouseEvent *event)
{
    m_bDraging = false ;
    QDialog::mouseReleaseEvent(event);
}

void DialogChart::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->pos();
        qDebug() << "Draging" ;
        m_bDraging = true ;
    }

    QDialog::mousePressEvent(event);
}
