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
    return (f->tam == 0);
}

bool estaCheia(Fila *f) {
    return (f->tam == f->max);
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

void limpaFila(Fila *f){

    free(f->dados);
    f->dados = NULL;
    f->inicio = 0;
    f->fim= -1;
}

void furaFila(Fila *f, int num){
    if(!estaVazia(f)){
    f->inicio =0;
    f->dados[f->inicio] = num;
    }
}

Fila *inverteFila(Fila *f){

Fila *aux = criarFila(f->max);
int elemento;
while(!estaVazia(f))
{   
    elemento = remover(f);
    inserir(aux, elemento);
}
    return aux;

}


int main() {

    Fila *f = criarFila(8);

    inserir(f, 10);
    inserir(f, 20);
    inserir(f, 50);
    inserir(f, 80);
    inserir(f, 90);
    inserir(f, 200);
    inserir(f, 40);
    inserir(f, 400);
    remover(f);
    remover(f);
    remover(f);
    inserir(f, 500);

  
    printf("\nFila invertida:\n");
    Fila *f_invertida = inverteFila(f);
    imprimeFila(f_invertida);

    return 0;
}