/*reconocer expresiones, declaraciones de variables, declaraciones de funciones, sentencias de distintos tipos y definiciones de funciones.
El mismo deberá tomar un archivo de texto como entrada (archivo fuente) y dar como salida en pantalla un reporte de variables declaradas 
indicando tipo de dato correspondiente, funciones declaradas, tipos sentencias encontradas a medida que realiza la lectura del archivo fuente. 
Deberá indicarse aquellas secuencias que no pertenezcan a ninguna categoría léxica o estructuras que no sean válidas sintácticamente.*/

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

void yyerror (char *smth) {
   fprintf ("encontre: %s\n", smth);
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
%token SIZEOF
%token ENUM

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

line:   '\n'                                    {fprintf(yyout,"\n");}
        | expresion '\n'                        {fprintf(yyout,"--------EXPRESION--------")}
        | sentencia '\n'                        {fprintf(yyout,"--------SENTENCIA--------")}
        | declaracion '\n'                      {fprintf(yyout,"--------DECLARACION--------")}
        | unidadDeTraduccion '\n'               {fprintf(yyout,"--------FUNCION--------")}
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

expAnd: expOInclusivo
        | expAnd AND expOInclusivo              {fprintf(yyout, "Se encontro un && \n");}
;

expOInclusivo: expOExcluyente
                |expOInclusivo '|' expOExcluyente       {fprintf(yyout, "Se encontro un | \n");}
;

expOExcluyente: expY
                |expOExcluyente '^' expY        {fprintf(yyout, "Se encontro un ^ \n");}
;

expY: expIgualdad
        |expY '&' expIgualdad                   {fprintf(yyout, "Se encontro un & \n");}
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
            | expSufijo '.' ID                  {fprintf(yyout, "Se encontro un . \n"); fprintf(yyout, "Identificador = %s \n", $<texto>3);}
            | expSufijo FLECHITA ID             {fprintf(yyout, "Se encontro un -> \n"); fprintf(yyout, "Identificador = %s /n", $<texto>3);}
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

nombreTipo: TIPO_DATO | "struct" | "typedef" | "union" | ENUM
;

ID: IDENTIFICADOR
        |IDENTIFICADOR '=' expresion
        |error  {printf("ERROR: falta ID \n");}
;

/*SENTENCIAS*/

sentencia:      sentExp
                | sentCompuesta         {printf("Se declaro una sentencia compuesta");}
                | sentAsignacion        {printf("Se declaro una sentencia de asignacion");}
                | sentSeleccion         {printf("Se declaro una sentencia de seleccion");}
                | sentIteracion         {printf("Se declaro una sentencia de iteracion");}
                | sentEtiquetada        {printf("Se declaro una sentencia etiquetada");}
                | sentSalto             {printf("Se declaro una sentencia de salto");}
                | error                 {printf("ERROR AL DECLARAR LA SENTENCIA \n");}
;

sentExp: expresionOP ';'
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

sentSeleccion:  "if" '(' expresion ')' sentencia                {fprintf(yyout, "Se utiliza el If \n");}
                | "if" '(' expresion ')' "else" sentencia       {fprintf(yyout,"Se utiliza el If Else \n");}
                | "switch" '(' expresion ')' sentencia          {fprintf(yyout,"Se utiliza el Switch \n")}
;

sentIteracion:  "while" '(' expresion ')' sentencia                                     {fprintf(yyout, "Se utiliza el While \n");}
                | "do" sentencia "while" '(' expresion ')'                              {fprintf(yyout, "Se utiliza el Do While \n");}
                | "for" '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia   {fprintf(yyout,"Se utiliza el for \n");}
;

sentEtiquetada: "case" expConst ':' sentencia                   {fprintf(yyout, "Se utiliza un Case \n");}
                | "default" ':' sentencia                       {fprintf(yyout,"Se utiliza el Default \n");}
                | IDENTIFICADOR ':' sentencia                   {fprintf(yyout, "Identificador = %s \n",$<texto>1); fprintf(yyout, "se utiliza el : \n");}
;

sentSalto:      "return" expresionOP ';'                        {fprintf(yyout,"Se utiliza el return \n");}
                | "continue" ';'                                {fprintf(yyout, "Se utiliza el Continue \n");}
                | "break" ';'                                   {fprintf(yyout,"Se utiliza el Break \n");}
                | "goto" IDENTIFICADOR ';'                      {fprintf(yyout,"Se utiliza el Goto\n");}
;

expresionOP: /* na de na */
             | expresion 
;

sentAsignacion: IDENTIFICADOR '=' expresion ';'                 {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
;


/*DECLARACIONES*/

declaracion:    espeDec listaDecOP  
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
                | SU IDENTIFICADOR                      {fprintf(yyout, "Identificador = %s \n",$<texto>2);}
;

IDENTIFICADOROP: /*na de na*/
                |IDENTIFICADOR                          {fprintf(yyout, "Identificador = %s \n",$<texto>1);}
;

SU: "struct"                                            {fprintf(yyout, "se utiliza un struct \n");}
        | "union"                                       {fprintf(yyout, "se utiliza un union \n");}
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
            | puntero                           {fprinf(yyout, "Se declaro un Puntero \n");}
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

  yyin = fopen("entrada.c", "r");
  yyout = fopen("salida.txt", "w");

  #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

  yyparse ();
  fclose(yyin);
  fclose(yyout);
}
