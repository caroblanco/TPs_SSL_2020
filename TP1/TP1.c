#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------------------DEFINIMOS LO QUE NECESITAMOS-------------------------------------------------------

int aQueColumnaVoy(char cCaracter, FILE *salida){
    
    if (cCaracter = '0') {
        columna = 0;
        fputc(cCaracter, salida);
        }
    else 
        if (cCaracter >= '1' &&  cCaracter <= '7') {
            columna = 1;
            fputc(cCaracter, salida);
        }
    else 
        if (caracter <=57 && caracter>=56) {
            columna = 2;
            fputc(cCaracter, salida);
        }
    else 
        if (caracter == 88 || caracter == 120){
            columna = 3;
            fputc(cCaracter, salida);
        }
    else 
        if (caracter>= 65 && caracter<=70 || caracter>= 102 && caracterASCII<=97){
            columna = 4;
            fputc(cCaracter, salida);
        }
    else{
            columna = 5;
            fputc(cCaracter, salida);
        }
    return columna;

    
int main(){
    
    int TT [7][6] =
    { 
    //   0  1-7 8-9 x-X lets error
        {q2, q1, q1, q6, q6, q6},   //q0
        {q1, q1, q1, q6, q6, q6},   //q1
        {q3, q5, q6, q3, q6, q6},   //q2
        {q4, q4, q4, q6, q4, q6},   //q3
        {q4, q4, q4, q6, q4, q6},   //q4
        {q5, q5, q6, q6, q6, q6},   //q5
        {q6, q6, q6, q6, q6, q6},   //q6
    };
    
    char caracter, muestra ;
    int caracterASCII, noReconocido = 0, estado = 0;
    FILE *archivo;
    FILE *salida;
    aQueColumnaVoy(caracter ; salida)
    while(fread(&caracter, si0eof(caracter), 1, archivo)){
        
        caracterASCII = caracter;
            for(int c=0; c<6; ++c){
                if(TT[0][c]==0){
                    
                    
                 }
            }

    }
    



































    archivo = fopen ("numeros.txt", "r+");
    salida = fopen ("num_salida.txt", "wb+");

    if(!archivo){
        printf ("no se pudo leer el archivo");
    }
    else{

        while(fread(&caracter, sizeof(caracter), 1, archivo)){
    
        }
    }

    
    return 0;
}