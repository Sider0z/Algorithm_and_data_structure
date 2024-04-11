#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


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

int fila_div_3(Fila *f1){
    int contador = 0;

for (int i = 0; i < f1->tam; i++) {
        int elemento = f1->dados[(f1->inicio + i) % f1->max];
        if (elemento % 3 == 0) {
            contador++;
        }
    }
    return contador;
}

int main(){

Fila *f1 = criarFila(8);
inserir(f1, 10);
inserir(f1, 3);
inserir(f1, 6);

printf("O numero de elementos diviseis por 3 da fila sao: %d", fila_div_3(f1));

}