#include <stdio.h>
void trocaInteiros(int *x, int *y){
    int aux;
    
    aux = *x;
    *x = *y;
    *y = aux; 
    
    printf("Valor de x: %d.\n Valor de y: %d", *x , *y);
    
}


int main()
{
   int num1=2, num2=3;
   
   trocaInteiros(&num1, &num2);
    

return 0;
}
