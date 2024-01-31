#include <stdio.h>
#include <stdlib.h>

void cargarNotas(float *notas, int alumnos);
float calcularPromedio(float *notas, int alumnos, float *promedio);

int main(){
    srand(time(NULL));
    int alumnos;
    float *notas, promedio;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &alumnos);
    notas = (float *)malloc(alumnos * (sizeof(float)));
    cargarNotas(notas, alumnos);
    for (int i = 0; i < alumnos; i++)
    {
        printf("Nota del alumno %d: %.2f\n", i, notas[i]);
    }
    float mejorNota = calcularPromedio(notas, alumnos, &promedio);
    printf("El promedio de notas es: %.2f\n", promedio);
    printf("La mejor nota es: %.2f\n", mejorNota);
    free(notas);
    return 0;
}

void cargarNotas(float *notas, int alumnos)
{
    int i;
    for(i = 0; i < alumnos; i++)
    {
        *notas = rand() % 11 + 1;
        notas++;
    }
}

float calcularPromedio(float *notas, int alumnos, float *promedio)
{
    float mejorNota = 0;
    for(int i = 0; i < alumnos; i++)
    {
        if(*notas > mejorNota)
        {
            mejorNota = *notas;
        }
        *promedio += *notas;
        notas++;
    }
    *promedio /= alumnos;
    return mejorNota;
}

