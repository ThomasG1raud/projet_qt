#include <QtWidgets>
#include "drawing.h"

Drawing::Drawing(QWidget *parent) : QWidget(parent){
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    drawing = false;
    penWidth = 10;
    penColor = Qt::black;
    image = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::white);
}

void Drawing::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        start = event->pos();
        drawing = true;
    }
}

void Drawing::mouseMoveEvent(QMouseEvent *event){
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        drawLineTo(event->pos());
    }
}

void Drawing::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && drawing) {
        drawLineTo(event->pos());
        drawing = false;
    }
}

void Drawing::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QRect fill = event->rect();
    painter.drawImage(fill, image, fill);  
}

void Drawing::drawLineTo(const QPoint &end){
    QPainter painter(&image);
    painter.setPen(QPen(penColor, penWidth));
    painter.drawLine(start, end);
    modified = true;
    update(QRect(start, end));
    start = end; 
}

void Drawing::setImage(const QImage &newImage){
    image = newImage;
    modified = true;
    update();
}