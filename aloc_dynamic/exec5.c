#include <stdio.h>
#include<stdlib.h>

int main()
{

    int *array;

    array = (int*) malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < 5; i++)
    {
       printf("\n%d", array[i]);
    }

}