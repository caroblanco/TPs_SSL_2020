%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    #define PALABRA_MAX 50
    int sumaEnteros = 0, linea = 1, valorD = 0, valorO = 0, valorH = 0, largo;

    typedef struct nodo
    {
        char* info;
        int dato;
        struct nodo* sig;
    } Nodo;

    
typedef struct nodoReal
    {
        char* info;
        int parteEntera;
        float parteFraccionaria;
        struct nodo* sig;
    } NodoReal;

typedef struct nodoString
    {
        char* info;
        struct nodo* sig;
    } NodoString;



    Nodo* listaDeIdentificadores = NULL;
    Nodo* listaDeLiterales = NULL;
    NodoString* listaDePalabrasReservadas = NULL;
    Nodo* listaDeOctales = NULL;
    Nodo* listaDeHexadecimales = NULL;
    Nodo* listaDeDecimales = NULL;
    NodoReal* listaDeReales = NULL;
    NodoString* listaDeCaracteres = NULL;
    NodoString* listaDeOperYPunt = NULL;
    NodoString* listaDeComentariosDeLinea = NULL;
    NodoString* listaDeComentariosDeBloque = NULL;
    Nodo* listaDeNoReconocidos = NULL;
    
%}

TIPO_DE_DATO int | float | char | struct | double | long | unsigned | signed | short | void | enum | struct | typedef | union | const
ESTRUCTURAS_DE_CONTROL switch | case | do | while | break | default | if | else | for | return | continue | goto
OTROS volatile | goto | extstatic | auto | register 

CARACTERES_PUNTUACION_OPERADORES "[" | "]" | "(" | ")" | "{" | "}" | "," | ";" | ":" | "*" | "=" | "#" | "!" | "%" | "^" | "&" | "–" | "+" | "|" | "~" | "\" | "'" | "<" | ">" | "?" | "." | "/" | "==" | | "+=" | "-=" | "~" | "&&" | "!=" | "++" | "--"
 
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_HEXADECIMAL 0[xX][0-9A-Fa-f]+
CONSTANTE_REAL   [0-9]+ "." [0-9]+ //no estamos muy seguros
CARACTER_LETRAS [a-zA-Z]

COMENTARIO_LINEA "//" .*
COMENTARIO_BLOQUE "/*"([^*]|\*+[^/])*\*+\/
COMODIN .
COMODINES .*
SALTO_DE_LINEA \
IDENTIFICADOR ({CARACTER_LETRAS} |_)({CARACTER_LETRAS} | [0-9]| _)*
PALABRAS_RESERVADAS {TIPO_DE_DATO} | {ESTRUCTURAS_DE_CONTROL} | {OTROS}
LITERAL_CADENA \".+\"
CARACTER \'.\''

%%

{CONSTANTE_DECIMAL}         {
                                valorD = obtenerNumero(yytext,10);  
                                insertarLista(yytext,listaDeDecimales);
                            } 
{CONSTANTE_OCTAL}	        {
                                valorO = obtenerNumero(yytext,8);
                                insertarLista(yytext,valorO,listaDeOctales);
                            }
{CONSTANTE_HEXADECIMAL}	    {
                                valorH = obtenerNumero(yytext,16);
                                insertarLista(yytext,valorH,listaDeHexadecimales);
                            }
{CONSTANTE_REAL}	        {
                                recReal(yytext);
                            }
{CARACTER}	                {
                                insertarLista(yytext,listaDeCaracteres);
                            }
{LITERAL_CADENA}            {
                                largo = strlen(yytext);
                                insertarLista(yytext,largo,listaDeLiterales);
                            }
{IDENTIFICADOR}             {
                                insertarOrdenado(yytext,listaDeIdentificadores);
                            }
{CARACTERES_PUNTUACION_OPERADORES} {
                                    insertarLista(yytext,listaDeOperYPunt);
                                   }
{PALABRAS_RESERVADAS}       {
                                insertarLista(yytext,listaDePalabrasReservadas);
                            }
{COMENTARIO_BLOQUE}         {
                                insertarLista(yytext,listaDeComentariosDeBloque);
                            }
{COMENTARIO_LINEA}          {
                                insertarLista(yytext,listaDeComentariosDeLinea);
                            }
{SALTO_DE_LINEA}            {linea ++;}
{COMODIN}                   {
                                insertarLista(yytext,linea,listaDeNoReconocidos);
                            }
{COMODINES}                 {
                                insertarLista(yytext,linea,listaDeNoReconocidos);
                            }

%%

int obtenerNumero(char* str, int base)
{
    char* ignorar;
    return strtol(str,&ignorar,base);
}

Nodo* crearNodo(char* dato){
    Nodo *nodo=(Nodo*) malloc(sizeof(Nodo));
    nodo->info = dato;
    nodo->sig = NULL;
    return nodo;
}


void insertarLista(char *loQueQuieroGuardar,int numero, Nodo *Lista){
    Nodo *nuevoNodo = crearNodo(loQueQuieroGuardar), *aux;
    nuevoNodo->dato = numero;
    
    if(Lista == NULL){
         Lista = nuevoNodo;
    }else{
        aux = Lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevoNodo;
    }
    return Lista;
}


void insertarOrdenado(char *loQueQuieroGuardar, Nodo *Lista){
    Nodo *nuevoNodo, *aux1, *aux2;
    nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->dato = loQueQuieroGuardar;
    nuevoNodo->info = 0;
    nuevoNodo->sig = NULL;

    if(Lista == NULL){
         Lista = nuevoNodo;
    }else{
        aux1 = Lista;
        while(strcmp(loQueQuieroGuardar, aux1->dato) > 0 && aux1 != NULL){
            aux2 = aux1;
            aux1 = aux1->sig;    
        }

        if(Lista==aux1){
            Lista = nuevoNodo;
        }else{
            aux2->sig = nuevoNodo;
            nuevoNodo->sig = aux1;
        }
    }
}

Nodo *insertarLista1String(char *loQueQuieroGuardar, Nodo *Lista){
    Nodo *nuevoNodo, *aux;
    nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->info = loQueQuieroGuardar;
    nuevoNodo->sig = NULL;
    
    if(Lista == NULL){
         Lista = nuevoNodo;
    }else{
        aux = Lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevoNodo;
    }
    return Lista;
}

void recReal(texto){
    char*ignorar;
    float valorR = strtof(texto,&ignorar);
    int entera = valorR;
    float decimales = valorR - entera;
    NodoReal *nuevoNodoReal, *aux;
    nuevoNodoReal = (NodoReal*) malloc(sizeof(NodoReal));
    nuevoNodoReal->info = texto;
    nuevoNodoReal->parteEntera = entero;
    nuevoNodoReal->parteFraccionaria = fraccionaria;
    nuevoNodoReal->sig = NULL;
    
    if(listaDeReales == NULL){
         listaDeReales = nuevoNodoReal;
    }else{
        aux = listaDeReales;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevoNodoReal;
    }
    return listaDeReales;
};


int main(){
    yyin = fopen("TextoEntrada.txt", "r");
    yyout = fopen("TextoSalida.txt", "w");

    FILE* reporte = fopen("Reporte.txt", "w");

    yylex();

    fclose(yyin);
    fclose(yyout);
    fclose(reporte);
}









































































.eze.