#include <stdio.h>
#define MAXTAM 10
#include <stdlib.h>




int main() {
    int *vetor;
    
    int x;
    scanf("%d", &x);
    vetor = (int*) malloc(x * (sizeof(int)));
    
    for(int i = 0; i<x; i++){
        
        scanf("%d",vetor[i]);
    }
    
    for(int i = 0; i<x; i++){
        
        if(vetor[i] == vetor[i+1]){
            
            
        }
    }
    
}