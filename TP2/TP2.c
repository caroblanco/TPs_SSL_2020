#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void masApertura
{
    push cimaDeLaPila;
    push R;
}

void 

int aQueColumnaVoy (char cCaracter, ) {
    
    int columna;

    if (cCaracter == '0') 
    {
        columna = 0;
        funcion 
    }
    else if (cCaracter >= '1' &&  cCaracter <= '9') 
    {
        columna = 1;
    }
    else if (cCaracter == '+' || cCaracter == '-' || cCaracter == '*' || cCaracter == '/')
    {
        columna = 2;
        push cimaDeLaPila;
        push R;
    }
    else if (cCaracter == '(') 
    {
        columna = 3;
        masApertura
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

/* donde esta el error
void tipodevariable(int estado){
    switch (estado){
        case 1:
            fputs("--> Es Decimal \n", );
            break;
        case 4:
            fputs("--> Es Hexadecimal \n", );
            break;
        case 2:
            fputs("--> Es 0 \n", );
            break;
        case 5:
            fputs("--> Es Octal \n", );
            break;
        default:
            fputs("--> No Fue Reconocido \n", );
            break;
    }
    return 0;
}
*/

int main(){

    int TT [7][6] = 
    {
    //   0   1-9  ops   (    )   error
        {7,   1,   7,   2,   7,   7},  //q0,$        0     
        {1,   1,   0,   7,   7,   7},  //q1,$        1     
        {7,   3,   7,   2,   7,   7},  //q0,R        2    
        {3,   3,   2,   7,   5,   7},  //q1,R        3    
        {7,   7,   2,   7,   5,   7},  //q2,R        4       
        {7,   7,   0,   7,   7,   7},  //q2,$        5 
        {7,   7,   7,   7,   7,   7}   //error       6 
    };
    
    char caracter, muestra, tipo;
    int caracterASCII, noReconocido = 0, estado = 0, columna;
    
    FILE* consola_entrada;
    FILE* consola_salida;
    
    consola_entrada = stdin; //"archivo" de la consola para ingresar datos
    consola_salida = stdout; //"archivo" de la consola para mostrar datos
    
    char expresion[50];
    

    printf("Ingrese una expresion: ");//seria lo mismo que fprintf(stdout,"Ingrese una expresion: ");
    fscanf(consola_entrada, "%s", &expresion);
    
    printf("%s",expresion);
    
    for(int i = 0; i < strlen(expresion); i++)
    {
        fputc(expresion[i],consola_salida);
        aQueColumnaVoy(caracter);
    }

    if(){
        printf ("No se pudo leer el archivo");
    }
    else{
        while(fread(&caracter, sizeof(caracter), 1, archivo))
        {
            fputc(caracter, salida);
            aQueColumnaVoy(caracter, salida);
            estado = TT[estado][aQueColumnaVoy(caracter,salida)];
            pop cimaDeLaPila
            if (estado == 2 || )
            {
                push cimaDeLaPila
                push R
            }
            else if (caracter == ')')
            {
                nada
            }
            else 
            {
                push cimaDeLaPila
            }

        }
            else {
                tipodevariable(estado,salida);
                estado = 0;
            }
        }
        }
        tipodevariable(estado,salida);
    }

    fclose(archivo);
    fclose(salida);
    return 0;
}
   
   
   
   
   
   
   
   
   
   
    /*
    PUSH: inserto un elemento en la lista, puede ser delante de todo o atrás
	Inserto al principio
		Nodo *lista = new nodo() ; lista->dato = 5 ; lista->sgte = NULL;
		Nodo *push = new nodo() ; push->dato = 3 ;
		Push->sgte = lista;
		Lista = push;
		
	Inserto al final
	Void push (nodo *&lista, int elemento) // AgregrarNodoAlFinal {
Nodo *paux ;  se usa un auxiliar para no perder la lista
		If (lista){  si existe lista, lista != NULL
			Paux = obtenerultimo(lista);  busco el ultimo y lo asigno a paux
			Paux->sgte = new nodo();  creo un nodo luego del ultimo
			Paux = paux->sgte;  paux apunta al Nuevo nodo
			Paux->dato = elemento;
			Paux->sgte = NULL;  crea un Nuevo ultimo nodo
		} else{ si lista = NULL, no hay info, creo el primer nodo
			Lista = new nodo();  lista apunta a un espacio
			Lista->dato = elemento;
			Lista->sgte = NULL;  lo que le sigue a donde apunta lista es NULL
		} }

	POP: quito un elemento, saco el ultimo que entro y lo devuelvo
	Int pop(nodo *&lista){
nodo *anterior , *paux ; int elemento ; 
		Anterior = NULL ; paux = lista;
		While(paux && paux->sgte){
			Anterior = paux;
			Paux = paux->sgte;
		}
		If(paux){
			Elemento = paux->dato;  elemento a devolver
			Delete paux;  borro paux
			If(anterior != NULL)  se entro al while
				Anterior->sgte = NULL;  anterior apunta a NULL, es el nuevo ultimo
			Else  paux = NULL, cuando queda solo un elemento, no se entra al while
				Lista = NULL;   borro la lista
			Return elemento;  devuelve el elemento que saco
		} else{
			Cout<<”ERROR: LISTA VACIA”<<endl;
		} }

    
    
    
    
    char caracter;
    int caracterASCII, noReconocido = 0, estado = 0, columna;
    char* expresion;
    
    printf ("Por favor, ingrese una expresion\n");
    
    
    // strlen("hola") = 4 
    for(int i = 0; i< strlen(expresion); i++)
    {
        
    }

    while( ){
            if (caracter !=  ' '){
                 
            }
            else {
                tipodevariable(estado,);
                estado = 0;
            }
    }
        tipodevariable(estado,salida);
    

    return 0;
}
aQueColumnaVoy(caracter, salida);
estado = TT[estado][aQueColumnaVoy(caracter,)]; */