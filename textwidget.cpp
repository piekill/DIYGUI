#include "textwidget.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QHBoxLayout>
TextWidget::TextWidget(const QString &fileName)
{
    QHBoxLayout *layout=new QHBoxLayout;
    textEdit = new QTextEdit;
    layout->addWidget(textEdit);
    setLayout(layout);
    loadFile(fileName);
}

void TextWidget::loadFile(const QString &fileName)
 {

     QFile file(fileName);
     if (!file.open(QFile::ReadOnly | QFile::Text)) {//打开失败或格式不对
         QMessageBox::warning(this, tr("SDI"),
                              tr("Cannot read file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }
     QTextStream in(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
        textEdit->setPlainText(in.readAll());//将内容显示在textEdit中
     QApplication::restoreOverrideCursor();
 }
