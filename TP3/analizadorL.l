%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #include "caro.c"

    int linea = 1;
    
%}


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
IDENTIFICADOR ({CARACTER_LETRAS}|_)({CARACTER_LETRAS}|[0-9]|_)*
PALABRAS_RESERVADAS int|float|char|struct|double|long|unsigned|signed|short|void|enum|struct|typedef|union|const
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
{IDENTIFICADOR}             {
                                insertarOrdenado(yytext,linea,&listaDeIdentificadores);
                            }
{CARACTERES_PUNTUACION_OPERADORES} {
                                    insertarLista(yytext,linea,&listaDeOperYPunt);
                                   }
{PALABRAS_RESERVADAS}       {
                                insertarLista(yytext,linea,&listaDePalabrasReservadas);
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

    yylex();

    fclose(yyin);
    fclose(yyout);
    fclose(reporte);
}