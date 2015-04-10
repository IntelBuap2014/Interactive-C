CC=gcc
CFLAGS=pkg-config --libs gtk+-3.0
LDFLAGS=pkg-config --cflags gtk+-3.0
SOURCES=*.c
OBJECTS=*.o

all: 
interfaz1
    
interfaz1: $(OBJECTS) 
    $(CC) $(LDFLAGS) -o gtk-unir-sesion gtk-unir-sesion.c $(CFLAGS)
