#ifndef DOTGRABBER_H
#define DOTGRABBER_H
#include <QWidget>
#include <QObject>
#include <QGraphicsRectItem>


class QGraphicsSceneHoverEventPrivate;
class QGraphicsSceneMouseEvent;

class DotGrabber : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit DotGrabber(QGraphicsItem *parentItem = 0, QObject *parent = 0);
    explicit DotGrabber(QPointF pos, QGraphicsItem *parentItem = 0, QObject *parent = 0);
    DotGrabber( const DotGrabber &other);
    ~DotGrabber();

    enum { Type = UserType + 3 };
    int type() const override { return Type;}
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    enum Flags {
        Movable = 0x01,
    };
    QPointF previousPosition() const;
    void setPreviousPosition(const QPointF previousPosition);

    void setDotFlags(unsigned int flags);    

signals:
    void previousPositionChanged();
    void signalMouseRelease();
    //void signalMove(QGraphicsItem *signalOwner, qreal dx, qreal dy);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    unsigned int m_flags;
    QPointF m_previousPosition;

};

#endif // DOTGRABBER_H
