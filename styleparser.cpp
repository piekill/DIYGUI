#include "styleparser.h"
#include <QFile>
#include <iostream>
#include <QString>
#include <QStringList>
#include <string>
#include <QBitArray>
#include <QMessageBox>

StyleParser::StyleParser(const QString& filename)
{
    parseFile(filename);
}

void StyleParser::parseFile(const QString& filename)
{
    QString filetext,category,background,item;
    QFile infile(filename);
    if(!infile.open(QIODevice::ReadOnly))
    {
        std::cerr<<"Cannot Open File:"<<qPrintable(infile.errorString())<<std::endl;
        return;
    }
    QTextStream in(&infile);
    filetext=in.readAll();
    category=filetext.mid(filetext.indexOf("category{")+9,filetext.indexOf('}')-filetext.indexOf("category{")-9);
    parseCategory(category);
    filetext=filetext.mid(filetext.indexOf('}')+1);
    background=filetext.mid(filetext.indexOf("background{")+11,filetext.indexOf('}')-filetext.indexOf("background{")-11);
    parseBackGround(background);
    filetext=filetext.mid(filetext.indexOf('}')+1);
    while(!filetext.isNull())
    {
        int num;
        QString temp(filetext.mid(filetext.indexOf("item_"),filetext.indexOf('{')-filetext.indexOf("item_")));
        temp=temp.mid(5,temp.size()-5);
        num=temp.toInt();
        item=filetext.mid(filetext.indexOf('{')+1,filetext.indexOf('}')-filetext.indexOf('{')-1);
        parseItem(item,num);
        filetext=filetext.mid(filetext.indexOf('}')+1);
    }
}
void StyleParser::parseCategory(const QString&category)
{
    QStringList attributes(category.split(','));
    QString type(attributes.at(0).section('=',1,1)),
            style(attributes.at(1).section('=',1,1)),
            max(attributes.at(2).section('=',1,1)),
            width(attributes.at(3).section('=',1,1)),
            height(attributes.at(4).section('=',1,1));

    cate.type.resize(4);
    cate.type.fill(false);
    if(type.contains("MENU",Qt::CaseInsensitive))
        cate.type.setBit(0);
    if(type.contains("ICON",Qt::CaseInsensitive))
        cate.type.setBit(1);
    if(type.contains("TOOLBAR",Qt::CaseInsensitive))
        cate.type.setBit(2);
    if(type.contains("LIST",Qt::CaseInsensitive))
        cate.type.setBit(3);

    if(style.toLower()=="fixed")
        cate.fixed=true;
    else if(style.toLower()=="float")
        cate.fixed=false;
    cate.maxitem=max.toInt();
    cate.width=width.toInt();
    cate.height=height.toInt();
    return;
}

void StyleParser::parseBackGround(const QString&background)
{
    QStringList attributes(background.split(','));
    QString attach(attributes.at(0).section('=',1,1)),
                    color(attributes.at(1).section('=',1,1)),
                    image(attributes.at(2).section('=',1,1)),
                    Xpos(attributes.at(3).section('=',1,1)),
                    Ypos(attributes.at(4).section('=',1,1)),
                    repeat(attributes.at(5).section('=',1,1));
    if(attach.toLower()=="true")
        bkg.attachment=true;
    else if(attach.toLower()=="false")
        bkg.attachment=false;
    else return;
    bkg.color.setNamedColor(color.toLower());
    bkg.image.load(image);
    bkg.Xpos=Xpos.toInt();
    bkg.Ypos=Ypos.toInt();
     if(repeat.toLower()=="true")
        bkg.repeat=true;
    else if(repeat.toLower()=="false")
        bkg.repeat=false;
}
void StyleParser::parseItem(const QString &item_i,int num)
{
    QStringList attributes(item_i.split(','));
    QString Xpos(attributes.at(0).section('=',1,1)),
            Ypos(attributes.at(1).section('=',1,1)),
            imageH(attributes.at(4).section('=',1,1)),
            imageW(attributes.at(5).section('=',1,1)),
            labelXpos(attributes.at(6).section('=',1,1)),
            labelYpos(attributes.at(7).section('=',1,1)),
            labelH(attributes.at(8).section('=',1,1)),
            labelW(attributes.at(9).section('=',1,1));
    Item_i item;
    item.index=num;
    item.Xpos=Xpos.toInt();
    item.Ypos=Ypos.toInt();
    item.imageheight=imageH.toInt();
    item.imagewidth=imageW.toInt();
    item.labelXpos=labelXpos.toInt();
    item.labelYpos=labelYpos.toInt();
    item.labelheight=labelH.toInt();
    item.labelwidth=labelW.toInt();
    items.push_back(item);
}
