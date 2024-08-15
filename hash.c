#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int primo = 2654435761; // Constante para a função de hash */

/* Função de hash para CNPJ, transforma o CNPJ em um índice da tabela hash*/
unsigned int funcaoHashCNPJ(char* cnpj) {
    int cnpjInt = atoi(cnpj);
    return (unsigned int)(cnpjInt * primo) % TAMANHO_TABELA;
}

/* Função de hash para Nome, transforma o nome em um índice da tabela hash*/
unsigned int funcaoHashNome(char* nome) {
    int soma = 0;
    int i = 0;
    while (nome[i] != '\0') {
        soma += nome[i];
        i++;
    }
    return (unsigned int)(soma * primo) % TAMANHO_TABELA;
}

/* Insere uma empresa na tabela hash, tanto pela chave CNPJ quanto Nome*/
void inserirTabelaHash(Empresa* emp) {
    unsigned int indiceCNPJ = funcaoHashCNPJ(emp->cnpj);
    unsigned int indiceNome = funcaoHashNome(emp->nome);

    // Inserção na tabela hash usando o CNPJ como chave*/
    emp->proximo = tabelaHashCNPJ[indiceCNPJ];
    tabelaHashCNPJ[indiceCNPJ] = emp;

    // Inserção na tabela hash usando o Nome como chave*/
    emp->proximo = tabelaHashNome[indiceNome];
    tabelaHashNome[indiceNome] = emp;
}

/* Busca uma empresa na tabela hash usando o CNPJ como chave*/
Empresa* buscarTabelaHashCNPJ(char* cnpj) {
    unsigned int indice = funcaoHashCNPJ(cnpj);
    Empresa* emp = tabelaHashCNPJ[indice];
    while (emp != NULL) {
        if (strcmp(emp->cnpj, cnpj) == 0) {
            return emp;
        }
        emp = emp->proximo;
    }
    return NULL;
}

/* Busca uma empresa na tabela hash usando o Nome como chave*/
Empresa* buscarTabelaHashNome(char* nome) {
    unsigned int indice = funcaoHashNome(nome);
    Empresa* emp = tabelaHashNome[indice];
    while (emp != NULL) {
        if (strcmp(emp->nome, nome) == 0) {
            return emp;
        }
        emp = emp->proximo;
    }
    return NULL;
}

/* Função para buscar e exibir os dados de uma empresa usando o CNPJ*/
void buscarPorCNPJ() {
    char cnpjTeste[20];
    printf("Digite o CNPJ para buscar: ");
    fgets(cnpjTeste, 20, stdin);
    removerNovaLinha(cnpjTeste); // Remove a nova linha ao final

    Empresa* resultadoCNPJ = buscarTabelaHashCNPJ(cnpjTeste);

    if (resultadoCNPJ) {
        printf("Dados para CNPJ %s:\n", cnpjTeste);
        printf("Nome: %s\n", resultadoCNPJ->nome);
        printf("Codigo 1: %s\n", resultadoCNPJ->cod1);
        printf("Codigo 2: %s\n", resultadoCNPJ->cod2);
        printf("Valor: %s\n", resultadoCNPJ->valor);
        printf("Situacao: %s\n", resultadoCNPJ->situacao);
    } else {
        printf("CNPJ não encontrado.\n");
    }
}

/* Função para buscar e exibir os dados de uma empresa usando o Nome*/
void buscarPorNome() {
    char nomeTeste[MAXCHAR];
    printf("Digite o nome para buscar: ");
    fgets(nomeTeste, MAXCHAR, stdin);
    removerNovaLinha(nomeTeste); // Remove a nova linha ao final*/

    Empresa* resultadoNome = buscarTabelaHashNome(nomeTeste);

    if (resultadoNome) {
        printf("Dados para Nome %s:\n", nomeTeste);
        printf("CNPJ: %s\n", resultadoNome->cnpj);
        printf("Codigo 1: %s\n", resultadoNome->cod1);
        printf("Codigo 2: %s\n", resultadoNome->cod2);
        printf("Valor: %s\n", resultadoNome->valor);
        printf("Situacao: %s\n", resultadoNome->situacao);
    } else {
        printf("Nome não encontrado.\n");
    }
}
