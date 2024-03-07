#include <stdio.h>
#include <stdlib.h>

void aloca_matriz(double ***mat){
    int col, linha;

    printf("\nQuantidade colunas: \n");
    scanf("%d", &col);

    *mat = (double**) malloc(col * sizeof(double*));

    printf("Quantidade de linhas: \n");
    scanf("%d", &linha);

    for(int i = 0; i < col; i++)
    {
        (*mat)[i] = (double*) malloc(linha * sizeof(double));   
    }

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < linha; j++)
        {
            scanf("%lf", &(*mat)[i][j]); 
        }
    }

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < linha; j++)
        {
            printf("%lf ", (*mat)[i][j]); 
        }
        printf("\n");
    }
}

void free_matriz(double **mat, int col) {
    for(int i = 0; i < col; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main(){
    double **mat;
    aloca_matriz(&mat);
    
    int col;
    printf("\nDigite o número de colunas para liberar: \n");
    scanf("%d", &col);
    free_matriz(mat, col);

    return 0;
}
