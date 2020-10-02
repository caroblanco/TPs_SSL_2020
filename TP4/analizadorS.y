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

void yyerror (char *cosa) {
   fprintf ("encontre: %s\n", cosa);
}

FILE* yyin;
FILE* yyout;

%}

%token <entero> NUMERO_ENTERO
%token <real> NUMERO_REAL
%token <texto> TIPO_DATO
%token <texto> IDENTIFICADOR
%token <texto> LITERALCADENA
%token <caracter> CARACTER
%token <texto> PALABRA_RESERVADA

%token P_INC
%token P_DEC 
%token DISTINTO 
%token IGUAL 
%token AND 
%token OR 
%token DIV_IGUAL
%token POR_IGUAL
%token MENOS_IGUAL
%token MAS_IGUAL 
%token MENOR_IGUAL
%token MAYOR_IGUAL
%token MOD_IGUAL 
%token BIT_SHIFT_L
%token BIT_SHIFT_R
%token FLECHITA
// ACA ES LA ESPECIFICACION DE LA RECURSIVIDAD
//   #e s p e C I C I f a c i o n


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
        | declaracion '\n' {}
;

/*EXPRESIONES*/
expresion: expresionAs  
        |expresion ',' expresionAs
;

expresionAs:      expUnaria operadorAs expresionAs
                | expCondicional
                | error {printf("que haces cap@ declara bien\n");}
;
operadorAs: '=' | DIV_IGUAL | POR_IGUAL | MENOS_IGUAL | MAS_IGUAL | MOD_IGUAL 
;

expCondicional: expOr
                | expOr '?' expresion ':' expCondicional
;

expOr:  expAnd
        | expOr OR expAnd
;

expAnd: expOInclusivo
        | expAnd AND expOInclusivo
;

expOInclusivo: expOExcluyente
                |expOInclusivo '|' expOExcluyente
;

expOExcluyente: expY
                |expOExcluyente '^' expY
;

expY: expIgualdad
        |expY '&' expIgualdad
;

expIgualdad:    expRelacional
                | expIgualdad IGUAL expRelacional
                | expIgualdad DISTINTO expRelacional
;            
expRelacional:  expAditiva
                | expRelacional MAYOR_IGUAL expAditiva 
                | expRelacional '>' expAditiva
                | expRelacional MENOR_IGUAL expAditiva
                | expRelacional '<' expAditiva
;

expCorrimiento: expAditiva
                |expCorrimiento BIT_SHIFT_L expAditiva
                |expAditiva BIT_SHIFT_R expCorrimiento
;
                
expAditiva:     expMultiplicativa
                | expAditiva '+' expMultiplicativa
                | expaditiva '-' expMultiplicativa
;

expMultiplicativa: expConversion
                        |expMultiplicativa '/' expConversion //     algo / 0 x  ERROR
                        |expMultiplicativa '*' expConversion
                        |expMultiplicativa '%' expConversion
;

expConversion: expUnaria
                |'(' nombreTipo ')' expConversion
;

expUnaria:      expPostfijo
                | incremento expUnaria
                | operUnario expConversion
                | expUnaria incremento
;

incremento: P_INC | P_DEC
;

oprUnario: '&' | '*' | '-' | '!' | '+' | '~'
;

expSufijo: expPrimaria
            | expSufijo '['expresion']'
            | expSufijo '('listaArgumentos')'
            | expSufijo '.' unID
            | expSufijo FLECHITA unID
            | expSufijo P_INC
            | expSufijo P_DEC
;

listaArgumentos: expAsignacion
                | listaArgumentos ',' expAsignacion
;
expPrimaria:    unID
                | NUMERO_ENTERO
                | NUMERO_REAL
                | LITERALCADENA 
                | '(' expresion ')'
;

nombreTipo: "char" | "const" | "float" | "int" | "long" | "signed" | "unsigned" | "short" | "void" | "struct" | "typedef" | "union" | "enum" 
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

sentExp: expresion '?'
;

sentCompuesta:  '{' listaDeclaraciones '?' listaSentencias '?' '}'
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
                | FOR '(' expresion '?' ';' expresion '?' ';' expresion '?' ')' sentencia
;

sentEtiquetada: CASE expConstante ':' sentencia
                | DEFAULT ':' sentencia
                | IDENTIFICADOR ':' sentencia
;

sentSalto:      RETURN expresion '?' ';'
                | CONTINUE ';'
                | BREAK ';'
                | GOTO IDENTIFICADOR ';'
;

sentAsignacion: IDENTIFICADOR '=' expresion ';'
;


/*DECLARACIONES*/

declaracion:    espeDec listDec '?' 
;

espeDec:        espeClasAlma espDec '?'
                |espeTipo espeDec '?'
                |caliTipo espeDec '?'
;

listDec:        declarador 
                |listDec ',' declarador
;

declarador:     decla 
                |decla '=' inicializador
;

inicializador:  expAsignación 
                |'{'listInicial'}'  
                |'{' listInicial ',' '}'
;

listInicial:    inicializador  
                |listInicial ',' inicializador
;

espeClasAlma: TYPEDEF | STATIC | AUTO | REGISTER | EXTERN
;

espeTipo: VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE | SIGNED | UNSIGNED
        | especificadorSU
        | especificadorE
        | nombreTypedef
;

caliTipo: CONST | VOLATILE
;

especificadorSU: SU IDENTIFICADOR '?''{'listaDecS '}' |
                | SU IDENTIFICADOR
;

SU: STRUCT | UNION
;

listaDecS: declaracionS
            | listaDecS declaracionS
;

declaracionS: listCali decS
;

listCali:  espeTipo listCali '?'
            |caliTipo listCali '?'
;

declaracionS: decS 
            |declaracionS ',' decS
;

decS: decS 
    | decla '?' ':' expConst
;

decla: puntero '?' decDirec
;

puntero:
        listCaliTipos '?'
        |listCaliTipos '?' puntero
;

listCaliTipos: caliTipo 
                |listCaliTipos caliTipo
;

decDirec: identificador 
        | '('decla')' 
        | decDirec '[' expConst '?' ']' 
        | decDirec '(' listTipoPar ')' 
        | decDirec '(' listIden '?' ')' 
;

listTipoPar:
        listParam 
       // | listParam ',' . . .  
;

listParam:
        decParam
        | listParam ',' decParam
;

decParam: espeDec decla 
        | espeDec decAbstract
;

listIden: identificador 
        | listIden ',' IDENTIFICADOR
;

especificadorE: enum IDENTIFICADOR '?' '{' listEnum '} '
        | enum IDENTIFICADOR
;

listEnum: enumerador
        | listEnum ',' enumerador
;

enumerador: constEnum 
        | constEnum '=' expConst
;

constEnum: IDENTIFICADOR
;

nombreTypedef: IDENTIFICADOR
;

nombTipo: listCali decAbstract '?'
;

decAbstract:puntero 
        | puntero '?' decAbstDirec
;

decAbstDirec: '('decAbstract')' 
        | decAbstDirec '?' '['expConst '?'']' 
        | decAbstDirec '?' '('listTipoPar '?'')'
;

%%

int main (){
        
  yyparse ();
}
