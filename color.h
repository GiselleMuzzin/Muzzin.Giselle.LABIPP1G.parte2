#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include "utn.h"

#define MAX_COLOR 20

typedef struct
{
    char nombreColor[MAX_COLOR]; // (máx 20 caracteres)
    int id; // (comienza en 5000)
    int isEmpty;
}Color;

void inicializarColoresHarcodeados(Color* colores, int len);
void pedirColor(Color* colores, int len, int* idColor);
int esIdDeColorValido(Color* colores, int len, int idColor);
int buscarIndicePorIdDeColor (Color* colores, int len, int idColor);
int mostrarColor(Color* colores, int len);
int checkColoresYLen (Color* colores, int len);


#endif // COLOR_H_INCLUDED
