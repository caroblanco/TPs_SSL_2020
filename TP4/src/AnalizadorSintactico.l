%option noyywrap

%{
    #include <AnalizadorSintactico.tab.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    extern FILE* yyin;
    
%}

CARACTERES_PUNTUACION_OPERADORES "."|"+"|"-"|"!"|"*"|"/"|"%"|"["|"]"|"<"|">"|"^"|"?"|"="|","|":"|"{"|"}"|"("|")"|";"|"|"|"^"|"&"
 
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_HEXADECIMAL 0[xX][0-9A-Fa-f]+
CONSTANTE_REAL   [0-9]+"."[0-9]*([eE](\+|\-)?[0-9]+)?
CARACTER_LETRAS [a-zA-Z]

IDENTIFICADOR ({CARACTER_LETRAS}|_)({CARACTER_LETRAS}|[0-9]|_)*
LITERAL_CADENA \".+\"
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

{CONSTANTE_DECIMAL}                 { yyval.entero = strtol(yytext, NULL, 10); return NUMERO_ENTERO;    } 
{CONSTANTE_OCTAL}	                { yyval.entero = strtol(yytext, NULL, 8); return NUMERO_ENTERO;     }
{CONSTANTE_HEXADECIMAL}	            { yyval.entero = strtol(yytext, NULL, 16); return NUMERO_ENTERO;    }
{CONSTANTE_REAL}	                { yyval.real = strtof(yytext, NULL); return NUMERO_REAL;            }
{CARACTER}	                        { return yytext[0];                                                 }
{LITERAL_CADENA}                     { yylval.cadena = strdup(yytext); return STRING;                    }
"switch"                                {yylval.cadena = strdup(yytext); return SWITCH ;}
"case"                                  {yylval.cadena = strdup(yytext); return CASE ;}
"break"                                 {yylval.cadena = strdup(yytext); return BREAK ;}
"default"                               {yylval.cadena = strdup(yytext); return DEFAULT ;}
"continue"                              {yylval.cadena = strdup(yytext); return CONTINUE ;}
"do"                                    {yylval.cadena = strdup(yytext); return DO ;}
"while"                                 {yylval.cadena = strdup(yytext); return WHILE ;}
"if"                                    {yylval.cadena = strdup(yytext); return IF ;}
"else"                                  {yylval.cadena = strdup(yytext); return ELSE ;}
"for"                                   {yylval.cadena = strdup(yytext); return FOR ;}
"return"                                {yylval.cadena = strdup(yytext); return RETURN ;}
"goto"                                  {yylval.cadena = strdup(yytext); return GOTO ;}
"sizeof"                                {yylval.cadena = strdup(yytext); return SIZEOF ;}
"static"                                {yylval.cadena = strdup(yytext); return STATIC ;}
"extern"                                {yylval.cadena = strdup(yytext); return EXTERN ;}
"const"                                 {yylval.cadena = strdup(yytext); return CONST ;}
"volatile"                              {yylval.cadena = strdup(yytext); return VOLATILE ;}
"struct"                                {yylval.cadena = strdup(yytext); return STRUCT ;}
"union"                                 {yylval.cadena = strdup(yytext); return UNION ;}
"typedef"                               {yylval.cadena = strdup(yytext); return TYPEDEF ;}
"auto"                                  {yylval.cadena = strdup(yytext); return AUTO ;}
"register"                              {yylval.cadena = strdup(yytext); return REGISTER ;}
"char"                                  {yylval.cadena = strdup(yytext); return CHAR ;}
"int"                                   {yylval.cadena = strdup(yytext); return INT ;}
"float"                                 {yylval.cadena = strdup(yytext); return FLOAT ;}
"long"                                  {yylval.cadena = strdup(yytext); return LONG ;}
"short"                                 {yylval.cadena = strdup(yytext); return SHORT ;}
"signed"                                {yylval.cadena = strdup(yytext); return SIGNED ;}
"unsigned"                              {yylval.cadena = strdup(yytext); return UNSIGNED ;}
"void"                                  {yylval.cadena = strdup(yytext); return VOID ;}
"enum"                                  {yylval.cadena = strdup(yytext); return ENUM ;}
"double"                                {yylval.cadena = strdup(yytext); return DOUBLE ;}
{P_INC}                             { return P_INC;                                                     }
{P_DEC}                             { return p_DEC;                                                     }
{DISTINTO}                          { return DISTINTO;                                                  }
{IGUAL}                             { return IGUAL;                                                     }
{AND}                               { return AND;                                                       }
{OR}                                { return OR;                                                        }
{DIV_IGUAL}                         { return DIV_IGUAL                                                  }
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
