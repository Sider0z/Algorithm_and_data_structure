#include <stdio.h>
#define MAXTAM 10
#include <stdlib.h>

typedef struct {
char nome[50];
int quantidade;
float valor;
}produto;

int main() {
int x;
produto *produtos;

printf("Digite o tamanho do vetor");
scanf("%d", &x);
produtos = (produto*) malloc(x * sizeof(produtos));

for(int i = 0; i<x; i++){
    
    scanf("%s", produtos[i].nome);
    scanf("%d", &produtos[i].quantidade);
    scanf("%f", &produtos[i].valor);
    }

for(int i = 0; i<x; i++){
    
    printf("%s\n", produtos[i].nome);
    printf("%d\n", produtos[i].quantidade);
    printf("%.2f\n", produtos[i].valor);
   
    
    }
}