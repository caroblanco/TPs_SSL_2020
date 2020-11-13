%{
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.c"

extern int yylineno;
#define YYDEBUG 1

int yylex ();
int yyerror (char*);

unsigned count = 0;

FILE* yyin;
FILE* yyout;

char* tempVar = NULL;
char* tempPointer = NULL;
%}

%type <valorString> declarador_directo
%type <valorString> decla
%type <valorString> declarador
%type <valorString> especificadores_declaracion

%token <valorEntero> NUM_ENTERO
%token <valorReal> NUM_REAL
%token <valorString> TIPO_DATO
%token <valorString> ID
%token ASIG_MULT
%token ASIG_DIV
%token ASIG_MOD
%token ASIG_SUMA
%token ASIG_RESTA
%token ASIG_DESP_IZQ
%token ASIG_DESP_DER
%token ASIG_AND_BIN
%token ASIG_XOR_BIN
%token ASIG_OR_BIN
%token OP_INC
%token OP_DEC
%token OP_IGUALDAD
%token OP_DESIGUALDAD
%token OP_AND
%token OP_OR
%token OP_MENOR_IGUAL
%token OP_MAYOR_IGUAL
%token OP_DESP_IZQ
%token OP_DESP_DER
%token OP_MIEMBRO_PUNT

%token <valorString> CHAR
%token <valorString> STRING

%token SIZEOF
%token <valorString> CLASE_ALM
%token CALIF_TIPO
%token STRUCT_UNION
%token ENUM
%token <valorString> CONTINUE
%token <valorString> BREAK
%token <valorString> IF
%token <valorString> ELSE
%token <valorString> SWITCH
%token <valorString> FOR
%token <valorString> DO
%token <valorString> WHILE
%token <valorString> CASE
%token <valorString> DEFAULT
%token <valorString> RETURN 
%token <valorString> GOTO
%token <valorString> ERROR

%union {
  int    valorEntero;
  double valorReal;
  char*  valorString;
}

%%

input:   /* vacio */
       | input line
;

line:  /* Vacio */
      | declaracion ';' {tempVar = NULL; tempPointer = NULL;} 
     // | declaracionFunciones
      | sentencia
      //|ERROR {fprintf(yyout,"se encontro un error lexico: %s",$<valorString>1)}
;

const:   NUM_ENTERO
       | NUM_REAL  
       | CHAR      
       | const_enum
;

const_enum: ID 
;

expresion:   exp_asignacion
           | expresion ',' exp_asignacion
;

exp_asignacion:   exp_condicional
                | exp_unaria op_asignacion exp_asignacion
;

exp_condicional:   exp_OR_log
                 | exp_OR_log '?' expresion ':' exp_condicional
;

op_asignacion:   '='          
               | ASIG_MULT    
               | ASIG_DIV     
               | ASIG_MOD     
               | ASIG_SUMA    
               | ASIG_RESTA   
               | ASIG_DESP_IZQ
               | ASIG_DESP_DER
               | ASIG_AND_BIN 
               | ASIG_XOR_BIN 
               | ASIG_OR_BIN  
;

exp_OR_log:   exp_AND_log
            | exp_OR_log OP_OR exp_AND_log
;

exp_AND_log:   exp_OR_in
             | exp_AND_log OP_AND exp_OR_in
;

exp_OR_in:   exp_OR_ex
           | exp_OR_in '|' exp_OR_ex 
;

exp_OR_ex:   exp_AND
           | exp_OR_ex '^' exp_AND 
;

exp_AND:   exp_igualdad
         | exp_AND '&' exp_igualdad 
;

exp_igualdad:   exp_relacional
              | exp_igualdad OP_IGUALDAD    exp_relacional  
              | exp_igualdad OP_DESIGUALDAD exp_relacional  
;

exp_relacional:   exp_desp
                | exp_relacional      '<'       exp_desp  
                | exp_relacional      '>'       exp_desp  
                | exp_relacional OP_MENOR_IGUAL exp_desp  
                | exp_relacional OP_MAYOR_IGUAL exp_desp  
;

exp_desp:   exp_aditiva
          | exp_desp OP_DESP_IZQ exp_aditiva  
          | exp_desp OP_DESP_DER exp_aditiva  
;

exp_aditiva:   exp_multip
             | exp_aditiva '+' exp_multip   
             | exp_aditiva '-' exp_multip   
;

exp_multip:   exp_conversion
            | exp_multip '*' exp_conversion   
            | exp_multip '/' exp_conversion   
            | exp_multip '%' exp_conversion   
;

exp_conversion:   exp_unaria
                | '(' nombre_tipo ')' exp_conversion exp_unaria   
;

exp_unaria:   exp_sufijo
            | OP_INC exp_unaria           
            | OP_DEC exp_unaria           
            | op_unario exp_conversion
            | SIZEOF exp_unaria
            | SIZEOF '(' nombre_tipo ')'                        
;

op_unario:   '&'
           | '*' 
           | '+'
           | '-'
           | '~'
           | '!'
;

exp_sufijo:   exp_primaria
            | exp_sufijo '[' expresion ']'        
            | exp_sufijo '(' lista_argumentos ')'               
            | exp_sufijo '.' ID                   
            | exp_sufijo OP_MIEMBRO_PUNT ID       
            | exp_sufijo OP_INC                   
            | exp_sufijo OP_DEC                   
;

lista_argumentos:   exp_asignacion
                  | lista_argumentos ',' exp_asignacion
;

exp_primaria:   const
              | STRING              
              | '(' expresion ')'                              
;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

declaracionFunciones: TIPO_DATO ID '(' lista_parametros ')' ';' {printf("retorno %s\n", $<valorString>1); printf("se ejecuta esta poronga?\n");agregarFuncion($<valorString>2, $<valorString>1, listaVarTemp, yylineno); list_clean(listaVarTemp);}

lista_parametros: TIPO_DATO ID                          {  nuevoParametro($<valorString>2, $<valorString>1); }
               | lista_parametros ',' TIPO_DATO ID      {  nuevoParametro($<valorString>4, $<valorString>3); }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

declaracion:  especificadores_declaracion lista_declaradores  
;

especificadores_declaracion:   CLASE_ALM           especificadores_declaracion_opc  {$<valorString>$ = strdup($<valorString>1);}
                             | especificador_tipo  especificadores_declaracion_opc  {$<valorString>$ = strdup($<valorString>1);}
                             | CALIF_TIPO          especificadores_declaracion_opc  {$<valorString>$ = strdup($<valorString>1);}
;

especificadores_declaracion_opc:   /* Vacio */
                                 | especificadores_declaracion
;

lista_declaradores:   declarador                        {intentarAgregarVar($<valorString>1,tempVar,yylineno); }          
                    | declarador ',' lista_declaradores {intentarAgregarVar($<valorString>1,tempVar,yylineno); }
;

declarador:   decla                   {$<valorString>$ = strdup($<valorString>1);}
            | decla '=' inicializador {$<valorString>$ = strdup($<valorString>1);}
;

inicializador:   exp_asignacion
               | '{' lista_inicializadores coma_opc '}' 
;

coma_opc:   /* Vacio */
          | ','
;

lista_inicializadores:   inicializador
                       | lista_inicializadores ',' inicializador
;

especificador_tipo:   TIPO_DATO                   {tempVar = strdup($<valorString>1); printf("tempVar %s\n linea %d", tempVar, yylineno);}              
                    | especificador_struct_union
                    | especificador_enum  {/*Sacamos nombre_typedef*/}
;

especificador_struct_union:   STRUCT_UNION ID_opc '{' lista_declaradores_struct '}' 
                            | STRUCT_UNION ID
;

ID_opc:   /* Vacio */
        | ID
;

lista_declaradores_struct:   declaracion_struct
                           | lista_declaradores_struct declaracion_struct
;

declaracion_struct: lista_calificadores declaradores_struct ';'
;

lista_calificadores:   especificador_tipo lista_calificadores_opc
                     | CALIF_TIPO         lista_calificadores_opc
;

lista_calificadores_opc:   /* Vacio */
                         | lista_calificadores
;

declaradores_struct:   decla_struct
                     | declaradores_struct ',' decla_struct
;

decla_struct:   decla
              | decla_opc ':' exp_constante
;

decla_opc:   /* Vacio */
           | decla
;

exp_constante: exp_condicional
;

exp_constante_opc:   /* Vacio */
                   | exp_constante
;

decla: puntero_opc declarador_directo {$<valorString>$ = strdup($<valorString>2);}
;

puntero_opc:   /* Vacio */
             | puntero
;

puntero:   '*' lista_calificadores_tipos_opc
         | '*' lista_calificadores_tipos_opc puntero
;

lista_calificadores_tipos_opc:   /* Vacio */
                              | lista_calificadores_tipos
;

lista_calificadores_tipos:   CALIF_TIPO
                           | lista_calificadores_tipos CALIF_TIPO
;

declarador_directo:   ID                                                    {$<valorString>$ = strdup($<valorString>1);}
                    | '(' decla ')'                                         {$<valorString>$ = strdup($<valorString>2);}
                    | declarador_directo '[' exp_constante_opc ']'          {$<valorString>$ = strdup($<valorString>1);}
                    | declarador_directo '(' lista_tipos_param_opc ')'      {$<valorString>$ = strdup($<valorString>1);}
                    | declarador_directo '(' lista_identificadores_opc ')'  {$<valorString>$ = strdup($<valorString>1);}
;

lista_identificadores_opc:   /* Vacio */
                           | lista_identificadores
;

lista_tipos_param: lista_parametros
;

lista_parametros:   declaracion_parametro                               
                  | lista_parametros ',' declaracion_parametro          
;

declaracion_parametro:   especificadores_declaracion decla
                       | especificadores_declaracion declarador_abstracto_opc
;

declarador_abstracto_opc:   /* Vacio */
                          | declarador_abstracto
;

lista_identificadores:   ID
                       | lista_identificadores ',' ID
;

especificador_enum:   ENUM ID_opc '{' lista_enumeradores'}'
                    | ENUM ID
;

lista_enumeradores:   enumerador
                    | lista_enumeradores ',' enumerador
;

enumerador:   const_de_enumeracion
            | const_de_enumeracion '=' exp_constante
;

const_de_enumeracion: ID
;

nombre_tipo: lista_calificadores declarador_abstracto_opc
;

declarador_abstracto:   puntero
                      | puntero_opc declarador_abstracto_directo
;

declarador_abstracto_directo:   '(' declarador_abstracto ')'                                    {printf("ARRANCA LA FN? 366\n");}                             
                              | declarador_abstracto_directo_opc '['   exp_constante_opc   ']'
                              | declarador_abstracto_directo_opc '(' lista_tipos_param_opc ')' // la fn no es por aca rey
;

declarador_abstracto_directo_opc:   /* Vacio */
                                  | declarador_abstracto_directo
;

lista_tipos_param_opc:   /* Vacio */
                       | lista_tipos_param
;

sentencia:   sentencia_exp
           | sentencia_compuesta
           | sentencia_seleccion
           | sentencia_iteracion
           | sentencia_etiquetada
           | sentencia_salto
           | especificadores_declaracion decla sentencia_compuesta  {   printf("agregando funcion %s\n", $<valorString>2); 
                                                                        t_list* nueva = list_duplicate(listaVarTemp);
                                                                        mostrarLista(nueva);
                                                                        agregarFuncion($<valorString>2, $<valorString>1, nueva,yylineno);
                                                                        
                                                                        fprintf(yyout, "Se define la funcion: \'%s\' que devuelve: \'%s\'\n", $<valorString>2, $<valorString>1);
                                                                        }
;

sentencia_exp: expresion_opc ';'
;

expresion_opc:   /* Vacio */
               | expresion
;

sentencia_compuesta: '{' lista_compuesta '}'
;

lista_compuesta:   lista_declaraciones_opc lista_sentencias_opc
                 | lista_compuesta lista_declaraciones_opc lista_sentencias_opc
;

lista_declaraciones_opc:   /* Vacio */
                         | lista_declaraciones
;

lista_sentencias_opc:   /* Vacio */
                      | lista_sentencias
;

lista_declaraciones:   declaracion ';'
                     | lista_declaraciones declaracion ';'
;

lista_sentencias:   sentencia
                  | lista_sentencias sentencia
;


sentencia_seleccion:  IF '(' expresion ')' sentencia                                            {fprintf(yyout, "Se encontro la sentencia IF\n");}
                    | IF '(' expresion ')' sentencia ELSE sentencia                             {fprintf(yyout, "Se encontro la sentencia IF y ELSE\n");}
                    | SWITCH '(' expresion ')' sentencia                                        {fprintf(yyout, "Se encontro la sentencia SWITCH\n");}
;

sentencia_iteracion:  WHILE '(' expresion ')' sentencia                                         {fprintf(yyout, "Se encontro la sentencia WHILE\n");}                                         
                    | DO sentencia WHILE '(' expresion ')' ';'                                  {fprintf(yyout, "Se encontro la sentencia DO WHILE\n");}                                  
                    | FOR '(' for_opc ';' expresion_opc ';' expresion_opc ')' sentencia         {fprintf(yyout, "Se encontro la sentencia FOR\n");}
;

for_opc:   /* Vacio */
         | expresion
         | declaracion
;

sentencia_etiquetada:  CASE exp_constante ':' sentencia  
                     | DEFAULT ':' sentencia            
                     | ID ':' sentencia  
;  
 
sentencia_salto:  CONTINUE ';'                                                                  {fprintf(yyout, "Se encontro la sentencia CONTINUE\n");}
                | BREAK ';'                                                                     {fprintf(yyout, "Se encontro la sentencia BREAK\n");}
                | RETURN expresion_opc ';'                                                      {fprintf(yyout, "Se encontro la sentencia RETURN\n");}  
                | GOTO ID ';'                                                                   {fprintf(yyout, "Se encontro la sentencia GO TO\n");}               
;  



%%

int yyerror (char *mensaje)  /* Funcion de error */
{
  fprintf (yyout, "Error: %s\n", mensaje);
}

void main(){ 

        yyin = fopen("entrada.c", "r");
        yyout = fopen("Salida.txt", "w");
        
        iniciarListas(); 
        fprintf(yyout,"-------------------REPORTE-------------------\n\n");

        #ifdef BISON_DEBUG
                yydebug = 1;
        #endif
    
        yyparse();
        
//////
        mostrarTutti(); //archivo funciones.c
        fclose(yyin);
        fclose(yyout);
    
}