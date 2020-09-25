
%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    
%}

TIPO_DATO int|float|char|struct|double|long|unsigned|signed|short|void|enum|struct|typedef|union|const

CARACTERES_PUNTUACION_OPERADORES "["|"]"|"("|")"|"{"|"}"|","|";"|":"|"*"|"="|"#"|"!"|"%"|"^"|"&"|"–"|"+"|"|"|"~"|"'"|"<"|">"|"?"|"."|"/"|"=="|"||"|"+="|"-="|"~"|"&&"|"!="|"++"|"--"
 
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_HEXADECIMAL 0[xX][0-9A-Fa-f]+
CONSTANTE_REAL   [0-9]+"."[0-9]*([eE](\+|\-)?[0-9]+)?
CARACTER_LETRAS [a-zA-Z]

COMODIN .
SALTO_DE_LINEA \n

IDENTIFICADOR ({CARACTER_LETRAS}|_)({CARACTER_LETRAS}|[0-9]|_)*
LITERAL_CADENA \".+\"
ESPACIOS [" "|\t]*  

%%

{CONSTANTE_DECIMAL}                 { yyval.entero = strtol(yytext, NULL, 10); return NUMERO_ENTERO;    } 
{CONSTANTE_OCTAL}	                { yyval.entero = strtol(yytext, NULL, 8); return NUMERO_ENTERO;     }
{CONSTANTE_HEXADECIMAL}	            { yyval.entero = strtol(yytext, NULL, 16); return NUMERO_ENTERO;    }
{CONSTANTE_REAL}	                { yyval.real = strtof(yytext, NULL); return NUMERO_REAL;            }
{CARACTER}	                        { return yytext;                                                    }
{IDENTIFICADOR}                     { yyval.texto = yytext; return IDENTIFICADOR                        }
{TIPO_DATO}                         { yyval.texto = yytext; return TIPO_DATO                            }
{CARACTERES_PUNTUACION_OPERADORES}  { }
{ESPACIOS}+                         { }
{COMODIN}                           { }


%%
