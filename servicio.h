#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#include "utn.h"

#define MAX_DESCRIPCIONSERVICIO 25

typedef struct
{
    int id; //(comienza en 20000)
    int isEmpty;
    char descripcion[MAX_DESCRIPCIONSERVICIO]; // (máximo 25 caracteres)
    float precio;
} Servicio;

void inicializarServiciosHarcodeados(Servicio* servicios, int len);
void pedirServicio(Servicio* servicios, int len, int* idServicio);
int esIdDeServicioValido(Servicio* servicios, int len, int idServicio);
int buscarIndiceDeServicioPorId (Servicio* servicios, int len, int idServicio);
int mostrarServicio(Servicio* servicios, int len);

#endif // SERVICIO_H_INCLUDED
