#include <QtWidgets>
#include <QColorDialog>
 
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

    changeColorAction = new QAction(tr("Change color"), this);
    connect(changeColorAction, SIGNAL(triggered()), this, SLOT(changeColor()));    

    changeWidthAction = new QAction(tr("Change width"), this);
    connect(changeWidthAction, SIGNAL(triggered()), this, SLOT(changeWidth()));
    
     
}

void MainWindow::createMenus(){
    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);


    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    
    editMenu = new QMenu(tr("&Edit"), this);
    editMenu->addAction(changeColorAction);
    editMenu->addAction(changeWidthAction);
    

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(editMenu);
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

void MainWindow::changeColor(){
    QColor color = QColorDialog::getColor(drawing->penColor, this, tr("Choose color"));
    if (color.isValid()) {
        drawing->penColor = color;
    }
}

void MainWindow::changeWidth(){    
    QStringList widths;
    for (int i = 1; i <= 100; i++) {
        widths << QString::number(i);
    }
    QString selectedWidth = QInputDialog::getItem(this, tr("Pen thickness"), tr("Select pen thickness:"), widths, drawing->penWidth - 1, false);
    drawing->penWidth = selectedWidth.toInt();
}
