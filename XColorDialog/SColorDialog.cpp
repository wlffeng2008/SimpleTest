#include "SColorDialog.h"
#include <QDebug>
#include "language.h"
#include <QSpacerItem>
#include "colorLabel.h"
#include <QPalette>


SColorDialog::SColorDialog(QWidget *parent) :
    QDialog(parent)
{
    Qt::WindowFlags flags = (windowFlags() | Qt::Popup);
    setWindowFlags(Qt::FramelessWindowHint | flags);
    //this->installEventFilter(this);

    colorConfig.loadConfig();
    setFixedSize(240,340);
    SetupUI();

    QVector<QColor> rainbow;
    for ( int i = 0; i < 360; i+= 360/6 )
        rainbow.push_back(QColor::fromHsv(i,255,255));
    rainbow.push_back(Qt::red);
    sliderHue->setColors(rainbow);

    comboxColorType->setCurrentIndex(0);
    lineeditColorFirst->hide();
    lineeditColorSecond->hide();
    lineeditColorThird->hide();

    this->setWindowTitle("Color Plane");
    setAcceptDrops(true);

    color2Text();
}

void SColorDialog::SetupUI()
{
    vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins(12,8,8,12);
    vLayout->setSpacing(4);

    QHBoxLayout* hLayoutTitle = new QHBoxLayout();
    QLabel* pLabelTitle = new QLabel();
    pLabelTitle->setText("Color Plane");
    pLabelTitle->setFixedSize(100,24);
    hLayoutTitle->addWidget(pLabelTitle);
    QSpacerItem* hTitleSpace = new QSpacerItem(20, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hLayoutTitle->addSpacerItem(hTitleSpace);
    QPushButton* pBtnClose = new QPushButton();
    pBtnClose->setObjectName("pushButton_close");
    pBtnClose->setFixedSize(24,24);
    connect(pBtnClose, SIGNAL(clicked()), this, SLOT(ClickedCloseButton()));
    hLayoutTitle->addWidget(pBtnClose);

    vLayout->addLayout(hLayoutTitle);

    colorSquare = new SColorSquare(this);
    colorSquare->setSquareSize(216, 138);
    colorSquare->setFixedSize(216, 138);
    //colorSquare->setGeometry(QRect(12,12,216,138));
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    colorSquare->setSizePolicy(sizePolicy);


    sliderHue = new XGradientSlider(this);
    sliderHue->setMaximum(359);
    sliderHue->setOrientation(Qt::Horizontal);
    //sliderHue->setGeometry(QRect(12,154,216,6));
    vLayout->addWidget(colorSquare);
    vLayout->addWidget(sliderHue);

    hLayoutComboxType = new QHBoxLayout();
    comboxColorType = new QComboBox(this);
    comboxColorType->setFixedSize(72,24);
    comboxColorType->addItem("Hex");
    comboxColorType->addItem("RGB");
    comboxColorType->addItem("HSL");
    comboxColorType->addItem("HSB");
    hLayoutComboxType->addWidget(comboxColorType);
    hLayoutComboxType->addSpacing(8);

    hLayoutLineEdit = new QHBoxLayout();
    lineeditHex = new QLineEdit(this);
    lineeditHex->setFixedHeight(24);
    hLayoutLineEdit->addWidget(lineeditHex);

    lineeditColorFirst = new QLineEdit(this);
    lineeditColorFirst->setFixedSize(42,24);
    lineeditColorSecond = new QLineEdit(this);
    lineeditColorSecond->setFixedSize(42,24);
    lineeditColorThird = new QLineEdit(this);
    lineeditColorThird->setFixedSize(42,24);

    intValidator255 = new QIntValidator(0, 255, this);
    intValidator255->setRange(0, 255);
    intValidator359 = new QIntValidator(0, 359, this);
    intValidator359->setRange(0, 359);
    lineeditColorFirst->setValidator(intValidator255);
    lineeditColorSecond->setValidator(intValidator255);
    lineeditColorThird->setValidator(intValidator255);

    hLayoutLineEdit->addWidget(lineeditColorFirst);
    hLayoutLineEdit->addWidget(lineeditColorSecond);
    hLayoutLineEdit->addWidget(lineeditColorThird);

    hLayoutComboxType->addLayout(hLayoutLineEdit);
    vLayout->addLayout(hLayoutComboxType);

    comboxColorHistory = new QComboBox(this);
    comboxColorHistory->setFixedHeight(24);

    Language* lang = Language::getInstance();
    QList<int> colorSet = colorConfig.getColorSet();
    for(int i = 0; i < colorSet.count(); i++)
    {
      comboxColorHistory->addItem(lang->getString(colorSet[i]), colorSet[i]);
    }
    comboxColorHistory->setCurrentIndex(0);
    vLayout->addWidget(comboxColorHistory);

    //int nIndex = comboxColorHistory->currentIndex();
    int nColorSet = comboxColorHistory->currentData().toInt();
    QList<QColor> lstColors = colorConfig.getColorList(nColorSet);

    int nCnt = 0;
    for(int row = 0; row < 2; row++)
    {
        QHBoxLayout* hColor = new QHBoxLayout();
        for(int col = 0; col < 8; col++)
        {
            nCnt = 8*row+col;
            //QString csColorLabelObj = QString("color_%1_%2").arg(row+1).arg(col+1);
            ColorLabel* colorLabel = new ColorLabel(this);
            colorLabel->setObjectName(QString::number(nCnt));
            connect(colorLabel, SIGNAL(clicked(QString)), this, SLOT(clickLabel(QString)));
            colorLabel->setFixedSize(24,24);
            if(nCnt < lstColors.count())
            {
                QString radiusSheetStyle = QString("border-radius: 12;  border:none;background:rgb(%1,%2,%3)")
                                           .arg(lstColors[nCnt].red()).arg(lstColors[nCnt].green()).arg(lstColors[nCnt].blue());
                colorLabel->setStyleSheet(radiusSheetStyle);
            }

            hColor->addWidget(colorLabel);
            if(nCnt < lstColors.count())
            {
                colorLabel->show();
            }
            else
            {
                colorLabel->hide();
            }

            lstColorRecommend.push_back(colorLabel);
        }
        QSpacerItem* hSpace = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        hColor->addSpacerItem(hSpace);
        vLayout->addLayout(hColor);
    }

    QSpacerItem* vSpace = new QSpacerItem(20, 20, QSizePolicy::Ignored, QSizePolicy::Expanding);
    vLayout->addSpacerItem(vSpace);

    this->setLayout(vLayout);
    SetConnect();
}

void SColorDialog::SetConnect()
{
    QObject::connect(sliderHue, SIGNAL(valueChanged(int)), this, SLOT(SetHSV()));
    QObject::connect(colorSquare, SIGNAL(colorSelected(QColor)), this, SLOT(UpdateWidgets()));
    QObject::connect(this, SIGNAL(checkedChanged(char)), colorSquare, SLOT(setCheckedColor(char)));

    QObject::connect(comboxColorType, SIGNAL(currentIndexChanged(int)), this, SLOT(comboxChanged(int)));
    QObject::connect(lineeditHex, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    QObject::connect(lineeditColorFirst, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    QObject::connect(lineeditColorSecond, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    QObject::connect(lineeditColorThird, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));

    QObject::connect(comboxColorHistory, SIGNAL(currentIndexChanged(int)), this, SLOT(comboxColorChanged(int)));
}

void SColorDialog::comboxChanged(int index)
{
  QString csText = comboxColorType->itemText(index);
  if("Hex" == csText)
  {
      lineeditHex->show();
      lineeditColorFirst->hide();
      lineeditColorSecond->hide();
      lineeditColorThird->hide();
  }
  else
  {
      lineeditHex->hide();
      lineeditColorFirst->show();
      lineeditColorSecond->show();
      lineeditColorThird->show();
      if("RGB" == csText)
      {
          lineeditColorFirst->setValidator(intValidator255);
      }
      else
      {
          lineeditColorFirst->setValidator(intValidator359);
      }
  }
  color2Text();
}

void SColorDialog::comboxColorChanged(int index)
{
    int nColorSet = comboxColorHistory->currentData().toInt();
    QList<QColor> lstColors = colorConfig.getColorList(nColorSet);

    for(int i = 0; i < lstColorRecommend.count(); i++)
    {
        QLabel* colorLabel = lstColorRecommend[i];
        int nIndex = colorLabel->objectName().toInt();
        if(nIndex < lstColors.count())
        {
            QString radiusSheetStyle = QString("border-radius: 12px;  border:none;background:rgb(%1,%2,%3)")
                                       .arg(lstColors[nIndex].red()).arg(lstColors[nIndex].green()).arg(lstColors[nIndex].blue());
            colorLabel->setStyleSheet(radiusSheetStyle);
            colorLabel->show();
        }
        else
        {
            colorLabel->hide();
        }
    }
}

QColor SColorDialog::color() const
{
    QColor color = colorSquare->color();
    return color;
}

void SColorDialog::SetColor(QColor color)
{
    colorSquare->setColor(color);
    UpdateWidgets();
    colorSquare->update();
}

void SColorDialog::SetHSV()
{
    if(!signalsBlocked())
    {
        colorSquare->setHue(sliderHue->value()/360.0);
        color2Text();
    }
}

void SColorDialog::color2Text()
{
    QColor col = color();
    QString csColorType = comboxColorType->currentText();
    unsigned int r = col.red();
    unsigned int g = col.green();
    unsigned int b = col.blue();

    //QObject::disconnect(lineeditHex, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    //QObject::disconnect(lineeditColorFirst, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    //QObject::disconnect(lineeditColorSecond, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    //QObject::disconnect(lineeditColorThird, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    if("Hex" == csColorType)
    {
        QRgb mRgb = qRgb(col.red(),col.green(),col.blue());
        //QString csHEX = "#"+ ((r<16)?QString("0"):"") + QString::number(r, 16).toUpper()
        //                   + ((g<16)?QString("0"):"") + QString::number(g, 16).toUpper()
        //                   + ((b<16)?QString("0"):"") + QString::number(b, 16).toUpper();
        //lineeditHex->setText(csHEX);
        lineeditHex->setText(QString("%1").arg(mRgb&0x00FFFFFF, 6, 16, QLatin1Char('0')).toUpper());
    }
    else if("RGB" == csColorType)
    {
        lineeditColorFirst->setText(QString::number(r));
        lineeditColorSecond->setText(QString::number(g));
        lineeditColorThird->setText(QString::number(b));
    }
    else if("HSL" == csColorType)
    {
        lineeditColorFirst->setText(QString::number(col.hslHue()));
        lineeditColorSecond->setText(QString::number(col.hslSaturation()));
        lineeditColorThird->setText(QString::number(col.lightness()));
    }
    else if("HSB" == csColorType)
    {
        lineeditColorFirst->setText(QString::number(col.hue()));
        lineeditColorSecond->setText(QString::number(col.saturation()));
        lineeditColorThird->setText(QString::number(col.value()));
    }

    //QObject::connect(lineeditHex, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    //QObject::connect(lineeditColorFirst, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    //QObject::connect(lineeditColorSecond, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
    //QObject::connect(lineeditColorThird, SIGNAL(textChanged(QString)), this, SLOT(UpdateColor()));
}
void SColorDialog::text2Color()
{
    QColor col;
    QString csColorType = comboxColorType->currentText();
    if("Hex" == csColorType)
    {
        QString csHEX = lineeditHex->text();
        //col = QColor::fromRgb(QRgb(csHEX.toUInt()));

        int r = csHEX.mid(0, 2).toInt(nullptr, 16); // 提取红色分量
        int g = csHEX.mid(2, 2).toInt(nullptr, 16); // 提取绿色分量
        int b = csHEX.mid(4, 2).toInt(nullptr, 16); // 提取蓝色分量
        col = QColor(r,g,b);
    }
    else if("RGB" == csColorType)
    {
        int r = lineeditColorFirst->text().toInt();
        int g = lineeditColorSecond->text().toInt();
        int b = lineeditColorThird->text().toInt();
        col = QColor::fromRgb(r,g,b);
    }
    else if("HSL" == csColorType)
    {
        int h = lineeditColorFirst->text().toInt();
        int s = lineeditColorSecond->text().toInt();
        int l = lineeditColorThird->text().toInt();
        col = QColor::fromHsl(h,s,l);
    }
    else if("HSB" == csColorType)
    {
        int h = lineeditColorFirst->text().toInt();
        int s = lineeditColorSecond->text().toInt();
        int v = lineeditColorThird->text().toInt();
        col = QColor::fromHsv(h,s,v);
    }
    colorSquare->setColor(col);
}

void SColorDialog::UpdateColor()
{
    blockSignals(true);
    foreach(QWidget* w, findChildren<QWidget*>())
        w->blockSignals(true);

    text2Color();
    sliderHue->setValue(qRound(colorSquare->hue()*360.0));

    blockSignals(false);
    foreach(QWidget* w, findChildren<QWidget*>())
        w->blockSignals(false);
    emit colorChanged(color());
}

void SColorDialog::UpdateWidgets()
{
    blockSignals(true);
    foreach(QWidget* w, findChildren<QWidget*>())
        w->blockSignals(true);

    QColor col = color();
    sliderHue->setValue(qRound(colorSquare->hue()*360.0));
    color2Text();

    blockSignals(false);
    foreach(QWidget* w, findChildren<QWidget*>())
        w->blockSignals(false);

    emit colorChanged(col);
}

void SColorDialog::ClickedOkButton()
{
    QColor color = this->color();
    emit colorSelected(color);
    this->hide();
}

void SColorDialog::ClickedCloseButton()
{
    ClickedOkButton();
}

void SColorDialog::clickLabel(QString csText)
{
    int nIndex = csText.toInt();

    for(int i = 0; i < lstColorRecommend.count(); i++)
    {
        QString csObjname= lstColorRecommend[i]->objectName();
        QColor color = lstColorRecommend[i]->palette().color(QPalette::Button);
        if(csText == csObjname)
        {
            QString radiusSheetStyle = QString("border-radius: 12px;  border:2px solid white;background:rgb(%1,%2,%3)")
                                       .arg(color.red()).arg(color.green()).arg(color.blue());
            lstColorRecommend[i]->setStyleSheet(radiusSheetStyle);

            SetColor(color);
        }
        else
        {
            QString radiusSheetStyle = QString("border-radius: 12px;  border:none;background:rgb(%1,%2,%3)")
                                       .arg(color.red()).arg(color.green()).arg(color.blue());
            lstColorRecommend[i]->setStyleSheet(radiusSheetStyle);
        }
    }
}
