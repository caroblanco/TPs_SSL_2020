//reconocer expresiones, declaraciones de variables, declaraciones de funciones, sentencias de distintos tipos y definiciones de funciones

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define YYDEBUG 1

int flag_error = 0; 

int yylex();

int yywrap()
{
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
%token SIZEOF
// ACA ES LA ESPECIFICACION DE LA RECURSIVIDAD

%union {
    int entero;
    char* texto;
    char caracter;
    float real;
}

// VER LINEAS: 72, que va entre llaves  -- 
 
%% 

input:  /* vacio */
        | input line
;

line:   '\n'
        | expresion '\n'   {}
        | sentencia '\n'   {}
        | funciones '\n'   {}
        | declaracion '\n' {}
;

/*EXPRESIONES*/
expresion: expresionAs  
        |expresion ';' expresionAs
;

expresionAs:      expUnaria operadorAs expresionAs
                | expCondicional
                | error {printf("que haces cap@ declara bien\n");}
;

operadorAs: '=' | DIV_IGUAL | POR_IGUAL | MENOS_IGUAL | MAS_IGUAL | MOD_IGUAL 
;

expCondicional: expOr
                | expOrOP expresion ':' expCondicional
;

expOr:  expAnd
        | expOr OR expAnd
;

expOrOP: /* na de na */
         | expOr
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
                        |expMultiplicativa '/' expConversion  { if($<real>3 == 0){printf("ERROR AL DIVIDIR POR 0"); return 0;}else $<real>$ = $<real>1 / $<real>3;}
                        |expMultiplicativa '*' expConversion
                        |expMultiplicativa '%' expConversion
;

expConversion: expUnaria
                |'(' nombreTipo ')' expConversion
;

expUnaria:      expSufijo
                | incremento expUnaria
                | operUnario expConversion
                | expUnaria incremento
                | SIZEOF expUnaria
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

nombreTipo: "char" | "const" | "float" | "int" | "long" | "signed" | "unsigned" | "short" | "void" | "struct" | "typedef" | "union" | ENUM
;

unID: IDENTIFICADOR
        |IDENTIFICADOR '=' expresion
        |error  {printf("ERROR: falta ID \n");}
;

/*SENTENCIAS*/

sentencia:      sentExp
                | sentCompuesta
                | sentAsignacion
                | sentSeleccion
                | sentIteracion
                | sentEtiquetada
                | sentSalto
                | error {printf("ERROR AL DECLARAR LA SENTENCIA \n");}
;

sentExp: expresionOP
;

sentCompuesta:  '{' listaDeclaracionesOP listaSentenciasOP '}'
                | '{' listaDeclaraciones '}'
                | '{' listaSentencias '}'
                | '{''}'
;

listaSentenciasOP: /*na de na*/
                        |listaSentencias
;

listaDeclaracionesOP: /*na de na*/
                        |listaDeclaraciones
;

listaDeclaraciones:     listaDeclaraciones declaracion 
                        | declaracion
;

listaSentencias:     sentencia
                        | listaSentencias sentencia
;

sentSeleccion:  IF '(' expresion ')' sentencia
                | IF '(' expresion ')' sentencia ELSE
                | SWITCH '(' expresion ')' sentencia
;

sentIteracion:  WHILE '(' expresion ')' sentencia
                | DO sentencia WHILE '(' expresion ')'
                | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia
;

sentEtiquetada: CASE expConstante ':' sentencia
                | DEFAULT ':' sentencia
                | IDENTIFICADOR ':' sentencia
;

sentSalto:      RETURN expresionOP ';'
                | CONTINUE ';'
                | BREAK ';'
                | GOTO IDENTIFICADOR ';'
;

expresionOP: /* na de na */
             | expresion
;

sentAsignacion: IDENTIFICADOR '=' expresion ';'
;


/*DECLARACIONES*/

declaracion:    espeDec listDecOP  
;

listaDecOP:     /* na de na */
                |listDec
;

espeDec:        espeClasAlma espDecOP 
                |espeTipo espeDecOP
                |caliTipo espeDecOP
;

espeDecOP:      /* na de na */      
                |espeDec
;

listDec:        declarador 
                |listDec ',' declarador
;

declarador:     decla
                |decla '=' inicializador
;

inicializador:  expAsignación
                |'{'listInicial'}'
                |'{' listInicial comaOP '}'
;

comaOP: /* na de na */
        | ','
;

listInicial:    inicializador
                |listInicial ',' inicializador
;

espeClasAlma: "typedef" | "static" | "auto" | "register" | "extern"
;

espeTipo: nombreTipo
        | especificadorSU
        | especificadorE
        | nombreTypedef
;

caliTipo: "const" | "volatile"
;

especificadorSU: SU IDENTIFICADOROP '{'listaDecS '}'
                | SU IDENTIFICADOR
;

IDENTIFICADOROP: /*na de na*/
                |IDENTIFICADOR
;

SU: "struct" | "union"
;

listaDecS: declaracionS
            | listaDecS declaracionS
;

declaracionS: listCali decS ';'
;

listCali: espeTipo listCaliOP
            |caliTipo listCaliOP
;

listCaliOP: /* na de na */
            |listCali
;

declaracionStruct: declaS
            |declaracionStruct ',' declaS
;

declaS: declaS
    | declaOP ':' expConst
;

declaOP: /* na de na */
          |decla
;

decla: punteroOP decDirec
;

punteroOP: /* na de na */
            | puntero
;

puntero: '*' listCaliTiposOP 
        |'*' listCaliTiposOP puntero
;

listCaliTiposOP: /*na de na*/
                |listaCaliTipos
;

listCaliTipos: caliTipo
                |listCaliTipos caliTipo
;

decDirec: IDENTIFICADOR
        | '('decla')'
        | decDirec '[' expConstOP ']'
        | decDirec '(' listTipoPar ')'
        | decDirec '(' listIdenOP ')'
;

listIdenOP: /*na de na*/
        | listaIden
;

listTipoPar:     listParam
                | listParam ',' '.' '.' '.'
;

listParam: decParam
          | listParam ',' decParam
;

decParam: espeDec decla
        | espeDec decAbstractOP
;

listIden: IDENTIFICADOR
        | listIden ',' IDENTIFICADOR
;

especificadorE: ENUM IDENTIFICADOROP '{' listEnum '} '
                | ENUM IDENTIFICADOR
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

nombTipo: listCali decAbstractOP 
;

decAbstractOP: /*na de na*/
                |decAbstract
;
decAbstract:puntero
         | punteroOP decAbstDirec
;

expConst: expCondicional
;

expConstOP: /*na de na*/
                |expConst
;

decAbstDirec: '('decAbstract')'
                | decAbstDirecOP  '['expConstOP ']'
                | decAbstDirecOP '('listTipoParOP ')'
;

listTipoParOP: /*na de na*/
                |listTipoPar
;

decAbstDirecOP: /*na de na*/
                | decAbstDirec 
;



%%

int main (){

  yyin = fopen("entrada.c", "r");
  yyout = fopen("salida.txt", "w");

  #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

  yyparse ();
  fclose(yyin);
  fclose(yyout);
}
