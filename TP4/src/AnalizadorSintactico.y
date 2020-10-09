%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define YYDEBUG 1

int flag_error = 0; 
int linea=1;

extern FILE* yyin;
FILE* yyout;


int yylex();

int yywrap()
{
    return(1);
}

void yyerror (char *smth) {
   fprintf (yyout,"error sintactico en la linea: %d = %s\n",linea, smth);
}

%}

%token <entero> NUMERO_ENTERO
%token <real> NUMERO_REAL
%token <texto> IDENTIFICADOR
%token <texto> LITERALCADENA
%token <caracter> CARACTER
%token <entero> error

%type <texto> ID

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
%token DO
%token WHILE
%token IF
%token ELSE
%token FOR
%token RETURN
%token GOTO
%token STATIC
%token EXTERN
%token CONST
%token VOLATILE
%token STRUCT
%token UNION
%token TYPEDEF
%token AUTO
%token REGISTER
%token CHAR
%token INT
%token FLOAT
%token LONG
%token SHORT
%token SIGNED
%token UNSIGNED
%token VOID
%token ENUM
%token DOUBLE
%token SIZEOF
%token SWITCH
%token CASE
%token BREAK
%token DEFAULT
%token CONTINUE

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

line:   '\n'                                    {fprintf(yyout,"\n"); linea++;}
        | sentencia '\n'                        {fprintf(yyout,"--------SENTENCIA--------");}
        | expresion '\n'                        {fprintf(yyout,"--------EXPRESION--------");linea++;}
        | declaracion '\n'                      {fprintf(yyout,"--------DECLARACION--------");linea++;}
        | unidadDeTraduccion '\n'               {fprintf(yyout,"--------FUNCION--------");linea++;}
        | error '\n'                            {fprintf(yyout, "\nse detecto un error sintactico en la linea %i", linea); linea++;}
;

/*EXPRESIONES*/

expresion: expresionAs  
        |expresion ';' expresionAs              {fprintf(yyout, "Se encontro un ; \n");}
;

expresionAs:      expUnaria operadorAs expresionAs
                | expCondicional
                | error                         {printf("ERROR al declarar la expresion asignacion \n");}
;

operadorAs: '=' | DIV_IGUAL | POR_IGUAL | MENOS_IGUAL | MAS_IGUAL | MOD_IGUAL 
;

expCondicional: expOr
                | expOrOP expresion ':' expCondicional          {fprintf(yyout, "Se encontro un : \n");}
;

expOr:  expAnd
        | expOr OR expAnd                       {fprintf(yyout, "Se encontro un || \n");}
;

expOrOP: /* na de na */
         | expOr
;

expAnd: expIgualdad
        | expAnd AND expIgualdad             {fprintf(yyout, "Se encontro un && \n");}
;

expIgualdad:    expRelacional
                | expIgualdad IGUAL expRelacional       {fprintf(yyout, "Se encontro un == \n");}
                | expIgualdad DISTINTO expRelacional    {fprintf(yyout, "Se encontro un != \n");}
;            
expRelacional:  expAditiva
                | expRelacional MAYOR_IGUAL expAditiva  {fprintf(yyout, "Se encontro un >= \n");}
                | expRelacional '>' expAditiva          {fprintf(yyout, "Se encontro un > \n");}
                | expRelacional MENOR_IGUAL expAditiva  {fprintf(yyout, "Se encontro un <= \n");}
                | expRelacional '<' expAditiva          {fprintf(yyout, "Se encontro un >= \n");}
;

expCorrimiento: expAditiva
                |expCorrimiento BIT_SHIFT_L expAditiva          {fprintf(yyout, "Se encontro un << \n");}
                |expAditiva BIT_SHIFT_R expCorrimiento          {fprintf(yyout, "Se encontro un >> \n");}
;
                
expAditiva:     expMultiplicativa
                | expAditiva '+' expMultiplicativa      {fprintf(yyout, "Se encontro un + \n");}
                | expAditiva '-' expMultiplicativa      {fprintf(yyout, "Se encontro un - \n");}
;

expMultiplicativa: expConversion
                        |expMultiplicativa '/' expConversion    { if($<real>3 == 0){printf("ERROR AL DIVIDIR POR 0"); return 0;}else $<real>$ = $<real>1 / $<real>3; fprintf(yyout,"se encontro un / \n");}
                        |expMultiplicativa '*' expConversion    {fprintf(yyout, "Se encontro un * \n");}
                        |expMultiplicativa '%' expConversion    {fprintf(yyout, "Se encontro un % \n");}
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

incremento: P_INC               {fprintf(yyout, "Se encontro un ++ \n");} 
                | P_DEC         {fprintf(yyout, "Se encontro un -- \n");}
;

operUnario: '&' | '*' | '-' | '!' | '+' | '~'
;

expSufijo: expPrimaria
            | expSufijo '['expresion']'         {fprintf(yyout, "Se encontro [ y ] \n");}
            | expSufijo '('listaArgumentos')'   {fprintf(yyout, "Se encontro un ( y un )\n");}
            | expSufijo '.' ID                  {fprintf(yyout, "Se encontro un . \n"); /*fprintf(yyout, "Identificador = %s \n", $<texto>3);*/}
            | expSufijo FLECHITA ID             {fprintf(yyout, "Se encontro un -> \n"); /*fprintf(yyout, "Identificador = %s /n", $<texto>3);*/}
            | expSufijo P_INC                   {fprintf(yyout, "Se encontro un ++ \n");}
            | expSufijo P_DEC                   {fprintf(yyout, "Se encontro un -- \n");}
;

listaArgumentos: expresionAs
                | listaArgumentos ',' expresionAs
;

expPrimaria:    ID                      {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
                | NUMERO_ENTERO         {fprintf(yyout, "Num entero = %d \n",$<entero>1);}
                | NUMERO_REAL           {fprintf(yyout, "Num real = %f \n",$<real>1);}
                | LITERALCADENA         {fprintf(yyout, "String = %s \n",$<texto>1);}
                | '(' expresion ')'     {fprintf(yyout, "Se encontro un ( y un ) \n");}
;

nombreTipo: tipoDato | STRUCT | TYPEDEF | UNION | ENUM
;

tipoDato: CHAR
        |INT            {fprintf(yyout, "se encontro tipo de dato int \n");}
        |FLOAT
        |LONG
        |SHORT
        |SIGNED
        |UNSIGNED
        |VOID
        |ENUM
        |DOUBLE
;

ID: IDENTIFICADOR
        |IDENTIFICADOR '=' expresion
        |error  {printf("ERROR: falta ID \n");}
;

/*SENTENCIAS*/

sentencia:      sentExp                 {printf("Se declaro una sentencia expresion");}
                | sentCompuesta         {printf("Se declaro una sentencia compuesta");}
                | sentAsignacion        {printf("Se declaro una sentencia de asignacion");}
                | sentSeleccion         {printf("Se declaro una sentencia de seleccion");}
                | sentIteracion         {printf("Se declaro una sentencia de iteracion");}
                | sentEtiquetada        {printf("Se declaro una sentencia etiquetada");}
                | sentSalto             {printf("Se declaro una sentencia de salto");}
                | error                 {printf("ERROR AL DEFINIR LA SENTENCIA \n");}
;

//EXPRESION
sentExp: expresionOP ';'
        | error                         {printf("ERROR AL DEFINIR LA SENTENCIA \n");}
;

//COMPUESTA
sentCompuesta:  '{' listaDeclaracionesOP listaSentenciasOP '}' PCOp
                | '{' listaDeclaraciones '}' PCOp
                | '{' listaSentencias '}' PCOp
                | '{''}' PCOp
;

PCOp: /*na de na*/
        |';'
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
                                | error                         {printf("ERROR AL DEFINIR LA SENTENCIA \n");}
;

//SELECCION
sentSeleccion:  IF '(' expresion ')' sentencia                {fprintf(yyout, "Se utiliza el If \n");}
                | IF '(' expresion ')' ELSE sentencia       {fprintf(yyout,"Se utiliza el If Else \n");}
                | SWITCH '(' expresion ')' sentencia          {fprintf(yyout,"Se utiliza el Switch \n")}
                | error                                        {printf("ERROR AL DEFINIR LA EXPRESION \n");}
;

//ITERACION
sentIteracion:  WHILE '(' expresion ')' sentencia                                     {fprintf(yyout, "Se utiliza el While \n");}
                | DO sentencia WHILE '(' expresion ')'                              {fprintf(yyout, "Se utiliza el Do While \n");}
                | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia   {fprintf(yyout,"Se utiliza el for \n");}
;

//ETIQUETADA
sentEtiquetada: CASE expConst ':' sentencia                   {fprintf(yyout, "Se utiliza un Case \n");}
                | DEFAULT ':' sentencia                       {fprintf(yyout,"Se utiliza el Default \n");}
                | IDENTIFICADOR ':' sentencia                   {fprintf(yyout, "Identificador = %s \n",$<texto>1); fprintf(yyout, "se utiliza el : \n");}
;

//SALTO
sentSalto:      RETURN expresionOP ';'                        {fprintf(yyout,"Se utiliza el return \n");}
                | CONTINUE ';'                                {fprintf(yyout, "Se utiliza el Continue \n");}
                | BREAK ';'                                   {fprintf(yyout,"Se utiliza el Break \n");}
                | GOTO IDENTIFICADOR ';'                      {fprintf(yyout,"Se utiliza el Goto\n");}
;

expresionOP: /* na de na */
             | expresion 
;

//ASIGNACION
sentAsignacion: IDENTIFICADOR '=' expresion ';'                 {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
;


/*DECLARACIONES*/

declaracion:    espeDec listaDecOP ';'
;

listaDecOP:     /* na de na */
                |listaDecS
;

espeDec:        espeClasAlma espeDecOP 
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

inicializador:  expresionAs
                |'{' listInicial'}'
                |'{' listInicial comaOP '}'
;

comaOP: /* na de na */
        | ','
;

listInicial:    inicializador
                |listInicial ',' inicializador
;

espeClasAlma: TYPEDEF | STATIC | AUTO | REGISTER | EXTERN
;

espeTipo: nombreTipo
        | especificadorSU
        | especificadorE
        | nombreTypedef
;

caliTipo: CONST | VOLATILE
;

especificadorSU: SU IDENTIFICADOROP '{'listaDecS '}'    
                | SU IDENTIFICADOR                      {fprintf(yyout, "Identificador = %s \n",$<texto>2);}
;

IDENTIFICADOROP: /*na de na*/
                |IDENTIFICADOR                          {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
;

SU: STRUCT                                           {fprintf(yyout, "se utiliza un struct \n");}
        | UNION                                       {fprintf(yyout, "se utiliza un union \n");}
;

listaDecS: declaracionS
            | listaDecS declaracionS
;

declaracionS: listCali declaS ';'                       
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
            | puntero                           {fprintf(yyout, "Se declaro un Puntero \n");}
;

puntero: '*' listCaliTiposOP            
        |'*' listCaliTiposOP puntero
;

listCaliTiposOP: /*na de na*/
                |listCaliTipos
;

listCaliTipos: caliTipo
                |listCaliTipos caliTipo
;

decDirec: IDENTIFICADOR {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
        | '('decla')'
        | decDirec '[' expConstOP ']'
        | decDirec '(' listTipoPar ')'
        | decDirec '(' listIdenOP ')'
;

listIdenOP: /*na de na*/
        | listIden
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

listIden: IDENTIFICADOR         {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
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

constEnum: IDENTIFICADOR        {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
;

nombreTypedef: IDENTIFICADOR    {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
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

/*FUNCIONES*/
unidadDeTraduccion: decExterna
                        |unidadDeTraduccion decExterna
;

decExterna: defFuncion          {fprintf(yyout, "se declaro a la funcion %s \n",$<texto>1);}
                |declaracion
;

defFuncion: espeDecOP decla listaDeclaracionesOP sentCompuesta
;

%%

int main (){

  int flag;

  yyin = fopen("entrada.c", "r");
  yyout = fopen("salida.txt", "w");

  #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

  flag = yyparse ();
  fclose(yyin);
  fclose(yyout);
  return flag;
}