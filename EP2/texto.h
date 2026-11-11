#ifndef TEXTO_H
#define TEXTO_H

typedef struct {
    char **palavras;
    int n;
} LinhaTokenizada;

/*
 * Extrai as palavras de uma linha UTF-8, sem modificar o texto original.
 *
 * - Preserva letras acentuadas, números e maiúsculas/minúsculas.
 * - Considera pontuação e outros caracteres não alfanuméricos separadores.
 * - Aloca uma string independente para cada palavra.
 *
 * Retorna 1 em caso de sucesso e -1 se o texto contiver UTF-8 inválido.
 * Em caso de sucesso (inclusive com zero palavras), o chamador deve
 * liberar o resultado com libera_linha_tokenizada().
 *
 * Requer que o programa configure uma locale UTF-8 antes da chamada,
 * por exemplo: setlocale(LC_CTYPE, "C.UTF-8");
 */
int tokeniza_linha(const char *texto, LinhaTokenizada *resultado);

/* Libera as strings e o vetor de palavras de uma linha tokenizada. */
void libera_linha_tokenizada(LinhaTokenizada *linha);

#endif
