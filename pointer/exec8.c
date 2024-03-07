#include <stdio.h>

int maior_menor(int *num1, int *num2, int *num3)
{
    int aux;

    if (*num2 < *num1) {
        aux = *num2;
        *num2 = *num1;
        *num1 = aux;
    }

    if (*num3 < *num1) {
        aux = *num3;
        *num3 = *num1;
        *num1 = aux;
    }

    if (*num3 < *num2) {
        aux = *num3;
        *num3 = *num2;
        *num2 = aux;
    }

    if((*num1 == *num2) && (*num2 == *num3))
    {
        printf("Todos os valores são iguais");
        return 1;
    }

    else
    {
         printf("Todos os valores são diferentes");

        return 0;
    }

    }
int main()
{
    int a , b ,c;
    scanf("%d %d %d", &a, &b, &c);

    


   int resultado = maior_menor(&a, &b, &c);
    printf("\n%d", resultado);
    printf("\n%d %d %d", a, b, c);
}

