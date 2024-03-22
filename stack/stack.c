#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct PILHA
{
    int *dados;
    int tam;
    int topo;
}PILHA;

PILHA* cria_pilha(int tam){

    PILHA *p = malloc(sizeof(PILHA));
    p->topo = -1;
    p->tam = tam;
    p->dados = malloc(tam * sizeof(int));

    return p;
}

bool isEmpty(PILHA *p){

    if(p->topo == -1)
    {
        printf("A pilha esta vazia!");

        return true;
    }

    printf("Não esta vazia!");
    return false;

}

bool isFull(PILHA *p){

    if(p->topo == p->tam - 1){

        printf("O topo está cheio!");
        
        return true;
    }
    else
    {
    printf("Não está cheia");
    return false;
    }
}

bool empilha(PILHA *p, int num){
    if(isFull(p))
    {
        return false;
    }

    else
    {
        p->topo += 1;
        p->dados[p->topo] = num;
        return true;
    }    
}

int desempilha(PILHA *p){

    if(isEmpty(p)== false)
    {
    // Para que o número que esta no topo não se perca atribui-se uma auxiliar para guarda-lo.    
    int aux = p->dados[p->topo];
    p->topo -= 1;
    return aux;
    }
}
