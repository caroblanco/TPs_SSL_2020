#ifndef _MAIN_H
#define _MAIN_H
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

void mostrarVariable(tVariables*);
void mostrarFuncion(tFunciones*);
tVariables* buscarVariable(char*);
void agregarVariable(char*, char* );
tFunciones* buscarFuncion(char*);
void agregarFuncion(char*, t_list*);

#endif