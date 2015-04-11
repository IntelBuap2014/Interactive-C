CC = gcc
CFLAGS = `pkg-config --libs gtk+-3.0`
LDFLAGS = `pkg-config --cflags gtk+-3.0`
FUESERVIDOR = fuentes/server.c
FUECLIENTE = fuentes/N_client.c
OBJCONEXION = $(HOME)/repositorios/Interactive-C/fuentes/*.o
SOURCES = interfaces/gtk-unir-sesion.c
OBJECTS = /interfaces*.o

all: interfaz1 servidor cliente
    
interfaz1: ${SOURCES} 
	${CC} ${LDFLAGS} -o bin/gtk-unir-sesion ${SOURCES} ${CFLAGS} 

servidor: ${FUESERVIDOR}
	${CC} ${FUESERVIDOR} -o bin/server

cliente: ${FUECLIENTE}
	${CC} ${FUECLIENTE} -o bin/cliente






