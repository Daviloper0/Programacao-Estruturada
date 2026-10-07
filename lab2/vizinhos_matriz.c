#include <stdio.h>

/*
1 1 0 0
1 1 0 0
0 0 0 0

centro = (0,0)
(i - 1)(j - 1) oob
(i - 1)(j) oob
(i - 1)(j + 1) oob
(i) (j - 1) oob
(i) (j) não considera
(i) (j + 1) 1
(i + 1) (j - 1) oob
(i + 1) (j) 1
(i + 1) (j + 1) 1
*/

int conta_vizinhos(int matriz[][100], int n_linhas, int n_colunas, int lin, int col) {
    short int contagem_vizinhos = 0;

    for (short int i = lin - 1; i <= lin + 1; i++) {
        for (short int j = col - 1; j <= col + 1; j++) {
            if (i == lin && j == col) continue;
            if (i < 0 || i >= n_linhas || j < 0 || j >= n_colunas) continue;
            
            if (matriz[i][j] == 1) contagem_vizinhos++;
        }
    }
    return contagem_vizinhos;
}

int main () {
    int matriz1[3][4] = {{1, 0, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};

    int quantidade_vizinhos_1 = conta_vizinhos(matriz1, 3, 4, 1, 1);

    if (quantidade_vizinhos_1 == 4) {
        printf("Passou no teste! \n");
    } else {
        printf("Reprovou no teste! %d\n", quantidade_vizinhos_1);
    }
    
}