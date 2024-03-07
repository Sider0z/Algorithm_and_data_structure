#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    int *p = &a;

    *p *= 2;
    
    printf("%d", a);


return 0;
}
