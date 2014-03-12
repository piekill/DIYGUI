#ifndef XMLREADER_H
#define XMLREADER_H
#include "Gui.h"
class XmlReader
{
    private:
    void parseGui(const QDomElement &elem);//解析XML文档中的GUI标签
    void parseItem(Gui &m,const QDomElement &elem);//解析item标签
    void parseMenu(Gui &g,const QDomElement &elem);//解析menu标签
    void parseToolbar(Gui &g,const QDomElement &elem);//解析toolbar标签
    Gui g;//保存描述文件信息
    public:
    bool readFile(const QString &filename);//读取并解析XML文档
    const Gui& gui()const{return g;}//获取保存信息的Gui对象
};
#endif // XMLREADER_H
