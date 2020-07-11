%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    #define PALABRA_MAX 50
    int sumaEnteros = 0, linea = 0, valorD = 0, valorO = 0, valorH = 0;
    float valorR;

    FILE* identificadores;
    FILE* literalesCadena;
    FILE* palabrasReservadas;
    FILE* caracteres;
    FILE* constantes;
    FILE* operadores;
    FILE* comentarios;

    struct Constante
    {
        int valor;
        char tipo[12];
    };
%}

TIPO_DE_DATO int | float | char | struct | double | long | unsigned | signed | short | void | enum | struct | typedef | union | const
ESTRUCTURAS_DE_CONTROL switch | case | do | while | break | default | if | else | for | return | continue | goto
OTROS volatile | goto | extstatic | auto | register 

CARACTERES_PUNTUACION_OPERADORES "[" | "]" | "(" | ")" | "{" | "}" | "," | ";" | ":" | "*" | "=" | "#" | "!" | "%" | "^" | "&" | "–" | "+" | "|" | "~" | "\" | "'" | "<" | ">" | "?" | "." | "/" | "==" | | "+=" | "-=" | "~" | "&&" | "!=" | "++" | "--"
 
CONSTANTE_ENTERA [1-9][0-9]*
CONSTANTE_OCTAL 0[0-7]*
CONSTANTE_HEXADECIMAL 0[xX][0-9A-Fa-f]+
CONSTANTE_REAL   [0-9]+ "." [0-9]+ //no estamos muy seguros
CARACTER_LETRAS [a-zA-Z]

COMENTARIO_LINEA "//" .*
COMENTARIO_BLOQUE "/*"  (. | \n)*  "*/"
COMODIN .
COMODINES .*
SALTO_DE_LINEA \
IDENTIFICADOR ({CARACTER_LETRAS} |_)({CARACTER_LETRAS} | [0-9]| _)*
PALABRAS_RESERVADAS {TIPO_DE_DATO} | {ESTRUCTURAS_DE_CONTROL} | {OTROS}
LITERAL_CADENA \".+\"
CARACTER \'.\''

%%

{CONSTANTE_ENTERA}          {
                                valorD = obtenerNumero(yytext,10); 
                                sumaEnteros += valorD; 
                                agregarConstante(valorD,"decimal");
                                printf("se encontro una constante decimal cuyo valor es : %d \n,valorD");
                            } 
{CONSTANTE_OCTAL}	        {
                                valorO = obtenerNumero(yytext,8);
                                agregarConstante(valorO,"octal");
                                printf("se encontro una constante octal: %s cuyo valor decimal es : %d \n",yytext,valorO);
                            }
{CONSTANTE_HEXADECIMAL}	    {
                                valorH = obtenerNumero(yytext,16);
                                agregarConstante(valorH,"hexadecimal");
                                printf("se encontro una variable hexadecimal: %s, cuya valor en decimal es: %d \n",yytext,valorH);
                            }
{CONSTANTE_REAL}	        {
                                char*ignorar;
                                float valorR = strtof(yytext,&ignorar);
                                int entera = valorR;
                                float decimales = valorR - entera;
                                agregarConstante(valorR,"real");
                                printf("se encontro una variable real: %s \n",yytext);
                            }
{CARACTER}	                {
                                printf ("se encontro el caracter: %s \n", yytext);
                                char caracter;
                                strcpy(caracter,yytext);
                                fwrite(&caracter , sizeof(caracter),1,caracteres);
                            }
{LITERAL_CADENA}            {
                                printf ("se encontro el literal cadena: %s, de largo %d \n", yytext,yyleng);
                                char literalCadena[PALABRA_MAX];
                                strcpy(literalCadena,yytext);
                                fwrite(&literalCadena, sizeof(literalCadena), 1, literalesCadena);
                            }
{IDENTIFICADOR}             {
                                printf ("se encontro el identificar: %s \n", yytext);
                                char identificador[PALABRA_MAX];
                                strcpy(identificador,yytext);
                                fwrite(&identificador,sizeof(identificador),1,identificadores);
                            }
{CARACTERES_PUNTUACION_OPERADORES} {
                                printf ("se encontro el caracter de puntuacion: %s \n", yytext);
                                char punt_oper[3];
                                strcpy(punt_oper,yytext);
                                fwrite(&punt_oper,sizeof(punt_oper),1,operadores);
                            }
{PALABRAS_RESERVADAS}       {
                                printf ("se encontro la palabra reservada: %s \n", yytext);
                                char palabrasReservada[PALABRA_MAX];
                                strcpy(palabrasReservada,yytext);
                                fwrite(&palabrasReservada,sizeof(palabrasReservada),1,palabrasReservadas);
                            }
{COMENTARIO_BLOQUE}         {printf("se encontro un comentario de multiples lineas: %s \n", yytext);}
{COMENTARIO_LINEA}          {printf("se encontro un comentario de una linea: %s \n", yytext);}
{SALTO_DE_LINEA}            {linea ++;}
{COMODIN}                   {printf("se encontro un caracter no identificado: %s, en la linea %d \n", yytext,linea);}
{COMODINES}                 {printf("se encontro una cadena de caracteres no identificados: %s, en la linea %d \n", yytext,linea);}

%%
void agregarConstante(int numero, char tipo[12])
{
    Constante constante;
    
    constante->valor = numero;
    strcopy(constante->tipo,tipo);
    
    fwrite(&constante, sizeof(constante), 1, constantes);
} 


int obtenerNumero(char* str, int base)
{
    char* ignorar;
    
    return strtol(str,&ignorar,base);
}

int main(){
    yyin = fopen("TextoEntrada.txt", "r");
    yyout = fopen("TextoSalida.txt", "w");
    
    identificadores = fopen("identificadores.txt","rw+");
    literalesCadena = fopen("literalesCadena.txt","rw+");
    palabrasReservadas = fopen("palabrasReservadas.txt","rw+");
    constantes = fopen("constantes.txt","rw+");
    caracteres = fopen("caracteres.txt","rw+");
    operadores = fopen("operadores.txt","rw+");
    comentarios = fopen("comentarios.txt","rw+");
    
    yylex();
    
    fclose(identificadores);
    fclose(literalesCadena));
    fclose(palabrasReservadas);
    fclose(constantes);
    fclose(operadores);
    fclose(comentarios);
    
    printf ("la suma de los valores enteros es: %i \n", sumaEnteros);

    fclose(yyin);
    fclose(yyout);
}

/*
 * C Program to Append the Content of File at the end of Another
 */
#include <stdio.h>
#include <stdlib.h>
 
main()
{
    FILE *fsring1, *fsring2, *ftemp;
    char ch, file1[20], file2[20], file3[20];
 
    printf("Enter name of first file ");
    gets(file1);
    printf("Enter name of second file ");
    gets(file2);
    printf("Enter name to store merged file ");
    gets(file3);
    fsring1 = fopen(file1, "r");
    fsring2 = fopen(file2, "r");
    if (fsring1 == NULL || fsring2 == NULL)
    {
        perror("Error has occured");
        printf("Press any key to exit...\n");
        exit(EXIT_FAILURE);
    }
    ftemp = fopen(file3, "w");
    if (ftemp == NULL)
    {
        perror("Error has occures");
        printf("Press any key to exit...\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(fsring1)) != EOF)
        fputc(ch, ftemp);
    while ((ch = fgetc(fsring2) ) != EOF)
        fputc(ch, ftemp);
    printf("Two files merged  %s successfully.\n", file3);
    fclose(fsring1);
    fclose(fsring2);
    fclose(ftemp);
    return 0;
}

/* 

SANTI, TE REGALAMOS UN PERRITO <3
______________________$$$$$$$$
_______________$$$$$$$________$$$$$$$$$
_____________$$________________________$$$$
____________$$_____________________________$$
___________$__________________________________$$
___________$$___________________________________$$
__________$$__$$______________________$$__________$$
________$$__$$___$$$$_________$$$$____$$__________$$$$
______$$___$$__$$$$__$$_____$$$$__$$_$$_____________$$$
______$$___$$____$$$$_________$$$$___$$_______________$$
______$$___$$________________________$$_______________$$
______$$____$$_______________________$$_____________$$
________$$__$$____$$$$$$_____________$$___________$$$
________$$__$$__$$______$$___________$$_________$$
________$$__$$__$$______$$___________$$_______$$
__________$$$$____$$$$$$_____________$$$$____$$$$
__________$$$$_____________________$$__$$____$$$
___________$$_$$$$$$$$$$$$_____$$$$______$$$$_$$
_____________$$___$$______$$$$$_______________$$
_____________$$_____$$$$$$$____________________$$
_____________$$________________________________$$
____________$$_________________________________$$
____________$$_________________________________$$
____________$$___________________________________$
____________$$___________________________________$$
__________$$_________________________$$___________$
__________$$__________$$___________$$_____________$$
________$$__$$________$$_________$$_______________$$
______$$____$$__________$$_______$$_______________$$
______$$____$$____________$$___$$_________________$$
____$$______$$_____________$$_$$_______$$_________$$
____$$______$$________$$____$$$________$$_________$$
____$$______$$________$$____$$$_______$$__________$$
____$$______$$________$$_______________$$__________$$
____$$______$$________$$_______________$$____________$
_$$$$_______$$________$$_______________$$____________$$
$___$$______$$________$$$$___________$$$$____________$$
$___$$______$$________$$__$$_______$$__$$____________$$
_$$$$$______$$________$$____$$___$$_____$$___________$$
____$$______$$________$$______$$_______$$___________$$
____$$______$$________$$_____$$________$$___________$$
__$$________$$________$$$$$$$$___$$$$$$__$$_________$$
__$$________$$________$$______$$$______$$$$_________$$
$$________$$__________$$_________$$$$$$__$$__________$
$$______$$__________$$$$$$$$$$$$$$$______$$__________$
$$_$$_$$$__________$$_____________$$$$$$$__$$_________$
_$$$$$$$___________$$______________________$$________$$
_____$$__$$__$$__$$_$______________________$$__________$$
______$$$$__$___$__$$______________________$$____________$
_______$$___$___$__$________________________$$_$__$$__$$__$
_________$$$$$$$$$$__________________________$$_$_$$$$$$$$


░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░█▀▀▀░█▀▀█░█▀▀▀░▀░█░░░░░
░░░█▀▀░░█▀▀█░▀▀▀█░█░█░░░░░
░░░▀░░░░▀░░▀░▀▀▀▀░▀░▀▀▀░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░

*/
