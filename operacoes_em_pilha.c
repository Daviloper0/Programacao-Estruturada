#include <stdio.h>

int main() {
    int pilha[10];
    int indiceProximoElementoPilha = 0;
    int soma = 0;

    char operacao;
    int numero;

    while (operacao != 'f') {
        scanf(" %c", &operacao);

        if (operacao == 'f') {
            for (short int j = 0; j < indiceProximoElementoPilha; j++) {
                printf("%d ", pilha[j]);
            }
            printf("\n");
            break;
        } else if (operacao == 's') {
            short int numeroElementos = indiceProximoElementoPilha - 1;

            for (short int j = 0; j < numeroElementos; j++) {
                pilha[indiceProximoElementoPilha--] = 0; 
            }

            pilha[0] = soma;
        }
        
        scanf("%d", &numero);
        
        if (operacao == 'a' && indiceProximoElementoPilha <= 9) {
            pilha[indiceProximoElementoPilha++] = numero;
            soma += numero;
            
        } else if (operacao == 'r') {
            for (short int j = 0; j < numero; j++) {
               if (indiceProximoElementoPilha < 0) break;
               soma -= pilha[indiceProximoElementoPilha]; 

               pilha[indiceProximoElementoPilha--] = 0;
            }

        }
    }
        
}