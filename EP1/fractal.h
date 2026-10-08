#ifndef FRACTAL_H
#define FRACTAL_H

#include "desenho.h"

#define DIST_Y_CANTOR 4
#define HTREE_MIN_DIST 3

#define H_VERTICAL 1
#define H_HORIZONTAL 0

void cantor_rec(
    unsigned char img[][MAX_DIM],
    int x, int y,
    int comprimento,
    int profundidade);

int cantor(
    unsigned char img[][MAX_DIM],
    int profundidade,
    const char nome_arquivo[]);

void arvore_h_rec(
    unsigned char img[][MAX_DIM],
    int x, int y,
    int tamanho,
    int profundidade,
    int orientacao);

int arvore_h(
    unsigned char img[][MAX_DIM],
    int profundidade,
    const char nome_arquivo[]);

void tapete_rec(
    unsigned char img[][MAX_DIM],
    int x,
    int y,
    int lado,
    int profundidade);

int tapete(
    unsigned char img[][MAX_DIM],
    int profundidade,
    const char nome_arquivo[]);

#endif
