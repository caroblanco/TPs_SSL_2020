#include "funciones.h"

// KENI VEL, MARIVEL

int iniciarListas()
{
    listaVariables = list_create();
    listaParametros = list_create();
    listaFunciones = list_create();
    errores = list_create();
    /* 
    //pruebas
    agregarVariable("a","int");

    agregarVariable("a","float");

    agregarVariable("b","float");
    list_iterate(listaVariables, (void*) mostrarVariable);
    
    t_list* params = list_create();

    tVariables* var = malloc(sizeof(tVariables));
    tVariables* var2 = malloc(sizeof(tVariables));
    tVariables* var3 = malloc(sizeof(tVariables));
    
    char* a = "a";
    char* b = "b";
    char* c = "c";
    char* entero = "int";
    char* doble = "double";

    var->nombre = a;
    var->tipo = entero;
    list_add(params, var);
    
    var2->nombre = b;
    var2->tipo = entero;
    list_add(params, var2);
    
    var3->nombre = c;
    var3->tipo = doble;
    list_add(params, var3);
    
    tFunciones* funcion = malloc(sizeof(tFunciones));
    funcion->nombre = "elpepe";
    funcion->parametros = params;

    agregarFuncion(funcion->nombre, funcion->parametros);
    agregarFuncion(funcion->nombre, funcion->parametros);
    
    mostrarFuncion(funcion);
    //#SantiNosBendijoConLeanTodoPoderoso ♥
    //:3
    //:V
    //:|
    */
}

/////////////
//VARIABLES//
/////////////

void mostrarVariable(tVariables* variable)
{
    printf("\t %s %s\n", variable->nombre, variable->tipo);
}
tVariables* buscarVariable(char* nombre)
{   
    int _nombre_igual(tVariables* variable)//vscode es malo pero gcc sape
    {
        return strcmp(variable->nombre,nombre) == 0;
    }
    list_find(listaVariables, (void*) _nombre_igual);
}
int agregarVariable(char* nombre, char* tipo)
{
    tVariables* temp = buscarVariable(nombre);

    if(temp != NULL)
    {
        //printf("ERROR: Ya existe la variable %s :(\n", nombre);
        return 0;
    }
    else
    {
        temp = malloc(sizeof(tVariables));
        temp->nombre = nombre;
        temp->tipo = tipo;
        list_add(listaVariables, temp);
        return 1;
    }
}

/////////////
//FUNCIONES//
/////////////

void mostrarFuncion(tFunciones* funcion)
{
    printf("%s ",funcion->nombre);
    printf("\n");
    list_iterate(funcion->parametros, (void*) mostrarVariable);
    printf("\n");
}

tFunciones* buscarFuncion(char* nombre)
{
    int _nombre_igual(tFunciones* funcion) //vscode es malo pero gcc sape
    {
        return strcmp(funcion->nombre, nombre) == 0;
    }
    list_find(listaFunciones, (void*) _nombre_igual);
}
int agregarFuncion(char * nombre, t_list* parametros)
{
    tFunciones* temp = buscarFuncion(nombre);

    if(temp != NULL)
    {
        printf("ERROR: la funcion %s ya esta definida :'( \n", nombre);
        return 0;
    }
    else
    {
        temp = malloc(sizeof(tFunciones));
        temp->nombre = nombre;
        temp->parametros = parametros;
        //int cantidad = list_size(temp->parametros);
        list_add(listaFunciones, temp);
        return 1;
    }
}

void agregarError(char* mensaje, char* tipo, int linea)
{
    tError* error = malloc(sizeof(tError));
    error->mensaje = mensaje;
    error->tipo = tipo;
    error->nroLinea = linea;

    list_add(errores, &error);
}
//Al menos un control de tipos de datos en alguna operación binaria
        