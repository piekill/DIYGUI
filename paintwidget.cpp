#include "PaintWidget.h"
#include <QPainter>
#include <QMessageBox>

PaintWidget::PaintWidget(const QString &background)
{
    bkgImage.load(background);
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,bkgImage);//绘制背景图片

    this->setFixedSize(bkgImage.size());//将部件大小设置为图片大小
}
