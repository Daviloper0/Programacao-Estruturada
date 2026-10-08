#include <stdio.h>

#include "desenho.h"
#include "fractal.h"

unsigned char imagem[MAX_DIM][MAX_DIM] = {0};

int main() {
    int tipo, profundidade, sucesso;

    printf("Escolha o fractal:\n");
    printf("1 - Conjunto de Cantor\n");
    printf("2 - Arvore H\n");
    printf("3 - Tapete de Sierpinski\n");

    printf("Fractal: ");
    scanf("%d", &tipo);

    printf("Profundidade: ");
    scanf("%d", &profundidade);

    if (profundidade < 0) {
        printf("Profundidade invalida.\n");
        return 1;
    }

    if (tipo == 1) {
        if (profundidade > 7) {
            printf("Profundidade muito grande.\n");
            return 1;
        }

        sucesso = cantor(
            imagem, profundidade, "cantor.pbm");

    } else if (tipo == 2) {
        if (profundidade > 14) {
            printf("Profundidade muito grande.\n");
            return 1;
        }

        sucesso = arvore_h(
            imagem, profundidade, "arvore_h.pbm");

    } else if (tipo == 3) {
        if (profundidade > 6) {
            printf("Profundidade muito grande.\n");
            return 1;
        }

        sucesso = tapete(
            imagem, profundidade, "tapete.pbm");

    } else {
        printf("Fractal invalido.\n");
        return 1;
    }

    if (!sucesso) {
        printf("Erro ao salvar a imagem.\n");
        return 1;
    }

    printf("Imagem salva com sucesso.\n");

    return 0;
}
