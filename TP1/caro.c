#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char caracter, muestra ;
    int caracterASCII, noRec = 0;
    FILE *archivo = fopen ("numeros.txt", "rb+");
    FILE *salida = fopen ("num_salida.txt", "rb+");

    if(!archivo){
        printf ("no se pudo leer el archivo");
    }
    else{
        while(fread(&caracter, sizeof(caracter), 1, archivo)){

            caracterASCII = caracter;
            
            if(caracterASCII <=57 && caracterASCII>=49){ //empieza con un num del 1-9 -> decimal

                fwrite (&caracter, sizeof(caracter), 1, salida);

                while(fread(&caracter, sizeof(caracter), 1, archivo) && caracter != ','){
                    
                    caracterASCII = caracter;

                    if(caracter<=57 && caracter >=48){  //usa de 0-9 -> decimal
                        fwrite (&caracter, sizeof(caracter), 1, salida);
                    }
                    else{
                        fwrite (&caracter, sizeof(caracter), 1, salida);
                        noRec=1;
                    }
                }
                if (noRec==0){
                    fputs(" --> Numero decimal \n",salida);
                }else {
                    fputs(" --> Numero no reconocido \n",salida);
                }
            }
            else if(caracterASCII == 48){  //octal o hexa
                
                fwrite (&caracter, sizeof(caracter), 1, salida);
                
                if (fread(&caracter, sizeof(caracter), 1, archivo) && caracter != ','){
                    caracterASCII = caracter;
                    
                    if(caracterASCII == 88 || caracterASCII == 120){  //hexa
                        fwrite (&caracter, sizeof(caracter), 1, salida);
                        noRec = 0;
                        while (fread(&caracter, sizeof(caracter), 1, archivo) && caracter != ','){
                            caracterASCII = caracter;
                            if (caracterASCII>= 65 && caracterASCII<=70 || caracter<=57 && caracter >=48){
                                fwrite (&caracter, sizeof(caracter), 1, salida);
                            }
                            else {
                                fwrite (&caracter, sizeof(caracter), 1, salida);
                                noRec=1;
                            }
                        }
                        if (noRec==0){
                            fpust(" --> numero hexadecimal \n", salida);
                        }
                        else{
                            fputs(" --> Numero no reconocido \n",salida);
                        }

                    }
                    else if (caracterASCII>= 48 && caracterASCII<=55){  //octal
                        fwrite (&caracter, sizeof(caracter), 1, salida);
                        noRec = 0;
                       
                        while (fread(&caracter, sizeof(caracter), 1, archivo) && caracter != ','){
                            caracterASCII = caracter;
                            if(caracterASCII>= 48 && caracterASCII<=55){
                                fwrite (&caracter, sizeof(caracter), 1, salida);
                            }
                            else {
                                fwrite (&caracter, sizeof(caracter), 1, salida);
                                noRec=1;
                            }
                        }
                        if (noRec==0){
                            fpust(" --> numero octal \n", salida);
                        }
                        else{
                            fputs(" --> Numero no reconocido \n",salida);
                        }
                    }
                }
            }
            else{ //no reconocido
                fwrite (&caracter, sizeof(caracter), 1, salida);
                while (fread(&caracter, sizeof(caracter), 1, archivo) && caracter != ','){
                    fwrite (&caracter, sizeof(caracter), 1, salida);
                }
                fputs(" --> Numero no reconocido \n",salida);
            }
        }
    }
    
    rewind (salida);
    
    while ((muestra = fgetc(archivo)) != EOF) {
        printf("%c",muestra);
    }

    fclose(archivo);
    fclose(salida);

    return 0;
}