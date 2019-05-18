CC := gcc
CFLAGS := -Wall -c -pedantic -std=c99 -g -O3
LFLAGS := -lm
INSTALL_DIR := /usr/sbin # Voy a tener que ser admin para instalar ahi

all: programa

main.o: main.c generador_terreno.h vectores_dinamicos.h naves.h caracteres.h fisica_del_juego.h generador_terreno.h diccionario.h
	$(CC) $(CFLAGS) $(LFLAGS) main.c

caracteres.o: caracteres.c caracteres.h
	$(CC) $(CFLAGS) caracteres.c

naves.o: naves.c naves.h
	$(CC) $(CFLAGS) naves.c

vectores_dinamicos.o: vectores_dinamicos.c vectores_dinamicos.h
	$(CC) $(CFLAGS) $(LFLAGS) vectores_dinamicos.c

generador_terreno.o: generador_terreno.c generador_terreno.h
	$(CC) $(CFLAGS) generador_terreno.c

fisica_del_juego.o: fisica_del_juego.c fisica_del_juego.h
	$(CC) $(CFLAGS) $(LFLAGS) fisica_del_juego.c

diccionario.o: diccionario.c diccionario.h
	$(CC) $(CFLAGS) diccionario.c

programa: main.o caracteres.o naves.o vectores_dinamicos.o generador_terreno.o fisica_del_juego.o
	$(CC) main.o caracteres.o naves.o vectores_dinamicos.o generador_terreno.o fisica_del_juego.o -o programa -lSDL2 $(LFLAGS) $(LFLAGS)

clean:
	rm *.o

