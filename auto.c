#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "auto.h"

/**
 * \brief Inicializa el array de autos indicando que todas las posiciones del mismo estan vacias (isEmpty=1)
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int inicializarEstructura(Auto* autos, int len) // Pone todas como isEmpty
{
    int retorno = -1; // caso de error
    if(checkAutosYLen(autos, len))
    {
        for(int i = 0; i<len; i++)
        {
            autos[i].isEmpty = 1;
        }
        retorno = 0; // ok
    }
    return retorno;
}


/**
 * \brief Busca el indice que corresponde a un indice disponible
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndiceLibre (Auto* autos, int len)
{
    int retorno = -1; // caso de error
    if(checkAutosYLen(autos, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(autos[i].isEmpty)
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
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id seleccionado por el usuario
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndicePorId (Auto* autos, int len, int idSeleccionado)
{
    int retorno = - 1; // error
    if(checkAutosYLen(autos, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(autos[i].id == idSeleccionado)
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
int checkAutosYLen (Auto* autos, int len)
{
    int retorno;
    if(autos!= NULL && len>0)
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
 * \brief Permite dar de alta un auto
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param indiceLibre Es un indice que se encuentra disponible
 * \param idAuto  Es el id del auto
 * \param patente  Es la patente del auto
 * \param idMarca Es el id de la marca seleccionad
 * \param idColor Es el id del color
 * \param modelo Es el modelo del auto
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int altaEstructura (Auto* autos, int len, int indiceLibre, int idAuto, char* patente, int idMarca, int idColor, int modelo, int idCliente)
{
    int retorno = - 1; // error
    if(checkAutosYLen(autos, len))
    {
        if (indiceLibre>=0 && indiceLibre<len)
        {
            strcpy(autos[indiceLibre].patente, patente);
            autos[indiceLibre].id = idAuto;
            autos[indiceLibre].idMarca = idMarca;
            autos[indiceLibre].idColor = idColor;
            autos[indiceLibre].modelo = modelo;
            autos[indiceLibre].idCliente = idCliente;
            autos[indiceLibre].isEmpty = 0;
            retorno = 0; // alta exitosa
        }
    }
    return retorno; // 0 ok, -1 error
}


/**
 * \brief Pide al usuario que ingrese el id del autos
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id  que selecciona el usuario
 * \return (void)
 *
 */
void pedirId (Auto* autos, int len, int* idSeleccionado)
{
    printf("Ingrese el id deseado: \n");
    scanf("%d", idSeleccionado);
    while(! esIdDeAutoValido(autos, len, *idSeleccionado))
    {
        printf("Id Invalido,reingrese id: \n");
        scanf("%d", idSeleccionado);
    }
}


/**
 * \brief Valida el id del auto
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id seleccionado
 * \return Retorna 0 (NO VALIDO) y 1 (VALIDO)
 *
 */
int esIdDeAutoValido(Auto* autos, int len, int idSeleccionado)
{
    int idValido;
    int index = buscarIndicePorId(autos, len, idSeleccionado);
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
 * \brief Permite modificar el color
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id seleccionado
 * \param idColor Es el color del auto
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int modificarColor (Auto* autos, int len, int idSeleccionado, int idColor)
{
    int retorno = -1; // error
    int indiceAModificar;
    indiceAModificar = buscarIndicePorId (autos, len, idSeleccionado);
    if(checkAutosYLen(autos, len))
    {
        if(indiceAModificar >=0 && indiceAModificar<len)
        {
            autos[indiceAModificar].idColor = idColor;
            retorno = 0;
        }
    }
    return retorno;
}


/**
 * \brief Permite modificar el modelo
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id seleccionado
 * \param modelo Es el modelo del auto
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int modificarModelo (Auto* autos, int len, int idSeleccionado, int modelo)
{
    int retorno = -1; // error
    int indiceAModificar;
    indiceAModificar = buscarIndicePorId (autos, len, idSeleccionado);
    if(checkAutosYLen(autos, len))
    {
        if(indiceAModificar >=0 && indiceAModificar<len)
        {
            autos[indiceAModificar].modelo = modelo;
            retorno = 0;
        }
    }
    return retorno;
}


/**
 * \brief Permite dar de baja un auto dado un id
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id seleccionado
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int bajaEstructura (Auto* autos, int len, int idSeleccionado)
{
    int retorno = - 1; // error
    int indiceBaja;
    indiceBaja = buscarIndicePorId (autos, len, idSeleccionado);
    if(checkAutosYLen(autos, len))
    {
        if(indiceBaja >=0 && indiceBaja<len)
        {
            autos[indiceBaja].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}


/**
 * \brief Muestra los autos cargados
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de colores del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de marcas del array
 * \return Retorna -1 (ERROR) y 0 (OK)
 *
 */
int mostrarEstructura(Auto* autos, int len, Color* colores, int lenColores, Marca* marcas, int lenMarcas,Cliente* clientes, int lenClientes)
{
    int retorno = -1;

    if(checkAutosYLen(autos, len))
    {
        retorno = 0;
        ordernarAutos(autos, len);
        printf("Auto   Patente    Color     Marca    Modelo     Cliente \n");
        printf("--------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                mostrarAuto(autos[i], colores, lenColores, marcas, lenMarcas, clientes, lenClientes);
            }
        }
        printf("\n");
    }
    return retorno;
}


/**
 * \brief Permite ordenar por marca y patente
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \return (void)
 *
 */
void ordernarAutos(Auto* autos, int len)
{
    for(int i = 0; i < len-1; i++)
    {
        for(int j=i+1; j < len; j++)
        {
            if(autos[i].isEmpty)
            {
                Auto aux = autos[i];
                autos[i]=autos[j];
                autos[j]=aux;
            }
            else
            {
                if(autos[j].isEmpty==0)
                {
                    // ninguno esta vacio, los puedo comparar
                    if(autos[i].idMarca > autos[j].idMarca || (autos[i].idMarca == autos[j].idMarca && strcmp(autos[i].patente, autos[j].patente)>0))
                    {
                        Auto aux = autos[i];
                        autos[i]=autos[j];
                        autos[j]=aux;
                    }
                }
            }
        }
    }
}


/**
 * \brief Pide al usuario que ingrese el modelo del auto
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idSeleccionado Es el id  que selecciona el usuario
 * \return (void)
 *
 */
void pedirModelo(int* modelo)
{
    utn_getNumero(modelo, "Ingrese modelo\n", "Numero invalido\n" );
    while(*modelo<1000 || *modelo>9999)
    {
        printf("Error, reingrese modelo\n");
        utn_getNumero(modelo, "Ingrese modelo\n", "Numero invalido\n" );
    }
}


/**
 * \brief Verifica que la patente exista
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente Es la patente del auto
 * \return (void)
 *
 */
int patenteExistente (Auto* autos, int len, char* patente)
{
    int retorno = -1; // error
    if(checkAutosYLen(autos, len))
    {
        retorno = 0;
        for(int i = 0; i<len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(strcmp(autos[i].patente, patente)== 0)
                {
                    retorno = 1;
                    break; // ya existe
                }

            }
        }
    }

    return retorno;
}


/**
 * \brief Lista las patentes del sistema
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \return -1 si hubo error, 0 si no.
 *
 */
int listarPatentes(Auto* autos, int len)
{
    int retorno = -1;
    if(checkAutosYLen(autos, len))
    {
        retorno = 0;
        printf("Las patentes existentes son: \n");
        for(int i = 0; i < len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                printf("%s\n",autos[i].patente);
            }
        }
    }
    return retorno;

}


/**
 * \brief Pide al usuario que ingrese la patente del auto
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente patente del auto a elegir por el usuario
 * \param lenPatente cantidad de caracteres maximo de una patente
 * \return (void)
 *
 */
void pedirPatente(Auto* autos, int len, char* patente, int lenPatente)
{
    listarPatentes(autos, len);
    utn_getPatente(patente, lenPatente, "Ingrese patente\n", "Patente invalida\n");
}


/**
 * \brief Pide al usuario que ingrese el modelo del auto
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente patente del auto a elegir por el usuario
 * \param lenPatente cantidad de caracteres maximo de una patente
 * \return (void)
 *
 */
void pedirPatenteParaAlta(Auto* autos, int len, char* patente, int lenPatente)
{
    utn_getPatente(patente, lenPatente, "Ingrese patente a dar de alta\n", "Patente invalida\n");
    while(patenteExistente (autos, len, patente))
    {
        printf("La patente ya ha sido ingresada\n\n");
        pedirPatente(autos, len, patente, lenPatente);
    }
}


/**
 * \brief Busca el indice que corresponde a la patente seleccionada por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente Es la patente del auto
 * \return Retorna -1 (ERROR) y el indice (i)
 *
 */
int buscarIndicePorPatente (Auto* autos, int len, char* patente)
{
    int retorno = - 1; // error
    if(checkAutosYLen(autos, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(strcmp(autos[i].patente, patente))
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
 * \brief Busca el id que corresponde a la patente seleccionada por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente Es la patente del auto
 * \return Retorna -1 (ERROR) y el id (id)
 *
 */
int buscarIdPorPatente (Auto* autos, int len, char* patente)
{
    int retorno = - 1; // error
    int id;
    if(checkAutosYLen(autos, len))
    {
        for(int i = 0; i<len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(strcmp(autos[i].patente, patente)==0)
                {
                    id = autos[i].id;
                    retorno = id;
                    break;
                }
            }
        }
    }
    return retorno;
}



// DOXYGENNNNN
/**
 * \brief Pide al usuario que ingrese el modelo del auto
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente patente del auto a elegir por el usuario
 * \param lenPatente cantidad de caracteres maximo de una patente
 * \return (void)
 *
 */
void mostrarAuto(Auto unAuto, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes)
{
    int indiceMarca;
    int indiceColor;
    int indiceCliente;
    indiceMarca = buscarIndiceDeMarcaPorId(marcas, lenMarcas, unAuto.idMarca);
    indiceColor = buscarIndicePorIdDeColor(colores, lenColores, unAuto.idColor);
    indiceCliente = buscarIndicePorIdCliente(clientes, lenClientes, unAuto.idCliente);

    printf(" %-4d %-10s %-10s %-10s  %-4d   %s\n", unAuto.id, unAuto.patente, colores[indiceColor].nombreColor, marcas[indiceMarca].descripcion, unAuto.modelo, clientes[indiceCliente].nombre);
}


/**
 * \brief Busca el id que corresponde a la patente seleccionada por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente Es la patente del auto
 * \return Retorna -1 (ERROR) y el id (id)
 *
 */
int listarAutosPorColor(Auto* autos, int len, int idColorDeseado, Color* colores,int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes)
{

    int retorno = -1;
    int hayAutoDeEseColor = 0;
    if(checkAutosYLen(autos, len))
    {
        retorno = 0;
        printf("Auto   Patente    Color     Marca    Modelo     Cliente \n");
        printf("--------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(autos[i].idColor == idColorDeseado)
                {
                    hayAutoDeEseColor=1;
                    mostrarAuto(autos[i], colores, lenColores, marcas, lenMarcas, clientes, lenClientes);
                }

            }
        }
        printf("\n");
    }
    if(hayAutoDeEseColor==0)
    {
        printf("No hay autos del color seleccionado\n\n");
    }
    return retorno;
}


/**
 * \brief Busca el id que corresponde a la patente seleccionada por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente Es la patente del auto
 * \return Retorna -1 (ERROR) y el id (id)
 *
 */
int listarAutosPorMarca(Auto* autos, int len, int idMarcaDeseada, Color* colores,int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes)
{

    int retorno = -1;
    int hayAutoDeEsaMarca = 0;
    if(checkAutosYLen(autos, len))
    {
        retorno = 0;
        printf("Auto   Patente    Color     Marca    Modelo     Cliente \n");
        printf("--------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(autos[i].idMarca == idMarcaDeseada)
                {
                    hayAutoDeEsaMarca=1;
                    mostrarAuto(autos[i], colores, lenColores, marcas, lenMarcas, clientes, lenClientes);
                }
            }
        }
        printf("\n");
        if(hayAutoDeEsaMarca==0)
        {
            printf("No hay autos de la marca\n\n");
        }
    }

    return retorno;
}


/**
 * \brief Busca el id que corresponde a la patente seleccionada por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente Es la patente del auto
 * \return Retorna -1 (ERROR) y el id (id)
 *
 */
int obtenerModeloMasViejo(Auto* autos, int len, int* modelo)
{
    int retorno = -1;
    int older;
    int primerModelo = 1;
    if(checkAutosYLen(autos, len))
    {
        retorno = 0;
        for(int i = 0; i < len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(primerModelo)
                {
                    older = autos[i].modelo;
                    primerModelo =0;
                }
                else
                {
                    if(autos[i].modelo < older)
                    {
                        older = autos[i].modelo;
                    }
                }
            }
        }
        *modelo = older;
    }
    return retorno;
}

/**
 * \brief Busca el id que corresponde a la patente seleccionada por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente Es la patente del auto
 * \return Retorna -1 (ERROR) y el id (id)
 *
 */
int listarAutosPorModelo(Auto* autos, int len, int modeloDeseado, Color* colores,int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes)
{

    int retorno = -1;
    int hayAutosDeEseModelo = 0;
    if(checkAutosYLen(autos, len))
    {
        retorno = 0;
        printf("Auto   Patente    Color     Marca    Modelo     Cliente \n");
        printf("--------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(autos[i].modelo == modeloDeseado)
                {
                    hayAutosDeEseModelo=1;
                    mostrarAuto(autos[i], colores, lenColores, marcas, lenMarcas, clientes, lenClientes);
                }

            }
        }
        printf("\n");
    }
    if(hayAutosDeEseModelo==0)
    {
        printf("No hay autos de el modelo seleccionado\n\n");
    }
    return retorno;
}

/**
 * \brief Pide al usuario que ingrese el modelo del auto
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param patente patente del auto a elegir por el usuario
 * \param lenPatente cantidad de caracteres maximo de una patente
 * \return (void)
 *
 */
void listarAutosMasViejos(Auto* autos, int len, Color* colores,int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes)
{
    int modeloMasViejo;
    obtenerModeloMasViejo(autos, len, &modeloMasViejo);
    listarAutosPorModelo(autos, len, modeloMasViejo, colores, lenColores, marcas, lenMarcas, clientes, lenClientes);
}

/**
 * \brief Permite contar los autos del color y de la marca seleccionados por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idColorDeseado Id de color seleccionado por el usuario
 * \param idMarcaDeseada Id de marca seleccionado por el usuarui
 * \param colores Array de colores
 * \param lenColores Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \return Retorna -1 (ERROR) y el id (id)
 *
 */
int contarColorYMarca(Auto* autos, int len, int idColorDeseado, int idMarcaDeseada, Color* colores,int lenColores, Marca* marcas, int lenMarcas)
{
    int contador = 0;

    if(checkAutosYLen(autos, len))
    {
        for(int i = 0; i < len; i++)
        {
            if(autos[i].isEmpty==0)
            {
                if(autos[i].idColor == idColorDeseado)
                {
                    if(autos[i].idMarca == idMarcaDeseada)
                    {
                        contador++;
                    }

                }
            }

        }
    }
    return contador;
}


/**
 * \brief Busca el id que corresponde a la patente seleccionada por el usuario
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param idMarca Es el id de la marca
 * \return Retorna -1 (ERROR) y el id (id)
 *
 */
int contarAutosPorMarca(Auto* autos, int len, int idMarca)
{
    int contador = 0;
    for(int i = 0; i<len; i++)
    {
        if(autos[i].isEmpty == 0)
        {
            if(autos[i].idMarca == idMarca)
            {
                contador++;
            }
        }
    }

    return contador;
}


/**
 * \brief Busca la cantidad de autos de la marca mas elegida
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \return Retorna la cantidad de autos de la marca mas elegida
 *
 */
int mayorNumeroDeAutosDeUnaMarca(Auto* autos, int len, Marca* marcas, int lenMarcas)
{
    int cantidadAutosMarcaMasElegida = 0;
    int flagPrimeraMarca = 1;
    int autosDeLaMarca;

    for (int i = 0; i<lenMarcas; i++)
    {
        if(marcas[i].isEmpty==0)
        {
            autosDeLaMarca = contarAutosPorMarca(autos, len, marcas[i].id);
            if(flagPrimeraMarca)
            {
                cantidadAutosMarcaMasElegida = autosDeLaMarca;
                flagPrimeraMarca = 0;
            }
            else
            {
                if(cantidadAutosMarcaMasElegida < autosDeLaMarca)
                {
                    cantidadAutosMarcaMasElegida = autosDeLaMarca;
                }
            }
        }
    }

    return cantidadAutosMarcaMasElegida;
}


/**
 * \brief Muestra la marca mas elegida
 * \param autos Array de autos
 * \param len Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \return (void)
 *
 */
void mostrarMarcaMasElegida(Auto* autos, int len, Marca* marcas, int lenMarcas)
{
    int mayorCantidad = mayorNumeroDeAutosDeUnaMarca(autos, len, marcas, lenMarcas);
    int cantidadDeEstaMarca;
    printf("La(s) marca(s) mas elegida(s) son:\n");
    for (int i = 0; i<lenMarcas; i++)
    {
        if(marcas[i].isEmpty == 0)
        {
            cantidadDeEstaMarca = contarAutosPorMarca(autos, len, marcas[i].id);
            if(cantidadDeEstaMarca == mayorCantidad)
            {
                printf("%s\n", marcas[i].descripcion);
            }
        }
    }
}
