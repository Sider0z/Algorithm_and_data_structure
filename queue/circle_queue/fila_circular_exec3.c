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
    return f->tam == 0;
}

bool inserir(Fila *f, int dado) {
    if (f->tam == f->max)
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

Fila* mergeFilas(Fila *F1, Fila *F2) {
    Fila *F3 = criarFila(F1->max + F2->max);

    while (!estaVazia(F1) && !estaVazia(F2)) {
        if (F1->dados[F1->inicio] < F2->dados[F2->inicio]) {
            inserir(F3, remover(F1));
        } else {
            inserir(F3, remover(F2));
        }
    }

    while (!estaVazia(F1)) {
        inserir(F3, remover(F1));
    }

    while (!estaVazia(F2)) {
        inserir(F3, remover(F2));
    }

    return F3;
}

void imprimirFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    int i = f->inicio;
    do {
        printf("%d ", f->dados[i]);
        i = (i + 1) % f->max;
    } while (i != (f->fim + 1) % f->max);
    printf("\n");
}

int main() {
    Fila *F1 = criarFila(5);
    Fila *F2 = criarFila(5);

    for (int i = 1; i <= 5; i++) {
        inserir(F1, 2 * i);
        inserir(F2, 2 * i - 1);
    }

    printf("Fila F1: ");
    imprimirFila(F1);
    printf("Fila F2: ");
    imprimirFila(F2);

    Fila *F3 = mergeFilas(F1, F2);

    printf("Fila F3 (unida e ordenada): ");
    imprimirFila(F3);

    free(F1->dados);
    free(F1);
    free(F2->dados);
    free(F2);
    free(F3->dados);
    free(F3);

    return 0;
}
