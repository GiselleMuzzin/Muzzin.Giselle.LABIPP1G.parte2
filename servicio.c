#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"

/**
 * \brief Inicializa los servicios con los valores harcodeados
 * \param servicios Array de servicios
 * \param len Cantidad de elementos del array
 * \return (void)
 *
 */
void inicializarServiciosHarcodeados(Servicio* servicios, int len)
{
    // Lavados (Lavado: $250, Pulido: $300, Encerado: $400, Completo: $600)
    strcpy(servicios[0].descripcion,"Lavado  ");
    servicios[0].id =  20000;
    servicios[0].precio =  250;
    servicios[0].isEmpty=0;
    strcpy(servicios[1].descripcion,"Pulido  ");
    servicios[1].id =  20001;
    servicios[1].precio =  300;
    servicios[1].isEmpty=0;
    strcpy(servicios[2].descripcion,"Encerado");
    servicios[2].id =  20002;
    servicios[2].precio =  400;
    servicios[2].isEmpty=0;
    strcpy(servicios[3].descripcion,"Completo");
    servicios[3].id =  20003;
    servicios[3].precio =  600;
    servicios[3].isEmpty=0;
}

/**
 * \brief Pide al usuario que ingrese el servicio deseado
 * \param servicios Array de servicios
 * \param len Cantidad de elementos del array
 * \param idServicio Es el id del servicio que selecciona el usuario
 * \return (void)
 *
 */
void pedirServicio(Servicio* servicios, int len, int* idServicio)
{
    mostrarServicio(servicios, len);
    utn_getNumero(idServicio, "Ingrese el id de servicio\n", "No es un numero valido\n");
    while(! esIdDeServicioValido(servicios, len, *idServicio))
    {
        printf("Id Invalido. Ingrese el id de servicio: \n");
        utn_getNumero(idServicio, "Ingrese el id de servicio\n", "No es un numero valido\n");
    }
}

/**
 * \brief Valida el id del servicio
 * \param servicios Array de servicios
 * \param len Cantidad de elementos del array
 * \param idServicio Es el id del servicio seleccionado por el usuario
 * \return Retorna 0 (id invalido) y 1 (OK)
 *
 */
int esIdDeServicioValido(Servicio* servicios, int len, int idServicio)
{
    int idValido;
    int index = buscarIndiceDeServicioPorId(servicios, len, idServicio);
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
 * \param servicios Array de servicios
 * \param len Cantidad de elementos del array
 * \param idServicio Es el id del servicio seleccionado por el usuario
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndiceDeServicioPorId (Servicio* servicios, int len, int idServicio)
{
    int retorno = - 1; // error
    if(servicios!= NULL && len>0)
    {
        for(int i = 0; i<len; i++)
        {
            if(servicios[i].id == idServicio)
            {
                retorno = i;
                break;
            }

        }
    }
    return retorno;
}

/**
 * \brief Muestra los servicios disponibles
 * \param servicios Array de servicios
 * \param len Cantidad de elementos del array
 * \param idServicio Es el id del servicio
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int mostrarServicio(Servicio* servicios, int len)
{
    int retorno = -1;
    if(servicios!= NULL && len>0)
    {
        retorno = 0;
        printf("     ***SERVICIOS***      \n");
        printf("Id         Descripcion   Precio\n");
        printf("--------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(servicios[i].isEmpty==0)
            {
                printf("%d      %s      $%.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
            }
        }
        printf("\n");
    }
    return retorno;
}
