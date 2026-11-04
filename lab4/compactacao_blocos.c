#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int valor;
    int quantidade;
} Bloco;

Bloco *compacta(const int v[], int n, int *n_blocos) {
    Bloco *blocos_compactados_grande = malloc(n * sizeof(Bloco));
    if (blocos_compactados_grande == NULL) return NULL;

    *n_blocos = 0;

    for (int i = 0, j = 0; i < n; i++) {
        if (i == 0 || v[i - 1] != v[i]) { //aqui antes eu estava verificando i != 0 && v[i - 1] != v[i], mas isso ignorava o primeiro caso
            (*n_blocos)++;
            j = 0;
        }
        blocos_compactados_grande[*n_blocos - 1] = (Bloco) {v[i], ++j}; // aí aqui teve que ajustar também, de n_blocos para n_blocos - 1.
    }

    Bloco *blocos_compactados = realloc(blocos_compactados_grande, *n_blocos * sizeof(Bloco));
    if (blocos_compactados != NULL) return blocos_compactados;
    return NULL;
}
 
int main() {
   	
int v[] = {8, 8, 8, 8, 8, 8};
int n_blocos;

Bloco *b = compacta(v, 6, &n_blocos);

printf("%d:", n_blocos);
for (int i = 0; i < n_blocos; i++)
    printf(" (%d,%d)", b[i].valor, b[i].quantidade);
printf("\n");

free(b);
}