#include <stdio.h>
#include <stdlib.h>

void maior_menor(int *maior, int *menor, int *vetor, int x)
{
    *maior = *menor = vetor[0];
    
    for (int i = 0; i < x; i++)
    {
        if (*maior < vetor[i])
        {
            *maior = vetor[i];
        }
        
        if (*menor > vetor[i])
        {
            *menor = vetor[i];
        }    
    }
}

int main()
{
    int x;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &x);
    
    int *vetor = (int*) malloc(sizeof(int) * x);
    
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    int maior, menor;
    maior_menor(&maior, &menor, vetor, x);
    
    printf("Menor: %d. Maior: %d\n", menor, maior);
    
    free(vetor);
    return 0;
}
