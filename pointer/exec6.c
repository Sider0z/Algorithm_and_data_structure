#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=2;
    float b=3;
    double c=4;
    
    printf("%d, %f, %lf\n",a, b, c);
    
    int *pont1 = &a;
    float *pont2 = &b;
    double *pont3 = &c;
    
    *pont1 +=2;
    *pont2 +=2;
    *pont3 +=2;
    
    printf("%d, %f, %lf",a, b, c);
    
}
