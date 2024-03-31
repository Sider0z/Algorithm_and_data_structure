#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int inicio, fim, max, tam;
    int *dados;
} Fila;

Fila* criarFila(int max) {
    Fila *f = malloc(sizeof(Fila));

    f->inicio = 0;
    f->fim = -1;
    f->tam = 0;
    f->max = max;
    f->dados = malloc(max * sizeof(int));

    return f;
}

bool estaVazia(Fila *f) {
    if(f->tam == 0)
        return true;
    else
        return false;
}

bool estaCheia(Fila *f) {
    if(f->max == f->tam){
        return true;
    }else{
        return false;
    }
}

bool inserir(Fila *f, int dado) {
    if(estaCheia(f))
        return false;

    f->fim = (f->fim+1) % f->max;
    f->dados[f->fim] = dado;
    f->tam++;

    return true;
}

int remover(Fila *f) {
    if(estaVazia(f) == false){
        int aux = f->dados[f->inicio];
        f->inicio = (f->inicio+1) % f->max;
        f->tam--;
        return aux;
    }
}

void imprimeFila(Fila *f){
    while(!estaVazia(f)){
        printf("%d\n", remover(f));
    }
}

int tamanho (Fila *f){
    return f->tam;
}

void verifica_maior(Fila *f1, Fila *f2){


    if(tamanho(f1) > tamanho(f2))
    {
        printf("A fila 1 eh maior\n");
    }

    else
    {
        printf("A fila 2 eh maior\n");
    }

    
}

int main(){

    Fila *f1 = criarFila(3);
    Fila *f2 = criarFila(4);

    verifica_tam(f1, f2);


}