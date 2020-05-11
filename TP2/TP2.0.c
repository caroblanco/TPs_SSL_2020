#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aQueColumnaVoy (char cCaracter){
    
    int columna;

    if (cCaracter == '0') 
    {
        columna = 0;
        push cimaPila;
    }
    else if (cCaracter >= '1' &&  cCaracter <= '9') 
    {
        columna = 1;
        push cimaPila;
    }
    else if (cCaracter == '+' || cCaracter == '-' || cCaracter == '*' || cCaracter == '/')
    {
        columna = 2;
        push cimaPila;
        
    }
    else if (cCaracter == '(') 
    {
        columna = 3;
        push cimaPila;
        push R;
    }
    else if (cCaracter == ')')
    {
        columna = 4;        
    }
    else
    {
        columna = 5;
    }
    return columna; 
}

int main(){
// CI = 0 CIMA DE LA PILA = $
//        CI  E  C                 C: 0 => 0    1 => 1-9  2=>{+,-,/,*} 3=>(  4=>)  5=>ERROR
        TT[0][0][0] =  3     // $, q0 , 0
        TT[0][0][1] =  1     // $, q0 , 1
        TT[0][0][2] =  3     // $, q0 , 2
        TT[0][0][3] =  0     // $, q0 , 3
        TT[0][0][4] =  3     // $, q0 , 4
        TT[0][0][5] =  3     // $, q0 , 5
        TT[0][1][0] =  1     // $, q1 , 0
        TT[0][1][1] =        // $, q1 , 1                       qo cuando puedo poner numero o parentesis de apertura
        TT[0][1][2] =        // $, q1 , 2                       q1 cuando puedo poner cero o numero o parentesis de cierre u operacion
        TT[0][1][3] =        // $, q1 , 3                       q2 cuando puedo poner operaciones o parentesis de cierre
        TT[0][1][4] =        // $, q1 , 4
        TT[0][1][5] =  3     // $, q1 , 5
        TT[0][2][0] =        // $, q2 , 0
        TT[0][2][1] =        // $, q2 , 1
        TT[0][2][2] =        // $, q2 , 2
        TT[0][2][3] =        // $, q2 , 3
        TT[0][2][4] =        // $, q2 , 4
        TT[0][2][5] =  3     // $, q2 , 5
        TT[0][3][0] =        // $, q3 , 0
        TT[0][3][1] =        // $, q3 , 1
        TT[0][3][2] =        // $, q3 , 2
        TT[0][3][3] =        // $, q3 , 3
        TT[0][3][4] =        // $, q3 , 4
        TT[0][3][5] =  3     // $, q3 , 5
// CI = 1 CIMA DE LA PILA ES R
//        CI  E  C                 C: 0 => 0    1 => 1-9  2=>{+,9} 3=>(  4=>) 
        TT[1][0][0] =        // R, q0 , 0
        TT[1][0][1] =        // R, q0 , 1
        TT[1][0][2] =        // R, q0 , 2
        TT[1][0][3] =        // R, q0 , 3
        TT[1][0][4] =        // R, q0 , 4
        TT[1][0][5] =  3     // R, q0 , 5
        TT[1][1][0] =        // R, q1 , 0
        TT[1][1][1] =        // R, q1 , 1
        TT[1][1][2] =        // R, q1 , 2
        TT[1][1][3] =        // R, q1 , 3
        TT[1][1][4] =        // R, q1 , 4
        TT[1][1][5] =  3     // R, q1 , 5
        TT[1][2][0] =        // R, q2 , 0
        TT[1][2][1] =        // R, q2 , 1
        TT[1][2][2] =        // R, q2 , 2
        TT[1][2][3] =        // R, q2 , 3
        TT[1][2][4] =        // R, q2 , 4
        TT[1][2][5] =  3     // R, q2 , 5
        TT[1][3][0] =        // R, q3 , 0
        TT[1][3][1] =        // R, q3 , 1
        TT[1][3][2] =        // R, q3 , 2
        TT[1][3][3] =        // R, q3 , 3
        TT[1][3][4] =        // R, q3 , 4
        TT[1][3][5] =  3     // R, q3 , 5 
    

char expresion[100], caracter, cimaPila;
int estado = 0, columna = 0;


for (int i=0, i<100 , i++) //recorremos la expresion
{
    
    caracter = expresion[i]

    if (estado != 3 && columna != 5 )  //osea, no hay error
    {
        cimaPila = pop pila;
        if (cimaPila == 'R'){
            ci = 1;
        } else {
            ci = 0;
        }
            
        estado = TT[ci][estado][aQueColumnaVoy(caracter)];
        
    }
}
