#include "documento.h"
#include "indice.h"
#include "texto.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>
#include <wchar.h>
#include <wctype.h>

void imprime_busca(Indice *indice, Documento *doc, char *palavra);
int processa_arquivo(FILE *arquivo, Documento *p_doc, Indice *p_indice);
void interface_principal(Indice *indice, Documento *doc);

char *le_linha(FILE *arquivo) {
    size_t capacidade = 128;
    size_t tamanho = 0;
    char *linha = malloc_safe(capacidade);
    int c;

    while ((c = fgetc(arquivo)) != EOF && c != '\n') {
        if (tamanho + 1 >= capacidade) {
            capacidade *= 2;
            linha = realloc_safe(linha, capacidade);
        }
        linha[tamanho++] = (char)c;
    }

    if (ferror(arquivo)) {
        fprintf(stderr, "Erro ao ler o arquivo de entrada.\n");
        free(linha);
        exit(EXIT_FAILURE);
    }

    if (c == EOF && tamanho == 0) {
        free(linha);
        return NULL;
    }

    linha[tamanho] = '\0';
    return linha;
}

/* As strings aceitas por setlocale variam entre plataformas. Alem de
 * configurar a locale, verificamos se ela realmente reconhece UTF-8. */
int configura_utf8() {
#ifdef _WIN32
    const char *opcoes[] = {".UTF8", ".UTF-8", "C.UTF-8", ""};
#else
    const char *opcoes[] = {"C.UTF-8", "en_US.UTF-8", ""};
#endif

    for (size_t i = 0; i < sizeof(opcoes) / sizeof(opcoes[0]); i++) {
        if (setlocale(LC_CTYPE, opcoes[i]) == NULL)
            continue;

        /* O caractere 'é' codificado em UTF-8 ocupa exatamente dois bytes. */
        mbstate_t estado = {0};
        wchar_t caractere;
        if (mbrtowc(&caractere, "\xC3\xA9", 2, &estado) == 2 &&
            iswalnum(caractere))
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *nome_arquivo;

    if (argc != 2) {
        printf("ERRO: forneca exatamente um arquivo de entrada.\n");
        printf("Como usar: %s <nome_arquivo>\n", argv[0]);
        return 1;
    }
    nome_arquivo = argv[1];

    if (!configura_utf8()) {
        fprintf(stderr, "Nao foi possivel configurar uma locale UTF-8.\n"
                        "Use um compilador/runtime C com suporte a UTF-8.\n");
        return 1;
    }

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao tentar abrir '%s'. Certifique-se que esse arquivo existe. \n", nome_arquivo);
        return 1;
    }

    Documento doc;
    /* Inicializacao defensiva: permite executar o esqueleto mesmo enquanto
     * inicializa_indice() e apenas um stub. Nao substitui a implementacao
     * dessa funcao pelos alunos. */
    Indice indice = {0};

    inicializa_documento(&doc);
    inicializa_indice(&indice);

    processa_arquivo(arquivo, &doc, &indice);
    interface_principal(&indice, &doc);

    libera_documento(&doc);
    libera_indice(&indice);
    fclose(arquivo);

    return 0;
}

int processa_arquivo(FILE *arquivo, Documento *p_doc, Indice *p_indice) {
    char *linha;
    int numero_linha = 0;

    while ((linha = le_linha(arquivo)) != NULL) {

        numero_linha++;
        linha[strcspn(linha, "\r\n")] = '\0';

        LinhaTokenizada tokens;

        if (tokeniza_linha(linha, &tokens) != 1) {
            printf("Problema ao tentar tokenizar a seguinte linha:\n");
            puts(linha);
            free(linha);
            linha = NULL;
            exit(1);
        }

        for (int i = 0; i < tokens.n; i++) {
            insere_palavra(p_indice, tokens.palavras[i], numero_linha);
        }

        libera_linha_tokenizada(&tokens);
        adiciona_linha(p_doc, linha);
    }

    return 1;
}

void imprime_busca(Indice *indice, Documento *doc, char *palavra) {

    int pos_palavra = busca_palavra(indice, palavra);

    if (pos_palavra == -1) {
        printf("Palavra não está presente no índice!\n");
        return;
    }

    Entrada *ent = &indice->entradas[pos_palavra];

    NoOcorrencia *p =
        primeira_ocorrencia(&ent->ocorrencias);

    while (p != NULL) {
        printf("Linha %d: %s\n",
               p->linha, obtem_linha(doc, p->linha));

        p = p->prox;
    }
}

void interface_principal(Indice *indice, Documento *doc) {
    char comando[512];
    char palavra[256];
    char extra;
    int opcao, numero_linha;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1 <palavra>\t- Buscar palavra\n");
        printf("2 <linha>\t- Remover linha do indice (BONUS)\n");
        printf("3\t\t- Imprimir indice completo\n");
        printf("0\t\t- Sair\n");
        printf("> ");

        if (fgets(comando, sizeof(comando), stdin) == NULL)
            break;

        if (sscanf(comando, "%d", &opcao) != 1) {
            printf("Comando invalido.\n");
            continue;
        }

        switch (opcao) {
        case 1:
            if (sscanf(comando, "%d %255s %c",
                       &opcao, palavra, &extra) != 2) {
                printf("Uso: 1 <palavra>\n");
                break;
            }
            printf("\n===== BUSCA: %s =====\n", palavra);
            imprime_busca(indice, doc, palavra);
            break;

        case 2:
            if (sscanf(comando, "%d %d %c",
                       &opcao, &numero_linha, &extra) != 2) {
                printf("Uso: 2 <numero_da_linha>\n");
                break;
            }

            if (numero_linha < 1 || numero_linha > doc->n) {
                printf("Numero de linha invalido.\n");
                break;
            }

            printf("\n===== REMOVE: %d =====\n", numero_linha);
            remove_linha(indice, numero_linha);
            break;

        case 3:
            if (sscanf(comando, "%d %c",
                       &opcao, &extra) != 1) {
                printf("Uso: 3\n");
                break;
            }

            printf("\n===== INDICE COMPLETO =====\n");
            imprime_indice(indice);
            break;

        case 0:
            if (sscanf(comando, "%d %c",
                       &opcao, &extra) != 1) {
                printf("Uso: 0\n");
                break;
            }

            printf("\n===== ENCERRANDO =====\n");
            return;

        default:
            printf("\n===== OPCAO INVALIDA =====\n");
        }
    }
}
