    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
 
  typedef struct nodo
    {
        char* dato;
        int linea;
        struct nodo* sig;
    } Nodo;

    Nodo* listaDeIdentificadores = NULL;
    Nodo* listaDeLiterales = NULL;
    Nodo* listaDeOctales = NULL;
    Nodo* listaDeHexadecimales = NULL;
    Nodo* listaDeDecimales = NULL;
    Nodo* listaDeReales = NULL;
    Nodo* listaDeCaracteres = NULL;
    Nodo* listaDeOperYPunt = NULL;
    Nodo* listaDeComentariosDeLinea = NULL;
    Nodo* listaDeComentariosDeBloque = NULL;
    Nodo* listaDeNoReconocidos = NULL;


Nodo* crearNodo(char* dato){
    Nodo *nodo=(Nodo*) malloc(sizeof(Nodo));
    nodo->dato = strdup(dato);
    nodo->sig = NULL;
    return nodo;
}

void insertarLista(char* loQueQuieroGuardar,int linea, Nodo **Lista){
    Nodo *nuevoNodo = crearNodo(loQueQuieroGuardar);
    nuevoNodo->linea = linea;
    
    if(*Lista == NULL){
         *Lista = nuevoNodo;
    }else{
        Nodo *aux;
        aux = *Lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevoNodo;
    }
}

int cantidadSaltosDeLinea(char* data)
{
    int linea= 0;
    int i = 0;
    while(data[i] != '\0')
    {
        if(data[i] == '\n')
            linea++;
        i++;
    }

    return linea;
}

void insertarOrdenado(char *loQueQuieroGuardar, int linea, Nodo **Lista){
    Nodo *nuevoNodo=crearNodo(loQueQuieroGuardar);
    Nodo *aux1;
    Nodo *aux2;
    nuevoNodo->linea = linea;

    if(*Lista == NULL){
         *Lista = nuevoNodo;
    }else{
        aux1 = *Lista;
        while(strcmp(loQueQuieroGuardar, aux1->dato) > 0 && aux1 != NULL){
            aux2 = aux1;
            aux1 = aux1->sig;    
        }
        if(*Lista==aux1){
            *Lista = nuevoNodo;
        }else{
            aux2->sig = nuevoNodo;
            nuevoNodo->sig = aux1;
        }
    }
}

int contarRepeticiones(char* dato, Nodo* lista ){
    Nodo* aux= lista;
    int contador=0;
    
    while(aux){
        if(strcmp(dato,aux->dato)==0){
            contador++;
        }
        aux=aux->sig;
    }
    return contador;
}

void copiarConRepeticiones(FILE * reporte, Nodo* lista){
    Nodo *aux = lista;
    char* nuevoDato;
    int contador;

    while(aux){
        if(nuevoDato != aux->dato){
            nuevoDato = aux->dato;
            contador = contarRepeticiones(nuevoDato,lista);
            fprintf(reporte, "%s: %d veces \n",nuevoDato,contador);
        }
        aux = aux->sig;
    }
}

void copiarConLength(FILE * reporte, Nodo* lista){
    Nodo* aux=lista;
    int length=0;
    char* literalCadena;

    while(aux){
        literalCadena = aux->dato;
        length = strlen(literalCadena);
        fprintf(reporte,"%s, que tiene largo: %d \n",literalCadena,length);
        aux=aux->sig;
    }
}

void copiarLista(FILE* reporte, Nodo* lista){
    Nodo* aux=lista;
    
    while(aux){
        fprintf(reporte,"%s \n",aux->dato);
        aux= aux->sig;
    }   
}

void copiarNumeros(FILE* reporte, Nodo*lista, int base){
    Nodo*aux = lista;
    int numeroDecimal;

    while(aux){
        numeroDecimal = strtol(aux->dato, NULL,base);
        fprintf(reporte,"%s -> %d \n",aux->dato,numeroDecimal);
        aux= aux->sig;
    }
}

void sumatoria(FILE * reporte, Nodo* lista){
    Nodo* aux=lista;
    int sumatoria=0;

    while(aux){
        sumatoria += atoi(aux->dato);
        aux=aux->sig;
    }
    
    fprintf(reporte,"La sumatoria es: %d \n",sumatoria);
}

void copiarCaracteres(FILE * reporte, Nodo* lista){
    Nodo* aux=lista;
    int num=1;

    while(aux){
        fprintf(reporte,"%d) %c \n",num,aux->dato);
        num ++;
        aux=aux->sig;
    }
}

void copiarNoRec(FILE * reporte, Nodo* lista){
    Nodo* aux= lista;
    
    while(aux){
        fprintf(reporte,"%c -> linea %d", aux->dato,aux->linea);
        aux = aux->sig;
    }
}

void parteEnteraYmantisa(FILE * reporte, Nodo* lista){
    Nodo* aux=lista;
    float mantisa;
    int parteEntera, numero;
    
    while(aux){
        numero=atof(aux->dato);
        parteEntera=(int)numero;
        mantisa= numero-parteEntera;
        fprintf(reporte,"La parte entera es: %d, su mantisa es: %f", parteEntera,mantisa);
        aux=aux->sig;
    }
}