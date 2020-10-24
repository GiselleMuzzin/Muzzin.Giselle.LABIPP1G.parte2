#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "cliente.h"
#include "utn.h"

/**
 * \brief Inicializa el array de clientes indicando que todas las posiciones del mismo estan vacias (isEmpty=1)
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int inicializarClientes(Cliente* clientes, int len) // Pone todas como isEmpty
{
    int retorno = -1; // caso de error
    if(checkClientesYLen(clientes, len))
    {
        for(int i = 0; i<len; i++)
        {
            clientes[i].isEmpty = 1;
        }
        retorno = 0; // ok
    }
    return retorno;
}


/**
 * \brief Busca el indice que corresponde a un indice disponible
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndiceLibreCliente (Cliente* clientes, int len)
{
    int retorno = -1; // caso de error
    if(checkClientesYLen(clientes, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(clientes[i].isEmpty)
            {
                retorno = i;
                break; // como encontre uno vacio, salgo
            }
        }
    }
    return retorno; // devuelvo -1 p error, el i si encontre libre
}


/**
 * \brief Busca el indice que corresponde al id seleccionado por el usuario
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id seleccionado por el usuario
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndicePorIdCliente (Cliente* clientes, int len, int idSeleccionado)
{
    int retorno = - 1; // error
    if(checkClientesYLen(clientes, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(clientes[i].isEmpty==0)
            {
                if(clientes[i].id == idSeleccionado)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}


/**
 * \brief Valida que el array no sea NULL y que el tamaño sea mayor a 0
 * \param objetos Array de objetos
 * \param len Cantidad de elementos del array
 * \return Retorna 0 (ERROR) y 1 (OK)
 *
 */
int checkClientesYLen (Cliente* clientes, int len)
{
    int retorno;
    if(clientes!= NULL && len>0)
    {
        retorno = 1; // ok p continuar
    }
    else
    {
        retorno = 0; // error
    }
    return retorno;
}


/**
 * \brief Permite dar de alta un cliente
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \param indiceLibre Es un indice que se encuentra disponible
 * \param idCliente  Es el id del cliente
 * \param nombre es el nombre del cliente
 * \param sexo es el sexo m o f del cliente
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int altaClientes (Cliente* clientes, int len, int indiceLibre, int idCliente, char sexo, char* nombre)
{
    int retorno = - 1; // error
    if(checkClientesYLen(clientes, len))
    {
        if (indiceLibre>=0 && indiceLibre<len)
        {
            strcpy(clientes[indiceLibre].nombre, nombre);
            clientes[indiceLibre].id = idCliente;
            clientes[indiceLibre].sexo = sexo;
            clientes[indiceLibre].isEmpty = 0;
            retorno = 0; // alta exitosa
        }
    }
    return retorno; // 0 ok, -1 error
}


/**
 * \brief Pide al usuario que ingrese el id del clientes
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id  que selecciona el usuario
 * \return (void)
 *
 */
void pedirIdCliente (Cliente* clientes, int len, int* idSeleccionado)
{

    printf("Ingrese el id deseado: \n");
    mostrarClientes(clientes, len);
    scanf("%d", idSeleccionado);
    while(! esIdDeClienteValido(clientes, len, *idSeleccionado))
    {
        printf("Id Invalido,reingrese id: \n");
        scanf("%d", idSeleccionado);
    }
}


/**
 * \brief Valida el id del cliente
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id seleccionado
 * \return Retorna 0 (NO VALIDO) y 1 (VALIDO)
 *
 */
int esIdDeClienteValido(Cliente* clientes, int len, int idSeleccionado)
{
    int idValido;
    int index = buscarIndicePorIdCliente(clientes, len, idSeleccionado);
    if(index == -1)
    {
        idValido = 0; // id no valido
    }
    else
    {
        idValido = 1;
    }
    return idValido;
}


/**
 * \brief Muestra los clientes cargados
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de colores del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de marcas del array
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int mostrarClientes(Cliente* clientes, int len)
{
    int retorno = -1;

    if(checkClientesYLen(clientes, len))
    {
        retorno = 0;
        for(int i = 0; i < len; i++)
        {
            if(clientes[i].isEmpty==0)
            {
                mostrarCliente(clientes[i]);
            }
        }
    }
    return retorno;
}


/**
 * \brief Pide al usuario que ingrese el sexo del cliente
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \param sexo char indicando m o f
 * \return (void)
 *
 */
void pedirSexo(char* sexo)
{
    printf("Ingrese sexo: m o f\n");
    __fpurge(stdin); // Linux
    *sexo = getchar();
    while(*sexo!= 'f' && *sexo != 'm')
    {
        printf("Sexo ingresado invalido. Ingrese sexo: m o f\n");
        __fpurge(stdin); // Linux
        *sexo = getchar();
    }
}


/**
 * \brief Pide al usuario que ingrese el nombre del cliente
 * \param clientes Array de clientes
 * \param len Cantidad de elementos del array
 * \param nombre
 * \return (void)
 */
void pedirNombre(char* nombre, int nombreLen)
{
    utn_getNombre(nombre, nombreLen, "Ingrese nombre de cliente\n", "Nombre incorrecto\n");
}


/**
 * \brief Permite mostrar un cliente
 * \param unCliente Un cliente
 * \return (void)
 */
void mostrarCliente(Cliente unCliente)
{
    printf("Cliente %d nombre: %s, Sexo: %c\n", unCliente.id, unCliente.nombre, unCliente.sexo);
}


