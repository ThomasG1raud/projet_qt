#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 

#include <QMainWindow>
 
class Drawing;

 
class MainWindow : public QMainWindow{
Q_OBJECT
public:
    MainWindow();
private slots:
    void about();
    void saveFile();
    void openFile();
    void newFile();
    void changeColor();
    void changeWidth();
    
private:
    void createActions();
    void createMenus();

    QMenu *helpMenu;
    QMenu *fileMenu;
    QMenu *editMenu;

    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *saveAction;
    QAction *openAction;
    QAction *newAction;
    QAction *changeColorAction;
    QAction *changeWidthAction;

    Drawing *drawing;

};
 
#endif