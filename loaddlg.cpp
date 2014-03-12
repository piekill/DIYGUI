#include "loaddlg.h"
#include "ui_loaddlg.h"
#include <QFile>
#include <QMessageBox>
loadDlg::loadDlg(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::loadDlg)
{
    m_ui->setupUi(this);
    m_ui->path->setFocus();
}

loadDlg::~loadDlg()
{
    delete m_ui;
}

void loadDlg::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void loadDlg::on_OkButton_clicked()
{
    if(!QFile::exists(m_ui->path->text())){
        QMessageBox::warning(this,"DIY GUI","The file does not exists");
        return;
    }
     pathway=m_ui->path->text();
}
