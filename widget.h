#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

#include "mapeo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void asignarFigura();
    void dibujarFigura();
    void dibujarFiguraMapeada();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;

    QPainter *canvas;
    //TRIANGULO
    //float Fig[4][3];
    //float FigAux[4][3];

    float Fig[86][3];
    float FigAux[86][3];

    int ancho;
    int centroX, centroY;

    bool dibujoOrientacionNormal;
    bool dibujoMapeado;

    int xpvMin,xpvMax,ypvMin,ypvMax;
    // rectangulo
    int rx1,ry1,rAncho,rAlto;

};
#endif // WIDGET_H
