#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include <QTextEdit>

class TextWidget : public QWidget
{
public:
    TextWidget(const QString &fileName);
private:
    void loadFile(const QString &fileName);//��ȡTXT�ļ�

    QTextEdit *textEdit;//������ʾ�ı�
};

#endif // TEXTWIDGET_H
