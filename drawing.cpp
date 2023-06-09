#include <QtWidgets>
#include "drawing.h"

Drawing::Drawing(QWidget *parent) : QWidget(parent){
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    drawing = false;
    penWidth = 3;
    penColor = Qt::black;
    image = QImage(QSize(1000, 1000), QImage::Format_ARGB32_Premultiplied);
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
        prettyLayout();
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
    painter.setPen(QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(start, end);
    modified = true;
    update();
    start = end; 
}

void Drawing::setImage(const QImage &newImage){
    image = newImage;
    modified = true;
    update();
}

void Drawing::prettyLayout() {
    if(modified){
        update();
        modified = false;
    }
}

void Drawing::resizeImage(int width, int height){
    QImage newImage(width, height, QImage::Format_ARGB32_Premultiplied);
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), image);
    image = newImage;
    update();
}

int Drawing::getImageWidth() {
    return image.width();
}

int Drawing::getImageHeight() {
    return image.height();
}

void Drawing::drawSquare(const QPoint &endPoint, QColor color) {
    QPainter painter(&image);
    painter.setPen(QPen(color, penWidth, Qt::SolidLine, Qt::RoundCap));
    painter.drawRect(QRect(start, endPoint));
    modified = true;
    update();
}

void Drawing::drawCircle(const QPoint &endPoint, QColor color) {
    QPainter painter(&image);
    painter.setPen(QPen(color, penWidth, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(QRect(start, endPoint));
    modified = true;
    update();
}
