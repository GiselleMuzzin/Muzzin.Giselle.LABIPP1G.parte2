#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"

/**
 * \brief Busca el indice que corresponde a un trabajo disponible
 * \param trabajos Array de trabajos
 * \param len Cantidad de elementos del array
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarTrabajoLibre(Trabajo* trabajos, int len)
{
    int retorno = -1; // caso de error
    if(checkTrabajosYLen(trabajos, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(trabajos[i].isEmpty)
            {
                retorno = i;
                break; // como encontre uno vacio, salgo
            }
        }
    }
    return retorno; // devuelvo -1 p error, el i si encontre libre
}

/**
 * \brief Inicializa el array de trabajos indicando que todas las posiciones del mismo estan vacias (isEmpty=1)
 * \param trabajos Array de trabajos
 * \param len Cantidad de elementos del array
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int inicializarTrabajos(Trabajo* trabajos, int len)
{
    int retorno = -1; // caso de error
    if(checkTrabajosYLen(trabajos, len))
    {
        for(int i = 0; i<len; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        retorno = 0; // ok
    }
    return retorno;
}

/**
 * \brief Valida que el array no sea NULL y que el tamaño sea mayor a 0
 * \param trabajos Array de trabajos
 * \param len Cantidad de elementos del array
 * \return Retorna 0 (ERROR) y 1 (OK)
 *
 */
int checkTrabajosYLen (Trabajo* trabajos, int len)
{
    int retorno;
    if(trabajos!= NULL && len>0)
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
 * \brief Permite dar de alta un trabajo
 * \param trabajos Array de trabajos
 * \param len Cantidad de elementos del array
 * \param indiceTrabajoLibre Es un indice de trabajo que se encuentra disponible
 * \param patente  Es la patente del objeto sobre el cual se realizara el servicio
 * \param idServicio Es el id del servicio seleccionado
 * \param fecha Es la fecha en la que se hara el trabajo
 * \param idTrabajo Es el id del trabajo
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int altaTrabajo(Trabajo* trabajos, int len, int indiceTrabajoLibre, char* patente, int idServicio, Fecha fecha, int idTrabajo)
{
    int retorno = - 1; // error
    if(checkTrabajosYLen(trabajos, len))
    {
        if (indiceTrabajoLibre>=0 && indiceTrabajoLibre<len)
        {
            strcpy(trabajos[indiceTrabajoLibre].patente, patente);
            trabajos[indiceTrabajoLibre].id = idTrabajo;
            trabajos[indiceTrabajoLibre].fechaDeServicio = fecha;
            trabajos[indiceTrabajoLibre].idServicio = idServicio;
            trabajos[indiceTrabajoLibre].isEmpty = 0;
            retorno = 0; // alta exitosa
        }
    }
    return retorno; // 0 ok, -1 error
}



/**
 * \brief Permite listar los trabajos
 * \param trabajos Array de trabajos
 * \param len Cantidad de elementos del array
 * \return void
 *
 */
void listarTrabajos(Trabajo* trabajos, int len, Servicio* servicios, int lenServicios)
{
    printf("Trabajo    Auto      Servicio    Fecha\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < len; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            mostrarTrabajo(trabajos[i], servicios, lenServicios);
        }
    }
    printf("\n");
}

void mostrarTrabajo(Trabajo trabajo,  Servicio* servicios, int lenServicios)
{
    int indiceServicios;
    indiceServicios = buscarIndiceDeServicioPorId(servicios, lenServicios, trabajo.idServicio);
    printf("%-10d %-10s %-10s %d/%d/%d\n", trabajo.id, trabajo.patente, servicios[indiceServicios].descripcion, trabajo.fechaDeServicio.dia, trabajo.fechaDeServicio.mes, trabajo.fechaDeServicio.anio);
}

int listarTrabajosPorPatente(Trabajo* trabajos, int len, char* patente, Servicio* servicios, int lenServicios)
{
    int retorno = -1;
    int hayTrabajosDeEseAuto = 0;
    if(checkTrabajosYLen(trabajos, len))
    {
        retorno = 0;
        printf("Trabajo    Auto      Servicio    Fecha\n");
        printf("----------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(trabajos[i].isEmpty==0)
            {
                if(strcmp(trabajos[i].patente,patente)==0)
                {
                    hayTrabajosDeEseAuto=1;
                    mostrarTrabajo(trabajos[i], servicios, lenServicios);
                }
            }
        }
        printf("\n");
        if(hayTrabajosDeEseAuto==0)
        {
            printf("No hay trabajos para ese auto\n\n");
        }
    }

    return retorno;
}

float importeServiciosPorAuto(Trabajo* trabajos, int len, char* patente, Servicio* servicios, int lenServicios)
{
    float acumuladorImporte = 0;
    int indiceServicio;
    for(int i = 0; i < len; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            if(strcmp(trabajos[i].patente,patente)==0)
            {
                indiceServicio = buscarIndiceDeServicioPorId(servicios, lenServicios, trabajos[i].idServicio);
                acumuladorImporte+=servicios[indiceServicio].precio;
            }

        }
    }

    return acumuladorImporte;

}

void mostrarAutoYFechaDeServicio(Trabajo* trabajos, int len, int idServicioSeleccionado)
{
    int flagServicio = 0;
    printf("Auto      Fecha\n");
    printf("-------------------\n");
    for(int i =0; i<len; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            if(trabajos[i].idServicio == idServicioSeleccionado)
            {
                printf("%s    %d/%d/%d\n", trabajos[i].patente, trabajos[i].fechaDeServicio.dia, trabajos[i].fechaDeServicio.mes, trabajos[i].fechaDeServicio.anio);
                flagServicio=1;
            }
        }
    }
    printf("\n");
    if(flagServicio==0)
    {
        printf("No hay autos a los que se le haya realizado el servicio seleccionado\n\n");
    }
}

void mostrarTrabajosEnFecha(Trabajo* trabajos, int len, Fecha fecha, Servicio* servicios, int lenServicios)
{
    int flagFecha = 0;
    printf("Trabajo    Auto      Servicio    Fecha\n");
    printf("----------------------------------------\n");
    for(int i =0; i<len; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            if(sonMismaFecha(fecha, trabajos[i].fechaDeServicio))
            {
                mostrarTrabajo(trabajos[i], servicios, lenServicios);
                // si solo queremos mostrar el servicio:
                // indiceServicio = buscarIndiceDeServicioPorId(servicios, lenServicios, trabajos[i].idServicio);
                // printf("Servicio %s\n", servicios[indiceServicio].descripcion);
                flagFecha=1;
            }
        }
    }
    printf("\n");
    if(flagFecha==0)
    {
        printf("No hubo servicios en la fecha seleccionada\n\n");
    }
}
