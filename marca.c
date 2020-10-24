#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"

/**
 * \brief Inicializa las marcas con los valores harcodeados
 * \param marcas Array de marcas
 * \param len Cantidad de elementos del array
 * \return (void)
 *
 */
void inicializarMarcasHarcodeadas(Marca* marcas, int len)
{
    strcpy(marcas[0].descripcion,"Renault");
    marcas[0].id =  1000;
    marcas[0].isEmpty=0;
    strcpy(marcas[1].descripcion,"Fiat");
    marcas[1].id =  1001;
    marcas[1].isEmpty=0;
    strcpy(marcas[2].descripcion,"Ford");
    marcas[2].id =  1002;
    marcas[2].isEmpty=0;
    strcpy(marcas[3].descripcion,"Chevrolet");
    marcas[3].id =  1003;
    marcas[3].isEmpty=0;
    strcpy(marcas[4].descripcion,"Peugeot");
    marcas[4].id =  1004;
    marcas[4].isEmpty=0;
}


/**
 * \brief Pide al usuario que ingrese la marca deseada
 * \param marcas Array de marcas
 * \param len Cantidad de elementos del array
 * \param idMarca Es el id de la marca que selecciona el usuario
 * \return (void)
 *
 */
void pedirIdMarca (Marca* marcas, int len, int* idMarca)
{
    mostrarMarca(marcas, len);
    utn_getNumero(idMarca, "Ingrese el id de la marca\n", "No es un numero valido. Reingrese\n");
    while(! esIdDeMarcaValido(marcas, len, *idMarca))
    {
        printf("Id Invalido. Ingrese el id de marca: \n");
        utn_getNumero(idMarca, "Ingrese el id de la marca\n", "No es un numero valido. Reingrese\n");
    }
}


/**
 * \brief Valida el id de la marca
 * \param colores Array de colores
 * \param len Cantidad de elementos del array
 * \param idMarca Es el id de la marca seleccionada por el usuario
 * \return Retorna 0 (id invalido) y 1 (OK)
 *
 */
int esIdDeMarcaValido(Marca* marcas, int len, int idMarca)
{
    int idValido;
    int index = buscarIndiceDeMarcaPorId(marcas, len, idMarca);
    if(index == -1)  // no esta
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
 * \brief Busca el indice que corresponde al id seleccionado por el usuario
 * \param marcas Array de marcas
 * \param len Cantidad de elementos del array
 * \param idMarca Es el id de la marca seleccionada por el usuario
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndiceDeMarcaPorId (Marca* marcas, int len, int idMarca)
{
    int retorno = - 1; // error
    if(checkMarcasYLen(marcas, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(marcas[i].isEmpty==0)
            {
                if(marcas[i].id == idMarca)
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
 * \param marcas Array de marcas
 * \param len Cantidad de elementos del array
 * \return Retorna 0 (ERROR) y 1 (OK)
 *
 */
int checkMarcasYLen (Marca* marcas, int len)
{
    int retorno;
    if(marcas != NULL && len > 0)
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
 * \brief Muestra las marcas disponibles
 * \param marcas Array de marcas
 * \param len Cantidad de elementos del array
 * \param idMarca Es el id de la marca
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int mostrarMarca(Marca* marcas, int len)
{
    int retorno = -1;
    if(checkMarcasYLen(marcas, len))
    {
        retorno = 0;
        printf("   ***MARCA***      \n");
        printf("Id      Descripcion  \n");
        printf("-------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(marcas[i].isEmpty==0)
            {
                printf(" %d   %s\n", marcas[i].id, marcas[i].descripcion);
            }
        }
        printf("\n");
    }
    return retorno;
}
