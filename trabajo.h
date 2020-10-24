#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "auto.h"
#include "fecha.h"
#include "servicio.h"

typedef struct
{
    char patente[PATENTE_LEN]; // (debe existir) Validar
    int id; // (autoincremental)
    int idServicio; // (debe existir) Validar
    int isEmpty;
    Fecha fechaDeServicio; // ( Validar día, mes y año )

} Trabajo;

int buscarTrabajoLibre(Trabajo* trabajos, int len);
int inicializarTrabajos(Trabajo* trabajos, int len);
int altaTrabajo(Trabajo* trabajos, int len, int indiceTrabajoLibre, char* patente, int idServicio, Fecha fecha, int idTrabajo);
int checkTrabajosYLen (Trabajo* trabajos, int len);
void listarTrabajos(Trabajo* trabajos, int len, Servicio* servicios, int lenServicios);
void mostrarTrabajo(Trabajo trabajo,  Servicio* servicios, int lenServicios);
int listarTrabajosPorPatente(Trabajo* trabajos, int len, char* patente, Servicio* servicios, int lenServicios);
float importeServiciosPorAuto(Trabajo* trabajos, int len, char* patente, Servicio* servicios, int lenServicios);
void mostrarAutoYFechaDeServicio(Trabajo* trabajos, int len, int idServicioSeleccionado);
void mostrarTrabajosEnFecha(Trabajo* trabajos, int len, Fecha fecha, Servicio* servicios, int lenServicios);
#endif // TRABAJO_H_INCLUDED
