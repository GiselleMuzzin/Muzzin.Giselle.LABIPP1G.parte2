#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "utn.h"
#include "color.h"
#include "marca.h"
#include "cliente.h"

#define PATENTE_LEN 8

typedef struct
{
    char patente[PATENTE_LEN];
    int id;
    int idMarca; // Validar
    int idColor; // Validar
    int modelo; // año de fabricación
    int idCliente;
    int isEmpty;
} Auto;

int inicializarEstructura(Auto* autos, int len);
int buscarIndiceLibre (Auto* autos, int len);
int buscarIndicePorId (Auto* autos, int len, int idSeleccionado);
int checkAutosYLen (Auto* autos, int len);
int altaEstructura (Auto* autos, int len, int indiceLibre, int idAuto, char* patente, int idMarca, int idColor, int modelo, int idCliente);
void pedirId (Auto* autos, int len, int* idSeleccionado);
int esIdDeAutoValido(Auto* autos, int len, int idSeleccionado);
int modificarColor (Auto* autos, int len, int idSeleccionado, int idColor);
int modificarModelo (Auto* autos, int len, int idSeleccionado, int modelo);
int bajaEstructura (Auto* autos, int len, int idSeleccionado);
int mostrarEstructura(Auto* autos, int len, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes);
void pedirModelo(int* modelo);
void pedirPatenteParaAlta(Auto* autos, int len, char* patente, int lenPatente);
int patenteExistente (Auto* autos, int len, char* patente);
int buscarIndicePorPatente (Auto* autos, int len, char* patente);
int buscarIdPorPatente (Auto* autos, int len, char* patente);
void pedirPatente(Auto* autos, int len, char* patente, int lenPatente);
void ordernarAutos(Auto* autos, int len);
void mostrarAuto(Auto unAuto, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes);
int listarAutosPorColor(Auto* autos, int len, int idColorDeseado, Color* colores,int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes);
int listarAutosPorMarca(Auto* autos, int len, int idMarcaDeseada, Color* colores,int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes);
int obtenerModeloMasViejo(Auto* autos, int len, int* modelo);
int listarAutosPorModelo(Auto* autos, int len, int modeloDeseado, Color* colores,int lenColores, Marca* marcas, int lenMarcas,Cliente* clientes, int lenClientes);
void listarAutosMasViejos(Auto* autos, int len, Color* colores,int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes);
int contarColorYMarca(Auto* autos, int len, int idColorDeseado, int idMarcaDeseada, Color* colores,int lenColores, Marca* marcas, int lenMarcas);
void mostrarMarcaMasElegida(Auto* autos, int len, Marca* marcas, int lenMarcas);
int mayorNumeroDeAutosDeUnaMarca(Auto* autos, int len, Marca* marcas, int lenMarcas);
int contarAutosPorMarca(Auto* autos, int len, int idMarca);
#endif // AUTO_H_INCLUDED
