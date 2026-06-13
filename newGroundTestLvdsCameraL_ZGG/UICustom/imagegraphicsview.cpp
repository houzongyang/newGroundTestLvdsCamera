/**
 * @file      imageGraphicsView.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "ImageGraphicsView.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <cmath>


ImageGraphicsView::ImageGraphicsView(QWidget *parent)
    : QGraphicsView(parent),isDragging(false)
{
    setDragMode(QGraphicsView::NoDrag);
    setCursor(Qt::ArrowCursor);

    setMouseTracking(true);

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

void ImageGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
        scale(scaleFactor, scaleFactor);
    else
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
}


void ImageGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    QGraphicsView::mouseMoveEvent(event);
    scenePos = mapToScene(event->pos());
    emit mousePositionChanged(static_cast<int>(scenePos.x()),static_cast<int>(scenePos.y()),scenePos);

    QPointF clickedPos = mapToScene(event->pos());
    QPointF itemPos = pixmapItem->mapFromScene(clickedPos);

    if (pixmapItem->contains(itemPos)) {
        QImage tempImg = pixmapItem->pixmap().toImage();

        QPoint pixelPos(floor(itemPos.x()), floor(itemPos.y()));

        pixelPos.setX(qBound(0, pixelPos.x(), tempImg.width() - 1));
        pixelPos.setY(qBound(0, pixelPos.y(), tempImg.height() - 1));

        int grayValue = qGray(tempImg.pixel(pixelPos));
        emit mouseClicked(grayValue, clickedPos);
    }
}

void ImageGraphicsView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);

    QSize viewportSize = viewport()->size();
    qreal sceneWidth = viewportSize.width() * 8;
    qreal sceneHeight = viewportSize.height() * 8;

    setSceneRect(-sceneWidth / 2, -sceneHeight / 2, sceneWidth, sceneHeight);
}

void ImageGraphicsView::adjustSceneRect() {
    qreal scenePadding = 500;

    QRectF newSceneRect = scene()->itemsBoundingRect().adjusted(-scenePadding, -scenePadding, scenePadding, scenePadding);
    setSceneRect(newSceneRect);
}


void ImageGraphicsView::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        setDragMode(QGraphicsView::ScrollHandDrag);
        dragStartPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
    QGraphicsView::mousePressEvent(event); /// 注意，这行代码必须放在后面，不能放在前面，如果防在前面
}


void ImageGraphicsView::mouseReleaseEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        setDragMode(QGraphicsView::NoDrag);
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsView::mouseReleaseEvent(event);
}
