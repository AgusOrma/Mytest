#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_CADENA 1000
#define FIL 7

bool esta_arriba(float coordenadas[][2], int n, float x, float y);

int main(){

   float mat[][2] = {{-10.1,20},{-5,20},{10.5,-10},{15,-10},{21,0},{34.5,-20},{48,7}};
   char cadena[MAX_CADENA];

   while(true){

     printf("Ingrese coordenada x: ");
     fgets(cadena, MAX_CADENA, stdin);
     float x = atof(cadena);

     if(mat[0][0]>x || x>mat[FIL-1][0]){

          printf("\nLa coordenada x no se encuentra dentro de los limites del vector\n");
          break;

      }
      else {

         printf("\nLa coordenada x se encuentra dentro de los limites del vector\nIngrese coordenada y: ");
         fgets(cadena, MAX_CADENA, stdin);
         float y = atof(cadena);
         printf("El punto %sesta arriba del vector\n\n", esta_arriba(mat, FIL, x, y) ? "" : "no ");
      }
    }
    return 0;
}

bool esta_arriba(float coordenadas[][2], int n, float x, float y){

  float m;
  float b;
  float yr;

  for(int i=0; i<(n-1);i++){
      if(coordenadas[i][0]<=x && x<=coordenadas[i+1][0]){
          m=(coordenadas[i+1][1]-coordenadas[i][1])/(coordenadas[i+1][0]-coordenadas[i][0]);
          b=coordenadas[i][1]-m*coordenadas[i][0];
          yr=m*x+b;
      return y>yr;
      }
  }
  return false;
}
