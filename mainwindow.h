#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 

#include <QMainWindow>
 
class Drawing;

 
class MainWindow : public QMainWindow
{

    Q_OBJECT
 
public:
    MainWindow();
 
private slots:
    void about();

private:
    void createActions();
    void createMenus();

    QMenu *helpMenu;

    Drawing *drawing;

    QAction *aboutAction;
    QAction *aboutQtAction;
};
 
#endif