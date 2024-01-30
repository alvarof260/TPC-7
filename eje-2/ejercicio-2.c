/*
escirba un programa en c que permita al usuario ingresar un arreglo de numeros enteros de
tamaño variable y luego encuentre y muestre el subarreglo contiguo de dos numeros con la suma
maxima.
adicionalmente guarde en el arreglo de salida la posicion de cada numero respectivamente
y al final el valor de la suma.
el arreglo de salida debe ser de 5 elementos
*/

#include <stdio.h>
#include <stdlib.h>

void cargarArreglo(int *puntero, int tama);
void mostrarArreglo(int *puntero, int tama);

int main()
{
    int *puntero, tama, suma = 0;
    int punteroSalida[5];
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tama);
    puntero = (int *)malloc(tama * sizeof(int));
    cargarArreglo(puntero, tama);
    for(int j = 0; j < tama; j++)
    {
        suma = puntero[j] + puntero[j+1];
        if(suma > punteroSalida[4])
        {
            punteroSalida[0] = puntero[j];
            punteroSalida[1] = puntero[j+1];
            punteroSalida[2] = j;
            punteroSalida[3] = j+1;
            punteroSalida[4] = suma;
        }
    }
    mostrarArreglo(puntero, tama);
    printf("\n");
    mostrarArreglo(punteroSalida, 5);
    free(puntero);
    return 0;
}

void cargarArreglo(int *puntero, int tama)
{
    for (int i = 0; i < tama; i++)
    {
        printf("Ingrese el valor %d: ", i);
        scanf("%d", &puntero[i]);
    }
}

void mostrarArreglo(int *puntero, int tama)
{
    for (int i = 0; i < tama; i++)
    {
        printf("%d ", puntero[i]);
    }
}
