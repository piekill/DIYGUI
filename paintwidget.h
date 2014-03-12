#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPixmap>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    PaintWidget(const QString&);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPixmap bkgImage;//±³¾°Í¼Æ¬
};


#endif // PAINTWIDGET_H
