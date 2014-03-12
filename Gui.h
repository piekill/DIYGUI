#ifndef GUI_H
#define GUI_H
#include <QVector>
#include <QString>
#include <QtGui/QIcon>
#include <QDomElement>

class Gui
{
    private:
    QString _label;//标签文本
    QIcon _icon;//图标
    QString _cmd;//命令
    QString _memo;//备注
    QString _src;//资源
    QString _srcType;//资源类型
    QString _background;//背景文件路径

    public:
    QVector<Gui> items;//下属的子项目
    QVector<int> toolpos;//工具栏项的索引

    void setattrib(const QDomElement &);//设置菜单/菜单项属性

    QString label()const{return _label;}//获取标签文本

    const QIcon & icon()const {return _icon;}//获取图标

    QString cmd()const{return _cmd;}//获取命令

    QString memo()const{return _memo;}//获取备注

    QString src()const{return _src;}//获取资源信息

    QString srcType()const{return _srcType;}//获取资源类型

    QString background()const{return _background;}//获取背景文件信息

    void setSrc(const QString &src){_src=src;}//设置资源信息

    void setSrcType(const QString &srcType){_srcType=srcType;}//设置资源类型

    void setBackGround(const QString &bkg){_background=bkg;}//设置背景文件
};
#endif // GUI_H
