#include "obszarrysowania.h"
#include "QDebug"
#include "QFile"
#include "QFileDialog"
#include "QString"
#include "QPen"
#include "QPainter"

ObszarRysowania::ObszarRysowania(QWidget *parent) : QWidget(parent)
{
    /*mRysowanie=false;
    QImage rysunek(500,500,QImage::Format_RGB32 );
    mRysunek=rysunek;
    mRysunek.fill (Qt::white);
    mKolor=Qt::black;
    this->update();*/
}
void ObszarRysowania::czerowny()
{
    qDebug()<<"czerwony";
    mKolor=Qt::red;
    this->update();
}
void ObszarRysowania::zolty ()
{
    qDebug()<<"zolty";
    mKolor=Qt::yellow;
    this->update();
}
void ObszarRysowania::niebieski ()
{
     qDebug()<<"niebieski";
     mKolor=Qt::blue;
     this->update();
}
void ObszarRysowania::zielony()
{
    qDebug()<<"zielony";
    mKolor=Qt::green;
    this->update();
}
void ObszarRysowania::czysc()
{
    qDebug()<<"czyszcze";
    QImage mRysunek1(500,500,QImage::Format_RGB32 );
    mRysunek1.fill(Qt::white);
    mRysunek= mRysunek1;
    this->update();
}

bool ObszarRysowania::save()
{
    QString filters("Pictures (*.PNG)");//filtry
    QString nazwa = QFileDialog::getSaveFileName(this, "Tytuł okna", QDir::currentPath(), filters);
    QFile file(nazwa);

    mRysunek.save(nazwa,"PNG");
    return true;
}
void ObszarRysowania::mousePressEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->button()==Qt::LeftButton)
       {
             qDebug()<<"Lewy przycisk zostal nacisniety";
             mRysowanie=true;
             Punkt=zdarzenie->pos();
       }


}

void ObszarRysowania::mouseMoveEvent(QMouseEvent *zdarzenie)
{
    if (mRysowanie==true)
    {
        qDebug()<<"nacisnales mysz";
        QPen pisak(mKolor,3);
        QPainter rysik(&mRysunek);//do bitmapy
        rysik.setPen(pisak);
        Punkt1=zdarzenie->pos();//pos=pozycja
        rysik.drawLine(Punkt,Punkt1);
        Punkt = Punkt1;
        this->update();//odswieza
    }
}

void ObszarRysowania::mouseReleaseEvent(QMouseEvent *zdarzenie)
{
    if (zdarzenie->button()==Qt::LeftButton)
       {
            qDebug()<<"Lewy przycisk zostal puszczony";
            mRysowanie=false;
       }
}

void ObszarRysowania::paintEvent(QPaintEvent *zdarzenie)//pod 7 . cw4
{
    QPainter rysik(this);
    rysik.drawImage(0,0,mRysunek);
}

void ObszarRysowania::resizeEvent(QResizeEvent *zdarzenie)//rozmiar
{
   QImage nowy_rysunek (zdarzenie->size(),QImage::Format_RGB32);
   mRysunek=nowy_rysunek;
   mRysunek.fill(Qt::white);
   mRysowanie=false;
   this->update();

}
