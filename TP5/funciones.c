#include "funciones.h"

// KENI VEL, MARIVEL

void iniciarListas()
{
    listaVar = list_create();
    listaVarTemp =  list_create();
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
    ii
    tFunciones* funcion = malloc(sizeof(tFunciones));
    funcion->nombre = "elpepe";,
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

void nuevoParametro(char* nombre, char* tipo)
{
    tVariables* paramTemp = malloc(sizeof(tVariables));
    int sznombre = strlen(nombre)+1;
    int sztipo = strlen(tipo)+1;
    
    paramTemp->nombre = malloc(sznombre);
    memcpy(paramTemp->nombre, nombre, sznombre);
    paramTemp->tipo = malloc(sztipo);
    memcpy(paramTemp->tipo, tipo, sztipo);
    printf("parametro: %s %s\n",tipo,nombre);
    list_add(listaVarTemp,paramTemp);
}

void mostrarError(tError* error)
{
    printf("%s (%s) en la linea: %d\n", error->mensaje, error->tipo, error->nroLinea);
}

void mostrarTutti(void)
{
    printf("\nlasva riables:\n");
    list_iterate(listaVariables, (void*) mostrarVariable);
    printf("\nlasfun ciones:\n");
    list_iterate(listaFunciones, (void*) mostrarFuncion);
    printf("\nlose rrores:\n");
    list_iterate(errores, (void*) mostrarError);
    
}

void mostrarLista(t_list* list) 
{
    printf("LISTA DE PARAMETROS \n");
    void _mostrar(char* elem)
    {
        printf("%s\n",elem);
    }
    list_iterate(list, (void*) _mostrar);
    printf("\n");
}
/////////////
//VARIABLES//
/////////////

void mostrarVariable(tVariables* variable)
{
    printf("\t %s %s\n", variable->tipo, variable->nombre);
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

void intentarAgregarVar(char* nombre, char* tipo, int linea)
{
    if(agregarVariable(nombre, tipo)) 
            printf("Se declaro una variable de tipo %s llamada %s en la linea %d\n", tipo, nombre, linea);
    else{
            printf("ERROR: doble declaracion de la variable %s\n",nombre);
            agregarError("ERROR: doble declaracion de variable", "SEMANTICO", linea);
    }
}
/////////////
//FUNCIONES//
/////////////

void mostrarFuncion(tFunciones* funcion)
{
    printf("%s ",funcion->tipo);
    printf("%s ",funcion->nombre);
    printf("\n");
    if(funcion->parametros != NULL)
    {
        if(list_size(funcion->parametros) != 0)
            list_iterate(funcion->parametros, (void*) mostrarVariable);
        else
            printf("\tsin parametros");
    }
    else
        printf("\tsin parametros");
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

void nuevaFuncion(char* tipo, char* identificador)
{
    identificadorFuncion = identificador;
    tFunciones* nueva = malloc(sizeof(tFunciones));
    nueva->tipo = tipo;
    nueva->nombre = identificador;
    nueva->parametros = list_create();
}

void agregarParametro(char* tipo, char* opcional, char* identificador)
{
    tFunciones* funcion = buscarFuncion(identificador);
    if(funcion != NULL)
    {
        tVariables* var = malloc(sizeof(tVariables));
        var->tipo = tipo;
        var->nombre = identificador;
        
        list_add(funcion->parametros, var);
    }
}  

int verificarParametros(t_list* parametros)
{ 
    int sz = list_size(parametros);
    int ret = 1;
    for (int i = 0; i < sz; i++)
    {
        tVariables* var = list_get(parametros,i);
        for(int j = 0; j < sz; j++)
        {
            tVariables* var2 = list_get(parametros,j);
            if(strcmp(var->nombre, var2->nombre) == 0 && j != i)
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int agregarFuncion(char * nombre, char* retorno, t_list* parametros, int linea)
{
    tFunciones* temp = buscarFuncion(nombre);

    if(temp != NULL)
    {
        printf("ERROR: la funcion %s ya esta definida :'( \n", nombre);
        agregarError("ERROR: doble declaracion de funcion", "SEMANTICO", linea);
        return 0;
    }
    else
    {
        temp = malloc(sizeof(tFunciones));
        temp->nombre = nombre;
        temp->tipo = retorno;
        printf("FUNCION %s, retorno %s\n", temp->nombre, temp->tipo);
        
        int c = 1;

        if(verificarParametros(parametros))
        {
            temp->parametros = list_duplicate(parametros);
            //int cantidad = list_size(temp->parametros);
            list_add(listaFunciones, temp);
            return 1;
        }
        else{
            //agregar a error
            printf("ERROR: dos parametros con el mismo nombre\n");
            agregarError("ERROR: hay dos parametros con el mismo nombre en la funcion", "SEMANTICO", linea);
            return 0;
        }
    }
}

void agregarError(char* mensaje, char* tipo, int linea)
{
    tError* error = malloc(sizeof(tError));
    error->mensaje = mensaje;
    error->tipo = tipo;
    error->nroLinea = linea;

    list_add(errores, error);
}
