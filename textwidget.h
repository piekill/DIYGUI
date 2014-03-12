#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include <QTextEdit>

class TextWidget : public QWidget
{
public:
    TextWidget(const QString &fileName);
private:
    void loadFile(const QString &fileName);//读取TXT文件

    QTextEdit *textEdit;//用来显示文本
};

#endif // TEXTWIDGET_H
