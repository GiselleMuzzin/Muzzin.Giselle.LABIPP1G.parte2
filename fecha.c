#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"

/**
 * \brief 	Valida que el dia sea correcto segun el mes y año ingresados
 * \param dia Es el dia que conforma la fecha
 * \param mes Es el mes que conforma la fecha
 * \param anio Es el año que conforma la fecha
 * \return Retorna 0 (NO VALIDO) y 1 (VALIDO)
 *
 */
int esDiaValido(int dia, int mes, int anio)
{
    int valido = 0;
    switch(mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(dia > 0 && dia < 32)
        {
            valido = 1; // ok p los meses de 31 dias
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(dia > 0 && dia < 31)
        {
            valido = 1; // ok p los meses de 30 dias
        }
        break;
    case 2:
        if(dia > 0 && dia < 29)
        {
            valido = 1; // ok febrero
        }
        else
        {
            if(dia == 29 && ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0))
            {
                valido = 1; // ok febrero año bisiesto
            }
        }
        break;
    }
    return valido;
}

/**
 * \brief 	Valida que el int mes sea un mes valido
 * \param mes Es el mes que conforma la fecha
 * \return Retorna 0 (NO VALIDO) y 1 (VALIDO)
 *
 */
int esMesValido(int mes)
{
    int valido = 0;
    if(mes<=12 && mes>=1)
    {
        valido = 1;
    }
    return valido;
}

/**
 * \brief 	Pide la fecha al usuario (dia, mes, año)
 * \param pFecha Puntero a fecha
 * \return (void)
 *
 */
void pedirFecha(Fecha* pFecha)
{
    int anio;
    int mes;
    int dia;
    printf("Ingrese año: \n");
    scanf("%d", &anio);
    while(anio<1000)
    {
        printf("Error, reingrese año: \n");
        scanf("%d", &anio);
    }
    printf("Ingrese mes: \n");
    scanf("%d", &mes);
    while(esMesValido(mes) == 0)
    {
        printf("Error, reingrese mes: \n");
        scanf("%d", &mes);
    }
    printf("Ingrese dia: \n");
    scanf("%d", &dia);

    while(!esDiaValido(dia, mes, anio))
    {
        printf("Error, reingrese dia: \n");
        scanf("%d", &dia);
    }
    (*pFecha).anio = anio;
    (*pFecha).mes = mes;
    (*pFecha).dia = dia;
}

/**
 * \brief 	Valida que dos fechas sean iguales
 * \param fecha1 Primera fecha
 * \param fecha2 Segunda fecha
 * \return Retorna 0 (NO VALIDO) y 1 (VALIDO)
 *
 */
int sonMismaFecha(Fecha fecha1, Fecha fecha2)
{
    int retorno = 0;
    if(fecha2.anio == fecha1.anio && fecha2.dia == fecha1.dia && fecha2.mes == fecha1.mes)
    {
        retorno = 1;
    }
    return retorno;

}
