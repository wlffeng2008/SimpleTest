#ifndef CHECKBOXHEADERVIEW_H
#define CHECKBOXHEADERVIEW_H

#include <QTableView>
#include <QHeaderView>
#include <QRect>
#include <QObject>

class CheckBoxHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    explicit CheckBoxHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr);
    void setChecked(int nCol, bool checked);
    bool isChecked(int nCol) const;
    void setCheckCol(int nCol);
    void setChckcImage(const QString&checked,const QString&unChecked);
    void setClickIndecator(bool click);

signals:
    void checkStateChanged(int nIndex,bool bChecked);
    void checkRectChanged(int index,const QRect&rect) const;

protected:
    void paintSection(QPainter *painter, const QRect &rect, int nCol) const override;
    void mousePressEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *editor, QEvent *event) override ;

private:
    QString m_checkedImage;
    QString m_uncheckedImage ;
    bool m_clickIndecator=false;
    QMap<int, bool> m_checkStates;
    QList<int> m_CheckCols;
    QMap<int, QRect>m_checkRects;
    QTableView *m_pView = nullptr ;
};

#endif // CHECKBOXHEADERVIEW_H
