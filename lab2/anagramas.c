#include <stdio.h>
#include <string.h>

int anagrama(char S[], char T[]) {
    short int tamanhoS = strlen(S);
    short int tamanhoT = strlen(T);
    short int somaTamanhoS = 0;
    short int somaTamanhoT = 0;

    if (tamanhoS != tamanhoT) {
        return 0;
    }
    
    for (short int i = 0; i < tamanhoS; i++) {
        somaTamanhoS += S[i];
        somaTamanhoT += T[i];
    }
    if (somaTamanhoS != somaTamanhoT) return 0;
    
    return 1;
    
}

int main() {
    printf("Anagrama de arco e caro: %d", anagrama("arco", "caro"));
    printf("Anagrama de casa e caso: %d", anagrama("casa", "caso"));
    printf("Anagrama de aaab e aabb: %d", anagrama("aaab", "aabb"));
    printf("Anagrama de deltarune e undertale: %d", anagrama("deltarune", "undertale"));
    return 0;
}