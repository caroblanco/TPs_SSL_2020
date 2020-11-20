#include "funciones.h"

// KENI VEL, MARIVEL

void iniciarListas()
{
    listaVar = list_create();
    listaVarTemp =  list_create();
    listaVariables = list_create();
    listaParametros = list_create();
    listaFuncionesDeclaradas = list_create();
    listaFuncionesDefinidas = list_create();
    errores = list_create();
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
    printf("\n-------------------------------------------------\n");
    printf("\nlasva riables:\n");
    list_iterate(listaVariables, (void*) mostrarVariable);
    printf("\nlasfun ciones definidas:\n");
    list_iterate(listaFuncionesDefinidas, (void*) mostrarFuncion);
    printf("\nlasfun ciones declaradas:\n");
    list_iterate(listaFuncionesDeclaradas, (void*) mostrarFuncion);
    
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

// void agregarParametro(char* tipo, char* opcional, char* identificador)
// {
//     tFunciones* funcion = buscarFuncion(identificador);
//     if(funcion != NULL)
//     {
//         tVariables* var = malloc(sizeof(tVariables));
//         var->tipo = tipo;
//         var->nombre = identificador;
        
//         list_add(funcion->parametros, var);
//     }
// }  

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
            else
                mostrarVariable(var);
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
        printf("parametros f1 null\n");
        return 0;
    }
    if(funcion2->parametros == NULL)
    {
        printf("parametros f2 null\n");
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
            printf("ERROR: algun tipo o nombre de variable no coincide crack (%d) %s %s vs %s %s\n",
                i, var->tipo, var->nombre, var2->tipo, var2->nombre );
            return 0;
        }
            
    }
    //printf("todo ok pa\n");
    return 1;
}
int agregarFuncion(char * nombre, char* retorno, t_list* parametros, t_fn TIPO, int linea)
{
    tFunciones* temp = buscarFuncion(nombre, TIPO);

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
                printf("capo no coinciden los parametros de la definicion y la declaracion\n");
                agregarError("ERROR: no coinciden los parametros de la definicion y la declaracion", "SEMANTICO", linea);
                return 0;
            }
            else if(TIPO == DECL)
            {
                temp->parametros = list_duplicate(parametros);
                //int cantidad = list_size(temp->parametros);
            
                list_add(listaFuncionesDeclaradas, temp);
              
                return 1;
            }
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


// int parametrosMismoTipo(char* operando1, char* operando2, char*tipoDest,t_op op)
// {
//     bool sePuedeTodo =  true
// }