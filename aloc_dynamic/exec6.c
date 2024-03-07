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
       printf("\n%d", array[i]);
    }

}