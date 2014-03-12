#ifndef GUI_H
#define GUI_H
#include <QVector>
#include <QString>
#include <QtGui/QIcon>
#include <QDomElement>

class Gui
{
    private:
    QString _label;//��ǩ�ı�
    QIcon _icon;//ͼ��
    QString _cmd;//����
    QString _memo;//��ע
    QString _src;//��Դ
    QString _srcType;//��Դ����
    QString _background;//�����ļ�·��

    public:
    QVector<Gui> items;//����������Ŀ
    QVector<int> toolpos;//�������������

    void setattrib(const QDomElement &);//���ò˵�/�˵�������

    QString label()const{return _label;}//��ȡ��ǩ�ı�

    const QIcon & icon()const {return _icon;}//��ȡͼ��

    QString cmd()const{return _cmd;}//��ȡ����

    QString memo()const{return _memo;}//��ȡ��ע

    QString src()const{return _src;}//��ȡ��Դ��Ϣ

    QString srcType()const{return _srcType;}//��ȡ��Դ����

    QString background()const{return _background;}//��ȡ�����ļ���Ϣ

    void setSrc(const QString &src){_src=src;}//������Դ��Ϣ

    void setSrcType(const QString &srcType){_srcType=srcType;}//������Դ����

    void setBackGround(const QString &bkg){_background=bkg;}//���ñ����ļ�
};
#endif // GUI_H
