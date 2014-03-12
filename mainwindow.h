#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include <QVector>
#include "Gui.h"
#include "paintwidget.h"
#include "textwidget.h"
#include "XmlReader.h"
class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(const QString &filename);

private slots:
    void handler_1();
    void handler_2();
    void handler_3();
    void handler_4();
    void handler_5();
    void handler_6();
    void handler_7();
    void handler_8();
    void handler_9();
    void handler_10();
private:

     void createActions(const Gui &gui);
     void createMenus(const Gui &gui);
     void createToolbar(const Gui &gui);
     void cmd_handler(const QString &cmd);
     void getConnection();

     QVector<QMenu *> menus;
     QVector<QAction *> actions;
     QToolBar *fileToolBar;
     QWidget *center;
     XmlReader reader;
};

#endif // MAINWINDOW_H
