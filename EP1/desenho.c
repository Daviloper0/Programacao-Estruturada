#include "desenho.h"
#include <stdio.h>

/*
 * FUNCOES A SEREM IMPLEMENTADAS PELO ALUNO
 */

void linha_horizontal(
    unsigned char img[][MAX_DIM],
    int x, int y, int comprimento,
    unsigned char cor) {

    /* TODO: implemente esta funcao. */
}

void linha_vertical(
    unsigned char img[][MAX_DIM],
    int x, int y, int comprimento,
    unsigned char cor) {

    /* TODO: implemente esta funcao. */
}

void pinta_retangulo(
    unsigned char img[][MAX_DIM],
    int x, int y,
    int largura, int altura,
    unsigned char cor) {

    /* TODO: implemente esta funcao. */
}

/*
 * ================================================================
 * FUNCOES JA IMPLEMENTADAS
 *
 * Nao modifique as funcoes abaixo desta linha.
 * ================================================================
 */

/*
 * Salva em um arquivo PBM a regiao da matriz correspondente
 * as primeiras 'altura' linhas e 'largura' colunas.
 *
 * Retorna 1 em caso de sucesso e 0 em caso de erro.
 */
int salva_pbm(const char nome_arquivo[],
              unsigned char img[][MAX_DIM],
              int largura,
              int altura) {
    FILE *arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL)
        return 0;

    fprintf(arquivo, "P1\n");
    fprintf(arquivo, "%d %d\n", largura, altura);

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            fprintf(arquivo, "%d", img[i][j]);

            if (j < largura - 1)
                fprintf(arquivo, " ");
        }

        fprintf(arquivo, "\n");
    }

    if (ferror(arquivo)) {
        fclose(arquivo);
        return 0;
    }

    if (fclose(arquivo) != 0)
        return 0;

    return 1;
}
