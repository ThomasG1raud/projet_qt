#include <QtWidgets>
 
#include "mainwindow.h"
 

MainWindow::MainWindow(){
    createActions();
    createMenus();

    setWindowTitle(tr("Scribble"));

    resize(500, 500);
}

void MainWindow::about(){
    QMessageBox::about(this, tr("About Paint"),tr("Paint project by Antoine LACHAT and Thomas GIRAUD"));
}

void MainWindow::createActions(){
    aboutAction = new QAction(tr("&About"), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus(){
    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    menuBar()->addMenu(helpMenu);
}
