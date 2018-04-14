#ifndef OBSZARRYSOWANIA_H
#define OBSZARRYSOWANIA_H

#include "QDebug"
#include <QWidget>
#include "QString"
#include "QMouseEvent"
#include "QPaintEvent"
#include "QResizeEvent"
#include "QPoint"


class ObszarRysowania : public QWidget
{
    Q_OBJECT
public:
    explicit ObszarRysowania(QWidget *parent = 0);
    bool mRysowanie;
    QImage mRysunek;
    QColor mKolor;
    QPoint Punkt;
    QPoint Punkt1;
signals:

public slots:
    void czerowny ();

    void zolty ();

    void niebieski ();

    void zielony ();

    void czysc ();

    bool save ();
protected:
    void mousePressEvent(QMouseEvent *zdarzenie);

    void mouseMoveEvent(QMouseEvent *zdarzenie);

    void mouseReleaseEvent(QMouseEvent *zdarzenie);

    void paintEvent(QPaintEvent *zdarzenie);

    void resizeEvent(QResizeEvent *zdarzenie);

};

#endif // OBSZARRYSOWANIA_H
