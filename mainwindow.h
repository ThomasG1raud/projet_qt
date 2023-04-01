#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 

#include <QMainWindow>
 

 
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

    QAction *openAction;

    QAction *aboutAction;
    QAction *aboutQtAction;
};
 
#endif