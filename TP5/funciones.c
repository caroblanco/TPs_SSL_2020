#include "funciones.h"

/////////////
//GENERALES//
/////////////

void iniciarListas()
{
    listaVar = list_create();
    listaVarTemp =  list_create();
    listaVariables = list_create();
    listaParametros = list_create();
    listaOperandos = list_create();
    listaFuncionesDeclaradas = list_create();
    listaFuncionesDefinidas = list_create();
    errores = list_create();
}

void mostrarError(tError* error)
{
    printf("%s (%s) en la linea: %d\n", error->mensaje, error->tipo, error->nroLinea);
}

void mostrarTutti(void)
{
    for(int i = 0; i < 50; i++)
        printf("\n");
    printf("\n--------------------------------------------------------------------\n");
    printf("\n--------------------------------------------------------------------\n");
    printf("\n----------------------- REPORTE MUY PIOLA :) -----------------------\n");
    printf("\n--------------------------------------------------------------------\n");
    printf("\n--------------------------------------------------------------------\n");
    printf("\nLas variables son:\n");
    list_iterate(listaVariables, (void*) mostrarVariable);
    printf("\nLas funciones definidas son:\n");
    list_iterate(listaFuncionesDefinidas, (void*) mostrarFuncion);
    printf("\nLas funciones declaradas son:\n");
    list_iterate(listaFuncionesDeclaradas, (void*) mostrarFuncion);
    printf("\nLos errores son:\n");
    list_iterate(errores, (void*) mostrarError);
    printf("\n\n");
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

void agregarError(char* mensaje, char* tipo, int linea)
{
    tError* error = malloc(sizeof(tError));
    error->mensaje = mensaje;
    error->tipo = tipo;
    error->nroLinea = linea;

    list_add(errores, error);
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
            agregarError("*Doble declaracion de variable", "SEMANTICO", linea);
    }
}

//////////////
//PARAMETROS//
//////////////

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

int verificarParametros(t_list* parametros)
{ 
    int sz = list_size(parametros);
    
    // printf("VERIFPARAM\nsz %d\n", sz);
    // if(parametros == NULL){
    //     printf("param null, laca gaste\n");
    //     return 0;
    // }
    // else
    //     printf("param encontrados\n");
    // if(list_size(parametros) == 0){
    //     printf("no tiene param, laca gaste\n");
    //     return 0;
    // }
    // else
    //     printf("cant parametros %d", list_size(parametros));
    for (int i = 0; i < sz; i++)
    {
        tVariables* var = list_get(parametros,i);
        if(var == NULL ){
            // printf("vari %dnull, laca gaste\n",i);
            return 0;
        }
        else
            mostrarVariable(var);
            
        for(int j = 0; j < sz; j++)
        {
            tVariables* var2 = list_get(parametros,j);
            if(var == NULL ){
                // printf("varj %d null, laca gaste\n",j);
                return 0;
            }
            //else
                //mostrarVariable(var);
            if(strcmp(var->nombre, var2->nombre) == 0 && j != i)
            {
                // printf("coinciden %s (%d) y %s (%d)\n",var->nombre,i, var2->nombre,j);
                return 0;
            }
        }
    }
    return 1;
}

int compararParametros(tFunciones* funcion1, tFunciones* funcion2)
{
    if(funcion1->parametros == NULL)
    {
        printf("Parametros f1 null\n");
        return 0;
    }
    if(funcion2->parametros == NULL)
    {
        printf("Parametros f2 null\n");
        return 0;
    }
    
    int sz = list_size(funcion1->parametros);
    int sz2 = list_size(funcion2->parametros);
    //printf("sz1 => %d |||| sz2 => %d\n", sz, sz2);
    if(sz != sz2)
    {
        printf("ERROR: distinta cantidad de parametros entre %s (%d) y %s (%d) \n", funcion1->nombre,sz, funcion2->nombre,sz2);
        return 0;
    }
        
    
    for(int i = 0; i < sz; i++)
    {
        tVariables* var = list_get(funcion1->parametros, i);
        tVariables* var2 = list_get(funcion2->parametros, i);
        if( strcmp(var->nombre, var2->nombre) != 0 || 
            strcmp(var->tipo, var2->tipo) != 0)
        {
            printf("ERROR: Algun tipo o nombre de variable no coincide (%d) %s %s vs %s %s\n",
                i, var->tipo, var->nombre, var2->tipo, var2->nombre );
            return 0;
        }
            
    }
    //printf("todo ok pa\n");
    return 1;
}


///////////////
///OPERANDOS///
///////////////

void agregarOperando(char* nombre)
{
    tVariables* temp = buscarVariable(nombre);
    if(temp == NULL){
        printf("No encontrado %s\n", nombre);
        return;
    }
    printf("Agregando %s \n", temp->tipo); 
    list_add(listaOperandos, temp->tipo);
}

void mismoTipoParametros(int linea)
{
    int todosIguales = 1;
    int sz = list_size(listaOperandos);
    if(sz == 0 )
    {
        printf("Lista vacia\n");
        return;
    }

    for(int i = 0; i < sz -1 ; i++)
    {
        char* temp1 = list_get(listaOperandos, i);
        char* temp2 = list_get(listaOperandos, i+1);
         
        todosIguales &= strcmp(temp1, temp2) == 0;
    }

    if(!todosIguales)
    {
        printf("ERROR: No coinciden los tipos de la operacion\n",todosIguales);
        agregarError("*No coinciden los tipos en la operacion binaria", "SEMANTICO", linea);
    }else
    {
        printf("Coinciden los tipos de la operacion\n",todosIguales);
    }
    
    list_clean(listaOperandos);
}

/////////////
//FUNCIONES//
/////////////

void mostrarFuncion(tFunciones* funcion)
{
    printf("%s ",funcion->tipo);
    printf("%s ",funcion->nombre);
    
    if(funcion->parametros != NULL)
    {
        int sz = list_size(funcion->parametros);
        if(sz != 0)
        {
            printf("(CANTIDAD PARAMETROS %d)\n", sz);
            list_iterate(funcion->parametros, (void*) mostrarVariable);
        }else
            printf("\n\tSin parametros");
    }
    else
        printf("\tSin parametros");
    printf("\n");
}

tFunciones* buscarFuncion(char* nombre, t_fn TIPO)
{
    int _nombre_igual(tFunciones* funcion) //vscode es malo pero gcc sape
    {
        return strcmp(funcion->nombre, nombre) == 0;
    }
    if(TIPO == DECL)
        return list_find(listaFuncionesDeclaradas, (void*) _nombre_igual);
    else if (TIPO == DEF)
        return list_find(listaFuncionesDefinidas, (void*) _nombre_igual);
}

void nuevaFuncion(char* tipo, char* identificador)
{
    identificadorFuncion = identificador;
    tFunciones* nueva = malloc(sizeof(tFunciones));
    nueva->tipo = tipo;
    nueva->nombre = identificador;
    nueva->parametros = list_create();
}

int agregarFuncion(char * nombre, char* retorno, t_list* parametros, t_fn TIPO, int linea)
{
    tFunciones* temp = buscarFuncion(nombre, TIPO);

    if(temp != NULL)
    {
        printf("ERROR: la funcion %s ya esta definida :'( \n", nombre);
        agregarError("*Doble declaracion de funcion", "SEMANTICO", linea);
        return 0;
    }
    else
    {
        temp = malloc(sizeof(tFunciones));
        temp->nombre = nombre;
        temp->tipo = retorno;
        printf("FUNCION %s, retorno %s\n", temp->nombre, temp->tipo);
        

        if(verificarParametros(parametros))
        {
            //printf("verificacion ok\n");
            if(TIPO == DEF)
            {
                tFunciones* declaracion = buscarFuncion(nombre, DECL);
                temp->parametros = list_duplicate(parametros);
                if(declaracion == NULL)
                {
                    //printf("declaracion no encontrada, agregando\n");
                    list_add(listaFuncionesDefinidas, temp);
                    list_add(listaFuncionesDeclaradas, temp);
                    return 1;
                }
                else
                    //printf("declaracion encontrada\n");

                if(compararParametros(temp, declaracion))
                {
                    //printf("comparacion ok\n");
                    
                    //int cantidad = list_size(temp->parametros);
                    list_add(listaFuncionesDefinidas, temp);

                    return 1;
                }
                printf("No coinciden los parametros de la definicion y la declaracion\n");
                agregarError("*No coinciden los parametros de la definicion y la declaracion", "SEMANTICO", linea);
                return 0;
            }
            else if(TIPO == DECL)
            {
                temp->parametros = list_duplicate(parametros);
            
                list_add(listaFuncionesDeclaradas, temp);
              
                return 1;
            }
        }
        else{
            printf("ERROR: dos parametros con el mismo nombre\n");
            agregarError("*Hay dos parametros con el mismo nombre en la funcion", "SEMANTICO", linea);
            return 0;
        }
    }
}

