#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VALOR10 1000.00
#define VALOR9 850.00
#define VALOR8 350.00
#define VALOR7 300.00
#define VALOR1O2 100.00
#define TIRO 350.00

void cargarTiros(int *puntos, int tiros);
float calcularGanancia(int *puntos, int tiros, float *perdida);

void main()
{
    srand(time(NULL));
    int tiros;
    int *puntos;
    float plataGastada = 0, ganancia, saldo_final = 0;
    
    printf("Ingrese la cantidad de tiros:\n");
    scanf("%d", &tiros);
    puntos = (int *)malloc(tiros * (sizeof(int)));
    cargarTiros(puntos, tiros);
    ganancia = calcularGanancia(puntos, tiros, &plataGastada);
    for (int i = 0; i < tiros; i++)
    {
        printf("Puntos del tiro %d: %d\n", i, puntos[i]);
    }
    printf("Lo gastado fue: %.2f\n", plataGastada);
    printf("La ganancia es: %.2f\n", ganancia);
    saldo_final = ganancia - plataGastada;
    printf("El saldo final es: %.2f\n", saldo_final);
    free(puntos);
}

void cargarTiros(int *puntos, int tiros)
{
    int i;
    for(i = 0; i < tiros; i++)
    {
        puntos[i] = rand() % 10 + 1;
    }
}

float calcularGanancia(int *puntos, int tiros, float *perdida)
{
    float ganancia = 0;
    for(int j = 0; j < tiros; j++)
    {
        *perdida += TIRO;
        switch (*puntos)
        {
        case 10:
            ganancia += VALOR10;
            break;
        case 9:
            ganancia += VALOR9;
            break;
        case 8:
            *perdida -= VALOR8;
            break;
        case 7:
            *perdida -= VALOR7;
            break;
        case 2:
        case 1:
            *perdida -= VALOR1O2;
            break;
        }
        puntos++;
    }
    return ganancia;
}