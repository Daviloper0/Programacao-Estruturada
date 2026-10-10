#ifndef DESENHO_H
#define DESENHO_H

#define MAX_DIM 1024

void linha_horizontal(
    unsigned char img[][MAX_DIM],
    int x, int y, int comprimento,
    unsigned char cor);

void linha_vertical(
    unsigned char img[][MAX_DIM],
    int x, int y, int comprimento,
    unsigned char cor);

void pinta_retangulo(
    unsigned char img[][MAX_DIM],
    int x, int y,
    int largura, int altura,
    unsigned char cor);

void desenha_segmento(
    unsigned char img[][MAX_DIM],
    int x, int y, int tamanho,
    unsigned char cor, int orientacao);

int salva_pbm(const char nome_arquivo[],
              unsigned char img[][MAX_DIM],
              int largura,
              int altura);

#endif
