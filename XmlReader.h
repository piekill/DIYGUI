#ifndef XMLREADER_H
#define XMLREADER_H
#include "Gui.h"
class XmlReader
{
    private:
    void parseGui(const QDomElement &elem);//����XML�ĵ��е�GUI��ǩ
    void parseItem(Gui &m,const QDomElement &elem);//����item��ǩ
    void parseMenu(Gui &g,const QDomElement &elem);//����menu��ǩ
    void parseToolbar(Gui &g,const QDomElement &elem);//����toolbar��ǩ
    Gui g;//���������ļ���Ϣ
    public:
    bool readFile(const QString &filename);//��ȡ������XML�ĵ�
    const Gui& gui()const{return g;}//��ȡ������Ϣ��Gui����
};
#endif // XMLREADER_H
