//reconocer expresiones, declaraciones de variables, declaraciones de funciones, sentencias de distintos tipos y definiciones de funciones

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int flag_error = 0; 
// SE PONE EN BLANCO ESTO flag del culo
int yylex();

int yywrap(){
	return(1);
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}


%}

%token <entero> NUMERO_ENTERO
%token <real> NUMERO_REAL
%token <texto> TIPO_DATO
%token <texto> IDENTIFICADOR
%token <texto> LITERALCADENA
%token <caracter> CARACTER


%union {
    int entero;
    char* texto;
    char caracter;
    float real;
}

 
%% 

input:  /* vacio */
        | input line
;

line:   '\n'
        | expresion '\n' {}
        | sentencia '\n' {}
        | funciones '\n' {}
;

/*EXPRESIONES*/

expresion:      expUnaria operadorAs expresion
                | expCondicional
                | error {printf("que haces cap@ declara bien\n");}
;
operadorAs: '=' | '+''=' 
;

expCondicional: expOr
                | expOr expresion ':' expCondicional
;

expOr:  expAnd
        | expOr '|''|' expAnd
;

expAnd: expIgualdad
        | expAnd '&''&' expIgualdad
;

expIgualdad:    expRelacional
                | expIgualdad '=''=' expRelacional
                | expIgualdad '!''=' expRelacional
;            
expRelacional:  expAditiva
                | expRelacional '>''=' expAditiva 
                | expRelacional '>' expAditiva
                | expRelacional '<''=' expAditiva
                | expRelacional '<' expAditiva
;
                
expAditiva:     expMultiplicativa
                | expAditiva '+' expMultiplicativa
                 | expaditiva '-' expMultiplicativa
;
expUnaria:      expPostfijo
                | incremento expUnaria
                | operUnario expUnaria
                 | expUnaria incremento
;

incremento: '+''+'|'-''-'
;

oprUnario: '&' | '*' | '-' | '!'
;

expPostfijo: expPrimaria
            | expPostfijo '['expresion']'
            | expPostfijo '('listaArgumentos')'
;

listaArgumentos: expAsignacion
                | listaArgumentos expAsignacion
;
expPrimaria:    IDENTIFICADOR
                | NUMERO_ENTERO
                | NUMERO_REAL
                | LITERALCADENA 
                | '('expresion')'
;

nombreTipo: char | int | double
;

expConst: expCondicional;

/*SENTENCIAS*/

sentencia:      sentExp
                | sentCompuesta
                | sentAsignacion
                | sentSeleccion
                | sentIteracion
                | sentEtiquetada
                | sentSalto
                | error {printf("ERROR AL DECLARAR LA SENTENCIA");}
;

sentExp: expresion
;

sentCompuesta:  '{' listaDeclaraciones listaSentencias '}'
                | '{' listaDeclaraciones '}'
                | '{' listaSentencias '}'
                | '{''}'
;

listaDeclaraciones:     listaDeclaraciones declaracion 
                        | declaracion
;

listaDeclaraciones:     sentencia   
                        | listaSentencias sentencia
;

sentSeleccion:  IF '(' expresion ')' sentencia
                | IF '(' expresion ')' sentencia ELSE
                | SWITCH '(' expresion ')' sentencia
;

sentIteracion:  WHILE '(' expresion ')' sentencia
                | DO sentencia WHILE '(' exprecion ')'
                | FOR '(' expresion ';' expresion ';' expresion ')' sentencia
;

sentEtiquetada: CASE expConstante ':' sentencia
                | DEFAULT ':' sentencia
                | IDENTIFICADOR ':' sentencia
;

sentSalto:      RETURN expresion ';'
                | RETURN ';'
                | CONTINUE ';'
                | BREAK ';'
                | GOTO IDENTIFICADOR ';'
;

sentAsignacion: IDENTIFICADOR '=' expresion ';'
;


/*DECLARACIONES*/

declaracion:    espeDec listDec? ;

espeDec:        espeClasAlma espDec
                |espeTipo espeDec 
                |caliTipo espeDec 
;

listDec:        declarador 
                |listDec ',' declarador;

declarador:     decla 
                |decla '=' inicializador;

inicializador:  expAsignación 
                |'{'listInicial'}'  
                |'{' listInicial ',' '}'
;

listInicial:    inicializador  
                |listInicial ',' inicializador;

espeClasAlma: TYPEDEF | STATIC | AUTO | REGISTER | EXTERN
;

espeTipo: VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE | SIGNED | UNSIGNED
        | especificadorSU
        | especificadorE
        | nombreTypedef
;

caliTipo: CONST | VOLATILE
;

especificadorSU: SU identificador '{'listaDecS '}' |
                | SU identificador
;

SU: STRUCT | UNION ;

listaDecS: declaracionS
            | listaDecS declaracionS
;

declaracionS: listCali decS ;

listCali:  espeTipo listCali 
            |caliTipo listCali
;

declaracionS: decS 
            |declaracionS ',' decS
;

decS: decS 
    | decla ':' expConst
;

decla: puntero decDirec
;

puntero:
        listCaliTipos 
        |listCaliTipos puntero
;

listCaliTipos: caliTipo 
                |listCaliTipos caliTipo
;

decDirec: identificador 
        | '('decla')' 
        | decDirec '[' expConst? ']' 
        | decDirec '(' listTipoPar ')' 
        | decDirec '(' listIden ')' 
;

listTipoPar:
        listParam 
       // | listParam ',' . . .  ????????
;

listParam:
        decParam
        | listParam ',' decParam
;

decParam: espeDec decla 
        | espeDec decAbstract
;

listIden: identificador 
        | listIden ',' identificador
;

especificadorE: enum identificador '{' listEnum '} '
        | enum identificador
;

listEnum: enumerador
        | listEnum ',' enumerador
;

enumerador: constEnum 
        | constEnum '=' expConst
;

constEnum: identificador
;

nombreTypedef: identificador
;

nombTipo: listCali decAbstract
;

decAbstract:puntero 
        | puntero decAbstDirec
;

decAbstDirec: '('decAbstract')' 
        | decAbstDirec '['expConst']' 
        | decAbstDirec '('listTipoPar')'
;

%%

int main (){

  yyparse ();
}
