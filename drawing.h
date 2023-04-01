#ifndef DRAWING_H
#define DRAWING_H

#include <QWidget>

class Drawing : public QWidget
{
    Q_OBJECT

public:
    Drawing(QWidget *parent = 0);
    bool openImage(const QString &fileName);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);

    bool modified;
    bool drawing;
    int penWidth;
    QColor penColor;
    QPoint start;
    QImage image;
};

#endif