%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define YYDEBUG 1

int flag_error = 0; 

char* nombre;
char* tipodato;

extern FILE* yyin;
FILE* yyout;



int yylex();

int yywrap()
{
    return(1);
}

void yyerror (char *smth) {
   fprintf (yyout,"error sintactico = %s\n", smth);
}

%}

%token <entero> NUMERO_ENTERO
%token <real> NUMERO_REAL
%token <texto> IDENTIFICADOR
%token <texto> LITERALCADENA
%token <caracter> CARACTER
%token <entero> error

%type <texto> ID

%token ERRORLEXICO
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

input:  /* na de na */
        | input line
;

line:   '\n'                                    {fprintf(yyout,"\n");}
        | sentencia                             {fprintf(yyout,"--------SENTENCIA--------\n");}         
        | declaracion                           {fprintf(yyout,"--------DECLARACION--------\n");}
        | definicionFunciones                   {fprintf(yyout,"-------FUNCION--------\n");}
        | ERRORLEXICO                           {fprintf(yyout, "\nSE DETECTO UN ERROR LEXICO: %s \n", $<texto>1);}
;

/*EXPRESIONES*/

expresion: expresionAs                                         {fprintf(yyout,"-------EXPRESION--------\n");}
        |expresion ';' expresionAs                              {fprintf(yyout,"-------EXPRESION--------\n");}
;

expresionAs:      expUnaria operadorAs expresionAs      
                | expCondicional                        
                | error                                 
;

operadorAs: '=' | DIV_IGUAL | POR_IGUAL | MENOS_IGUAL | MAS_IGUAL | MOD_IGUAL 
;

expCondicional: expOr
                | expOrOP expresion ':' expCondicional          {fprintf(yyout, "Se utiliza un : \n");}
;

expOr:  expAnd
        | expOr OR expAnd                       {fprintf(yyout, "Se utiliza un || \n");}
;

expOrOP: /* na de na */
|         | expOr
;

expAnd: expIgualdad
        | expAnd AND expIgualdad             {fprintf(yyout, "Se utiliza un && \n");}
;

expIgualdad:    expRelacional
                | expIgualdad IGUAL expRelacional       {fprintf(yyout, "Se utiliza un == \n");}
                | expIgualdad DISTINTO expRelacional    {fprintf(yyout, "Se utiliza un != \n");}
;            
expRelacional:  expAditiva
                | expRelacional MAYOR_IGUAL expAditiva  {fprintf(yyout, "Se utiliza un >= \n");}
                | expRelacional '>' expAditiva          {fprintf(yyout, "Se utiliza un > \n");}
                | expRelacional MENOR_IGUAL expAditiva  {fprintf(yyout, "Se utiliza un <= \n");}
                | expRelacional '<' expAditiva          {fprintf(yyout, "Se utiliza un >= \n");}
;

/*expCorrimiento: expAditiva
                |expCorrimiento BIT_SHIFT_L expAditiva          {fprintf(yyout, "Se utiliza un << \n");}
                |expAditiva BIT_SHIFT_R expCorrimiento          {fprintf(yyout, "Se utiliza un >> \n");}
;*/
                
expAditiva:     expMultiplicativa
                | expAditiva '+' expMultiplicativa      {fprintf(yyout, "Se utiliza un + \n");}
                | expAditiva '-' expMultiplicativa      {fprintf(yyout, "Se utiliza un - \n");}
;

expMultiplicativa: expConversion
                        |expMultiplicativa '/' expConversion    { if($<real>3 == 0){printf("ERROR AL DIVIDIR POR 0"); return 0;}else $<real>$ = $<real>1 / $<real>3; fprintf(yyout,"se utiliza un / \n");}
                        |expMultiplicativa '*' expConversion    {fprintf(yyout, "Se utiliza un * \n");}
                        |expMultiplicativa '%' expConversion    {fprintf(yyout, "Se utiliza un % \n");}  
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

incremento: P_INC               {fprintf(yyout, "Se utiliza un ++ \n");} 
                | P_DEC         {fprintf(yyout, "Se utiliza un -- \n");}        
;

operUnario: '&' | '*' | '-' | '!' | '+' | '~'
;

expSufijo: expPrimaria                          
            | expSufijo '['expresion']'         {fprintf(yyout, "Se utiliza [ y ] \n");}
            | expSufijo '('listaArgumentos')'   {fprintf(yyout, "Se utiliza un ( y un )\n");}
            | expSufijo '.' ID                  {fprintf(yyout, "Se utiliza un . \n");}
            | expSufijo FLECHITA ID             {fprintf(yyout, "Se utiliza un -> \n");}
            | expSufijo P_INC                   {fprintf(yyout, "Se utiliza un ++ \n");}
            | expSufijo P_DEC                   {fprintf(yyout, "Se utiliza un -- \n");}               
;

listaArgumentos: expresionAs
                | listaArgumentos ',' expresionAs
;

expPrimaria:    ID                      {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
                | NUMERO_ENTERO         {fprintf(yyout, "Num entero = %d \n",$<entero>1);}
                | NUMERO_REAL           {fprintf(yyout, "Num real = %f \n",$<real>1);}
                | LITERALCADENA         {fprintf(yyout, "String = %s \n",$<texto>1);}
                | '(' expresion ')'     
;

nombreTipo: tipoDato | STRUCT | TYPEDEF | UNION | ENUM
;

tipoDato: CHAR           {tipodato = strdup($<texto>1);}
        |INT            {tipodato = strdup($<texto>1);}
        |FLOAT          {tipodato = strdup($<texto>1);}
        |LONG           {tipodato = strdup($<texto>1);}
        |SHORT          {tipodato = strdup($<texto>1);}
        |SIGNED         {tipodato = strdup($<texto>1);}
        |UNSIGNED        {tipodato = strdup($<texto>1);}
        |VOID           {tipodato = strdup($<texto>1);}
        |ENUM           {tipodato = strdup($<texto>1);}
        |DOUBLE         {tipodato = strdup($<texto>1);}
;

ID: IDENTIFICADOR
        |IDENTIFICADOR '=' expresion
;

/*SENTENCIAS*/

sentencia:      sentExp                 {fprintf(yyout,"Se declaro una sentencia expresion \n");}
                | sentCompuesta         
                | sentAsignacion        {fprintf(yyout,"Se declaro una sentencia de asignacion\n");}
                | sentSeleccion         {fprintf(yyout,"Se declaro una sentencia de seleccion\n");}
                | sentIteracion         {fprintf(yyout,"Se declaro una sentencia de iteracion\n");}
                | sentEtiquetada        {fprintf(yyout,"Se declaro una sentencia etiquetada\n");}
                | sentSalto             {fprintf(yyout,"Se declaro una sentencia de salto\n");}
                | error                 {fprintf(yyout,"ERROR AL DEFINIR LA SENTENCIA \n");}
;

//EXPRESION
sentExp: expresionOP ';'                
        | error                         {fprintf(yyout,"falta ; en la definicion de la sentencia de expresion \n");}
;

//COMPUESTA
sentCompuesta:  '{' listaDeclaracionesOP listaSentenciasOP '}' PCOp     {fprintf(yyout,"Se declaro una sentencia compuesta\n");}
                | '{' listaDeclaraciones '}' PCOp                       {fprintf(yyout,"Se declaro una sentencia compuesta\n");}
                | '{' listaSentencias '}' PCOp                          {fprintf(yyout,"Se declaro una sentencia compuesta\n");}
                | '{''}' PCOp                                           {fprintf(yyout,"Se declaro una sentencia compuesta\n");}
                | error                                                 {fprintf(yyout, "error al declarar la sentencia compuesta\n");}
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
sentSeleccion:  IF '(' expresion ')' sentencia                          {fprintf(yyout, "Se utiliza el If \n");}
                | IF '(' expresion ')' sentencia ELSE sentencia         {fprintf(yyout,"Se utiliza el If Else \n");}
                | SWITCH '(' expresion ')' sentencia                    {fprintf(yyout,"Se utiliza el Switch \n")}
                |IF error                                               {fprintf(yyout,"ERROR SINTACTICO EN EL IF\n");}
                |SWITCH error                                           {fprintf(yyout, "ERROR SINTACTICO EN EL SWITCH\n");}
;

//ITERACION
sentIteracion:  WHILE '(' expresion ')' sentencia                                       {fprintf(yyout, "Se utiliza el While \n");}
                | DO sentencia WHILE '(' expresion ')'                                  {fprintf(yyout, "Se utiliza el Do While \n");}
                | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia     {fprintf(yyout,"Se utiliza el For \n");}
                | WHILE error                                                           {fprintf(yyout, "ERROR SINTACTICO EN EL WHILE\n");}
                | DO error                                                              {fprintf(yyout, "ERROR SINTACTICO EN EL DO\n");}
                |FOR error                                                              {fprintf(yyout, "ERROR SINTACTICO EN EL FOR\n");}
;

//ETIQUETADA
sentEtiquetada: CASE expConst ':' sentencia                   {fprintf(yyout, "Se utiliza un Case \n");}
                | DEFAULT ':' sentencia                       {fprintf(yyout,"Se utiliza el Default \n");}
                | IDENTIFICADOR ':' sentencia                 
                |CASE error                                     {fprintf(yyout, "ERROR SINTACTICO EN EL CASE\n");}
                | DEFAULT error                                 {fprintf(yyout, "ERROR SINTACTICO EN EL DEFAULT\n");}
;
expConst: expCondicional
;
//SALTO
sentSalto:      RETURN expresionOP ';'                        {fprintf(yyout,"Se utiliza el return \n");}
                | CONTINUE ';'                                {fprintf(yyout, "Se utiliza el Continue \n");}
                | BREAK ';'                                   {fprintf(yyout,"Se utiliza el Break \n");}
                | GOTO IDENTIFICADOR ';'                      {fprintf(yyout,"Se utiliza el Goto\n");}
                |GOTO error                                     {fprintf(yyout, "ERROR SINTACTICO EN EL GOTO, mal identificador\n");}
                |BREAK error                                    {fprintf(yyout, "ERROR SINTACTICO EN EL BREAK, falta ;\n");}
                | CONTINUE error                                {fprintf(yyout, "ERROR SINTACTICO EN EL CONTINUE, falta ;\n");}
                |RETURN error                                   {fprintf(yyout, "ERROR SINTACTICO EN EL RETURN, falta ;\n");}
;

expresionOP: /* na de na */
             | expresion 
;

//ASIGNACION
sentAsignacion: IDENTIFICADOR '=' expresion ';' 
;

/*DECLARACIONES*/
declaracion: declaracionVariablesSimples  
            | declaracionFunciones
;

declaracionVariablesSimples: tipoDato listaVariablesSimples ';' {fprintf(yyout,"se declaro una variable de tipo %s llamada %s\n", tipodato,nombre);}
                                | error                         {fprintf(yyout,"Falta el ; en la declaracion \n"); } 
;

listaVariablesSimples: variableSimple       
                     | listaVariablesSimples ',' variableSimple
;

variableSimple: IDENTIFICADOR opcionInicializacion { nombre = strdup($<texto>1); }
;

opcionInicializacion:   /* vacio */
                     | operadorAs constante 
;

constante: NUMERO_ENTERO        {fprintf(yyout,"num = %d\n",$<entero>1);}
        | NUMERO_REAL           {fprintf(yyout,"float = %f\n",$<real>1);}
        | CARACTER              {fprintf(yyout,"caracter = %c \n", $<caracter>1);}
        | LITERALCADENA         {fprintf(yyout,"literal = %s \n", $<texto>1);}
        | expresionAs
;

//FUNCIONES
declaracionFunciones: tipoDato IDENTIFICADOR '(' opcionArgumentosConTipo ')'  {fprintf(yyout,"se declara una funcion de tipo %s llamada %s\n",tipodato, $<texto>2);}
;

opcionArgumentosConTipo:        /* vacio */ 
                                | tipoDato opcionReferencia IDENTIFICADOR
                                | tipoDato opcionReferencia IDENTIFICADOR ',' argumentosConTipo 
;

argumentosConTipo: tipoDato opcionReferencia IDENTIFICADOR
                 | tipoDato opcionReferencia IDENTIFICADOR ',' argumentosConTipo
;

opcionReferencia: /* vacio */
                  | '&'
;

definicionFunciones: tipoDato IDENTIFICADOR '(' opcionArgumentosConTipo ')' sentencia   {fprintf(yyout,"se define una funcion de tipo %s llamada %s\n",tipodato, $<texto>2);}
                        |error {fprintf(yyout,"ERROR AL DEFINIR LA FUNCION\n");}
;


%%

int main (){

  int flag;

  yyin = fopen("entrada.c", "r");
  yyout = fopen("salida.txt", "w");

  fprintf(yyout,"-------------------REPORTE-------------------\n\n");
  #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

  flag = yyparse ();
  fprintf(yyout,"\n\n-------------finalizo el analisis----------\n:)");
  fclose(yyin);
  fclose(yyout);
  return flag;
}