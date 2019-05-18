#include"fisica_del_juego.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

double computar_velocidad(double vi, double a, double dt){

  return vi + a * dt;
}

double computar_posicion(double pi, double vi, double dt){

  return pi + vi * dt;
}

/*bool esta_arriba(float **coordenadas, int n, float x, float y){

  float m;
  float b;
  float yr;

  for(int i = 0 ; i < (n-1); i++){

      if(coordenadas[i][0] <= x && x <= coordenadas[i+1][0]){

          m = (coordenadas[i+1][1]-coordenadas[i][1])/(coordenadas[i+1][0]-coordenadas[i][0]);
          b = coordenadas[i][1]-m*coordenadas[i][0];
          yr = m * x + b;

      return y>yr;
      }
  }
  return false;
}*/

void trasladar(float **coordenadas, int n, float dx, float dy){

   for(int i = 0; i < n; i++){

     coordenadas[i][0]+=dx;
     coordenadas[i][1]+=dy;
   }
}

void rotar(float **coordenadas, int n, double rad){

   float cos_rad = cos(rad);
   float sen_rad = sin(rad);

   for(int i=0; i<n; i++){

     float px = coordenadas[i][0];
     float py = coordenadas[i][1];
     coordenadas[i][0] = px * cos_rad - py * sen_rad;
     coordenadas[i][1] = px * sen_rad + py * cos_rad;
   }
}
