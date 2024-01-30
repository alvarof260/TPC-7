#include <stdio.h>
#include <ctype.h>
#define MAX 100

int esConsonante(char c);

int main()
{
    char frase[MAX];
    char *pc;
    int cont_consonantes = 0;
    int cont_mayus = 0;
    int cont_minus = 0;

    printf("Ingrese una frase: ");
    gets(frase);
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (esConsonante(frase[i]))
        {
            cont_consonantes++;
        }
        if (isupper(frase[i]))
        {
            cont_mayus++;
        }
        if (islower(frase[i]) && esConsonante(frase[i]))
        {
            cont_minus++;
        }
    }

    pc = frase;
    printf("la variable pc contiene: %p\n", pc);
    // pc = &frase[3];
    pc = pc + 3;
    printf("la variable pc contiene: %p\n", pc);
    pc = pc + 5;
    printf("la variable pc contiene: %p\n", pc);

    printf("-------------------------\n");
    printf("Cantidad de consonantes: %d\n", cont_consonantes);
    printf("Cantidad de mayusculas: %d\n", cont_mayus);
    printf("Cantidad de minusculas consonantes: %d\n", cont_minus);
    return 0;
}

int esConsonante(char c)
{
    if (isalpha(c))
    {
        c = tolower(c);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}