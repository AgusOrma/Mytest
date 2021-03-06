#include"vectores_dinamicos.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COL 2 //Cantidad de columnas de la matriz

/*Esta funcion la voy a utilizar para liberar la memoria asignada a un determinado vector
de manera tal que dicha reserva quede a disposición de cualquier otro proceso.*/
void vector_destruir(float **v, size_t n, size_t m){

  for(size_t i = 0; i < n; i++)
        free(v[i]);

  free(v);
}

/*Funcion que se le asigna el tamaño y crea una matriz dinamica de 2 columnas*/
float **crear_vdin(int n){

  float **vdin;

  vdin = malloc(n * sizeof(float *));

  if(vdin == NULL){
     return NULL;
  }

  for(size_t i = 0; i < n; i++){
     vdin[i] = malloc(COL * sizeof(float));
        if(vdin == NULL){
           vector_destruir(vdin, n, COL);
              return NULL;
        }
   }
   return vdin;
}


/*Esta funcion la voy a utilizar para pasar una matriz a un vector dinamico con la misma
cantidad de elementos*/
float **vector_desde_matriz(const float m[][2], size_t n){

   float **vdin = crear_vdin(n);

   for(size_t i = 0; i < n; i++)
      for(size_t j = 0; j < COL; j++)
         vdin[i][j] = m[i][j];

   return vdin;
}


/*Con esta funcion genero un numero aleatorio dentro de un intervalo dado*/
float generar_aleatorio_entre(float max, float min){

   return ((float)rand() / (float)RAND_MAX) * (max - min) + min;
}


/*Esta funcion me va a ser de utilidad cuando quiera calcular la imagen de una
variable x perteneciente a una recta*/
float imagen_de_x(float **v, size_t nv, float x){

   float m; /*pendiente de la recta*/
   float b; /*ordenada al origen de la recta*/
   float imagen;

   for(size_t i = 0; i < nv ; i++){
      if(v[i][0] <= x && x <= v[i+1][0]){

         m = (v[i+1][1] - v[i][1]) / (v[i+1][0] - v[i][0]);
         b = v[i][1] - m * v[i][0];
         return imagen = m * x + b;
      }
   }
   return 0;
}


/* La funcion densificar vector la voy a utilizar para, dado un vector de coordenadas,
 genere una versión densificada de la misma con puntos aleatorios.
La cantidad de coordenadas del vector densificado deben ser mayores
a las del vector original. Ya que como condicion necesaria el vector nuevo
debe conservar los puntos del vector original.
*/
float **vector_densificar(float **v, size_t nv, size_t nn, float margen){

  srand(time(NULL));

  /*Asumo que los elementos del vector se encuentran ordenados por coordenada x creciente.*/

  float xi = v[0][0];    /*Entre las absiscas xi y xf del vector ingresado genero las */
  float xf = v[nv-1][0]; /*coordenadas x aleatorias*/

  float ymax;     /*Declaro variables ymax ymin, estas van a ser pertenecientes al margen superior e inferior*/
  float ymin;     /*en ese intervalo se va a encontrar la variable y aleatoria*/

  float **vnuevo = crear_vdin(nn);

  /*copio las coordenadas del vector ingresado al vector nuevo*/
  for(size_t i = 0; i < nv; i++)
     for(size_t j = 0; j < COL; j++)
        vnuevo[i][j] = v[i][j];

  /*Genero la variable x, esta debe estar entre xi y xf*/
  /*La variable contador se encarga de ingresar la cantidad de nuevas
  coordenadas pedidas*/

  for(size_t contador = 0; contador < (nn - nv); contador++){


     float x = generar_aleatorio_entre(xf, xi);

     ymax = imagen_de_x(v, nv, x) + margen;
     ymin = imagen_de_x(v, nv, x) - margen;

     float y = generar_aleatorio_entre(ymax, ymin);

     size_t k;
     for(k = 0; k < nn; k++)
        if(x < vnuevo[k][0])
           break;

     for(size_t j = nn - 1; j > k; j--){
        vnuevo[j][0] = vnuevo[j-1][0];
        vnuevo[j][1] = vnuevo[j-1][1];
     }

     vnuevo[k][0] = x;
     vnuevo[k][1] = y;

  }

  return vnuevo;

}
