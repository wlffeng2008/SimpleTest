#include "CheckBoxHeaderView.h"
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QApplication>

CheckBoxHeaderView::CheckBoxHeaderView(Qt::Orientation orientation, QWidget *parent):
    QHeaderView(orientation,parent)
{
    m_pView = static_cast<QTableView *>(parent);
    setMouseTracking(true) ;
    installEventFilter(this) ;
}

void CheckBoxHeaderView::paintSection(QPainter *painter, const QRect &rect, int nCol) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, nCol);
    painter->restore();
    QStandardItemModel *pModel = (QStandardItemModel *)this->model() ;
    if (m_CheckCols.contains(nCol))
    {
        QStyleOptionButton option;
        option.rect = rect.adjusted(-2,-2,-2,-2);
        option.state = QStyle::State_Enabled | QStyle::State_Active;
        option.state |= m_checkStates.value(nCol, false) ? QStyle::State_On : QStyle::State_Off;

        //painter->fillRect(rect,QBrush(Qt::blue));
        QString strText= pModel->headerData(nCol,Qt::Horizontal).toString() ;

        painter->setRenderHint(QPainter::SmoothPixmapTransform);
        //style()->drawControl(QStyle::CE_CheckBox, &option, painter);

        QRect rcBox = rect.adjusted(2,2,-2,-2);
        rcBox.setRight(rcBox.left() + 20);
        rcBox.setBottom(rcBox.top() + 20);
        if(m_checkStates.value(nCol, false))
            painter->drawImage(rcBox,QImage(":/images/BoxChecked.png"));
        else
            painter->drawImage(rcBox,QImage(":/images/BoxUncheck.png"));
        //painter->drawText( rect.adjusted(30,0,0,0),strText);
    }
    else
    {
    }
}

void CheckBoxHeaderView::mousePressEvent(QMouseEvent *event)
{
    int nCol = logicalIndexAt(event->pos());
    if (m_CheckCols.contains(nCol))
    {
        bool checked = !m_checkStates.value(nCol, false);
        setChecked(nCol,checked) ;
        updateSection(nCol);
    }
    QHeaderView::mousePressEvent(event);
}

void CheckBoxHeaderView::mouseMoveEvent(QMouseEvent *event)
{
    int nCol = logicalIndexAt(event->pos());
    if (m_CheckCols.contains(nCol))
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
        event->accept() ;
        return ;
    }

    QHeaderView::mouseMoveEvent(event);
}

bool CheckBoxHeaderView::eventFilter(QObject *editor, QEvent *event)
{
    if (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
        return true ;
    }
    QApplication::restoreOverrideCursor() ;

    return QHeaderView::eventFilter(editor, event);
}

bool CheckBoxHeaderView::isChecked(int nCol) const
{
    return m_checkStates.value(nCol, false) ;
}

void CheckBoxHeaderView::setChecked(int nCol,bool checked)
{
    m_checkStates[nCol] = checked ;
    emit checkStateChanged(nCol, checked);
    if(!m_pView)
        return ;

    QStandardItemModel *pModel = static_cast<QStandardItemModel *>(m_pView->model()) ;
    int nCount = pModel->rowCount() ;
    for(int i=0; i<nCount; i++)
        pModel->item(i,nCol)->setCheckState(checked?Qt::Checked:Qt::Unchecked) ;
}

void CheckBoxHeaderView::setCheckCol(int nCol)
{
    if(!m_CheckCols.contains(nCol))
        m_CheckCols.append(nCol) ;
}
