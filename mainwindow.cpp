#include <QtWidgets>
 
#include "mainwindow.h"
#include "drawing.h"

MainWindow::MainWindow(){
    createActions();
    createMenus();

    drawing = new Drawing;
    setCentralWidget(drawing);
    setWindowTitle(tr("Paint"));

    resize(650, 500);

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
    saveAction->setShortcut(QKeySequence::Save);

    openAction = new QAction(tr("Open"), this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    openAction->setShortcut(QKeySequence::Open);

    newAction = new QAction(tr("New"), this);
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
    newAction->setShortcut(QKeySequence::New);
}

void MainWindow::createMenus(){
    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);


    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    
    
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(helpMenu);
    
}

void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"));

    if (!fileName.isEmpty()) {
        QImage image(drawing->size(), QImage::Format_ARGB32_Premultiplied);
        QPainter painter(&image);
        drawing->render(&painter);

        image.save(fileName, "PNG");
        setWindowTitle(fileName);
    }
}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png)"));

    if (!fileName.isEmpty()) {
        QImage image(fileName);
        drawing->setImage(image);
        setWindowTitle(fileName);
    }
}

void MainWindow::newFile(){
    Drawing *newDrawing = new Drawing;
    setCentralWidget(newDrawing);
    delete drawing;
    drawing = newDrawing;
    setWindowTitle(tr("Paint"));
}