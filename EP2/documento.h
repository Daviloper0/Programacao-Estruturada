#ifndef DOCUMENTO_H
#define DOCUMENTO_H

typedef struct {
    char **linhas;
    int n;
    int capacidade;
} Documento;

/* Inicializa um documento vazio. */
void inicializa_documento(Documento *doc);

/*
 * Adiciona a linha original ao documento, sem copiá-la.
 *
 * A partir desta chamada, o Documento assume a responsabilidade por
 * liberar a memória de linha. O chamador não deve reutilizar nem
 * liberar esse buffer. Passe apenas strings alocadas dinamicamente.
 */
void adiciona_linha(Documento *doc, char *linha);

/*
 * Retorna a linha original de número 1, 2, 3, ...
 * Retorna NULL se o número da linha não existir.
 * A string pertence ao Documento; não deve ser modificada nem liberada.
 */
char *obtem_linha(Documento *doc, int numero);

/* Libera cada linha original e o vetor de ponteiros. */
void libera_documento(Documento *doc);

#endif
