#include "XmlReader.h"
#include <QFile>
#include <iostream>
#include <QMessageBox>

bool XmlReader::readFile(const QString &filename)
{
    QFile file(filename);//打开filename指示的文件
    if(!file.open(QFile::ReadOnly|QFile::Text))//若打开失败则报错并返回false
    {
        std::cerr<<"Error:Cannot read file"<<qPrintable(filename)<<";"<<qPrintable(file.errorString())
                <<std::endl;
        return false;
    }
    QString errorStr;
    int errorLine;
    int errorCol;
    QDomDocument doc;//用QDomDocument读取打开的文件
    if(!doc.setContent(&file,false,&errorStr,&errorLine,&errorCol))//若读取失败则提示错误信息并返回false
    {
        std::cerr<<"Error:Parse error at line"<<errorLine<<","<<"column"<<errorCol<<":"<<
                qPrintable(errorStr)<<std::endl;
        return false;
    }
    QDomElement root=doc.documentElement();//获取XML文档的根标签
    if(root.tagName()!="gui")
    {
        std::cerr<<"Error:Not a GUI file"<<std::endl;
        return false;
    }
    parseGui(root);//调用parseGui()函数解析该标签内容
    return true;
 }
void XmlReader::parseGui(const QDomElement &elem)
{
    QDomNode child=elem.firstChild();//获取elem第一个子节点
    while(!child.isNull())
    {
        if(child.toElement().tagName()=="menu")
            parseMenu(g,child.toElement());
        else if(child.toElement().tagName()=="toolbar")
            parseToolbar(g,child.toElement());
        else if(child.toElement().tagName()=="srctype")
            g.setSrcType(child.toElement().text());
        else if(child.toElement().tagName()=="src")
            g.setSrc(child.toElement().text());
        else if(child.toElement().tagName()=="background")
            g.setBackGround(child.toElement().text());
        child=child.nextSibling();//取得下一个子节点
    }
}
void XmlReader::parseMenu(Gui &g,const QDomElement &elem)
{
    Gui m;
    QDomNode child=elem.firstChild();
    while(!child.isNull())
    {
        if(child.toElement().tagName()=="item")
            parseItem(m,child.toElement());
        else m.setattrib(child.toElement());
        child=child.nextSibling();
    }
    g.items.push_back(m);
}
void XmlReader::parseItem(Gui &m,const QDomElement &elem)
{
    Gui i;
    QDomNode child=elem.firstChild();
    while(!child.isNull())
    {
        i.setattrib(child.toElement());
        child=child.nextSibling();
    }
    m.items.push_back(i);
}
void XmlReader::parseToolbar(Gui &g,const QDomElement &elem)
{
    QDomNode child=elem.firstChild();
    int i,j,pos=0;
    while(!child.isNull())
    {
       i=child.toElement().text().section(',',0,0).toInt()-1;
       j=child.toElement().text().section(',',1,1).toInt()-1;
       for(;i!=0;i--)
           pos+=g.items[i-1].items.size();
       pos+=j;
       g.toolpos.push_back(pos);
       pos=0;
       child=child.nextSibling();
    }
}
