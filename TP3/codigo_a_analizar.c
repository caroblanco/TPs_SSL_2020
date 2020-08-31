#include<stdio.h>
#include<conio.h>
#include<string.h> 
#define CERO 0

//Funcion hecha solo para usar la palabra reservada static
static int fun(void) 
{ 
  printf("Funcion estatica"); 
} 

/*INICIO MAIN*/
int main()
{
    char nombre[10][20],aux[20];
    unsigned nHexa_1=0xFAFA,nHexa_2=0xC2,nHexa_resul,nOct_1=0144,nOct_2=02,nOct_resul,nDec_1=81,nDec_2=12,nDec_resul;
    short c1='a',c2='b',c3='f',cResul;
    int i,j,k,l=CERO,y=28;
    float x = 10.3270,z=12.8346,w=100.1929;
    int vt_octal='\013';/*ASCII vertical tab*/ 
    int bell_octal='\007';/*ASCII bell character*/ 
    int vt_hexadecimal='\xb';/*ASCII vertical tab*/ 
    int bell_hexadecimal='\x7';/*ASCII bell character*/ 

    $0xG$ // Deberia emparejar con NO RECONOCIDOS LOS DOS $ 

    
    printf("Suma de valores: \n\n");

    //CONSTANTES HEXADECIMALES

    printf("CONSTANTES HEXADECIMALES\n");
	
	printf("El valor de la primer constante hexadecimal es igual a: %X \n",nHexa_1);
	printf("El valor de la segunda constante  hexadecimal es igual a: %X \n",nHexa_2);

    nHexa_resul=nHexa_1+nHexa_2;

    printf("El valor de la suma entre las dos constantes hexadecimales anteriores es igual a: %X \n\n",nHexa_resul);

    //CONSTANTES OCTALES

    printf("CONSTANTES OCTALES\n");

    printf("El valor de la primer constante octal es igual a: %o \n",nOct_1);
	printf("El valor de la segunda constante octal es igual a: %o \n",nOct_2);

    nOct_resul=nOct_1+nOct_2;

    printf("El valor de la suma entre las dos constantes octales anteriores es igual a: %o \n\n",nOct_resul);

    # // deberia emparejar con NO RECONOCIDOS

    //CONSTANTES DECIMALES

    printf("CONSTANTES DECIMALES\n");

    printf("El valor de la primer constante decimal es igual a: %d \n",nDec_1);
	printf("El valor de la segunda constante decimal es igual a: %d \n",nDec_2);

    nDec_resul=nDec_1+nDec_2;

    printf("El valor de la suma entre las dos constantes decimales anteriores es igual a: %d \n\n",nDec_resul);

    //CONSTANTES CARACTER

    printf("CONSTANTES CARACTER\n");

    printf("La constante caracter :'%c' en la tabla ASCII es igual a: %d \n",c1,c1);
	printf("La constante caracter :'%c' en la tabla ASCII es igual a: %d \n",c2,c2);
    printf("La constante caracter :'%c' en la tabla ASCII es igual a: %d \n",c3,c3);

    cResul=c1+c2+c3;

    printf("El valor de la suma entre las tres constantes caracter anteriores es igual a: %d \n\n",cResul);
	
    
    //CONSTANTES REALES

    printf("CONSTANTES REALES\n");

    printf("El valor de la constante real de tipo flotante z es : %f\n", z);
    printf("El valor de la constante real de tipo flotante w es : %f\n", w);
    printf("La suma z+w es : %f\n\n", (z+w));

    printf("El valor de  la constante real de tipo flotante x es : %f\n", x);
    printf("El valor de  la constante decimal de tipo entero y es : %d\n", y);
    printf("La suma x+y es : %f\n\n", (x+y));


    //INGRESAR PALABRAS Y ORDENARLAS ALFABETICAMENTE

    printf("INGRESO DE PALABRAS PARA ORDENAR ALFABETICAMENTE\n");
    
    printf("Para terminar escriba un asterisco * \n");
    do{
            printf("Introduzca un nombre: ");
            gets(nombre[l]);//lee cadenas y las almacena.
            l++;
        }while (strcmp(nombre[l-1],"*")!=CERO);//permite comparar cadenas.

    // ORDENAR CADENAS
    for(i=CERO; i<l-1; i++)
    {
        k=i;
        strcpy(aux, nombre[i]);
        for(j=i+1; j<l; j++)
        {
            if(strcmp(nombre[j], aux)<CERO)
            {
                k=j;
                strcpy(aux, nombre[j]);
               //permite hacer una copia auxiliar de la cadena nombre[j];
            }
        }
        strcpy(nombre[k],nombre[i]);
        strcpy(nombre[i],aux);
    }

    printf("Cadenas de caracteres ordenadas alfabeticamente\n");

    for(i=CERO; i<l; i++)
    {
            printf("\"%s\"",nombre[i]);
            printf("\n");
    }

  return CERO;/*FIN DEL MAIN*/
}