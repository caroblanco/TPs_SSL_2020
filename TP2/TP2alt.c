#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// estructura de la pila
struct pila
{
	int cantidadElementos;	// capacidad de la pila
	int top;
	char *items;
};

struct estadoCima
{
    int estado;
    char cima;
};

int ProcesarEstado(struct estadoCima, struct pila* pila );
int ObtenerEP(int, struct pila * pila);
int ObtenerEC(char c);
struct pila* NuevaPila(int);
int CantidadElementosPila(struct pila *pt);
int EstaVacia(struct pila *pt);
int EstaLlena(struct pila *pt);
int Pop(struct pila *pt);
void Push(struct pila *pt, char);

int main(){
    
    struct estadoCima TT[6][5] = 
    {
        //q0,$
        {   //0         [1-9]      [op]       (         )
            {-1,' '}, { 1,'$'}, {-1,' '}, { 0,'S'}, {-1,' '}
        },
        //q1,$
        {
            { 1,'$'}, { 1,'$'}, { 0,'$'}, {-1,' '}, {-1,' '}
        },
        //q0,R
        {
            {-1,' '},  {1,'R'}, {-1,' '}, {0,'S'}, {-1,' '}
        },
        //q1,R
        {
            { 1,'R'}, { 1,'R'}, {0,'R'}, {-1,' '}, {2,'e'}
        },
        //q2,R
        {
            {-1,' '}, {-1,' '}, { 0,'R'}, {-1,' '}, {2,'e'}
        },
        //q2,$
        {
            {-1,' '}, {-1,' '}, { 0,'$'}, {-1,' '}, {-1,' '}
        }
    };

    FILE* consola_entrada;
    FILE* consola_salida;
    
    consola_entrada = stdin; //"archivo" de la consola para ingresar datos
    consola_salida = stdout; //"archivo" de la consola para mostrar datos
    
    //char expresion[50];
    //int expresionInvalida = 0;
    while (1) //para probar mas de una vez
    {
        char expresion[50];
        int expresionInvalida = 0;
        printf("Ingrese una expresion: "); //seria lo mismo que fprintf(stdout,"Ingrese una expresion: ");
        fscanf(consola_entrada, "%s", expresion);
        
        fprintf (consola_salida,"\n%s ",expresion);
        
        struct pila *pila = NuevaPila(strlen(expresion));
        struct estadoCima estadoCimaTemporal;
        
        estadoCimaTemporal.estado = 0;

        

        Push(pila,'$');//Simbolo de pila vacia
        for(int i = 0; i < strlen(expresion); i++) //recorro todos los caracteres, ignoro " "
        {
            if(!expresionInvalida)
                if(expresion[i] != ' ')
                {
                    //para debug
                    //fputc(expresion[i],consola_salida);  
                        
                    //obtengo el siguiente estado
                    //TT [Y][X] [Estado][Cima]

                    estadoCimaTemporal = TT[ObtenerEP(estadoCimaTemporal.estado,pila)][ObtenerEC(expresion[i])];
                    //para debug
                    //fprintf(consola_salida,"(%d,%c)",estadoCimaTemporal.estado, estadoCimaTemporal.cima);
                    if(ProcesarEstado(estadoCimaTemporal,pila) == 0)
                        expresionInvalida = 1;

                }
        }
        if(!expresionInvalida)
        {
            //Para debug
            //printf("\n\n(%d,%c)",estadoCimaTemporal.estado,Peek(pila));

            if( estadoCimaTemporal.estado == 1 && Peek(pila) == '$' ||
                estadoCimaTemporal.estado == 2 && Peek(pila) == '$' )
            {
                fprintf(consola_salida,"es una expresion VALIDA :3\n");
            }
            else
            {
                fprintf(consola_salida,"es una expresion INVALIDA :(\n");
            }
            
        }
        else
        {
            fprintf(consola_salida,"es una expresion INVALIDA :(\n");
        }
        
    }
    return 0;
}

int ProcesarEstado(struct estadoCima ec, struct pila* pila )
{
    char tempPila;

    if(ec.estado == -1)
    {
        return 0;
    }
    else if((ec.estado == 0 && ec.cima == '$') ||
            (ec.estado == 0 && ec.cima == 'R') ||
            (ec.estado == 1 && ec.cima == '$') ||
            (ec.estado == 1 && ec.cima == 'R') ||
            (ec.estado == 2 && ec.cima == '$') ||
            (ec.estado == 2 && ec.cima == 'R') )
    {
        tempPila = Pop(pila);
        Push(pila, tempPila);
        return 1;
    }
    else if(ec.estado == 0 && ec.cima == 'S')//R$ / RR
    {
        tempPila = Pop(pila);
        Push(pila, tempPila);
        Push(pila, 'R');
        return 1;   
    }
    else if (ec.estado == 2 && ec.cima == 'e')//E
    {
        tempPila = Pop(pila);
        return 1;
    }
    
    return 0;
}
int ObtenerEP(int est, struct pila * pila)
{
    int estado = 0;
    int cima = Peek(pila);

    if(est == 0 && cima == '$')
        return 0;
    else if (est == 1 && cima == '$')
        return 1;
    else if (est == 0 && cima == 'R')
        return 2;
    else if (est == 1 && cima == 'R')
        return 3;
    else if (est == 2 && cima == 'R')
        return 4;
    else if (est == 2 && cima == '$')
        return 5;
}
int ObtenerEC (char c)
{
    if (c == '0') 
        return 0;
    else if (c >= '1' &&  c <= '9') 
        return 1;
    else if (c == '+' || c == '-' || c == '*' || c == '/')
        return 2;
    else if (c == '(') 
        return 3;
    else if (c == ')')
        return 4;
    else // error
        return 5;
}
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
void Push(struct pila *pt, char x)
{
	//Si esta llena, tirar un error
	if (EstaLlena(pt))
	{
		printf("OverFlow\n");
		exit(EXIT_FAILURE);
	}
    //para debug
	//printf("Push %c\n", x);
	
	//añadir elemento
	pt->items[++pt->top] = x;
}

//Devuelve el elemento de arriba de la pila (no lo saca)
int Peek(struct pila *pt)
{
	// si no esta vacia
	if (!EstaVacia(pt))
		return pt->items[pt->top];
	else
		exit(EXIT_FAILURE);
}

// quita el elemento de arriba de la pila
int Pop(struct pila *pt)
{
	// se fija si esta vacia
	if (EstaVacia(pt))
	{
		printf("UnderFlow");
		exit(EXIT_FAILURE);
	}
    //para debug
	//printf("Pop %c\n", Peek(pt));
	// decrementa el tamaño de la pila (quita el elemento) y lo devuelve
	return pt->items[pt->top--];
}

