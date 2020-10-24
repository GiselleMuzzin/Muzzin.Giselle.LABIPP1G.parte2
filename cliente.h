#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define NOMBRE_CLIENTE_LEN 50

typedef struct
{
    char nombre[NOMBRE_CLIENTE_LEN];
    int id;
    char sexo; // Validar 'f' o 'm'
    int isEmpty;
} Cliente;

int inicializarClientes(Cliente* clientes, int len);
int buscarIndiceLibreCliente (Cliente* clientes, int len);
int buscarIndicePorIdCliente (Cliente* clientes, int len, int idSeleccionado);
int checkClientesYLen (Cliente* clientes, int len);
int altaClientes (Cliente* clientes, int len, int indiceLibre, int idCliente, char sexo, char* nombre);
void pedirIdCliente (Cliente* clientes, int len, int* idSeleccionado);
int esIdDeClienteValido(Cliente* clientes, int len, int idSeleccionado);
void pedirSexo(char* sexo);
void pedirNombre(char* nombre, int lenNombre);
int mostrarClientes(Cliente* clientes, int len);
void mostrarCliente(Cliente unCliente);

#endif // CLIENTE_H_INCLUDED
