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
    if (estaCheia(f))
        return false;

    f->fim = (f->fim + 1) % f->max;
    f->dados[f->fim] = dado;
    f->tam++;
    return true;
}

int remover(Fila *f) {
    if (estaVazia(f))
        return -1;

    int aux = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->max;
    f->tam--;
    return aux;
}

void unirFilasOrdemDecrescente(Fila *f1, Fila *f2, Fila *f3) {
    while (!estaVazia(f1) && !estaVazia(f2)) {
        int dado_f1 = f1->dados[f1->inicio];
        int dado_f2 = f2->dados[f2->inicio];
        if (dado_f1 > dado_f2) {
            inserir(f3, dado_f1);
            remover(f1);
        } else {
            inserir(f3, dado_f2);
            remover(f2);
        }
    }
    while (!estaVazia(f1)) {
        inserir(f3, f1->dados[f1->inicio]);
        remover(f1);
    }
    while (!estaVazia(f2)) {
        inserir(f3, f2->dados[f2->inicio]);
        remover(f2);
    }
}

int main() {
    Fila *F1 = criarFila(5);
    Fila *F2 = criarFila(5);
    
    inserir(F1, 5);
    inserir(F1, 10);
    inserir(F1, 15);
    inserir(F1, 20);
    inserir(F1, 25);

    inserir(F2, 2);
    inserir(F2, 7);
    inserir(F2, 12);
    inserir(F2, 17);
    inserir(F2, 22);

    Fila *F3 = criarFila(10);

    unirFilasOrdemDecrescente(F1, F2, F3);

    printf("Fila F3 (ordem decrescente):\n");
    while (!estaVazia(F3)) {
        printf("%d\n", remover(F3));
    }

    free(F1->dados);
    free(F1);
    free(F2->dados);
    free(F2);
    free(F3->dados);
    free(F3);

    return 0;
}