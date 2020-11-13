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

t_list* listaVarTemp;
t_list* listaVar;
char* identificadorFuncion;
void iniciarListas(void);
void mostrarVariable(tVariables*);
void nuevoParametro(char*,char*);

void nuevaFuncion(char*, char*);
void mostrarFuncion(tFunciones*);
tVariables* buscarVariable(char*);
int agregarVariable(char*, char* );
void intentarAgregarVar(char*, char*, int);
tFunciones* buscarFuncion(char*);
int agregarFuncion(char*, char*, t_list*,int);
void agregarError(char*, char*, int);
void mostrarError(tError*);
void agregarParametro(char*, char*, char*);
void motrarTutti(void);
void mostrarLista(t_list*);
#endif 