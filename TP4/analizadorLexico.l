%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    
%}

TIPO_DATO int|float|char|struct|double|long|unsigned|signed|short|void|enum|struct|typedef|union|const
ESTRUCTURAS switch|case|break|default|continue|do|while|if|else|for|return|goto

CARACTERES_PUNTUACION_OPERADORES "["|"]"|"("|")"|"{"|"}"|","|";"|":"|"*"|"="|"#"|"!"|"%"|"^"|"&"|"–"|"+"|"|"|"~"|"'"|"<"|">"|"?"|"."|"/"|"~"
 
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_HEXADECIMAL 0[xX][0-9A-Fa-f]+
CONSTANTE_REAL   [0-9]+"."[0-9]*([eE](\+|\-)?[0-9]+)?
CARACTER_LETRAS [a-zA-Z]

COMODIN .
SALTO_DE_LINEA \n

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

%%

{CONSTANTE_DECIMAL}                 { yyval.entero = strtol(yytext, NULL, 10); return NUMERO_ENTERO;    } 
{CONSTANTE_OCTAL}	                { yyval.entero = strtol(yytext, NULL, 8); return NUMERO_ENTERO;     }
{CONSTANTE_HEXADECIMAL}	            { yyval.entero = strtol(yytext, NULL, 16); return NUMERO_ENTERO;    }
{CONSTANTE_REAL}	                { yyval.real = strtof(yytext, NULL); return NUMERO_REAL;            }
{CARACTER}	                        { return yytext[0];                                                 }
{IDENTIFICADOR}                     { strcpy(yylval.texto, yytext); return IDENTIFICADOR;               }
{TIPO_DATO}                         { strcpy(yylval.texto, yytext); return TIPO_DATO;                   }
{ESTRUCTURAS}                       { strcpy(yylval.texto, yytext); return ESTRUCTURAS;                 }
{CARACTERES_PUNTUACION_OPERADORES}  { return yytext[0];                                                 }
{ESPACIOS}+                         {                                                                   }
{COMODIN}                           {                                                                   }
{COMENTARIO_LINEA}                  {                                                                   }
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
.                                   {                                                                   }

%%
