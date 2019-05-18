#include"generador_terreno.h"
#include"vectores_dinamicos.h"
#include"config.h"

// Devuelve un vector que representa el terreno y su tamaño n.
float ** crear_terreno( size_t * n ){

  * n = 0;

  const float terreno_estatico[][2] = {
      { 0 , 100} ,                       //izquierda
      { -1 , VENTANA_ALTO * 2.0 / 3} ,  // " medio "
      { VENTANA_ANCHO , 100}            //derecha
  };

  size_t nt = 3;

  float ** terreno = vector_desde_matriz(terreno_estatico , nt );

  if( terreno == NULL ) return NULL;

  // Asignamos la coordenada del medio aleatoriamente :
  terreno [1][0] = rand () % VENTANA_ANCHO;

  // Iterativamente densificamos 30 veces achicando el margen cada vez :
  for( size_t i = 1; i < 30; i ++) {
      float ** aux = vector_densificar(terreno , nt , 2 * ( i + 5) , 100 / i );
      vector_destruir( terreno , nt , 2);
          if( aux == NULL ) return NULL;
              terreno = aux;
              nt = 2 * ( i + 5);
  }

  * n = nt;
  return terreno;

}
