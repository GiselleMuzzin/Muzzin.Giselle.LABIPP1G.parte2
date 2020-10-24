#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

#include "utn.h"

#define MAX_DESCRIPCIONMARCA 20

typedef struct
{
    int id; // (comienza en 1000)
    int isEmpty;
    char descripcion[MAX_DESCRIPCIONMARCA]; // (máx 20 caracteres)
} Marca;

void inicializarMarcasHarcodeadas(Marca* marcas, int len);
void pedirIdMarca (Marca* marcas, int len, int* idMarca);
int esIdDeMarcaValido(Marca* marcas, int len, int idMarca);
int buscarIndiceDeMarcaPorId (Marca* marcas, int len, int idMarca);
int checkMarcasYLen (Marca* marcas, int len);
int mostrarMarca(Marca* marcas, int len);

#endif // MARCA_H_INCLUDED
