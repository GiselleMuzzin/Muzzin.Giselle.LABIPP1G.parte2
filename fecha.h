#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

int esDiaValido(int dia, int mes, int anio);
int esMesValido(int mes);
void pedirFecha(Fecha* pFecha);
int sonMismaFecha(Fecha fecha1, Fecha fecha2);

#endif // FECHA_H_INCLUDED
