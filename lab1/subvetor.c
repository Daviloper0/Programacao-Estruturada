/*
Chamaremos de subvetor de um vetor o que sobra depois que zero ou mais elementos são apagados, sem alterar a ordem dos elementos restantes. Por exemplo, 12 13 10 3 é uma subvetor de 11 12 13 11 10 9 7 3 3, mas não é uma subvetor de 11 12 10 11 13 9 7 3 3. Escreva uma função que determine se sub_vec é uma subvetor de vec.
*/
#include <stdio.h>

int eh_subvetor(int sub_vec[], int m, int vec[], int n) {
    int indice_subvetor = 0;

    for (int i = 0; i < n; i++) {
        if (vec[i] == sub_vec[indice_subvetor]) {
            indice_subvetor++;
        }
    }
    return indice_subvetor == m ? 1 : 0; 
}
int main() {
    int subvec1[] = {12, 13, 10, 3};
    int vec1[] = {11, 12, 13, 11, 10, 9, 7, 3, 3};
    int m1 = 4;
    int n1 = 9;
    
    int subvec2[] = {12, 13, 10, 3};
    int vec2[] = {11, 12, 10, 11, 13, 9, 7, 3, 3};
    int m2 = 4;
    int n2 = 9;
    printf("%d\n", eh_subvetor(subvec1, m1, vec1, n1));
    printf("%d\n", eh_subvetor(subvec2, m2, vec2, n2));
    return 0;
}