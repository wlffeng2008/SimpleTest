#ifndef CHECKBOXHEADERVIEW_H
#define CHECKBOXHEADERVIEW_H

#include <QTableView>
#include <QHeaderView>
#include <QObject>

class CheckBoxHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    explicit CheckBoxHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr);
    void setChecked(int nCol, bool checked);
    bool isChecked(int nCol) const;
    void setCheckCol(int nCol);

protected:
    void paintSection(QPainter *painter, const QRect &rect, int nCol) const override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *editor, QEvent *event) override ;

signals:
    void checkStateChanged(int nIndex,bool bChecked);

private:
    QMap<int, bool> m_checkStates;
    QMultiMap<int, QRect> m_checkRects;
    QList<int> m_CheckCols;
    QTableView *m_pView = nullptr ;
};

#endif // CHECKBOXHEADERVIEW_H
