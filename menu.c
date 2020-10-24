#include "menu.h"

/**
 * \brief Permite dar de alta un auto
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \param clientes Array de clientes
 * \param lenClientes Cantidad de elementos del array
 * \param clienteDadoDeAlta Es el cliente que se dio de alta
 * \param idAutos Es el id del auto
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void altaAuto(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int* idAutos, int* contadorAutosActivos)
{
    char patente[PATENTE_LEN];
    int modelo;
    int idColor;
    int idMarca;
    int idClientSeleccionado;
    int indiceLibre;

    if(clienteDadoDeAlta==0)
    {
        printf("Debe dar de alta un cliente primero\n");
    }
    else
    {

        indiceLibre = buscarIndiceLibre(autos, lenAutos);
        if(indiceLibre == -1)
        {
            printf("No fue posible realizar el alta\n\n");
        }
        else
        {
            pedirPatenteParaAlta(autos, lenAutos, patente, PATENTE_LEN); // pide patente y verifica q no este cargada
            pedirModelo(&modelo); // pide el modelo y lo valida
            pedirColor(colores, LEN_COLORES, &idColor);
            pedirIdMarca(marcas, lenMarcas, &idMarca); // pide el modelo y lo valida
            pedirIdCliente(clientes, lenClientes, &idClientSeleccionado);
            // guarda los datos en autos[indiceLibre] y setea el isEmpty = 0
            altaEstructura(autos, lenAutos, indiceLibre, *idAutos, patente, idMarca, idColor, modelo, idClientSeleccionado);
            (*idAutos)++;
            (*contadorAutosActivos)++;

        }
    }

}

/**
 * \brief Muestra las opciones del menu para que el usuario seleccione
 * \param void
 * \return Retorna void
 *
 */
void displayOptions()
{
    printf("Ingrese opcion\n");
    printf("1 Alta Auto\n");
    printf("2 Modificar Auto\n");
    printf("3 Baja Auto\n");
    printf("4 Listar Auto\n");
    printf("5 Listar Marcas\n");
    printf("6 Listar Colores\n");
    printf("7 Listar Servicios\n");
    printf("8 Alta trabajo\n");
    printf("9 Listar Trabajos\n");
    printf("10 Informe: Autos por color\n");
    printf("11 Informe: Autos por marca\n");
    printf("12 Informe: Auto mas viejo \n");
    printf("13 Informe: Listar autos por marca\n");
    printf("14 Informe: Cantidad de autos por color y marca\n");
    printf("15 Informe: Marca mas elegida\n");
    printf("16 Informe: Trabajos por auto\n");
    printf("17 Informe: Importe de los servicios realizados\n");
    printf("18 Informe: Servicio por auto y fecha\n");
    printf("19 Informe: Servicios por fecha\n");
    printf("20 Alta clientes\n");
    printf("0 Salir\n");
}

/**
 * \brief Muestra el menu de opciones para que el usuario seleccione
 * \param void
 * \return Retorna la opcion elegida
 *
 */
int showMenu()
{
    int opcion;
    displayOptions();
    scanf("%d", &opcion);
    while(opcion < 0 || opcion > 20)
    {
        printf("Opcion invalida.\n");
        displayOptions();
        scanf("%d", &opcion);
    }
    return opcion;
}
/**
 * \brief Muestra el menu de opciones para que el usuario seleccione la modificacion a realizar
 * \param void
 * \return Retorna la opcion elegida
 *
 */
int showModificationMenu()
{
    int opcion;
    printf("Indique si desea modificar color (1) o modelo (2)\n");
    scanf("%d", &opcion);
    while(opcion != 1 && opcion != 2)
    {
        printf("Opcion invalida. Indique si desea modificar color (1) o modelo (2)\n");
        scanf("%d", &opcion);
    }
    return opcion;
}

/**
 * \brief Permite harcodear trabajos
  int* contadorAutosActivos, int* primerTrabajo, int* clienteDadoDeAlta)
 * \param trabajos Array de trabajos
 * \param lenTrabajos Cantidad de elementos del array
 * \param clientes Array de clientes
 * \param lenClientes Cantidad de elementos del array
  * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
  * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de elementos del array
 * \param servicios Array de servicios
 * \param lenServicio Cantidad de elementos del array
 * \param idCliente Es el id
 * \param idTrabajo Es el id
 * \param idAuto Es el id
 * \param primerTrabajo Bandera primer trabajo
 * \param contadorAutosActivos Es el contador de autos activos
 * \param clienteDadoDeAlta Es el cliente que se dio de alta
 * \return Retorna void
 *
 */
void harcodearTrabajos(Trabajo* trabajos, int lenTrabajos, Cliente* clientes, int lenClientes, Auto* autos, int lenAutos, Marca* marcas, int lenMarcas, Color* colores, int lenColores, Servicio* servicios, int lenServicio, int* idCliente, int* idTrabajo, int* idAuto, int* contadorAutosActivos, int* primerTrabajo, int* clienteDadoDeAlta)
{
    altaClientes(clientes, lenClientes, 0, 1, 'm', "jose");
    altaClientes(clientes, lenClientes, 1, 2, 'm', "pedro");
    altaClientes(clientes, lenClientes, 2, 3, 'f', "rosa");
    altaClientes(clientes, lenClientes, 3, 4, 'f', "laura");
    altaClientes(clientes, lenClientes, 4, 5, 'm', "carlos");
    *clienteDadoDeAlta =1;
    *idCliente = 6;

    altaEstructura(autos, lenAutos, 0, 1, "abc123", marcas[0].id, colores[0].id, 2000, 1);
    altaEstructura(autos, lenAutos, 1, 2, "def123", marcas[1].id, colores[1].id, 2000, 2);
    altaEstructura(autos, lenAutos, 2, 3, "ghi123", marcas[2].id,colores[2].id, 2000, 3);
    altaEstructura(autos, lenAutos, 3, 4, "jkl123",marcas[3].id, colores[3].id, 2000, 4);
    altaEstructura(autos, lenAutos, 4, 5, "mno123", marcas[4].id,colores[4].id, 2005, 5);
    *idAuto = 6;
    *contadorAutosActivos=6;

    Fecha f;
    f.mes = 1;
    f.anio = 2020;
    f.dia = 1;
    altaTrabajo(trabajos, lenTrabajos, 0, "abc123", servicios[0].id, f, 1);
    f.mes = 1;
    f.anio = 2020;
    f.dia = 2;
    altaTrabajo(trabajos, lenTrabajos, 1, "def123", servicios[1].id, f, 2);
    f.mes = 1;
    f.anio = 2020;
    f.dia = 3;
    altaTrabajo(trabajos, lenTrabajos, 2, "ghi123", servicios[2].id, f, 3);
    f.mes = 1;
    f.anio = 2020;
    f.dia = 4;
    altaTrabajo(trabajos, lenTrabajos, 3, "jkl123", servicios[3].id, f, 4);
    *primerTrabajo=1;
    *idTrabajo=5;
}


/**
 * \brief Permite modificar un auto
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \param clientes Array de clientes
 * \param lenClientes Cantidad de elementos del array
 * \param clienteDadoDeAlta Es el cliente que se dio de alta
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void modificarAuto(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int contadorAutosActivos)
{

    char patente[PATENTE_LEN];
    int modelo;
    int idColor;
    int idSeleccionado;
    int optionModification;
    if(contadorAutosActivos>0)
    {
        pedirPatente(autos, lenAutos, patente,PATENTE_LEN );
        idSeleccionado = buscarIdPorPatente(autos, lenAutos, patente);
        if(idSeleccionado!=-1)
        {

            optionModification = showModificationMenu();
            if(optionModification == 1)
            {
                pedirColor(colores, LEN_COLORES, &idColor);
                modificarColor(autos, lenAutos, idSeleccionado, idColor);
            }
            else
            {
                pedirModelo(&modelo);
                modificarModelo(autos, lenAutos, idSeleccionado, modelo);
            }
        }
        else
        {
            printf("La patente ingresada no existe\n\n");
        }
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}

/**
 * \brief Permite dar de baja un auto
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \param clientes Array de clientes
 * \param lenClientes Cantidad de elementos del array
 * \param clienteDadoDeAlta Es el cliente que se dio de alta
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void bajaAuto(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int* contadorAutosActivos)
{
    char patente[PATENTE_LEN];
    int idSeleccionado;

    if(*contadorAutosActivos>0)
    {
        pedirPatente(autos, lenAutos, patente, PATENTE_LEN);
        idSeleccionado = buscarIdPorPatente(autos, lenAutos, patente);
        if(idSeleccionado!=-1)
        {
            bajaEstructura(autos, lenAutos, idSeleccionado);
            (*contadorAutosActivos)--;
        }
        else
        {
            printf("La patente no existe\n\n");

        }
    }
    else
    {
        printf("No hay autos activos\n\n");
    }

}

/**
 * \brief Permite mostrar los autos
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \param clientes Array de clientes
 * \param lenClientes Cantidad de elementos del array
 * \param clienteDadoDeAlta Es el cliente que se dio de alta
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void mostrarAutosLista(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, Cliente* clientes, int lenClientes,  int clienteDadoDeAlta, int contadorAutosActivos)
{
    if(contadorAutosActivos>0)
    {
        mostrarEstructura(autos, lenAutos, colores, lenColores, marcas, lenMarcas, clientes, lenClientes);
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}

/**
 * \brief Permite dar de alta un trabajo
 Servicio* servicios, int lenServicios, int contadorAutosActivos, int* idTrabajo, int* primerTrabajo)
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param trabajos Array de trabajos
 * \param lenTrabajos Cantidad de elementos del array
 * \param servicios Array de servicios
 * \param lenServicios Cantidad de elementos del array
 * \param clientes Array de clientes
 * \param lenClientes Cantidad de elementos del array
 * \param contadorAutosActivos Es el contador de autos activos
 * \param idTrabajo Es el id del trabajo
 * \param primerTrabajo Banderadel primer trabajo
 * \return Retorna void
 *
 */
void altraTrabajoMenu(Auto* autos, int lenAutos, Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos, int* idTrabajo, int* primerTrabajo)
{
    char patente[PATENTE_LEN];
    int idSeleccionado;
    int indiceTrabajoLibre;
    int idServicio;
    Fecha fecha;
    if(contadorAutosActivos>0)
    {
        // ALTA TRABAJO: Se dará de alta pidiéndole al usuario que elija un auto y un Servicio
        indiceTrabajoLibre = buscarTrabajoLibre(trabajos, lenTrabajos);
        if(indiceTrabajoLibre == -1)
        {
            printf("No fue posible realizar el alta\n\n");
        }
        else
        {
            pedirPatente(autos, lenAutos, patente, PATENTE_LEN);
            idSeleccionado = buscarIdPorPatente(autos, lenAutos, patente);
            if(idSeleccionado!=-1)
            {
                pedirServicio(servicios,lenServicios, &idServicio);
                pedirFecha(&fecha);
                altaTrabajo(trabajos, MAX_TRABAJOS, indiceTrabajoLibre, patente,idServicio, fecha, *idTrabajo);
                (*idTrabajo)++;
                (*primerTrabajo) = 1;
            }
            else
            {
                printf("la patente ingresada no existe\n\n");
            }

        }
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}


/**
 * \brief Permite dar de alta un cliente
 * \param clientes Array de clientes
 * \param lenClientes Cantidad de elementos del array
 * \param idCliente Es el id del cliente
 * \param clienteDadoDeAlta Cliente dado de alta
 * \return Retorna void
 *
 */
void altaClienteMenu(Cliente* clientes, int lenClientes, int* idCliente, int* clienteDadoDeAlta)
{
    int indiceLibre;
    char sexo;
    char nombreCliente[NOMBRE_CLIENTE_LEN];
    indiceLibre = buscarIndiceLibreCliente(clientes, lenClientes);
    if(indiceLibre != -1)
    {
        pedirNombre(nombreCliente, NOMBRE_CLIENTE_LEN);
        pedirSexo(&sexo);
        altaClientes(clientes, lenClientes, indiceLibre, *idCliente, sexo, nombreCliente);
        (*clienteDadoDeAlta) = 1;
        idCliente++;
    }
    else
    {
        printf("No hay lugar disponible para mas clientes\n");
    }

}

/**
 * \brief Permite listar los trabajos segun fecha
 * \param trabajos Array de trabajos
 * \param lenTrabajos Cantidad de elementos del array
  * \param servicios Array de servicios
 * \param lenServicios Cantidad de elementos del array
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void listarTrabajosEnFecha(Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos)
{
    Fecha fecha;
    if(contadorAutosActivos>0)
    {
        pedirFecha(&fecha);
        mostrarTrabajosEnFecha(trabajos, MAX_TRABAJOS, fecha, servicios, LEN_SERVICIOS);

    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}

/**
 * \brief Permite listar autos por fecha y servicio
  * \param trabajos Array de trabajos
 * \param lenTrabajos Cantidad de elementos del array
  * \param servicios Array de servicios
 * \param lenServicios Cantidad de elementos del array
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void listarAutoYFechaPorServicio(Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos)
{
    int idServicio;
    if(contadorAutosActivos>0)
    {
        pedirServicio(servicios, lenServicios,&idServicio);
        mostrarAutoYFechaDeServicio(trabajos, lenTrabajos, idServicio);
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}

/**
 * \brief Permite mortrar el importe
  * \param trabajos Array de trabajos
 * \param lenTrabajos Cantidad de elementos del array
  * \param servicios Array de servicios
 * \param lenServicios Cantidad de elementos del array
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void mostrarImportePorAuto(Auto* autos, int lenAutos, Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos)
{
    char patente[PATENTE_LEN];
    float importePorPatente;
    if(contadorAutosActivos>0)
    {
        pedirPatente(autos, lenAutos, patente, PATENTE_LEN);
        importePorPatente = importeServiciosPorAuto(trabajos, lenTrabajos, patente, servicios, lenServicios);

        if(importePorPatente==0)
        {
            printf("No hubo trabajos para ese auto\n\n");
        }
        else
        {
            printf("El importe de los servicios realizados al auto seleccionado es $%.2f\n\n", importePorPatente);
        }
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}

/**
 * \brief Permite mostrar los trabajos por patente
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param trabajos Array de trabajos
 * \param lenTrabajos Cantidad de elementos del array
  * \param servicios Array de servicios
 * \param lenServicios Cantidad de elementos del array
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void mostrarTrabajosPorPatente(Auto* autos, int lenAutos, Trabajo* trabajos, int lenTrabajos, Servicio* servicios, int lenServicios, int contadorAutosActivos)
{
    char patente[PATENTE_LEN];
    if(contadorAutosActivos>0)
    {
        pedirPatente(autos, lenAutos, patente, PATENTE_LEN);
        listarTrabajosPorPatente(trabajos, lenTrabajos, patente, servicios, lenServicios);
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}

/**
 * \brief Permite listar la marca mas elegida
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void listarMarcasMasElegida(Auto* autos, int lenAutos, Marca* marcas, int lenMarcas, int contadorAutosActivos)
{

    if(contadorAutosActivos>0)
    {
        mostrarMarcaMasElegida(autos, lenAutos, marcas, lenMarcas);
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}

/**
 * \brief Permite listar por color y marca
 * \param autos Array de autos
 * \param lenAutos Cantidad de elementos del array
 * \param colores Array de colores
 * \param lenColores Cantidad de elementos del array
 * \param marcas Array de marcas
 * \param lenMarcas Cantidad de elementos del array
 * \param contadorAutosActivos Es el contador de autos activos
 * \return Retorna void
 *
 */
void listAutosPorColorYMarca(Auto* autos, int lenAutos, Color* colores, int lenColores, Marca* marcas, int lenMarcas, int contadorAutosActivos)
{
    int idColor;
    int idMarca;
    int contadorColorYMarca;
    int indiceColor;
    int indiceMarca;

    if(contadorAutosActivos>0)
    {

        pedirColor(colores,lenColores, &idColor);
        pedirIdMarca(marcas, lenMarcas, &idMarca);
        contadorColorYMarca = contarColorYMarca(autos, lenAutos, idColor, idMarca, colores, lenColores, marcas, lenMarcas);
        if(contadorColorYMarca==0)
        {
            printf("No hay autos de ese color/marca\n\n");
        }
        else
        {
            indiceColor = buscarIndicePorIdDeColor(colores, lenColores, idColor);
            indiceMarca = buscarIndiceDeMarcaPorId(marcas, lenMarcas, idMarca);
            printf("Hay %d auto de color %s y la marca %s\n\n", contadorColorYMarca, colores[indiceColor].nombreColor, marcas[indiceMarca].descripcion);
        }
    }
    else
    {
        printf("No hay autos activos\n\n");
    }
}
