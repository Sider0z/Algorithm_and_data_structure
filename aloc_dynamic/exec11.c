#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main()
{

    int *vetor, contador = 0;

   vetor = (int*) calloc(1500, sizeof(int));

    for(int i = 0; i<1500; i++)
    {
        if(vetor[i]== 0)
        {
            contador += contador;
        }
        vetor[i] = i;
        if(i<=10){

            printf("Os 10 primeiros valores são: %d\n", vetor[i]);
        }

        if(i >= 1450 && i <= 1500 ){

            printf("Os ultimos 10 valores são: %d \n", vetor[i]);

        }
    }


}