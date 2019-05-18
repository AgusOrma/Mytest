#ifndef	_FISICA_DEL_JUEGO_H
#define	_FISICA_DEL_JUEGO_H

#include "fisica_del_juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double computar_velocidad(double vi, double a, double dt);

double computar_posicion(double pi, double vi, double dt);

bool esta_arriba(float coordenadas[][2], int n, float x, float y);

void trasladar(float coordenadas[][2], int n, float dx, float dy);

void rotar(float coordenadas[][2], int n, double rad);

#endif // _FISICA_DEL_JUEGO_H
