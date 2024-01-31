#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mezclarCadenas(char *cad1, char *cad2, int pos);

int main(){
    char *cadena1;
    char *cadena2;
    int tama1, tama2;
    int posicion;

    printf("Ingrese el tamaño de la cadena1: ");
    scanf("%d", &tama1);
    cadena1 = (char *)malloc((tama1+1) * sizeof(char)); // +1 para el carácter nulo
    printf("Ingrese la cadena1: ");
    scanf("%s", cadena1);
    printf("Ingrese el tamaño de la cadena2: ");
    scanf("%d", &tama2);
    cadena2 = (char *)malloc((tama2+1) * sizeof(char)); // +1 para el carácter nulo
    printf("Ingrese la cadena2: ");
    scanf("%s", cadena2);
    printf("Ingrese la posición en la que se mezclarán las cadenas: ");
    scanf("%d", &posicion);

    mezclarCadenas(cadena1, cadena2, posicion);

    free(cadena1);
    free(cadena2);

    return 0;
}

void mezclarCadenas(char *cad1, char *cad2, int pos)
{
    int i = 0;
    while (*cad1 != '\0' || *cad2 != '\0')
    {
        if(i == pos && *cad2 != '\0'){
            while (*cad2 != '\0')
            {
                printf("%c", *cad2);
                cad2++;
            }
            
        }
        else if(*cad1 != '\0'){
            printf("%c", *cad1);
            cad1++;
        }
        i++;
    }
    printf("\n");
}