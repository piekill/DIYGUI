#ifndef LOADDLG_H
#define LOADDLG_H

#include <QtGui/QDialog>

namespace Ui {
    class loadDlg;
}

class loadDlg : public QDialog {
    Q_OBJECT
public:
    loadDlg(QWidget *parent = 0);
    QString path(){return pathway;}
    ~loadDlg();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::loadDlg *m_ui;
    QString pathway;

private slots:
    void on_OkButton_clicked();
};

#endif // LOADDLG_H
