#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aQueColumnaVoy (char cCaracter){
    
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
typedef struct 
{
    int estado;
    char cimapila;
} otracosa ;

int main(){

    int EE [6][6] =
        {
    //   0   1-9  ops   (    )   error
        {7,   1,   7,   2,   7,   7},  //q0,$        0     EE.estado = 7 EE.cimapila = 'E'
        {1,   1,   0,   7,   7,   7},  //q1,$        1     :3
        {7,   3,   7,   2,   7,   7},  //q0,R        2    
        {3,   3,   2,   7,   5,   7},  //q1,R        3    
        {7,   7,   2,   7,   5,   7},  //q2,R        4    
        {7,   7,   0,   7,   7,   7},  //q2,$        5    
        {7,   7,   7,   7,   7,   7}   //error       6  
        };
    char PP [6][6] =
        {
        // 0    1-9    ops     (     )     error
        {'E',   '$',   'E',   'R',  'E',   'E'},  //q0,$        0     
        {'$',   '$',   '$',   'E',  'E',   'E'},  //q1,$        1     
        {'E',   'R',   'E',   'R',  'E',   'E'},  //q0,R        2     
        {'R',   'R',   'R',   'E',  '$',   'E'},  //q1,R        3    
        {'E',   'E',   'R',   'E',  '$',   'E'},  //q2,R        4    
        {'E',   'E',   '$',   'E',  'E',   'E'},  //q2,$        5    
        {'E',   'E',   'E',   'E',  'E',   'E'}   //error       6  
        };
    
   
   
    char caracter, muestra, tipo;
    int caracterASCII, noReconocido = 0, estado = 0, columna;
    otracosa posicionCompleta; 
    char expresion[100];
    
    FILE* consola_entrada;
    FILE* consola_salida;
    
    consola_entrada = stdin; //"archivo" de la consola para ingresar datos
    consola_salida = stdout; //"archivo" de la consola para mostrar datos
    
    printf("Ingrese una expresion: "); //seria lo mismo que fprintf(stdout,"Ingrese una expresion: ");
    fscanf(consola_entrada, "%s", &expresion);
    printf ("%s",expresion);
    
    for(int i = 0; i < strlen(expresion); i++)
    {
        fputc(expresion[i],consola_salida);
        if(expresion[i] != " ")
            estado = [estado][aQueColumnaVoy(caracter)];
        
    }

    if(){
        printf ("No se pudo leer el archivo");
    }
    else{
        while(fread(&caracter, sizeof(caracter), 1, archivo))
        {
            fputc(caracter, salida);
            aQueColumnaVoy(caracter, salida);// 
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
    tipodevariable(estado,salida);
    }

    fclose(consola_entrada);
    fclose(consola_salida);
    
    return 0;
}
   // estructura de la pila
struct pila
{
	int cantidadElementos;	// capacidad de la pila
	int top;		
	char *items;
};

// funcion para crear la pila
struct pila* NuevaPila(int cantidadElementos)
{
	struct pila *pt = (struct pila*)malloc(sizeof(struct pila));

	pt->cantidadElementos = cantidadElementos;
	pt->top = -1;
	pt->items = (char*)malloc(sizeof(char) * cantidadElementos);

	return pt;
}

// funcion para ver cuantos elementos tiene la pila
int CantidadElementosPila(struct pila *pt)
{
	return pt->top + 1;
}

// funcion para ver si la pila esta vacia
int EstaVacia(struct pila *pt)
{
	return pt->top == -1;	
}

// funcion para ver si la pila esta llena
int EstaLlena(struct pila *pt)
{
	return pt->top == pt->cantidadElementos - 1;	
}

// funcion para añadir un elemento a la pila
void Push(struct pila *pt, int x)
{
	//Si esta llena, tirar un error
	if (EstaLlena(pt))
	{
		printf("OverFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	printf("Push %c\n", x);
	
	//añadir elemento
	pt->items[++pt->top] = x;
}



// quita el elemento de arriba de la pila
int Pop(struct pila *pt)
{
	// se fija si esta vacia
	if (EstaVacia(pt))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	printf("Pop %c\n", Peek(pt));

	
	// decrementa el tamaño de la pila (quita el elemento) y lo devuelve
	return pt->items[pt->top--];
}





















































































//Devuelve el elemento de arriba de la pila (no lo saca)
\*int Peek(struct pila *pt)
{
	// si no esta vacia
	if (!EstaVacia(pt))
		return pt->items[pt->top];
	else
		exit(EXIT_FAILURE);
}

/*