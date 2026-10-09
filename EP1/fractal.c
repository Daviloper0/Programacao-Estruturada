#include "fractal.h"

/*
 * FUNCOES A SEREM IMPLEMENTADAS PELO ALUNO
 */

void cantor_rec(
    unsigned char img[][MAX_DIM],
    int x, int y,
    int comprimento,
    int profundidade) 
{
    if (profundidade == 0) {
        return;
    }
    
    linha_horizontal(img, x, y, comprimento, 1);

    if (profundidade > 1) {
        cantor_rec(img, x, y + 4, comprimento / 3, profundidade - 1);
        cantor_rec(img, x + (comprimento / 3) * 2, y + 4, comprimento / 3, profundidade - 1);
    }
}

void arvore_h_rec(
    unsigned char img[][MAX_DIM],
    int x, int y,
    int tamanho,
    int profundidade,
    int orientacao) {

    /* TODO: implemente esta funcao. */
}

void tapete_rec(
    unsigned char img[][MAX_DIM],
    int x,
    int y,
    int lado,
    int profundidade) {

    /* TODO: implemente esta funcao. */
}

/*
 * ================================================================
 * FUNCOES JA IMPLEMENTADAS
 *
 * Nao modifique as funcoes abaixo desta linha.
 * ================================================================
 */

int cantor(
    unsigned char img[][MAX_DIM],
    int profundidade,
    const char nome_arquivo[]) {
    int comprimento = 1;
    int altura_imagem;

    for (int i = 1; i < profundidade; i++)
        comprimento *= 3;

    cantor_rec(img, 0, 1, comprimento, profundidade);

    if (profundidade > 0) {
        altura_imagem = (profundidade - 1) * DIST_Y_CANTOR + 2;
    } else {
        altura_imagem = 1;
    }

    return salva_pbm(nome_arquivo, img, comprimento, altura_imagem);
}

int arvore_h(
    unsigned char img[][MAX_DIM],
    int profundidade,
    const char nome_arquivo[]) {

    int largura, altura, meio;
    int r_min = HTREE_MIN_DIST;
    int r = r_min;

    for (int i = 0; i < (profundidade - 1) / 2; i++)
        r *= 2;

    meio = 2 * r - HTREE_MIN_DIST + 2; /* +2 para borda de 2 pixels */
    altura = largura = 2 * meio + 1;

    arvore_h_rec(
        img,
        meio, meio,
        r,
        profundidade,
        H_HORIZONTAL);

    return salva_pbm(nome_arquivo, img, largura, altura);
}

int tapete(
    unsigned char img[][MAX_DIM],
    int profundidade,
    const char nome_arquivo[]) {
    int lado = 1;

    for (int i = 0; i < profundidade; i++)
        lado *= 3;

    tapete_rec(
        img,
        0,
        0,
        lado,
        profundidade);

    return salva_pbm(nome_arquivo, img, lado, lado);
}
