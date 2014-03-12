#include <QtGui/QApplication>
#include "loaddlg.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadDlg load;
    while(load.path()=="")
    {
       if(load.exec()==QDialog::Rejected)
           return 0;
    }
        MainWindow w(load.path());
        w.show();
        return a.exec();
}
