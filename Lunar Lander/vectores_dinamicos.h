#ifndef	_VECTORES_DINAMICOS_H
#define	_VECTORES_DINAMICOS_H

#include"vectores_dinamicos.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COL 2 //Cantidad de columnas de la matriz

void vector_destruir(float **v, size_t n, size_t m);

float **crear_vdin(int n);

float **vector_desde_matriz(const float m[][2], size_t n);

float generar_aleatorio_entre(float max, float min);

float imagen_de_x(float **v, size_t nv, float x);

float **vector_densificar(float **v, size_t nv, size_t nn, float margen);

#endif // _VECTORES_DINAMICOS_H
