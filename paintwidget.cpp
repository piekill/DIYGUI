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

    painter.drawPixmap(0,0,bkgImage);//���Ʊ���ͼƬ

    this->setFixedSize(bkgImage.size());//��������С����ΪͼƬ��С
}
