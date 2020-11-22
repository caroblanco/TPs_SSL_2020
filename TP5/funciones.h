#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
typedef enum 
{
    DECL,
    DEF
} t_fn;
typedef enum
{
    SUMA,
    RESTA,
    MULT,
    DIV,
    MOD
} t_op;
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
t_list* listaFuncionesDeclaradas; //lista de tFunciones
t_list* listaFuncionesDefinidas;


typedef struct 
{
    char* mensaje;  // la cagaste papi 
    char* tipo;     // lexico | sintactico | semantico
    int nroLinea;   // cantidad de pizzas
}tError;
t_list* errores;    // lista de tError

t_list* listaVarTemp;
t_list* listaVar;
t_list* listaOperandos;
char* identificadorFuncion;
void iniciarListas(void);
void mostrarVariable(tVariables*);
void nuevoParametro(char*,char*);

void nuevaFuncion(char*, char*);
void mostrarFuncion(tFunciones*);
tVariables* buscarVariable(char*);
int agregarVariable(char*, char* );
void intentarAgregarVar(char*, char*, int);
tFunciones* buscarFuncion(char*, t_fn);
int agregarFuncion(char*, char*, t_list*,t_fn,int);
void agregarOperando(char*);
void mismoTipoParametros(int);
void agregarError(char*, char*, int);
void mostrarError(tError*);
void agregarParametro(char*, char*, char*);
void mostrarTutti(void);
void mostrarLista(t_list*);
// int parametrosMismoTipo(char*,char*, t_op);
#endif 