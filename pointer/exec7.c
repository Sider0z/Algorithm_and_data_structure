#include <stdio.h>
#include <stdlib.h>

void altera_valor(int *ptr1, int *ptr2){
    int aux;

    if (*ptr1 < *ptr2)
    {
       aux = *ptr1;
       *ptr1 = *ptr2;
       *ptr2 = aux;
    }
   
        printf("O valor do 1º numero é : %d. \n O valor do 2º numero é: %d", *ptr1, *ptr2);

}


int main(){

    int num1, num2;

    scanf("%d %d", &num1, &num2);

    altera_valor(&num1, &num2);

}