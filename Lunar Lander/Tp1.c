#include <stdio.h>
#include <math.h>

#define DT 0.001
#define G 9.81
#define VELOCIDAD_INICIAL 20
#define ANGULO_INICIAL 50
#define PI 3.141592

double computar_velocidad(double vi, double a, double dt);
double computar_posicion(double pi, double vi, double dt);

int main(void){
  double y=0;
  double x=0;
  double vx=VELOCIDAD_INICIAL*cos((ANGULO_INICIAL*PI)/180);
  double vy=VELOCIDAD_INICIAL*sin((ANGULO_INICIAL*PI)/180);
  for(double i=0;y>=0;i+=DT){
    printf("%f;%f;%f\n",i,x,y);
    vy=computar_velocidad(vy,-G,DT);
    vx=computar_velocidad(vx,0,DT);
    y=computar_posicion(y,vy,DT);
    x=computar_posicion(x,vx,DT);
  }
return 0;
}

double computar_velocidad(double vi, double a, double dt){
  return vi+a*dt;
}
double computar_posicion(double pi, double vi, double dt){
  return pi+vi*dt;
}
