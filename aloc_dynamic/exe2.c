#include <stdio.h>
#define MAXTAM 10
#include <stdlib.h>


void aloca(int *ptr){
    int x;
    float media;
    scanf("%d", &x);
    ptr = (int*) malloc(x * (sizeof(int)));
    int maior, menor;
    
    for(int i = 0; i<x; i++){
        
        scanf("%d", &ptr[i]);
        
    }
    
    for(int i = 0; i<x; i++){
        
        printf("\n%d", ptr[i]);
        
    }
    
    for(int i = 0; i<x; i++){
        
        maior = menor = ptr[0];
        if(ptr[i]>maior)
        {
            maior = ptr[i];
        }
        
        if(ptr[i]<menor){
            menor = ptr[i];
        }
    media += ptr[i];
    }
    media = media/x;
    printf("\nMenor:%d", menor);
    printf("\nMaior:%d", maior);
    printf("\nmedia %.2f", media);
    
    free(ptr);
}


int main() {
    int *vetor;
    
    aloca(vetor);
    
    
    
}