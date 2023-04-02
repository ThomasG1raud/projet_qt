#include "primarywindow.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>

PrimaryWindow::PrimaryWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Primary Window");

    m_startButton = new QPushButton("Start", this);
    m_startButton->setFixedSize(100, 50);
    m_startButton->move((width() - m_startButton->width()) / 2,
                        (height() - m_startButton->height()) / 2);

    connect(m_startButton, &QPushButton::clicked, this, &PrimaryWindow::onStartButtonClicked);

    QPalette palette;
    QPixmap background("./image.jfif");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void PrimaryWindow::onStartButtonClicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    close();
} 