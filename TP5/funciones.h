#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include "list.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char* nombre;  
    char* tipo;
}tVariables;
t_list* listaVariables; //lista de tVariables

t_list* listaParametros; //lista de tVariables

typedef struct
{
    char* nombre;
    char* tipo;
    t_list* parametros; //lista de tParametros
}tFunciones;
t_list* listaFunciones; //lista de tFunciones

typedef struct 
{
    char* mensaje;  // la cagaste papi 
    char* tipo;     // lexico | sintactico | semantico
    int nroLinea;   // cantidad de pizzas
}tError;
t_list* errores;    // lista de tError

void mostrarVariable(tVariables*);
void mostrarFuncion(tFunciones*);
tVariables* buscarVariable(char*);
int agregarVariable(char*, char* );
tFunciones* buscarFuncion(char*);
int agregarFuncion(char*, t_list*);
void agregarError(char*, char*, int);
#endif // _FUNCIONES_H