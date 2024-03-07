#include <stdio.h>
#include<stdlib.h>

int main()
{

    int *array, x;

    scanf("%d", &x);

    array = (int*) malloc(x * sizeof(int));

    for(int i = 0; i < x; i++)
    {
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < x; i++)
    {
        if(array[i] % 2 == 0)
        {
       printf("\n O numero %d eh par.\n", array[i]);
        }
        else{

            printf(" O numero %d eh impar.\n", array[i]);
        }
    }    

}