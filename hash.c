#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

static const unsigned long primo = 2654435761UL; /* Constante primo usada nas funções de hash */

/* Calcula o índice de hash baseado no CNPJ */
int calculoCnpj(char* cnpj) {
    int cnpjInt = atoi(cnpj);
    return (int)(cnpjInt * primo % 10000); /* Retorna o índice de hash, limitado ao tamanho da tabela */
}

/* Calcula o índice de hash baseado no nome */
int calculoNome(char* linha) {
    int soma = 0;
    int i = 12;

    while (linha[i] != '"') {
        soma += linha[i];
        i++;
    }
    return (int)(soma * primo % 10000); /* Retorna o índice de hash, limitado ao tamanho da tabela */
}


