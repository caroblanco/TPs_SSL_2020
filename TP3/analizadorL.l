%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #include "caro.c"

    int linea = 1;
    
%}

TIPO_DE_DATO int|float|char|struct|double|long|unsigned|signed|short|void|enum|struct|typedef|union|const
ESTRUCTURAS_DE_CONTROL switch|case|do|while|break|default|if|else|for|return|continue|goto
OTROS volatile|extern|static|auto|register

CARACTERES_PUNTUACION_OPERADORES "["|"]"|"("|")"|"{"|"}"|","|";"|":"|"*"|"="|"#"|"!"|"%"|"^"|"&"|"–"|"+"|"|"|"~"|"'"|"<"|">"|"?"|"."|"/"|"=="|"||"|"+="|"-="|"~"|"&&"|"!="|"++"|"--"
 
CONSTANTE_DECIMAL [1-9][0-9]*
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_HEXADECIMAL 0[xX][0-9A-Fa-f]+
CONSTANTE_REAL   [0-9]+"."[0-9]*([eE](\+|\-)?[0-9]+)?
CARACTER_LETRAS [a-zA-Z]
COMENTARIO_LINEA "//".*
COMENTARIO_BLOQUE "/*"([^*]|\*+[^/])*\*+\/
COMODIN .
SALTO_DE_LINEA \n
PALABRAS_RESERVADAS {TIPO_DE_DATO}|{ESTRUCTURAS_DE_CONTROL}|{OTROS}
IDENTIFICADOR ({CARACTER_LETRAS}|_)({CARACTER_LETRAS}|[0-9]|_)*
LITERAL_CADENA \".+\"
CARACTER \'.\'

%%

{CONSTANTE_DECIMAL}         { 
                                insertarLista(yytext,linea,&listaDeDecimales);
                            } 
{CONSTANTE_OCTAL}	        {
                                insertarLista(yytext,linea,&listaDeOctales);
                            }
{CONSTANTE_HEXADECIMAL}	    {
                                insertarLista(yytext,linea,&listaDeHexadecimales);
                            }
{CONSTANTE_REAL}	        {
                                insertarLista(yytext,linea,&listaDeReales);
                            }
{CARACTER}	                {
                                insertarLista(yytext,linea,&listaDeCaracteres);
                            }
{LITERAL_CADENA}            {
                                insertarLista(yytext,linea,&listaDeLiterales);
                            }
{PALABRAS_RESERVADAS}       {
                                insertarLista(yytext,linea,&listaDePalabrasReservadas);
                            }
{IDENTIFICADOR}             {
                                insertarOrdenado(yytext,linea,&listaDeIdentificadores);
                            }
{CARACTERES_PUNTUACION_OPERADORES} {
                                    insertarLista(yytext,linea,&listaDeOperYPunt);
                                   }
{COMENTARIO_BLOQUE}         {
                                insertarLista(yytext,linea,&listaDeComentariosDeBloque);
                                linea+= cantidadSaltosDeLinea(yytext);
                            }
{COMENTARIO_LINEA}          {
                                insertarLista(yytext,linea,&listaDeComentariosDeLinea);
                            }
{SALTO_DE_LINEA}            {linea ++;}
[" "|\t]*                   {}
{COMODIN}                   {
                                insertarLista(yytext,linea,&listaDeNoReconocidos);
                            }


%%

int main(){
    yyin = fopen("TextoEntrada.txt", "r");
    yyout = fopen("TextoSalida.txt", "w");

    FILE* reporte = fopen("Reporte.txt", "w");
    yylex();

    fprintf(reporte,"-----------------REPORTE ANALIZADOR LEXICO--------------\n\n");
    
    fprintf(reporte,"Lista de identificadores: \n");
    copiarConRepeticiones(reporte, listaDeIdentificadores);

    fprintf(reporte,"Lista de literales cadena: \n");
    copiarConLength(reporte,listaDeLiterales);

    fprintf(reporte,"Lista de palabras reservadas: \n");
    copiarLista(reporte,listaDePalabrasReservadas);

    fprintf(reporte,"Lista de numeros octales: \n");
    copiarNumeros(reporte,listaDeOctales,8);
    
    fprintf(reporte,"Lista de numeros hexadecimales: \n");
    copiarNumeros(reporte,listaDeHexadecimales,16);

    fprintf(reporte,"Lista de numeros decimales: \n");
    copiarNumeros(reporte,listaDeDecimales,10);
    sumatoria(reporte,listaDeDecimales);

    fprintf(reporte,"Lista de constantes reales: \n"); 
    parteEnteraYmantisa(reporte,listaDeReales);

    fprintf(reporte,"Lista de constantes caracter: \n");
    copiarCaracteres(reporte,listaDeCaracteres);

    fprintf(reporte,"Lista de caracteres de puntuacion / operadores: \n");
    copiarConRepeticiones(reporte,listaDeOperYPunt);

    fprintf(reporte, "Lista de comentarios de una linea: \n");
    copiarLista(reporte,listaDeComentariosDeLinea);

    fprintf(reporte,"Lista de comentarios de bloque: \n");
    copiarLista(reporte,listaDeComentariosDeBloque);

    fprintf(reporte, "Lista de caracteres no reconocidos: \n"); 
    copiarNoRec(reporte,listaDeNoReconocidos);

    fclose(yyin);
    fclose(yyout);
    fclose(reporte);

    free(listaDeCaracteres);
    free(listaDeComentariosDeBloque);
    free(listaDeComentariosDeLinea);
    free(listaDeDecimales);
    free(listaDeHexadecimales);
    free(listaDeIdentificadores);
    free(listaDeLiterales);
    free(listaDeNoReconocidos);
    free(listaDeOctales);
    free(listaDeOperYPunt);
    free(listaDeReales);
    
}