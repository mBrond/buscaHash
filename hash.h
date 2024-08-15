#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

#define MAXCHAR 1000
#define TAMANHO_TABELA 10007 // Tamanho da tabela hash

// Estrutura para armazenar dados da empresa
typedef struct Empresa {
    char cnpj[20];
    char nome[MAXCHAR];
    char cod1[20];
    char cod2[20];
    char valor[20];
    char situacao[20];
    struct Empresa* proximo; // Ponteiro para o próximo elemento na lista encadeada
} Empresa;

// Tabelas hash para CNPJ e Nome
extern Empresa* tabelaHashCNPJ[TAMANHO_TABELA];
extern Empresa* tabelaHashNome[TAMANHO_TABELA];

// Função de hash para CNPJ
unsigned int funcaoHashCNPJ(char* cnpj);

// Função de hash para Nome
unsigned int funcaoHashNome(char* nome);

// Insere uma empresa na tabela hash
void inserirTabelaHash(Empresa* emp);

// Busca uma empresa na tabela hash usando o CNPJ como chave
Empresa* buscarTabelaHashCNPJ(char* cnpj);

// Busca uma empresa na tabela hash usando o Nome como chave
Empresa* buscarTabelaHashNome(char* nome);

// Função para buscar e exibir os dados de uma empresa usando o CNPJ
void buscarPorCNPJ();

// Função para buscar e exibir os dados de uma empresa usando o Nome
void buscarPorNome();

#endif
