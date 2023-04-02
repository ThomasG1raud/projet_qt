#ifndef PRIMARYWINDOW_H
#define PRIMARYWINDOW_H

#include <QWidget>

class QPushButton;

class PrimaryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PrimaryWindow(QWidget *parent = nullptr);

private slots:
    void onStartButtonClicked();

private:
    QPushButton *m_startButton;
};

#endif // PRIMARYWINDOW_H