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

    saveAction = new QAction(tr("Save"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
}

void MainWindow::createMenus(){
    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);


    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(saveAction);
    
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(helpMenu);
    
}

void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"));

    if (!fileName.isEmpty()) {
        QPixmap pixmap(drawing->size());
        drawing->render(&pixmap);

        pixmap.save(fileName, "PNG");
    }
}