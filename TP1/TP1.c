#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------------------DEFINIMOS LO QUE NECESITAMOS-------------------------------------------------------

int aQueColumnaVoy(char cCaracter, FILE *salida){
    
    int columna;

    if (cCaracter == '0') {
        columna = 0;
        }
    else 
        if (cCaracter >= '1' &&  cCaracter <= '7') {
            columna = 1;
        }
    else 
        if (cCaracter == '8' || cCaracter == '9') {
            columna = 2;
        }
    else 
        if (cCaracter == 'x' || cCaracter == 'X') {
            columna = 3;
        }
    else 
        if ((cCaracter >= 'a' && cCaracter <= 'f')|| (cCaracter >= 'A' && cCaracter <= 'F')) {
            columna = 4;
        }
    else{
            columna = 5;
        }
    return columna;
}

int main(){

    int TT [7][6] =
   {
    //   0   1-7  8-9  x-X  lets error
        {2,   1,   1,   6,   6,   6},   //q0
        {1,   1,   1,   6,   6,   6},   //q1
        {3,   5,   6,   3,   6,   6},   //q2
        {4,   4,   4,   6,   4,   6},   //q3
        {4,   4,   4,   6,   4,   6},   //q4
        {5,   5,   6,   6,   6,   6},   //q5
        {6,   6,   6,   6,   6,   6},   //q6
    };
    
    char caracter, muestra, tipo;
    int caracterASCII, noReconocido = 0, estado = 0, columna;
    FILE *archivo;
    FILE *salida;

    archivo = fopen ("numeros.txt", "r+");
    salida = fopen ("num_salida.txt", "wb+");
    
    if(!archivo){
        printf ("No se pudo leer el archivo");
    }
    else{
        while(fread(&caracter, sizeof(caracter), 1, archivo)){
            if (caracter !=  ','){
                 fputc(caracter, salida);
                 aQueColumnaVoy(caracter, salida);
                 estado = TT[estado][aQueColumnaVoy(caracter,salida)];
            }
            else {
                switch (estado)
                {
                case 1:
                    fputs("--> Es Decimal \n", salida);
                    break;
                case 4:
                    fputs("--> Es Hexadecimal \n", salida);
                    break;
                case 2:
                    fputs("--> Es 0 \n", salida);
                    break;
                case 5:
                    fputs("--> Es Octal \n", salida);
                    break;
                default:
                    fputs("--> No Fue Reconocido \n", salida);
                    break;
                }

                estado = 0;
            }
        }
    }

    fclose(archivo);
    fclose(salida);
    return 0;
}