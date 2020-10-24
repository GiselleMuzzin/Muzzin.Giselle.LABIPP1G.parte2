#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "color.h"

/**
 * \brief Inicializa los colores con los valores harcodeados
 * \param colores Array de colores
 * \param len Cantidad de elementos del array
 * \return (void)
 *
 */
void inicializarColoresHarcodeados(Color* colores, int len)
{
    strcpy(colores[0].nombreColor, "Negro");
    colores[0].id =  5000;
    colores[0].isEmpty=0;
    strcpy(colores[1].nombreColor, "Blanco");
    colores[1].id =  5001;
    colores[1].isEmpty=0;
    strcpy(colores[2].nombreColor, "Gris");
    colores[2].id =  5002;
    colores[2].isEmpty=0;
    strcpy(colores[3].nombreColor, "Rojo");
    colores[3].id =  5003;
    colores[3].isEmpty=0;
    strcpy(colores[4].nombreColor, "Azul");
    colores[4].id =  5004;
    colores[4].isEmpty=0;
}

/**
 * \brief Pide al usuario que ingrese el color deseado
 * \param colores Array de colores
 * \param len Cantidad de elementos del array
 * \param idColor Es el id del color que selecciona el usuario
 * \return (void)
 *
 */
void pedirColor(Color* colores, int len, int* idColor)
{
    mostrarColor(colores, len);
    utn_getNumero(idColor, "Ingrese el id del color deseado\n", "Numero invalido\n");
    while(!esIdDeColorValido(colores, len, *idColor))
    {
        printf("Id de color invalido. Ingrese el id del color deseado: \n");
    utn_getNumero(idColor, "Ingrese el id del color deseado\n", "Numero invalido\n");
    }
}

/**
 * \brief Valida el id del color
 * \param colores Array de colores
 * \param len Cantidad de elementos del array
 * \param idColor Es el id del color seleccionado por el usuario
 * \return Retorna 0 (id invalido) y 1 (OK)
 *
 */
int esIdDeColorValido(Color* colores, int len, int idColor)
{
    int idValido;
    int index = buscarIndicePorIdDeColor(colores, len, idColor);
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
 * \brief Busca el indice que corresponde al id seleccionado por el usuario
 * \param colores Array de colores
 * \param len Cantidad de elementos del array
 * \param idColor Es el id del color seleccionado por el usuario
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndicePorIdDeColor (Color* colores, int len, int idColor)
{
    int retorno = -1; // error
    if(checkColoresYLen(colores, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(colores[i].isEmpty==0)
            {
                if(colores[i].id == idColor)
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
 * \param colores Array de colores
 * \param len Cantidad de elementos del array
 * \return Retorna 0 (ERROR) y 1 (OK)
 *
 */
int checkColoresYLen (Color* colores, int len)
{

    int retorno = 1;
    if(colores == NULL || len < 0)
    {
       retorno = 0;
    }
    return retorno;
}

/**
 * \brief Muestra los colores disponibles
 * \param colores Array de colores
 * \param len Cantidad de elementos del array
 * \param idColor Es el id del color
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int mostrarColor(Color* colores, int len)
{
    int retorno = -1;
    if(colores!= NULL && len>0)
    {
        retorno = 0;
        printf("   ***COLORES***      \n");
        printf("Id      Descripcion  \n");
        printf("-------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(colores[i].isEmpty==0)
            {
                printf(" %d   %s\n", colores[i].id, colores[i].nombreColor);
            }
        }
        printf("\n");
    }
    return retorno;
}

