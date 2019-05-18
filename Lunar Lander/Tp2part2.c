#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define MAX_CADENA 1000
#define FIL 7

void trasladar(float coordenadas[][2], int n, float dx, float dy);
void rotar(float coordenadas[][2], int n, double rad);

int main(){

   float mat[][2] = {{-10.1, 20},{-5, 20},{10.5, -10},{15, -10},{21, 0},{34.5, -20},{48, 7}};

   printf("coordenadas del vector:\n");

   for(int i=0; i<FIL; i++){
      printf("%f %f\n", mat[i][0], mat[i][1]);
   }

   printf("\ncoordenadas del vector trasladado:\n");

   for(int i=0; i<FIL; i++){
      trasladar(mat, FIL, 5, 5);
      printf("%f %f\n", mat[i][0], mat[i][1]);
      trasladar(mat, FIL, -5, -5);
   }

   printf("\ncoordenadas del vector rotado:\n");

   for(int i=0; i<FIL; i++){
      rotar(mat, FIL, PI);
      printf("%f %f\n", mat[i][0], mat[i][1]);
      rotar(mat, FIL, -PI);
   }
   return 0;
}


void trasladar(float coordenadas[][2], int n, float dx, float dy){
   for(int i=0; i<n; i++){
     coordenadas[i][0]+=dx;
     coordenadas[i][1]+=dy;
   }
}

void rotar(float coordenadas[][2], int n, double rad){

   float cos_rad = cos(rad);
   float sen_rad = sin(rad);

   for(int i=0; i<n; i++){
     float px=coordenadas[i][0];
     float py=coordenadas[i][1];
     coordenadas[i][0] = px*cos_rad - py*sen_rad;
     coordenadas[i][1] = px*sen_rad + py*cos_rad;
   }
}
