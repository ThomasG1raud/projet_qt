#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 

#include <QMainWindow>
#include <QWidget>
 
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
    void resizeImage();
    void drawSquare();
    void drawCircle();
    
private:
    void createActions();
    void createMenus();

    QMenu *helpMenu;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *drawMenu;

    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *saveAction;
    QAction *openAction;
    QAction *newAction;
    QAction *changeColorAction;
    QAction *changeWidthAction;
    QAction *resizeAction;
    QAction *drawSquareAction;
    QAction *drawCircleAction;
    

    Drawing *drawing;

};
 
#endif