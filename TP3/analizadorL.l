%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    int linea = 1;

    typedef struct nodo
    {
        char* dato;
        int linea;
        struct nodo* sig;
    } Nodo;


    Nodo* listaDeIdentificadores = NULL;
    Nodo* listaDeLiterales = NULL;
    Nodo* listaDePalabrasReservadas = NULL;
    Nodo* listaDeOctales = NULL;
    Nodo* listaDeHexadecimales = NULL;
    Nodo* listaDeDecimales = NULL;
    Nodo* listaDeReales = NULL;
    Nodo* listaDeCaracteres = NULL;
    Nodo* listaDeOperYPunt = NULL;
    Nodo* listaDeComentariosDeLinea = NULL;
    Nodo* listaDeComentariosDeBloque = NULL;
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
SALTO_DE_LINEA \
IDENTIFICADOR ({CARACTER_LETRAS} |_)({CARACTER_LETRAS} | [0-9]| _)*
PALABRAS_RESERVADAS {TIPO_DE_DATO} | {ESTRUCTURAS_DE_CONTROL} | {OTROS}
LITERAL_CADENA \".+\"
CARACTER \'.\''

%%

{CONSTANTE_DECIMAL}         { 
                                insertarLista(yytext,linea,listaDeDecimales);
                            } 
{CONSTANTE_OCTAL}	        {
                                insertarLista(yytext,linea,listaDeOctales);
                            }
{CONSTANTE_HEXADECIMAL}	    {
                                insertarLista(yytext,linea,listaDeHexadecimales);
                            }
{CONSTANTE_REAL}	        {
                                insertarLista(yytext,linea,listaDeReales);
                            }
{CARACTER}	                {
                                insertarLista(yytext,linea,listaDeCaracteres);
                            }
{LITERAL_CADENA}            {
                                insertarLista(yytext,linea,listaDeLiterales);
                            }
{IDENTIFICADOR}             {
                                insertarOrdenado(yytext,linea,listaDeIdentificadores);
                            }
{CARACTERES_PUNTUACION_OPERADORES} {
                                    insertarLista(yytext,linea,listaDeOperYPunt);
                                   }
{PALABRAS_RESERVADAS}       {
                                insertarLista(yytext,linea,listaDePalabrasReservadas);
                            }
{COMENTARIO_BLOQUE}         {
                                insertarLista(yytext,linea,listaDeComentariosDeBloque);
                                linea+= cantidadSaltosDeLinea(yytext);
                            }
{COMENTARIO_LINEA}          {
                                insertarLista(yytext,linea,listaDeComentariosDeLinea);
                            }
{SALTO_DE_LINEA}            {linea ++;}
[" "|\t]*                   {;}
{COMODIN}                   {
                                insertarLista(yytext,linea,listaDeNoReconocidos);
                            }


%%

Nodo* crearNodo(char* dato){
    Nodo *nodo=(Nodo*) malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->sig = NULL;
    return nodo;
}

void insertarLista(char* loQueQuieroGuardar,int linea, Nodo *Lista){
    Nodo *nuevoNodo = crearNodo(loQueQuieroGuardar), *aux;
    nuevoNodo->linea = linea;
    
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

void insertarOrdenado(char *loQueQuieroGuardar, int linea, Nodo *Lista){
    Nodo *nuevoNodo=crearNodo(loQueQuieroGuardar), *aux1, *aux2;
    nuevoNodo->linea = linea;

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
    int numeroDecimal, numero;
    char* ignorar;

    while(aux){
        numero = atoi(aux->dato);
        numeroDecimal = strtol(numero,&ignorar,base);
        fprintf(reporte,"%d -> %d \n",numero,numeroDecimal);
        aux= aux->sig;
    }
}

void sumatoria(FILE * reporte, Nodo* lista){
    Nodo* aux=lista;
    int sumatoria=0;

    while(aux){
        sumatoria += strtoll(aux->dato);
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
        numero=fabs(aux->dato);
        parteEntera=floor(numero);
        mantisa= numero-parteEntera;
        fprinf(reporte,"La parte entera es: %d, su mantisa es: %f", parteEntera,mantisa);
        aux=aux->sig;
    }
}

int main(){
    yyin = fopen("TextoEntrada.txt", "r");
    yyout = fopen("TextoSalida.txt", "w");

    FILE* reporte = fopen("Reporte.txt", "w");

    fprintf(reporte,"-----------------REPORTE ANALIZADOR LEXICO--------------\n\n");
    
    fprintf(reporte,"Lista de identificadores: \n");
    copiarConRepeticiones(reporte, listaDeIdentificadores);

    fprintf(reporte,"Lista de literales cadena: \n");
    copiarConLength(reporte,listaDeLiterales);

    fprintf(reporte,"Lista de palabras reservadas: \n");
    copiarLista(reporte,listaDePalabrasReservadas);

    fprintf(reporte,"Lista de numeros octales: \n");
    copiarNumeros(reporte,listaDeOctales,8);
    
    fprintf(reporte,"Lista de numeros hexadecimales: \n");
    copiarNumeros(reporte,listaDeHexadecimales,16);

    fprintf(reporte,"Lista de numeros decimales: \n");
    copiarNumeros(reporte,listaDeDecimales,10);
    sumatoria(reporte,listaDeDecimales);

    fprintf(reporte,"Lista de constantes reales: \n"); 
    parteEnteraYmantisa(reporte,listaDeReales);

    fprintf(reporte,"Lista de constantes caracter: \n");
    copiarCaracteres(reporte,listaDeCaracteres);

    fprintf(reporte,"Lista de caracteres de puntuacion / operadores: \n");
    copiarConRepeticiones(reporte,listaDeOperYPunt);

    fprintf(reporte, "Lista de comentarios de una linea: \n");
    copiarLista(reporte,listaDeComentariosDeLinea);

    fprintf(reporte,"Lista de comentarios de bloque: \n");
    copiarLista(reporte,listaDeComentariosDeBloque);

    fprintf(reporte, "Lista de caracteres no reconocidos: \n"); 
    copiarNoRec(reporte,listaDeNoReconocidos);

    yylex();

    fclose(yyin);
    fclose(yyout);
    fclose(reporte);
}




































.eze.
