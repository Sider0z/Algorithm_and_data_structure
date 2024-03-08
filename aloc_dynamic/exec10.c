#include <stdio.h>
#include<stdlib.h>

int main()
{

    int *array, x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    array = (int*) malloc(x * sizeof(int));

    for(int i = 0; i < x; i++)
    {
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < x; i++)
    {
        if(array[i] % y == 0)
        {
       printf("O numero %d eh multiplo de %d.\n", array[i], y);
        }
        else{

            printf(" O numero %d nao eh multiplo de %d.\n", array[i], y);
        }
    }    

}