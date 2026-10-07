/*Entrada
A entrada é composta de 3 linhas, cada uma contendo 2 inteiros:

A primeira linha contém as coordenadas do canto inferior esquerdo do retângulo.
A segunda linha contém as coordenadas do canto superior direito.
A terceira linha contém as coordenadas do ponto que representa o tiro.
*/

/*
4 2
18 12
10 8

"SIM"

4 2
18 12
23 3

"NAO"
*/

#include <stdio.h>

int main() {
    int x_comeco, y_comeco, x_final, y_final, x_tiro, y_tiro = 0;
    scanf("%d %d", &x_comeco, &y_comeco);
    scanf("%d %d", &x_final, &y_final);
    scanf("%d %d", &x_tiro, &y_tiro);

    if (x_tiro >= x_comeco && x_tiro <= x_final && y_tiro >= y_comeco && y_tiro <= y_final) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
}