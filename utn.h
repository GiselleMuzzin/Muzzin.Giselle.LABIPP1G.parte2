#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado,int longitud);
int esDescripcion(char* cadena,int longitud);
int getDescripcion(char* pResultado, int longitud);
void utn_getNumeroEnRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
void utn_getNumeroMayorA(int* pResultado, char* mensaje, char* mensajeError, int minimo);
void utn_getNumero(int* pResultado, char* mensaje, char* mensajeError);
void utn_getNumeroFlotanteEnRango(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);
void utn_getNumeroFlotanteMayorA(float* pResultado, char* mensaje, char* mensajeError, float minimo);
void utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError);
void utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError);
void utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError);
void utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError);
int getPatente(char* pResultado, int longitud);
int esPatente(char* cadena,int longitud);
void utn_getPatente(char* pResultado, int longitud,char* mensaje, char* mensajeError);


#endif // UTN_H_INCLUDED
