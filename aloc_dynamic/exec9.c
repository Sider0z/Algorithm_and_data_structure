#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{

    int x, i, j;
    double *vetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &x);

    vetor = (double*) malloc(x * sizeof(double));   
    srand(time(NULL));

    for ( i = 0; i < x; i++)
    {
        vetor[i] = rand() % 100;
    }
    
    for ( i = 0; i < x; i++){

        printf("%.2lf ", vetor[i]);

    }
}