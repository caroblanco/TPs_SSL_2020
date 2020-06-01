#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
   char valor;
   struct nodo * siguiente;
} tipoNodo;

//INGRESO EL VALOR EN LA CIMA
tipoNodo *push(tipoNodo *pila, char cima) {
   tipoNodo *aux, *nuevo;

   nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
   nuevo->valor = cima;

   nuevo->siguiente = NULL;

   if (pila == NULL){
       pila=nuevo;
   }else{
       aux=pila;
       while(aux->siguiente != NULL)
            aux = aux->siguiente;
       aux->siguiente = nuevo;
   }
   return pila;
}

tipoNodo *borrar (tipoNodo *pila) //BORRA EL ULTIMO VALOR DE LA PILA
{
    tipoNodo *nodo;
    nodo=pila;
    if (nodo->siguiente==NULL)
    {
        free(nodo);
        pila=NULL;
    }
    else {
        while (nodo->siguiente->siguiente!=NULL)
        nodo = nodo->siguiente;
        free(nodo->siguiente);
        nodo->siguiente=NULL;
    }
    return pila;
}

//DEVUELVO EL ULTIMO VALOR
char pop(tipoNodo **pila) {
   tipoNodo *nuevo;
   char cima;     

   nuevo = *pila;
   if(!nuevo) return 0; 
   
   while(nuevo -> siguiente != NULL)
        nuevo = nuevo -> siguiente;

   cima = nuevo -> valor;

   *pila = borrar (*pila);

   return cima;
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

tipoNodo *pilasuper (char cCaracter, tipoNodo *pila, char *cimaPila){

    char nuevaCimaPila;

    if (cCaracter == '0')
    {
        nuevaCimaPila = pop (&pila);
        pila = push (pila, nuevaCimaPila);
        *cimaPila = nuevaCimaPila;
    }
    else if (cCaracter >= '1' &&  cCaracter <= '9')
    {
        nuevaCimaPila = pop (&pila);
        pila = push (pila, nuevaCimaPila);
        *cimaPila = nuevaCimaPila;
    }
    else if (cCaracter == '+' || cCaracter == '-' || cCaracter == '*' || cCaracter == '/')
    {
        nuevaCimaPila = pop (&pila);
        pila = push (pila, nuevaCimaPila);
        *cimaPila = nuevaCimaPila;

    }
    else if (cCaracter == '(')
    {
        nuevaCimaPila = pop (&pila);
        pila = push (pila, nuevaCimaPila);
        pila = push(pila,'R');
        *cimaPila = 'R';
    }
    else if (cCaracter == ')')
    {
        nuevaCimaPila = pop (&pila);
        *cimaPila = nuevaCimaPila;
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


char expresion[100], caracter, cimaPila;
int estado = 0, columna = 0, ci = 0, error=0,contador=0;
tipoNodo *pila = NULL;

printf ("Porfis ingrese una expresion :3 \n");
scanf("%s",&expresion);

while (expresion[contador]!='\0')
            contador++;

pila=push (pila, '$'); //inicializamos

for(int i=0; i<contador; i++) //recorremos la expresion
{
    caracter = expresion[i];
    columna = aQueColumnaVoy(caracter);

    if (estado != 3 && columna != 5 )  //osea, no hay error   :3
    {
        pila=pilasuper (caracter, pila, &cimaPila);          //(°_°) (°_°) (°_°)
        if (cimaPila == 'R'){
            ci = 1;
        } else {
            ci = 0;
        }
    
        estado = TT[ci][estado][columna];
        printf ("%c", caracter);
    }
    else if (error != 1){
        printf (" --> ERROR SINTACTICO :( \n");
        error = 1;
    }
}

//para el ultimo caracter
if (error != 1){
    if (estado ==3 || columna == 5){
        //error en el ultimo caracter
        printf (" --> ERROR SINTACTICO :( \n");
        error = 1;
    } else if (columna == 2){
        //verifico que no quede un operador solo
        printf (" --> ERROR SINTACTICO :( \n");
        error = 1;
    }else{
        //verifico que no quedo parentesis abierto
        cimaPila = pop(&pila);
        if(cimaPila == 'R'){
            printf (" --> ERROR SINTACTICO :( \n");
            error = 1;
        }
    }
} else if (error != 1){
    printf (" NO HAY ERROR SINTACTICO :) \n");
}

printf("\nT ~(o_o~) \nE ~(o_o)~ \nR (~o_o)~ \nM ~(o_o)~ \nI ~(o_o~) \nN ~(o_o)~ \nA (~o_o)~ \nM ~(o_o)~ \nO ~(o_o~) \nS ~(o_o)~ \n");

return 0;
}
 
