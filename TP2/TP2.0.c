
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct tipoNodo {
   char valor;
   struct _nodo * siguiente;
};

typedef struct tipoNodo * pNodo;
typedef struct tipoNodo * Pila;


Pila push(Pila *pila, char v) {
   pNodo nuevo;
   nuevo = (pNodo)malloc(sizeof(Pila));
   nuevo->valor = v;

   nuevo->siguiente = pila;
  
   pila = nuevo;
   return pila;
}

char pop(Pila *pila) {
   pNodo nodo;
   char v;     

   nodo = pila;
   if(!nodo) return 0; 
   
   pila = nodo->siguiente;

   v = nodo->valor;

   return v;
}

int aQueColumnaVoy (char cCaracter){

    int columna;

    if (cCaracter == '0')
    {
        columna = 0;
    }
    else if (cCaracter >= '1' &&  cCaracter <= '9')
    {
        columna = 1;
    }
    else if (cCaracter == '+' || cCaracter == '-' || cCaracter == '*' || cCaracter == '/')
    {
        columna = 2;
    }
    else if (cCaracter == '(')
    {
        columna = 3;
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

Pila pilasuper (char cCaracter, Pila *pila, char cimaPila){

    if (cCaracter == '0')
    {
        push (pila, cimaPila);
    }
    else if (cCaracter >= '1' &&  cCaracter <= '9')
    {
        push (pila,cimaPila);
    }
    else if (cCaracter == '+' || cCaracter == '-' || cCaracter == '*' || cCaracter == '/')
    {
        push (pila,cimaPila);

    }
    else if (cCaracter == '(')
    {
        push (pila,cimaPila);
        push (pila,cimaPila);
    }
    else if (cCaracter == ')')
    {
        push (pila,cimaPila);
    }
    else
    {
        return 0;
    }
    return pila;
}
int main(){

int TT [2][4][6];
// CI = 0 CIMA DE LA PILA = $       (ﾉ^_^)ﾉ
//        CI  E  C                 C: 0 => 0    1 => 1-9  2=>{+,-,/,*} 3=>(  4=>)  5=>ERROR
        TT[0][0][0] =3;        // $, q0 , 0
        TT[0][0][1] =1;        // $, q0 , 1
        TT[0][0][2] =3;        // $, q0 , 2
        TT[0][0][3] =0;        // $, q0 , 3
        TT[0][0][4] =3;        // $, q0 , 4
        TT[0][0][5] =3;        // $, q0 , 5
        TT[0][1][0] =1;        // $, q1 , 0
        TT[0][1][1] =1;        // $, q1 , 1
        TT[0][1][2] =0;        // $, q1 , 2
        TT[0][1][3] =3;        // $, q1 , 3
        TT[0][1][4] =3;        // $, q1 , 4
        TT[0][1][5] =3;        // $, q1 , 5
        TT[0][2][0] =3;        // $, q2 , 0
        TT[0][2][1] =3;        // $, q2 , 1
        TT[0][2][2] =0;        // $, q2 , 2
        TT[0][2][3] =3;        // $, q2 , 3
        TT[0][2][4] =3;        // $, q2 , 4
        TT[0][2][5] =3;        // $, q2 , 5
        TT[0][3][0] =3;        // $, q3 , 0
        TT[0][3][1] =3;        // $, q3 , 1
        TT[0][3][2] =3;        // $, q3 , 2
        TT[0][3][3] =3;        // $, q3 , 3
        TT[0][3][4] =3;        // $, q3 , 4
        TT[0][3][5] =3;        // $, q3 , 5
// CI = 1 CIMA DE LA PILA ES R
//        CI  E  C                 C: 0 => 0    1 => 1-9  2=>{+,9} 3=>(  4=>)
        TT[1][0][0] =3;        // R, q0 , 0
        TT[1][0][1] =1;        // R, q0 , 1
        TT[1][0][2] =3;        // R, q0 , 2
        TT[1][0][3] =0;        // R, q0 , 3
        TT[1][0][4] =3;        // R, q0 , 4
        TT[1][0][5] =3;        // R, q0 , 5
        TT[1][1][0] =1;        // R, q1 , 0
        TT[1][1][1] =1;        // R, q1 , 1
        TT[1][1][2] =0;        // R, q1 , 2
        TT[1][1][3] =3;        // R, q1 , 3
        TT[1][1][4] =2;        // R, q1 , 4
        TT[1][1][5] =3;        // R, q1 , 5
        TT[1][2][0] =3;        // R, q2 , 0
        TT[1][2][1] =3;        // R, q2 , 1
        TT[1][2][2] =0;        // R, q2 , 2
        TT[1][2][3] =3;        // R, q2 , 3
        TT[1][2][4] =2;        // R, q2 , 4
        TT[1][2][5] =3;        // R, q2 , 5
        TT[1][3][0] =3;        // R, q3 , 0
        TT[1][3][1] =3;        // R, q3 , 1
        TT[1][3][2] =3;        // R, q3 , 2
        TT[1][3][3] =3;        // R, q3 , 3
        TT[1][3][4] =3;        // R, q3 , 4
        TT[1][3][5] =3;        // R, q3 , 5


char expresion[3], caracter, cimaPila;
int estado = 0, columna = 0, ci = 0, error=0,contador=0;
Pila *pila = NULL;

printf ("Porfis ingrese una expresion :3 \n");
scanf("%s",&expresion);

while (expresion[contador]!='\0')
            contador++;

pila=push (pila, '$');

for(int i=0; i<contador; i++) //recorremos la expresion
{
    caracter = expresion[i];
    columna = aQueColumnaVoy(caracter);

    if (estado != 3 && columna != 5 )  //osea, no hay error   :3
    {
        cimaPila = pop (pila);               //(°_°) (°_°) (°_°)
        if (cimaPila == 'R'){
            ci = 1;
        } else {
            ci = 0;
        }
        pila=pilasuper (caracter, pila, cimaPila);
        estado = TT[ci][estado][columna];
        printf ("%c", caracter);
    }
    else if (error != 1){
        printf (" --> ERROR SINTACTICO :(");
        error = 1;
    }
}
if (error != 1){
    printf (" NO HAY ERROR SINTACTICO :)");
}
}
// ~(o_o~) ~(o_o)~ (~o_o)~  ~(o_o~) ~(o_o)~ (~o_o)~ 
