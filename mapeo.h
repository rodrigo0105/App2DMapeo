#ifndef MAPEO_H
#define MAPEO_H

#include <math.h>

class mapeo
{
    float xwMin,xwMax,ywMin,ywMax;//VENTANA, ESPACIO DEL MUNDO REAL
    int xpvMin,xpvMax,ypvMin,ypvMax;//PUERTO DE VISIN, ESPACIO
                        //DONDE SE DIBUJARA EN LA PANTALLA

public:
    //mapeo();
    //LA VENTANA PUDE UTILIZAR CUALQUIER SISTEMA DE MEDIDAD
    //km mts, cms, mms, Millas, pies, yardas
    void ventana(float wx1, float wy1, float wx2, float wy2);
    //EL PUERTO UTILIZA PIXELES O PUNTOS PARA DIBUJAR LA PANTALLA
    void puerto(int pvX1, int pvY1, int pvX2, int pvY2);
    //A TRAVES DE LAS REFERENCIAS & MANEJAMOS LA SALIDA DEL PUNTO TRANSFORMADO
    void mapear(int x, int y, int &xT, int &yT, int L, int M);
    //L y M representan el origen a partir del cual se duibujara

};

//TAREA: SELECCIONAR LA IMAGENN, CARICATURA
//DIBUJARLA EN UNA HOJA CUADRICULADA
//OBTENER SUS PUNTOS 20
//VACIARLOS EN UN ARREGLO BIDIMENSIONAL

#endif // MAPEO_H
