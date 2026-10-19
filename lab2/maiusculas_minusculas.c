#include <stdio.h>
#include <string.h>

char* inverterCaixas(char Texto[]) {
    for (short int i = 0; i < strlen(Texto); i++) {
        if (Texto[i] >= 65 && Texto[i] <= 90) {
            Texto[i] = Texto[i] + 32;
        } else if (Texto[i] >= 97 && Texto[i] <= 122) {
            Texto[i] = Texto[i] - 32;
        }
    }
    return Texto;
}

int main() {
    char texto[101];
    fgets(texto, 101, stdin);
    
    inverterCaixas(texto);
    puts(texto);
    return 0;
}