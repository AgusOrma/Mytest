#include"caracteres.h"
#include<stdio.h>
#include<stdlib.h>

typedef enum caracter {A ,B ,C ,D ,E ,F ,G ,H ,I ,J ,K ,L ,M ,N ,O ,P ,Q ,R ,S ,T ,U ,V ,W ,X ,Y ,Z ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 , derecha, izquierda, arriba, abajo, espacio}car_t;

typedef const int (*matrizc_t)[2];

matrizc_t caracteres = {

	 	[A] = caracter_a,
		[B] = caracter_b,
		[C] = caracter_c,

};

const int caracter[] = {

 	[A] = 'A',
	[B] = 'B',
	[C] = 'C',

};

const int tamagno_caracter[] = {7 ,12 ,4 ,7 ,7 ,6 ,7 ,6 ,6 ,4 ,6 ,3 ,5 ,4 ,5 ,5 ,9 ,7 ,6 ,4 ,4 ,3 ,5 ,5 ,5 ,4 ,5 ,2 ,6 ,7 ,5 ,6 ,5 ,3 ,7 ,5 ,5 ,5 ,5 ,5 ,1 };
