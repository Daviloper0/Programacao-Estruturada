#include <stdio.h>
#include <string.h>

int eh_palindromo_rec(char str[], int inicio, int fim) {
    if (str[inicio] != str[fim]) return 0;
    if (inicio == fim) return 1;
    if (inicio == fim - 1 && str[inicio] == str[fim]) return 1;
     
    return eh_palindromo_rec(str, inicio + 1, fim - 1);
}

int main() {
    int palindromo1 = eh_palindromo_rec("arara", 0, 4);
    int palindromo2 = eh_palindromo_rec("casa", 0, 3);
    int palindromo3 = eh_palindromo_rec("osso", 0, 3);
    int palindromo4 = eh_palindromo_rec("bolso", 0, 3);
    int palindromo5 = eh_palindromo_rec("bolsb", 0, 3);
    printf("Palindromo 1: %d \n", palindromo1);
    printf("Palindromo 2: %d \n", palindromo2);
    printf("Palindromo 3: %d \n", palindromo3);
    printf("Palindromo 4: %d \n", palindromo4);
    printf("Palindromo 5: %d \n", palindromo5);
    return 0;
}