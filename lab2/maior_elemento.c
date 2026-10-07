#include <stdio.h>

void maiores_linhas(int matriz[][100], int n_linhas, int n_colunas,int maiores[]) {
    short int indice_maiores = 0;
    short int maior_atual;

    for (short int i = 0; i < n_linhas; i++) {
        maior_atual = matriz[i][0];

        for (short int j = 1; j < n_colunas; j++) {
            if (matriz[i][j] > maior_atual) maior_atual = matriz[i][j];
        }
        maiores[indice_maiores++] = maior_atual;
    }
}
// o programa não precisa mesmo de main, mas foi últil pra testar, tive problema por não inicializar a variável indice_maiores
int main () {
    int maiores[3] = {0};
    int matriz1[3][4] = {{3, -2, 8, 5}, {7, 7, 1, 4}, {-3, -10, -5, -1}};

    maiores_linhas(matriz1, 3, 4, maiores);
    
    for (int i = 0; i < 3; i++) {
        printf("%d \n", maiores[i]);
    }
    
    
}