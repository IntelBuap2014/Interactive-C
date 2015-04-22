CC = gcc
CFLAGS = `pkg-config --libs gtk+-3.0`
LDFLAGS = `pkg-config --cflags gtk+-3.0`
FUESERVIDOR = src/controlador/server.c
FUECLIENTE = src/controlador/N_client.c
OBJCONEXION = src/controlador/*.o
CREARSESION = src/interfaces/gtk-crear-sesion.c
UNIRSESION = src/interfaces/gtk-unir-sesion.c
PRINCIPAL = src/interfaces/gtk-principal.c
OBJECTS = src/interfaces*.o

all: iprincipal usesion csesion servidor cliente
    

iprincipal: ${PRINCIPAL}
	${CC} ${LDFLAGS} -o src/interfaces/gtk-principal ${PRINCIPAL} ${CFLAGS}

usesion: ${UNIRSESION} 
	${CC} ${LDFLAGS} -o src/interfaces/gtk-unir-sesion ${UNIRSESION} ${CFLAGS}

csesion: ${CREARSESION}
	${CC} ${LDFLAGS} -o src/interfaces/gtk-crear-sesion ${CREARSESION} ${CFLAGS} 

servidor: ${FUESERVIDOR}
	${CC} ${FUESERVIDOR} -o src/controlador/server

cliente: ${FUECLIENTE}
	${CC} ${FUECLIENTE} -o src/controlador/cliente






