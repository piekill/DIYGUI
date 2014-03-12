/********************************************************************************
** Form generated from reading ui file 'loaddlg.ui'
**
** Created: Fri Jan 22 22:08:52 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOADDLG_H
#define UI_LOADDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loadDlg
{
public:
    QLineEdit *path;
    QLabel *label;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *loadDlg)
    {
        if (loadDlg->objectName().isEmpty())
            loadDlg->setObjectName(QString::fromUtf8("loadDlg"));
        loadDlg->resize(400, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loadDlg->sizePolicy().hasHeightForWidth());
        loadDlg->setSizePolicy(sizePolicy);
        loadDlg->setMinimumSize(QSize(400, 200));
        loadDlg->setMaximumSize(QSize(400, 200));
        loadDlg->setModal(false);
        path = new QLineEdit(loadDlg);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(60, 80, 291, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Aharoni"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        path->setFont(font);
        label = new QLabel(loadDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 241, 41));
        OkButton = new QPushButton(loadDlg);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setGeometry(QRect(180, 140, 81, 31));
        CancelButton = new QPushButton(loadDlg);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setGeometry(QRect(280, 140, 81, 31));

        retranslateUi(loadDlg);
        QObject::connect(CancelButton, SIGNAL(clicked()), loadDlg, SLOT(reject()));
        QObject::connect(OkButton, SIGNAL(clicked()), loadDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(loadDlg);
    } // setupUi

    void retranslateUi(QDialog *loadDlg)
    {
        loadDlg->setWindowTitle(QApplication::translate("loadDlg", "DIY GUI", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("loadDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">The Path to Visit:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("loadDlg", "Open", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("loadDlg", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(loadDlg);
    } // retranslateUi

};

namespace Ui {
    class loadDlg: public Ui_loadDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADDLG_H
