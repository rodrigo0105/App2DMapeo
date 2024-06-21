#include "mapeo.h"

/*mapeo::mapeo()
{

}*/

void mapeo::ventana(float wx1, float wy1, float wx2, float wy2)
{//MUNDO REAL
    xwMin = wx1;
    ywMin = wy1;
    xwMax = wx2;
    ywMax = wy2;
}

void mapeo::puerto(int pvX1, int pvY1, int pvX2, int pvY2)
{// PUERTO DE VISION
    xpvMin = pvX1;
    ypvMin = pvY1;
    xpvMax = pvX2;
    ypvMax = pvY2;
}

void mapeo::mapear(int x, int y, int &xT, int &yT, int L, int M)
{
    float sX, sY;
    sX = (xpvMax-xpvMin)/(xwMax-xwMin); //ESCALACION EN X
    sY = (ypvMax-ypvMin)/(ywMax-ywMin); //ESCALACION EN Y

    //POR LA REFERENCIA REGRESAMOS LA XT Y YT

    xT = floor((sX*(x-xwMin)+xpvMin+L)+0.5);

    yT = floor((sY*(ywMin-y)-ypvMin+M)+0.5);

}
