#include "mainwindow.h"
#include "XmlReader.h"
#include "paintwidget.h"
#include "textwidget.h"
#include <QtGui>
#include <QPainter>

MainWindow::MainWindow(const QString &filename)
{
    reader.readFile(filename);//����filenameָʾ��XML�ĵ�

    createActions(reader.gui());//����������
    createMenus(reader.gui());//�����˵�
    createToolbar(reader.gui());//����������

    if(reader.gui().srcType()=="TXT")//��xml��Դ����ΪTXT
    {
        center= new TextWidget(reader.gui().src());
        this->setCentralWidget(center);
    }
    else if(reader.gui().srcType()=="MESSAGE")//��xml��Դ����ΪMESSAGE
    {
        center=new QLabel(reader.gui().src());
        center->setFont(QFont("Verdana",12));
        this->setCentralWidget(center);
    }
    else{
        center=new PaintWidget(reader.gui().background());//Ĭ������£�����һ��PaintWidget���͵Ĳ���
        this->setCentralWidget(center);
        this->adjustSize();
        this->setMaximumSize(this->width(),this->height());
    }
}

void MainWindow::createActions(const Gui &g)
{
    for(int i=0;g.items.size()!=0&&i<g.items.size();i++)
    {
        for(int j=0;g.items[i].items.size()!=0&&j<g.items[i].items.size();j++)
        {
            QString label=g.items[i].items[j].label();
            QAction *newaction=new QAction(label,this);//����QAction���󣨶����
            newaction->setIcon(g.items[i].items[j].icon());//����ͼ��
            newaction->setWhatsThis(g.items[i].items[j].cmd());//����Ӧ��cmd������whatsthis������
            actions.push_back(newaction);//��actions����Ӹö�����
        }
    }
    getConnection();//����������ź���۹���
}

void MainWindow::createMenus(const Gui &g)
{
    int size=g.items.size(),pos=0;
    for(int i=0;i<size;i++)
    {
        QString label=g.items[i].label();
        QMenu *newMenu;
        newMenu=menuBar()->addMenu(label);//���˵���ӵ��˵���
        for(int k=0;k<g.items[i].items.size();k++,pos++)
            newMenu->addAction(actions[pos]);//����Ӧ��QAction���������ӵ��˵�
        menus.push_back(newMenu);//��menus����Ӹò˵�
    }
}

void MainWindow::createToolbar(const Gui &g)
{
    if(!g.toolpos.size())return;
    fileToolBar = addToolBar(g.items[0].label());
    for(int i=0;i<g.toolpos.size();i++)//����toolpos�е�������������Ӧ�������Ĺ�������
    {
        if(g.toolpos[i]<actions.size())
        fileToolBar->addAction(actions[(g.toolpos[i])]);
    }
}

void MainWindow::cmd_handler(const QString& cmd)
{
    if(!cmd.isEmpty())
    {
        if(cmd.toUpper()=="EXIT")
            this->close();
        else{
            if(!QFile::exists(cmd)){
                QMessageBox::warning(this,"DIY GUI","No such xml File");
                return;
            }

            MainWindow *other = new MainWindow(cmd);
            other->show();
        }
    }
 }

void MainWindow::getConnection()
{
    for(int i=0;i<actions.size();i++)
        switch(i){
        case 0:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_1()));break;
        case 1:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_2()));break;
        case 2:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_3()));break;
        case 3:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_4()));break;
        case 4:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_5()));break;
        case 5:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_6()));break;
        case 6:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_7()));break;
        case 7:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_8()));break;
        case 8:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_9()));break;
        case 9:
            connect(actions[i],SIGNAL(triggered()),this,SLOT(handler_10()));break;
        default:
            break;
        }
}

void MainWindow::handler_1()
{
    if(actions.size()>0){
        QString cmd=actions[0]->whatsThis();
        cmd_handler(cmd);
    }
}

void MainWindow::handler_2()
{
    if(actions.size()>1){
        QString cmd=actions[1]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_3()
{
    if(actions.size()>2){
        QString cmd=actions[2]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_4()
{
    if(actions.size()>3){
        QString cmd=actions[3]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_5()
{
    if(actions.size()>4){
        QString cmd=actions[4]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_6()
{
    if(actions.size()>5){
        QString cmd=actions[5]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_7()
{
    if(actions.size()>6){
        QString cmd=actions[6]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_8()
{
    if(actions.size()>7){
        QString cmd=actions[7]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_9()
{
    if(actions.size()>8){
        QString cmd=actions[8]->whatsThis();
        cmd_handler(cmd);
    }
}
void MainWindow::handler_10()
{
    if(actions.size()>9){
        QString cmd=actions[9]->whatsThis();
        cmd_handler(cmd);
    }
}
