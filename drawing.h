#ifndef DRAWING_H
#define DRAWING_H

#include <QWidget>

class Drawing : public QWidget{
Q_OBJECT
public:
    Drawing(QWidget *parent = nullptr);
    int penWidth;
    QColor penColor;
    QImage image;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    void drawLineTo(const QPoint &endPoint);
    void prettyLayout();
    
    bool modified;
    bool drawing;
    
    
    QPoint start;

public slots:
    void setImage(const QImage& newImage);
    void resizeImage(int width, int height);
    int getImageWidth();
    int getImageHeight();
};

#endif