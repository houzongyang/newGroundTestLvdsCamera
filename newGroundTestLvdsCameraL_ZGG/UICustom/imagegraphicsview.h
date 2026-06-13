#ifndef IMAGEGRAPHICSVIEW_H
#define IMAGEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

class ImageGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ImageGraphicsView(QWidget *parent = nullptr);

    QGraphicsPixmapItem* pixmapItem;
    void setPixmapItem(QGraphicsPixmapItem* item) {
        pixmapItem = item;
    }

protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void adjustSceneRect();


private:
    double scaleFactor = 1.15; // 缩放因子

    bool isDragging;  // 记录是否处于拖动状态
    QPoint dragStartPos;  // 记录拖动的起始位置
    QPointF scenePos;

signals:
    void mousePositionChanged(int x,int y,QPointF scenePos);
    void mouseClicked(int pixelValue,QPointF scenePos);
};

#endif // IMAGEGRAPHICSVIEW_H
