%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.c"

#define YYDEBUG 1

int flag_error = 0; 

char* nombre;
char* tipodato;
extern int yylineno;
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
        | ERRORLEXICO                           {fprintf(yyout, "\n SE DETECTO UN ERROR LEXICO: %s \n", $<texto>1);}
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
                | expOrOP expresion ':' expCondicional          {fprintf(yyout, "Se utiliza un :  en la linea %d\n",yylineno);}
;

expOr:  expAnd
        | expOr OR expAnd                       {fprintf(yyout, "Se utiliza un || en la linea %d\n",yylineno);}
;

expOrOP: /* na de na */
|         | expOr
;

expAnd: expIgualdad
        | expAnd AND expIgualdad             {fprintf(yyout, "Se utiliza un && en la linea %d\n",yylineno);}
;

expIgualdad:    expRelacional
                | expIgualdad IGUAL expRelacional       {fprintf(yyout, "Se utiliza un == en la linea %d\n",yylineno);}
                | expIgualdad DISTINTO expRelacional    {fprintf(yyout, "Se utiliza un != en la linea %d\n",yylineno);}
;            
expRelacional:  expAditiva
                | expRelacional MAYOR_IGUAL expAditiva  {fprintf(yyout, "Se utiliza un >= en la linea %d\n",yylineno);}
                | expRelacional '>' expAditiva          {fprintf(yyout, "Se utiliza un > en la linea %d\n",yylineno);}
                | expRelacional MENOR_IGUAL expAditiva  {fprintf(yyout, "Se utiliza un <= en la linea %d\n",yylineno);}
                | expRelacional '<' expAditiva          {fprintf(yyout, "Se utiliza un >= en la linea %d\n",yylineno);}
;

/*expCorrimiento: expAditiva
                |expCorrimiento BIT_SHIFT_L expAditiva          {fprintf(yyout, "Se utiliza un << en la linea %d\n",yylineno);}
                |expAditiva BIT_SHIFT_R expCorrimiento          {fprintf(yyout, "Se utiliza un >> en la linea %d\n",yylineno);}
;*/
                
expAditiva:     expMultiplicativa
                | expAditiva '+' expMultiplicativa      {fprintf(yyout, "Se utiliza un + en la linea %d\n",yylineno);}
                | expAditiva '-' expMultiplicativa      {fprintf(yyout, "Se utiliza un - en la linea %d\n",yylineno);}
;

expMultiplicativa: expConversion
                        |expMultiplicativa '/' expConversion    { if($<real>3 == 0){printf("ERROR AL DIVIDIR POR 0"); return 0;}else $<real>$ = $<real>1 / $<real>3; fprintf(yyout,"se utiliza un / \n");}
                        |expMultiplicativa '*' expConversion    {fprintf(yyout, "Se utiliza un * en la linea %d\n",yylineno);}
                        |expMultiplicativa '%' expConversion    {fprintf(yyout, "Se utiliza un % en la linea %d\n",yylineno);}  
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

incremento: P_INC               {fprintf(yyout, "Se utiliza un ++ en la linea %d\n",yylineno);} 
                | P_DEC         {fprintf(yyout, "Se utiliza un -- en la linea %d\n",yylineno);}        
;

operUnario: '&' | '*' | '-' | '!' | '+' | '~'
;

expSufijo: expPrimaria                          
            | expSufijo '['expresion']'         {fprintf(yyout, "Se utiliza [ y ] en la linea %d\n",yylineno);}
            | expSufijo '('listaArgumentos')'   {fprintf(yyout, "Se utiliza un ( y un ) en la linea %d\n",yylineno);}
            | expSufijo '.' ID                  {fprintf(yyout, "Se utiliza un . en la linea %d\n",yylineno);}
            | expSufijo FLECHITA ID             {fprintf(yyout, "Se utiliza un -> en la linea %d\n",yylineno);}
            | expSufijo P_INC                   {fprintf(yyout, "Se utiliza un ++ en la linea %d\n",yylineno);}
            | expSufijo P_DEC                   {fprintf(yyout, "Se utiliza un -- en la linea %d\n",yylineno);}               
;

listaArgumentos: expresionAs
                | listaArgumentos ',' expresionAs
;

expPrimaria:    ID                      {fprintf(yyout, "Identificador = %s  en la linea %d\n",$<texto>1,yylineno);}
                | NUMERO_ENTERO         {fprintf(yyout, "Num entero = %d en la linea %d\n",$<entero>1,yylineno);}
                | NUMERO_REAL           {fprintf(yyout, "Num real = %f en la  linea %d\n",$<real>1,yylineno);}
                | LITERALCADENA         {fprintf(yyout, "String = %s en la linea %d\n",$<texto>1,yylineno);}
                | '(' expresion ')'     
;

nombreTipo: tipoDato | STRUCT | TYPEDEF | UNION | ENUM
;

tipoDato: CHAR          {tipodato = strdup($<texto>1);}
        |INT            {tipodato = strdup($<texto>1);}
        |FLOAT          {tipodato = strdup($<texto>1);}
        |LONG           {tipodato = strdup($<texto>1);}
        |SHORT          {tipodato = strdup($<texto>1);}
        |SIGNED         {tipodato = strdup($<texto>1);}
        |UNSIGNED       {tipodato = strdup($<texto>1);}
        |VOID           {tipodato = strdup($<texto>1);}
        |ENUM           {tipodato = strdup($<texto>1);}
        |DOUBLE         {tipodato = strdup($<texto>1);}
;

ID: IDENTIFICADOR
        |IDENTIFICADOR '=' expresion
;

/*SENTENCIAS*/

sentencia:      sentExp                 {fprintf(yyout,"Se declaro una sentencia expresion en la linea %d\n", yylineno);}
                | sentCompuesta         
                | sentAsignacion        {fprintf(yyout,"Se declaro una sentencia de asignacion en la linea %d\n", yylineno);}
                | sentSeleccion         {fprintf(yyout,"Se declaro una sentencia de seleccion en la linea %d\n", yylineno);}
                | sentIteracion         {fprintf(yyout,"Se declaro una sentencia de iteracion en la linea %d\n", yylineno);}
                | sentEtiquetada        {fprintf(yyout,"Se declaro una sentencia etiquetada en la linea %d\n", yylineno);}
                | sentSalto             {fprintf(yyout,"Se declaro una sentencia de salto en la linea %d\n", yylineno);}
                | error                 {fprintf(yyout,"ERROR AL DEFINIR LA SENTENCIA EN LA LINEA %d\n",yylineno);}
;

//EXPRESION
sentExp: expresionOP ';'                
        | error                         {fprintf(yyout,"falta ; en la definicion de la sentencia de expresion en la linea %d\n", yylineno);}
;

//COMPUESTA
sentCompuesta:  '{' listaDeclaracionesOP listaSentenciasOP '}' PCOp     {fprintf(yyout,"Se declaro una sentencia compuesta en la linea %d\n", yylineno);}
                | '{' listaDeclaraciones '}' PCOp                       {fprintf(yyout,"Se declaro una sentencia compuesta en la linea %d\n", yylineno);}
                | '{' listaSentencias '}' PCOp                          {fprintf(yyout,"Se declaro una sentencia compuesta en la linea %d\n", yylineno);}
                | '{''}' PCOp                                           {fprintf(yyout,"Se declaro una sentencia compuesta en la linea %d\n", yylineno);}
                | error                                                 {fprintf(yyout, "error al declarar la sentencia compuesta en la linea %d\n", yylineno);}
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
                        | error                         {printf("ERROR AL DEFINIR LA SENTENCIA EN LA LINEA %d\n", yylineno);}
;

//SELECCION
sentSeleccion:  IF '(' expresion ')' sentencia                          {fprintf(yyout, "Se utiliza el If en la linea %d\n", yylineno);}
                | IF '(' expresion ')' sentencia ELSE sentencia         {fprintf(yyout,"Se utiliza el If Else en la linea %d\n", yylineno);}
                | SWITCH '(' expresion ')' sentencia                    {fprintf(yyout,"Se utiliza el Switch en la linea %d\n", yylineno)}
                |IF error                                               {fprintf(yyout,"ERROR SINTACTICO EN EL IF en la linea %d\n", yylineno);}
                |SWITCH error                                           {fprintf(yyout, "ERROR SINTACTICO EN EL SWITCH en la linea %d\n", yylineno);}
;

//ITERACION
sentIteracion:  WHILE '(' expresion ')' sentencia                                       {fprintf(yyout, "Se utiliza el While en la linea %d\n", yylineno);}
                | DO sentencia WHILE '(' expresion ')'                                  {fprintf(yyout, "Se utiliza el Do While en la linea %d\n", yylineno);}
                | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia     {fprintf(yyout,"Se utiliza el For en la linea %d\n", yylineno);}
                | WHILE error                                                           {fprintf(yyout, "ERROR SINTACTICO EN EL WHILE en la linea %d\n", yylineno);}
                | DO error                                                              {fprintf(yyout, "ERROR SINTACTICO EN EL DO en la linea %d\n", yylineno);}
                |FOR error                                                              {fprintf(yyout, "ERROR SINTACTICO EN EL FOR en la linea %d\n", yylineno);}
;

//ETIQUETADA
sentEtiquetada: CASE expConst ':' sentencia                   {fprintf(yyout, "Se utiliza un Case en la linea %d\n", yylineno);}
                | DEFAULT ':' sentencia                       {fprintf(yyout,"Se utiliza el Default en la linea %d\n", yylineno);}
                | IDENTIFICADOR ':' sentencia                 
                |CASE error                                     {fprintf(yyout, "ERROR SINTACTICO EN EL CASE en la linea %d\n", yylineno);}
                | DEFAULT error                                 {fprintf(yyout, "ERROR SINTACTICO EN EL DEFAULT en la linea %d\n", yylineno);}
;
expConst: expCondicional
;
//SALTO
sentSalto:      RETURN expresionOP ';'                        {fprintf(yyout,"Se utiliza el return en la linea %d\n", yylineno);}
                | CONTINUE ';'                                {fprintf(yyout, "Se utiliza el Continue en la linea %d\n", yylineno);}
                | BREAK ';'                                   {fprintf(yyout,"Se utiliza el Break en la linea %d\n", yylineno);}
                | GOTO IDENTIFICADOR ';'                      {fprintf(yyout,"Se utiliza el Goto en la linea %d\n", yylineno);}
                |GOTO error                                   {fprintf(yyout, "ERROR SINTACTICO EN EL GOTO, mal identificador en la linea %d\n", yylineno);}
                |BREAK error                                  {fprintf(yyout, "ERROR SINTACTICO EN EL BREAK, falta ; en la linea %d\n", yylineno);}
                | CONTINUE error                              {fprintf(yyout, "ERROR SINTACTICO EN EL CONTINUE, falta ; en la linea %d\n", yylineno);}
                |RETURN error                                 {fprintf(yyout, "ERROR SINTACTICO EN EL RETURN, falta ; en la linea %d\n", yylineno);}
;

expresionOP: /* na de na */
             | expresion 
;

//ASIGNACION
sentAsignacion: IDENTIFICADOR '=' expresion ';' 
;

/*DECLARACIONES*/
declaracion: declaracionVariablesSimples  
            | declaracionFunciones ';'
;

declaracionVariablesSimples: tipoDato listaVariablesSimples ';' {if(agregarVariable(nombre, tipodato)) 
                                                                        printf("se declaro una variable de tipo %s llamada %s en la linea %d\n", tipodato,nombre, yylineno);
                                                                else{
                                                                        printf("que queres declarar papichulo? ya existe eso\n");
                                                                        agregarError("que queres declarar papichulo? ya existe eso", "semantico", yylineno);
   
                                                                }}
                                | error                         {fprintf(yyout,"Falta el ; en la declaracion en la linea %d\n", yylineno);
                                                                        agregarError("te olvidaste el ; en la linea %d capoeira", "sintactico", yylineno);
                                                                         } 
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
declaracionFunciones: tipoDato IDENTIFICADOR '(' opcionArgumentosConTipo ')'    {
                                                                                        nuevaFuncion(tipodato, $<texto>2);
                                                                                        fprintf(yyout,"se declara una funcion de tipo %s llamada %s en la linea %d\n",tipodato, $<texto>2,yylineno);
                                                                                }
;

opcionArgumentosConTipo:        /* vacio */ 
                                | tipoDato opcionReferencia IDENTIFICADOR                       {agregarParametro(tipodato, $<texto>2, $<texto>3)}
                                | tipoDato opcionReferencia IDENTIFICADOR ',' argumentosConTipo {agregarParametro(tipodato, $<texto>2, $<texto>3)}
;

argumentosConTipo: tipoDato opcionReferencia IDENTIFICADOR                                      {agregarParametro(tipodato, $<texto>2, $<texto>3)}
                 | tipoDato opcionReferencia IDENTIFICADOR ',' argumentosConTipo                {agregarParametro(tipodato, $<texto>2, $<texto>3)}
;

opcionReferencia: /* vacio */
                  | '&'
;

definicionFunciones: tipoDato IDENTIFICADOR '(' opcionArgumentosConTipo ')' sentencia   {
        fprintf(yyout,"se define una funcion de tipo %s llamada %s\n",tipodato, $<texto>2);
        }
                     |error {fprintf(yyout,"ERROR AL DEFINIR LA FUNCION\n");}
;
%%
int main (){
 
  int flag;
  iniciarListas(); //archivo funciones.c
  yyin = fopen("entrada.c", "r");
  yyout = fopen("salida.txt", "w");

  fprintf(yyout,"-------------------REPORTE-------------------\n\n");
  #ifdef BISON_DEBUG
       yydebug = 1;
  #endif

  flag = yyparse ();
  fprintf(yyout,"\n\n-------------finalizo el analisis----------\n=)");
  fclose(yyin);
  fclose(yyout);
  mostrarTutti(); //archivo funciones.c
  return flag;
}