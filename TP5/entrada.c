#include <stdio.h>
#include <stdlib.h>
int b = 43;
int b = 42;
int x = 2; 
int nivelDeFachaDeEsteTP = b + x;

ñ
// es un error lexico;

int funcionUno(char a, float l, int w);

int funcionUno(char a, float l){ //debe tirar error de tipos de parametros
    a += 2;
    return 1;
}

int main(){

    char* d = "SSL";
    char* e = "S.S.L.";
    int f = 1;

    if(f){
        while(1)
        {
            strcpy(d, "hola");
            while(x < 10)
            {
                b += 2;
                x+= 1;
                continue;
            }

            break;
        }
    }

    printf("Cadena: %s", d);

    return 0;
}
