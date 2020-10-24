#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "auto.h"
#include "color.h"
#include "fecha.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

#define MAX_AUTOS 100
#define MAX_TRABAJOS 100
#define LEN_MARCAS 5
#define LEN_COLORES 5
#define LEN_SERVICIOS 4
#define MAX_CLIENTES 100

int showMenu();
int showModificationMenu();
void harcodearTrabajos(Trabajo* trabajos, int lenTrabajos, Cliente* clientes, int lenClientes, Auto* autos, int lenAutos, Marca* marcas, int lenMarcas, Color* colores, int lenColores, Servicio* servicios, int lenServicio, int* idCliente, int* idTrabajo, int* idAuto, int* contadorAutosActivos, int* primerTrabajo, int* clienteDadoDeAlta);
void altaAuto(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int* idAutos, int* contadorAutosActivos);
void modificarAuto(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int contadorAutosActivos);
void bajaAuto(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int* contadorAutosActivos);
void altraTrabajoMenu(Auto* autos, int lenAutos, Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos, int* idTrabajo, int* primerTrabajo);
void mostrarAutosLista(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int contadorAutosActivos);
void altaClienteMenu(Cliente* clientes, int lenClientes, int* idCliente, int* clienteDadoDeAlta);


void listarTrabajosEnFecha(Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos);
void listarAutoYFechaPorServicio(Trabajo* trabajos, int lenTrabajos, Servicio* Servicios, int lenServicios, int contadorAutosActivos);
void mostrarImportePorAuto(Auto* autos, int lenAutos, Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos);
void mostrarTrabajosPorPatente(Auto* autos, int lenAutos, Trabajo* trabajos, int lenTrabajos, Servicio* Servicios, int lenServicios, int contadorAutosActivos);
void listarMarcasMasElegida(Auto* autos, int lenAutos, Marca* marcas, int lenMarcas, int contadorAutosActivos);
void listAutosPorColorYMarca(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, int contadorAutosActivos);
#endif // MENU_H_INCLUDED
