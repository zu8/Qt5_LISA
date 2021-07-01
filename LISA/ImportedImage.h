#ifndef IMPORTEDIMAGE_H
#define IMPORTEDIMAGE_H
#include <QWidget>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>

class ImportedImage : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    ImportedImage(QGraphicsPixmapItem* parent = 0);
    ImportedImage(const ImportedImage &other);
    void setImportedImage(const QPixmap &pxmp);
    void setScValue(qreal val);
    qreal getScValue();
    void setScPos(QPointF);
    QPointF getScPos();
    QPointF previousPosition() const;
    void setPreviousPosition(const QPointF previousPosition);
    QRectF boundingRect () const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    QPainterPath shape() const override;
    enum {
        Type = UserType + 1
    };
    int type() const override;
    friend QDataStream& operator>>( QDataStream& in, ImportedImage& image );
    friend QDataStream & operator<<(QDataStream & out,   const ImportedImage & image);    
protected:
    //QSize sizeHint() const;
    void mousePressEvent (QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent (QGraphicsSceneMouseEvent *event) override;
public:
    QPixmap m_pxmp;
    QRect selection_mask;
    QPointF m_previousPosition;    
    bool status;
    qreal scalingValue;
    QPointF scPos;
signals:
    void ImgClicked(bool);
public slots:
    void ImageIsBlocked(bool);
    //friend class LISA_Scene;
};

//Перегрузка операций << и >> для ImportedImage и QDataStream:
QDataStream & operator<<(QDataStream & out,  const ImportedImage  & image);
QDataStream & operator>>(QDataStream & in,  ImportedImage & image);

#endif // IMPORTEDIMAGE_H
