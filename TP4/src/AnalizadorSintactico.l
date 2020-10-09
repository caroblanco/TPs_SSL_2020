%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #include "AnalizadorSintactico.tab.h"

    extern FILE* yyin;
    //mingw32-make
%}

CARACTERES_PUNTUACION_OPERADORES "."|"+"|"-"|"!"|"*"|"/"|"%"|"["|"]"|"<"|">"|"^"|"?"|"="|","|":"|"{"|"}"|"("|")"|";"|"|"|"^"|"&"
 
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_HEXADECIMAL 0[xX][0-9A-Fa-f]+
CONSTANTE_REAL   [0-9]+"."[0-9]*([eE](\+|\-)?[0-9]+)?
CARACTER_LETRAS [a-zA-Z]

IDENTIFICADOR ({CARACTER_LETRAS}|_)({CARACTER_LETRAS}|[0-9]|_)*
LITERALCADENA \".+\"
CARACTER \'.\'
ESPACIOS [" "|\t]*
COMENTARIO_LINEA "//".*
COMENTARIO_BLOQUE "/*"([^*]|\*+[^/])*\*+\/  

P_INC "++"
P_DEC "--"
DISTINTO "!="
IGUAL "=="
AND "&&"
OR "||"
DIV_IGUAL "/="
POR_IGUAL "*="
MENOS_IGUAL "-="
MAS_IGUAL "+="
MENOR_IGUAL "<="
MAYOR_IGUAL ">="
MOD_IGUAL "%="
BIT_SHIFT_R ">>"
BIT_SHIFT_L "<<"
FLECHITA "->"


COMODIN .
SALTO_DE_LINEA \n

%%

{CONSTANTE_DECIMAL}                 { yylval.entero = strtol(yytext, NULL, 10); return NUMERO_ENTERO;    } 
{CONSTANTE_OCTAL}	                { yylval.entero = strtol(yytext, NULL, 8); return NUMERO_ENTERO;     }
{CONSTANTE_HEXADECIMAL}	            { yylval.entero = strtol(yytext, NULL, 16); return NUMERO_ENTERO;    }
{CONSTANTE_REAL}	                { yylval.real = strtof(yytext, NULL); return NUMERO_REAL;            }
{CARACTER}	                        { return yytext[0];                                                 }
{LITERALCADENA}                    { yylval.texto = strdup(yytext); return LITERALCADENA;                    }
"switch"                                {yylval.texto = strdup(yytext); return SWITCH ;}
"case"                                  {yylval.texto = strdup(yytext); return CASE ;}
"break"                                 {yylval.texto = strdup(yytext); return BREAK ;}
"default"                               {yylval.texto = strdup(yytext); return DEFAULT ;}
"continue"                              {yylval.texto = strdup(yytext); return CONTINUE ;}
"do"                                    {yylval.texto = strdup(yytext); return DO ;}
"while"                                 {yylval.texto = strdup(yytext); return WHILE ;}
"if"                                    {yylval.texto = strdup(yytext); return IF ;}
"else"                                  {yylval.texto = strdup(yytext); return ELSE ;}
"for"                                   {yylval.texto = strdup(yytext); return FOR ;}
"return"                                {yylval.texto = strdup(yytext); return RETURN ;}
"goto"                                  {yylval.texto = strdup(yytext); return GOTO ;}
"sizeof"                                {yylval.texto = strdup(yytext); return SIZEOF ;}
"static"                                {yylval.texto = strdup(yytext); return STATIC ;}
"extern"                                {yylval.texto = strdup(yytext); return EXTERN ;}
"const"                                 {yylval.texto = strdup(yytext); return CONST ;}
"volatile"                              {yylval.texto = strdup(yytext); return VOLATILE ;}
"struct"                                {yylval.texto = strdup(yytext); return STRUCT ;}
"union"                                 {yylval.texto = strdup(yytext); return UNION ;}
"typedef"                               {yylval.texto = strdup(yytext); return TYPEDEF ;}
"auto"                                  {yylval.texto = strdup(yytext); return AUTO ;}
"register"                              {yylval.texto = strdup(yytext); return REGISTER ;}
"char"                                  {yylval.texto = strdup(yytext); return CHAR ;}
"int"                                   {yylval.texto = strdup(yytext); return INT ;}
"float"                                 {yylval.texto = strdup(yytext); return FLOAT ;}
"long"                                  {yylval.texto = strdup(yytext); return LONG ;}
"short"                                 {yylval.texto = strdup(yytext); return SHORT ;}
"signed"                                {yylval.texto = strdup(yytext); return SIGNED ;}
"unsigned"                              {yylval.texto = strdup(yytext); return UNSIGNED ;}
"void"                                  {yylval.texto = strdup(yytext); return VOID ;}
"enum"                                  {yylval.texto = strdup(yytext); return ENUM ;}
"double"                                {yylval.texto = strdup(yytext); return DOUBLE ;}
{P_INC}                             { return P_INC;                                                     }
{P_DEC}                             { return P_DEC;                                                     }
{DISTINTO}                          { return DISTINTO;                                                  }
{IGUAL}                             { return IGUAL;                                                     }
{AND}                               { return AND;                                                       }
{OR}                                { return OR;                                                        }
{DIV_IGUAL}                         { return DIV_IGUAL;                                                  }
{POR_IGUAL}                         { return POR_IGUAL;                                                 } 
{MENOS_IGUAL}                       { return MENOS_IGUAL;                                               }
{MAS_IGUAL}                         { return MAS_IGUAL;                                                 }
{MENOR_IGUAL}                       { return MENOR_IGUAL;                                               }
{MAYOR_IGUAL}                       { return MAYOR_IGUAL;                                               }
{MOD_IGUAL}                         { return MOD_IGUAL;                                                 }
{BIT_SHIFT_R}                       { return BIT_SHIFT_R;                                               }
{BIT_SHIFT_L}                       { return BIT_SHIFT_L;                                               }
{FLECHITA}                          { return FLECHITA;                                                  } 
{IDENTIFICADOR}                     { strcpy(yylval.texto, yytext); return IDENTIFICADOR;               }
{CARACTERES_PUNTUACION_OPERADORES}  { return yytext[0];                                                 }
{ESPACIOS}+                         {                                                                   }
{COMENTARIO_LINEA}                  {                                                                   }
{COMODIN}                           {                                                                   }

%%
