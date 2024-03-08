#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{

    int x, i, j;
    char *string, vogais[] = "aAeEiIoOuU";

    printf("Digite o tamanho da string: ");
    scanf("%d", &x);

    string = (char*) malloc((x + 1) * sizeof(char));

    printf("Digite a string: ");

    for(i = 0; i< x; i++){
        scanf(" %c", &string[i]);
    }

    for( i = 0, j = 0 ; string[i] !='\0'; i++)
    {

        if(strchr(vogais, string[i]) == NULL){
            
            string[j] = string[i];
            j++; 
        }

        
    }

    string[j] = '\0';
    printf("\nString sem vogal %s\n", string);

    free(string);
}