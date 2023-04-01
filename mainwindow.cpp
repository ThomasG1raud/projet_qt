#include <QtWidgets>
 
#include "mainwindow.h"
#include "drawing.h"

MainWindow::MainWindow(){
    createActions();
    createMenus();

    drawing = new Drawing;
    setCentralWidget(drawing);
    setWindowTitle(tr("Paint"));

    resize(1000, 1000);
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
