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
    void saveFile();

private:
    void createActions();
    void createMenus();


    QMenu *helpMenu;
    QMenu *fileMenu;

    

    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *saveAction;

    Drawing *drawing;
};
 
#endif