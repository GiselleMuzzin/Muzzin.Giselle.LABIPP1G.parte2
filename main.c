#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "auto.h"
#include "color.h"
#include "fecha.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"


int main()
{
    int option;
    int contadorAutosActivos = 0;
    int idAutos = 1;
    int idTrabajo = 1;
    int idMarca;
    int idColor;
    int primerTrabajo= 0;
    int clienteDadoDeAlta = 0;
    int idCliente=1;


    Auto autos[MAX_AUTOS];
    Trabajo trabajos[MAX_TRABAJOS];
    Marca marcas[LEN_MARCAS];
    Color colores[LEN_COLORES];
    Servicio servicios[LEN_SERVICIOS];
    Cliente clientes[MAX_CLIENTES];

    inicializarEstructura(autos, MAX_AUTOS);
    inicializarTrabajos(trabajos, MAX_TRABAJOS);
    inicializarMarcasHarcodeadas(marcas, LEN_MARCAS);
    inicializarColoresHarcodeados(colores, LEN_COLORES);
    inicializarServiciosHarcodeados(servicios, LEN_SERVICIOS);
    inicializarClientes(clientes, MAX_CLIENTES);

    harcodearTrabajos(trabajos, MAX_TRABAJOS, clientes, MAX_CLIENTES, autos, MAX_AUTOS, marcas, LEN_MARCAS, colores, LEN_COLORES, servicios, LEN_SERVICIOS, &idCliente, &idTrabajo, &idAutos, &contadorAutosActivos, &primerTrabajo, &clienteDadoDeAlta);


    option = showMenu();
    while(option != 0)
    {
        switch(option)
        {
        case 1: // alta
            altaAuto(autos, MAX_AUTOS, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES, clienteDadoDeAlta, &idAutos, &contadorAutosActivos);
            break;
        case 2: // modificar
            modificarAuto(autos, MAX_AUTOS, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES, clienteDadoDeAlta,contadorAutosActivos);
            break;
        case 3: //baja
            bajaAuto(autos, MAX_AUTOS, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES, clienteDadoDeAlta,&contadorAutosActivos);
            break;
        case 4: // listar - ordenar
            mostrarAutosLista(autos, MAX_AUTOS, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES, clienteDadoDeAlta,contadorAutosActivos);
            break;
        case 5: // listar marcas
            mostrarMarca(marcas, LEN_MARCAS);
            break;
        case 6: // listar colores
            mostrarColor(colores, LEN_COLORES);
            break;
        case 7: // listar servicios
            mostrarServicio(servicios, LEN_SERVICIOS);
            break;
        case 8: // alta trabajo
            altraTrabajoMenu(autos, MAX_AUTOS, trabajos, MAX_TRABAJOS, servicios, LEN_SERVICIOS, contadorAutosActivos, &idTrabajo, &primerTrabajo);
            break;
        case 9: // lista trabajos
            if(primerTrabajo==0)
            {
                printf("No hay trabajos para listar\n\n");
            }
            else
            {
                listarTrabajos(trabajos, MAX_TRABAJOS, servicios, LEN_SERVICIOS);
            }
            break;
        case 10:
            if(contadorAutosActivos>0)
            {
                pedirColor(colores,LEN_COLORES, &idColor);
                listarAutosPorColor(autos, MAX_AUTOS, idColor, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES);
            }
            else
            {
                printf("No hay autos activos\n\n");
            }
            break;
        case 11:
            if(contadorAutosActivos>0)
            {
                pedirIdMarca(marcas, LEN_MARCAS, &idMarca);
                listarAutosPorMarca(autos, MAX_AUTOS, idMarca, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES);
            }
            else
            {
                printf("No hay autos activos\n\n");
            }
            break;
        case 12:
            if(contadorAutosActivos>0)
            {
                listarAutosMasViejos(autos, MAX_AUTOS, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES);
            }
            else
            {
                printf("No hay autos activos\n\n");
            }
            break;
        case 13:
            if(contadorAutosActivos>0)
            {
                for(int i = 0; i < LEN_MARCAS; i++)
                {
                    idMarca = marcas[i].id;
                    printf("Autos de la marca %s: \n\n", marcas[i].descripcion);
                    listarAutosPorMarca(autos, MAX_AUTOS, idMarca, colores, LEN_COLORES, marcas, LEN_MARCAS, clientes, MAX_CLIENTES);
                }
            }
            else
            {
                printf("No hay autos activos\n\n");
            }
            break;
        case 14:
            listAutosPorColorYMarca(autos, MAX_AUTOS, colores, LEN_COLORES, marcas, LEN_MARCAS, contadorAutosActivos);
            break;
        case 15:
            listarMarcasMasElegida(autos, MAX_AUTOS, marcas, LEN_MARCAS, contadorAutosActivos);

            break;
        case 16:
            mostrarTrabajosPorPatente(autos, MAX_AUTOS, trabajos, MAX_TRABAJOS, servicios, LEN_SERVICIOS, contadorAutosActivos);

            break;
        case 17:
            mostrarImportePorAuto(autos, MAX_AUTOS,  trabajos, MAX_TRABAJOS, servicios, LEN_SERVICIOS, contadorAutosActivos);
            break;
        case 18:
            listarAutoYFechaPorServicio(trabajos, MAX_TRABAJOS, servicios, LEN_SERVICIOS, contadorAutosActivos);
            break;
        case 19:
            listarTrabajosEnFecha(trabajos, MAX_TRABAJOS, servicios, LEN_SERVICIOS, contadorAutosActivos);
            break;
        case 20:
            altaClienteMenu(clientes, MAX_CLIENTES, &idCliente, &clienteDadoDeAlta);
            break;
        }
        option = showMenu();
    }
    return 0;
}



