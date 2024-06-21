#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    dibujoOrientacionNormal = dibujoMapeado = false;
    xpvMin=150,xpvMax=350,ypvMin=100,ypvMax=400;
    rx1=150,ry1=100,rAncho=200,rAlto=300;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    canvas = new QPainter(this);
    if(dibujoOrientacionNormal)
        dibujarFigura();
    else if(dibujoMapeado)
        dibujarFiguraMapeada();

    canvas->end();
}



//EVALUACION MAPEO MAÑANA 12 DE MAYO

void Widget::asignarFigura()
{
    /*Fig[0][0] = 10; Fig[0][1] = 10; Fig[0][2] = 1;
    Fig[1][0] = 30; Fig[1][1] = 10; Fig[1][2] = 1;
    Fig[2][0] = 10; Fig[2][1] = 30; Fig[2][2] = 1;
    //PARA CERRAR LA FIGURA
    Fig[3][0] = 10; Fig[3][1] = 10; Fig[3][2] = 1;*/

    /*Fig[0][0] = 1.5; Fig[0][1] = 1.5; Fig[0][2] = 1;
    Fig[1][0] = 9.5; Fig[1][1] = 1.5; Fig[1][2] = 1;
    Fig[2][0] = 9.5; Fig[2][1] = 9.5; Fig[2][2] = 1;
    //PARA CERRAR LA FIGURA
    Fig[3][0] = 1.5; Fig[3][1] = 1.5; Fig[3][2] = 1;*/

    /*Fig[0][0] = 1.5; Fig[0][1] = 1.5; Fig[0][2] = 1;
    Fig[1][0] = 21.5; Fig[1][1] =1.5; Fig[1][2] = 1;
    Fig[2][0] = 21.5; Fig[2][1] = 27.5; Fig[2][2] = 1;
    //PARA CERRAR LA FIGURA
    Fig[3][0] = 1.5; Fig[3][1] = 1.5; Fig[3][2] = 1;*/

    /*Fig[0][0] = 0.0; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 22/2; Fig[1][1] = 28; Fig[1][2] = 1;
    Fig[2][0] = 22; Fig[2][1] = 0.0; Fig[2][2] = 1;
    Fig[3][0] = 0; Fig[3][1] = 28/2; Fig[3][2] = 1;
    Fig[4][0] = 22; Fig[4][1] = 28/2; Fig[4][2] = 1;
    //PARA CERRAR
    Fig[5][0] = 0; Fig[5][1] = 0; Fig[5][2] = 1;*/

    Fig[ 0][0] =  1;  Fig[ 0][1] =   12; Fig[ 0][2] = 1;
    Fig[ 1][0] =  1; Fig[ 1][1] =  13; Fig[ 1][2] = 1;
    Fig[ 2][0] =  2; Fig[ 2][1] =   13 ; Fig[ 2][2] = 1;
    Fig[ 3][0] =  2; Fig[ 3][1] =   14; Fig[ 3][2] = 1;
    Fig[ 4][0] =  3; Fig[ 4][1] =   14; Fig[ 4][2] = 1;
    Fig[ 5][0] =  3; Fig[ 5][1] =   15; Fig[ 5][2] = 1;
    Fig[ 6][0] =  4; Fig[ 6][1] =   15; Fig[ 6][2] = 1;
    Fig[ 7][0] =  4; Fig[ 7][1] =  16; Fig[ 7][2] = 1;
    Fig[ 8][0] =  5; Fig[ 8][1] =  16; Fig[ 8][2] = 1;
    Fig[ 9][0] =  5; Fig[ 9][1] =  17; Fig[ 9][2] = 1;
    Fig[10][0] =  8; Fig[10][1] =  17; Fig[10][2] = 1;
    Fig[11][0] =  8; Fig[11][1] =  16; Fig[11][2] = 1;
    Fig[12][0] =  7; Fig[12][1] =  16; Fig[12][2] = 1;
    Fig[13][0] =  7; Fig[13][1] =  18; Fig[13][2] = 1;
    Fig[14][0] =  9; Fig[14][1] =  17; Fig[14][2] = 1;
    Fig[15][0] =  8; Fig[15][1] =  17; Fig[15][2] = 1;
    Fig[16][0] =   8; Fig[16][1] =  17; Fig[16][2] = 1;
    Fig[17][0] =   8; Fig[17][1] =  19; Fig[17][2] = 1;
    Fig[18][0] =   10; Fig[18][1] =  19; Fig[18][2] = 1;
    Fig[19][0] =   10; Fig[19][1] =  18; Fig[19][2] = 1;
    Fig[20][0] =   9; Fig[20][1] =  17; Fig[20][2] = 1;
    Fig[21][0] =   9; Fig[21][1] =  20; Fig[21][2] = 1;
    Fig[22][0] =   12; Fig[22][1] =  20; Fig[22][2] = 1;
    Fig[23][0] =   12; Fig[23][1] =   21; Fig[23][2] = 1;
    Fig[24][0] =   16; Fig[24][1] =   21; Fig[24][2] = 1;
    Fig[25][0] =   16; Fig[25][1] =   22; Fig[25][2] = 1;

    Fig[26][0] =  20; Fig[26][1] =   22; Fig[26][2] = 1;
    Fig[27][0] =  20; Fig[27][1] =  21; Fig[27][2] = 1;
    Fig[28][0] =  21; Fig[28][1] =   21 ; Fig[28][2] = 1;
    Fig[29][0] =  21; Fig[29][1] =   19; Fig[29][2] = 1;
    Fig[30][0] =  22; Fig[30][1] =   19; Fig[30][2] = 1;
    Fig[31][0] =  22; Fig[31][1] =   18; Fig[31][2] = 1;
    Fig[32][0] =  23; Fig[32][1] =   18; Fig[32][2] = 1;
    Fig[33][0] =  23; Fig[33][1] =  12; Fig[33][2] = 1;
    Fig[34][0] =  22; Fig[34][1] =  12; Fig[34][2] = 1;
    Fig[35][0] =  22; Fig[35][1] =  10; Fig[35][2] = 1;
    Fig[36][0] =  21; Fig[36][1] =  10; Fig[36][2] = 1;
    Fig[37][0] =  21; Fig[37][1] =  11; Fig[37][2] = 1;
    Fig[38][0] =  19; Fig[38][1] =  11; Fig[38][2] = 1;
    Fig[39][0] =  19; Fig[39][1] =  15; Fig[39][2] = 1;
    Fig[40][0] =  18; Fig[40][1] =  15; Fig[40][2] = 1;
    Fig[41][0] =  18; Fig[41][1] =  10; Fig[41][2] = 1;
    Fig[42][0] =  17; Fig[42][1] =  10; Fig[42][2] = 1;
    Fig[43][0] =  17; Fig[43][1] =  9; Fig[43][2] = 1;
    Fig[44][0] =  15; Fig[44][1] =  9; Fig[44][2] = 1;
    Fig[45][0] =  15; Fig[45][1] =  8; Fig[45][2] = 1;
    Fig[46][0] =  14; Fig[46][1] =  7; Fig[46][2] = 1;
    Fig[47][0] =  16; Fig[47][1] =  7; Fig[47][2] = 1;
    Fig[48][0] =  16; Fig[48][1] =  6; Fig[48][2] = 1;
    Fig[49][0] =  15; Fig[49][1] =  6; Fig[49][2] = 1;
    Fig[50][0] =  15; Fig[50][1] =  5; Fig[50][2] = 1;
    Fig[51][0] =  14; Fig[51][1] =  5; Fig[51][2] = 1;

    Fig[52][0] =  14; Fig[52][1] =  4; Fig[52][2] = 1;
    Fig[53][0] =  9; Fig[53][1] =   4; Fig[53][2] = 1;
    Fig[54][0] =  9; Fig[54][1] =   5; Fig[54][2] = 1;
    Fig[55][0] =  7; Fig[55][1] =   5; Fig[55][2] = 1;
    Fig[56][0] =  7; Fig[56][1] =   6; Fig[56][2] = 1;
    Fig[57][0] =  9; Fig[57][1] =   6; Fig[57][2] = 1;
    Fig[58][0] =  9; Fig[58][1] =   7; Fig[58][2] = 1;
    Fig[59][0] =  11; Fig[59][1] =   7; Fig[59][2] = 1;
    Fig[60][0] =  11; Fig[60][1] =  9; Fig[60][2] = 1;
    Fig[61][0] =  12; Fig[61][1] = 9; Fig[61][2] = 1;
    Fig[62][0] =  12; Fig[62][1] =  13; Fig[62][2] = 1;
    Fig[63][0] =  11; Fig[63][1] =  13; Fig[63][2] = 1;
    Fig[64][0] =  11; Fig[64][1] =  14; Fig[64][2] = 1;
    Fig[65][0] =  9; Fig[65][1] =  14; Fig[65][2] = 1;
    Fig[66][0] =  9; Fig[66][1] =  13; Fig[66][2] = 1;
    Fig[67][0] =  7; Fig[67][1] =  13; Fig[67][2] = 1;
    Fig[68][0] =  7; Fig[68][1] =  12; Fig[68][2] = 1;
    Fig[69][0] =  6; Fig[69][1] =  12; Fig[69][2] = 1;
    Fig[70][0] =  6; Fig[70][1] =  11; Fig[70][2] = 1;
    Fig[71][0] =  5; Fig[71][1] =  11; Fig[71][2] = 1;
    Fig[72][0] =  5; Fig[72][1] =  9; Fig[72][2] = 1;
    Fig[73][0] =  6; Fig[73][1] =  9; Fig[73][2] = 1;
    Fig[74][0] =  6; Fig[74][1] =  8; Fig[74][2] = 1;
    Fig[75][0] =  7; Fig[75][1] =  8; Fig[75][2] = 1;
    Fig[76][0] =  7; Fig[76][1] =  7; Fig[76][2] = 1;
    Fig[77][0] =  5; Fig[77][1] =  7; Fig[77][2] = 1;
    Fig[78][0] =  5; Fig[78][1] =  8; Fig[78][2] = 1;
    Fig[79][0] =  4; Fig[79][1] =  8; Fig[79][2] = 1;
    Fig[80][0] =  4; Fig[80][1] =  9; Fig[80][2] = 1;
    Fig[81][0] =  3; Fig[81][1] =  9; Fig[81][2] = 1;
    Fig[82][0] =  3; Fig[82][1] =  10; Fig[82][2] = 1;
    Fig[83][0] =  2; Fig[83][1] =  10; Fig[83][2] = 1;
    Fig[84][0] =  2; Fig[84][1] =  12; Fig[84][2] = 1;
    Fig[85][0] =  1; Fig[85][1] =  12; Fig[85][2] = 1;

    //RESPALDAR LOS VALORES DEL POLIGONO EN FIGAUX

    for(int r = 0; r < 86; r++)
        for(int c = 0; c < 3; c++)
            FigAux[r][c] = Fig[r][c];

    ancho = this->size().width() - ui->widget->size().width();

    centroX = ancho / 2;
    centroY = this->size().height() / 2;


}

void Widget::dibujarFigura()
{
    QPen pen(QColor(0,200,0), 5);
    canvas->setPen(pen);

    //DIBUJAR EL PRIMER CUADRANTE
    //LINEA HORIZONTAL
    //canvas->drawLine(0,0,ancho,0);
    //LINEA VERTICAL
    //canvas->drawLine(0,0,0,size().height());

    //DIBUJAR CUADRANTES
    //LINEA HORIZONTAL
    canvas->drawLine(0,centroY,ancho,centroY);
    //LINEA VERTICAL
    canvas->drawLine(centroX,0,centroX,size().height());

    canvas->setPen(QColor(0,0,255));
    for(int i = 0; i < 26; i++)
                        //PUNTO INICIAL
        canvas->drawLine(centroX+Fig[i][0],centroY+Fig[i][1],centroX+Fig[i+1][0],centroY+Fig[i+1][1]);

}

void Widget::dibujarFiguraMapeada()
{
    QPen pen(QColor(0,200,0), 5);
    canvas->setPen(pen);

    //DIBUJAR EL PRIMER CUADRANTE CON ORIENTACION NORMAL (Y HACIA ARRIBA)
    //LINEA HORIZONTAL
    //canvas->drawLine(0,this->size().height(),ancho,size().height());
    //LINEA VERTICAL
    //canvas->drawLine(0,0,0,size().height());
    //UTILIZAR LA CLASE MAPEO

    //DIBUJAR CUADRANTES
    //LINEA HORIZONTAL
    //canvas->drawLine(0,centroY,ancho,centroY);
    //LINEA VERTICAL
    //canvas->drawLine(centroX,0,centroX,size().height());

    //UTILIZAR CLASE MAPEO
    mapeo dibujo;
    //dibujo.ventana(ancho/2,0, ancho,size().height()/2);

    //dibujo.ventana(0,0, ancho,size().height());

    //TAMAÑO DE HOJA DE MAQUINA
    dibujo.ventana(0,0,22,28);

    // XPVmin ofrece un factor de traslacion
    //PRUEBA DE ESCRITORIO UTILIZANDO EL VALOR DE XPVMIN Y L = 0

    //dibujo.puerto(ancho/2,0,ancho,size().height()/2); //2 <-- L = 0

    //PRUEBA DE ESCRITORIO UTILIZANDO EL VALOR DE XPVMIN = 0,  L = CENTROX (ancho/2)
    //dibujo.puerto(0,0,ancho/2,size().height()/2);

    //SIMULACION DE UNA HOJA DE MAQUINA EN EL PUERTO DE VISION

    //
    dibujo.puerto(xpvMin,ypvMin,xpvMax,ypvMax);

    canvas->drawRect(rx1,ry1,rAncho,rAlto);

    //ORIGEN EN LA ESQUINA INFERIOR IZQUIERDA
    //int L = 0;
    //int M = this->size().height();
    //ORIGEN EN EL CENTRO DEL AREA DE DIBUJO
    /*int L = centroX;
    int M = centroY;*/

    //ORIGEN PARA SIMULAR HOJA DE MAQUINA
    int L = 0;
    int M = 500; //se debe sumar ypvmin + ypvmax

    canvas->setPen(QColor(255,0,0));
    int x1, y1, x2, y2;

    dibujo.mapear(Fig[0][0],Fig[0][1],x1,y1,L,M);
    dibujo.mapear(Fig[85][0],Fig[85][1],x2,y2,L,M);

    canvas->drawLine(x1,y1,x2,y2);

    for(int i=0;i<85;i++){
        dibujo.mapear(Fig[i][0],Fig[i][1],x1,y1,L,M);
        dibujo.mapear(Fig[i+1][0],Fig[i+1][1],x2,y2,L,M);
        canvas->drawLine(x1,y1,x2,y2);
    }

}


void Widget::on_pushButton_clicked()
{
    asignarFigura();
    dibujoOrientacionNormal = true;
    dibujoMapeado = false;
    repaint();
}


void Widget::on_pushButton_2_clicked()
{
    asignarFigura();
    dibujoOrientacionNormal = false;
    dibujoMapeado = true;
    repaint();
}


void Widget::on_pushButton_3_clicked()
{
    if(xpvMax<440){
    xpvMax += 10;
    ypvMax += 10;
    xpvMin -= 10;
    ypvMin -= 10;
    rx1-=10;
    ry1-=10;
    rAncho+=20;
    rAlto+=20;
    on_pushButton_2_clicked();
    }
}


void Widget::on_pushButton_4_clicked()
{
    if(xpvMax>220){
    xpvMax -= 10;
    ypvMax -= 10;
    xpvMin += 10;
    ypvMin += 10;
    rx1+=10;
    ry1+=10;
    rAncho-=20;
    rAlto-=20;
    on_pushButton_2_clicked();
    }
}

