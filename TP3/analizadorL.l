%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    int sumaEnteros=0, linea = 0, valorD=0,valorO=0;
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

{CONSTANTE_ENTERA}          {valorD = atoi(yytext); sumaEnteros += valorD; printf("se encontro una constante decimal cuyo valor es : %d \n,valorD");} 
{CONSTANTE_OCTAL}	        {valorO = atoi(yytext); printf("se encontro una constante octal: %s cuyo valor decimal es : %d \n",yytext,deOctalADecimal(valor));}
{CONSTANTE_HEXADECIMAL}	    {printf("se encontro una variable hexadecimal: %s, cuya valor en decimal es: %d \n",yytext,deHexaADecimal(yytext));}
{CONSTANTE_REAL}	        
{CARACTER}	                
{LITERAL_CADENA}            {printf ("se encontro el literal cadena: %s, de largo %d \n", yytext,yyleng);}
{IDENTIFICADOR}
{CARACTERES_PUNTUACION_OPERADORES}
{PALABRAS_RESERVADAS}       {printf ("se encontro la palabra reservada: %s \n", yytext);}
{COMENTARIO_BLOQUE}         {printf("se encontro un comentario de multiples lineas: %s \n", yytext);}
{COMENTARIO_LINEA}          {printf("se encontro un comentario de una linea: %s \n", yytext);}
{SALTO_DE_LINEA}            {linea ++;}
{COMODIN}                   {printf("se encontro un caracter no identificado: %s, en la linea %d \n", yytext,linea);}
{COMODINES}                 {printf("se encontro una cadena de caracteres no identificados: %s, en la linea %d \n", yytext,linea);}


%%

int main(){
    yyin = fopen("TextoEntrada.txt", "r");
    yyout = fopen("TextoSalida.txt", "w");

    yylex();

    printf ("la suma de los valores enteros es: %i \n", sumaEnteros);

    fclose(yyin);
    fclose(yyout);
}

int deOctalADecimal (int octal)
{
    int i =0,decimal=0;
    while (octal != 0)
    {
    decimal += (octal % 10)* pow(8, i++);
    octal = octal / 10;
    }
    return decimal;
}

int deHexaADecimal (char* hexa)
{
    char caracter;
    int largo = 0, i=0,decimal=0;
   while (caracter != '\0')
    {
        caracter = hexa[largo];
        largo++; 
    }

    while (i <= largo-2){
        caracter = hexa[i+2];
        if (caracter >= 48 && caracter <= 57){      // o si quieren asi caracter>='0' && caracter<='9' 
            numero = atoi caracter;
            decimal =  decimal +(numer)* pow(16, i++);
        }else{
            if(caracter >= 92 && caracter <= 107)
                decimal = decimal + (caracter - 97 + 10)* pow(16,i++);
            else
                decimal = decimal + (caracter - 65 + 10)* pow(16,i++);           
   
        }
        i++;
    }
    return decimal;
}

int deHexaADecimal (char* hexa)
{
    int largo = 0, i=0,decimal=0, numero=0,caracter;
    while (caracter != '\0')
    {
        caracter = hexa[largo];
        largo++; 
    }

    while (i<=largo-2){
        caracter = hexa[largo-i];
        if (caracter >= 48 && caracter <= 57){      // o si quieren asi caracter>='0' && caracter<='9'
            numero = caracter-48;
            decimal =  decimal + ((numero)*(pow(16, i)));
        }else{
            if(caracter >= 92 && caracter <= 107)
                decimal = decimal + ((caracter - 97 + 10) * pow(16,i));
            else
                decimal = decimal + ((caracter - 65 + 10)*(pow(16,i)));
        }
        i++;
    }
    return decimal;
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
*/

